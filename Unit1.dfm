object Form1: TForm1
  Left = 409
  Top = -395
  Caption = 'Form1'
  ClientHeight = 444
  ClientWidth = 621
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesigned
  TextHeight = 15
  object Label1: TLabel
    Left = 312
    Top = 332
    Width = 281
    Height = 15
    Caption = 'Label1'
  end
  object VirtualStringTree1: TVirtualStringTree
    Left = 8
    Top = 8
    Width = 605
    Height = 318
    Align = alCustom
    Header.AutoSizeIndex = -1
    Header.MainColumn = 1
    Header.Options = [hoColumnResize, hoDrag, hoShowSortGlyphs, hoVisible]
    TabOrder = 0
    OnAddToSelection = VirtualStringTree1AddToSelection
    OnGetText = VirtualStringTree1GetText
    Touch.InteractiveGestures = [igPan, igPressAndTap]
    Touch.InteractiveGestureOptions = [igoPanSingleFingerHorizontal, igoPanSingleFingerVertical, igoPanInertia, igoPanGutter, igoParentPassthrough]
    Columns = <
      item
        Position = 0
        Text = #1048#1084#1103' '#1092#1072#1081#1083#1072
        Width = 125
      end>
  end
  object Button1: TButton
    Left = 8
    Top = 332
    Width = 137
    Height = 61
    Caption = #1047#1072#1087#1086#1083#1085#1080#1090#1100
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 160
    Top = 332
    Width = 129
    Height = 61
    Caption = #1054#1095#1080#1089#1090#1082#1072
    TabOrder = 2
    OnClick = Button2Click
  end
end
