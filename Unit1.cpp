//---------------------------------------------------------------------------

#include <vcl.h>
#include <string.h>
#pragma hdrstop


#include "Unit1.h"
#include "sqlite3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VirtualTrees"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	VirtualStringTree1->NodeDataSize =sizeof(TreeNodeStruct);
    VirtualStringTree2->NodeDataSize =sizeof(TreeNodeStruct);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
		 VirtualStringTree1->Clear();
		 VirtualStringTree1->BeginUpdate();

		 char *db_name="Databases.db";

		 AnsiString str="Select * from databases ;";

		 sqlite3 *db;
		 sqlite3_stmt *pStmt;
		 int rc,coln,i,j;

		 if ( sqlite3_open(db_name,&db))
			{
		ShowMessage("Can't open database: ");
		ShowMessage(sqlite3_errmsg(db));
		sqlite3_close(db);
			}


		// шаг 1 подготовка SQL инструкции к выполнению
        //(компил¤ци¤ ее в байт-код)
		if (sqlite3_prepare(db, str.c_str(), -1, &pStmt, NULL))
		{
			sqlite3_finalize(pStmt);
            sqlite3_close(db);
		}
		// шаг 2 выполнение SQL инструкций

		while((rc = sqlite3_step(pStmt)) == SQLITE_ROW)
		{
			PVirtualNode entryNode = VirtualStringTree1->AddChild(VirtualStringTree1->RootNode);
			TreeNodeStruct *nodeData = (TreeNodeStruct*) VirtualStringTree1->GetNodeData(entryNode);
			coln = sqlite3_data_count(pStmt);
            for(j=0; j<coln; j++)
			{
			AnsiString otwet;
			otwet.printf("%s",sqlite3_column_text(pStmt, j));
				  switch (j) {
					case 0:
					  {
						  nodeData->id =otwet.ToInt();;
						  break;
					  }
					case 1:
					  {
						  nodeData->origin = UnicodeString(otwet);
						  break;
					  }
					case 2:
					  {
						  nodeData->name=  UnicodeString(otwet);
						  break;
					  }
					case 3:
					  {
						  nodeData->description= UnicodeString(otwet);
						  break;
					  }
					case 4:
					  {
						  nodeData->estimated_size=otwet.ToInt();
						  break;
					  }

				  }

			}

		}
		// получение сообщени¤ при ошибке
		// шаг 4 завершение выполнени¤ запроса
		sqlite3_finalize(pStmt);


	// закрытие Ѕƒ
	sqlite3_close(db);

		 VirtualStringTree1->EndUpdate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
		VirtualStringTree1->Clear();
		VirtualStringTree2->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::VirtualStringTree1GetText(TBaseVirtualTree *Sender, PVirtualNode Node,
		  TColumnIndex Column, TVSTTextType TextType, UnicodeString &CellText)

{
	  if(Node == NULL) return;
	  TreeNodeStruct *nodeData = (TreeNodeStruct*) VirtualStringTree1->GetNodeData(Node);

	  switch (Column) {
	  case 0:
	  {
		  CellText = (UnicodeString)nodeData->id;
		  break;
	  }
	  case 1:
	  {
		  CellText = nodeData->origin;
		  break;
	  }

	  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::VirtualStringTree1AddToSelection(TBaseVirtualTree *Sender,
          PVirtualNode Node)
{
		if(Node == NULL) return;

		VirtualStringTree2->Clear();
		VirtualStringTree2->BeginUpdate();

		TreeNodeStruct *nodeData1 = (TreeNodeStruct*) VirtualStringTree1->GetNodeData(Node);

		PVirtualNode entryNode = VirtualStringTree2->AddChild(VirtualStringTree2->RootNode);
		TreeNodeStruct *nodeData2 = (TreeNodeStruct*) VirtualStringTree2->GetNodeData(entryNode);


		nodeData2->name=nodeData1->name;
		nodeData2->description=nodeData1->description;
		nodeData2->estimated_size=nodeData1->estimated_size;

		VirtualStringTree2->EndUpdate();

}
//---------------------------------------------------------------------------



void __fastcall TForm1::VirtualStringTree2GetText(TBaseVirtualTree *Sender, PVirtualNode Node,
          TColumnIndex Column, TVSTTextType TextType, UnicodeString &CellText)

{
	 TreeNodeStruct *nodeData = (TreeNodeStruct*) VirtualStringTree2->GetNodeData(Node);

	switch (Column) {
		case 0:
		{
		  CellText=nodeData->name;
		  break;
		}
	case 1:
		{
		  CellText=nodeData->description;
		  break;
		}
	case 2:
		{
		  CellText=(UnicodeString)nodeData->estimated_size;
		  break;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
		 char *db_name="Databases.db";
		 PVirtualNode numstr =  VirtualStringTree1->GetFirstSelected();
		 if(numstr==NULL)
		 {
		  return;
		 }
		 TreeNodeStruct *nodeData = (TreeNodeStruct*) VirtualStringTree1->GetNodeData(numstr);

		 AnsiString str="DELETE from databases where id = "+(AnsiString)nodeData->id +" ;";
		 sqlite3 *db;
		 sqlite3_stmt *pStmt;
		 int rc,coln,j;
		 UnicodeString Zapros;

		 if ( sqlite3_open(db_name,&db))
			{
		ShowMessage("Can't open database: ");
		ShowMessage(sqlite3_errmsg(db));
		sqlite3_close(db);
			}

			if (sqlite3_exec(db, str.c_str(), NULL, 0,NULL))
			{
				Label1->Caption=str;
				sqlite3_finalize(pStmt);
				sqlite3_close(db);
			}


		sqlite3_finalize(pStmt);
		sqlite3_close(db);

         Button1Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
		char *db_name="Databases.db";
		 PVirtualNode numstr =  VirtualStringTree1->GetFirstSelected();
		 TreeNodeStruct *nodeData = (TreeNodeStruct*) VirtualStringTree1->GetNodeData(numstr);

		 AnsiString str="DELETE from databases;";
		 sqlite3 *db;

		 UnicodeString Zapros;

		 if ( sqlite3_open(db_name,&db))
			{
		ShowMessage("Can't open database: ");
		ShowMessage(sqlite3_errmsg(db));
		sqlite3_close(db);
			}

		// шаг 2 выполнение SQL инструкций
		if (sqlite3_exec(db, str.c_str(), NULL, 0,NULL))
		{
            Label1->Caption="Error";
			sqlite3_close(db);
		}

		sqlite3_close(db);
		Button2Click(Sender);
}
//---------------------------------------------------------------------------

