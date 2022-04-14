//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
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
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
		 VirtualStringTree1->Clear();
		 VirtualStringTree1->BeginUpdate();
		 for(int i=0; i<1000000; i++)
		 {
			PVirtualNode entryNode = VirtualStringTree1->AddChild(VirtualStringTree1->RootNode);

			TreeNodeStruct *nodeData = (TreeNodeStruct*) VirtualStringTree1->GetNodeData(entryNode);
			nodeData->id =i;
			nodeData->FileName = u"Ôאיכ םמלונ " + UnicodeString(i);

		 }
         VirtualStringTree1->EndUpdate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        VirtualStringTree1->Clear();
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
		  CellText = nodeData->FileName;
		  break;
	  }

	  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::VirtualStringTree1AddToSelection(TBaseVirtualTree *Sender,
          PVirtualNode Node)
{
		if(Node == NULL) return;

		TreeNodeStruct *nodeData = (TreeNodeStruct*) VirtualStringTree1->GetNodeData(Node);

		Label1->Caption=nodeData->id;

}
//---------------------------------------------------------------------------

