object Form1: TForm1
  Left = 694
  Top = 312
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
    Left = 8
    Top = 408
    Width = 193
    Height = 28
    Caption = 'Label1'
  end
  object VirtualStringTree1: TVirtualStringTree
    Left = 8
    Top = 8
    Width = 605
    Height = 318
    Align = alCustom
    Header.AutoSizeIndex = -1
    Header.Options = [hoColumnResize, hoDrag, hoShowSortGlyphs, hoVisible]
    TabOrder = 0
    OnAddToSelection = VirtualStringTree1AddToSelection
    OnGetText = VirtualStringTree1GetText
    Touch.InteractiveGestures = [igPan, igPressAndTap]
    Touch.InteractiveGestureOptions = [igoPanSingleFingerHorizontal, igoPanSingleFingerVertical, igoPanInertia, igoPanGutter, igoParentPassthrough]
    Columns = <
      item
        Position = 0
        Text = #1048#1076#1077#1085#1090#1080#1092#1080#1082#1072#1090#1086#1088
        Width = 99
      end
      item
        Position = 1
        Text = #1048#1084#1103' '#1092#1072#1081#1083#1072
        Width = 125
      end>
  end
  object Button1: TButton
    Left = 8
    Top = 332
    Width = 89
    Height = 29
    Caption = #1047#1072#1087#1086#1083#1085#1080#1090#1100
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 112
    Top = 332
    Width = 89
    Height = 29
    Caption = #1054#1095#1080#1089#1090#1082#1072
    TabOrder = 2
    OnClick = Button2Click
  end
  object VirtualStringTree2: TVirtualStringTree
    Left = 224
    Top = 332
    Width = 389
    Height = 109
    Align = alCustom
    Header.AutoSizeIndex = 0
    Header.Options = [hoColumnResize, hoDrag, hoShowSortGlyphs, hoVisible]
    TabOrder = 3
    OnGetText = VirtualStringTree2GetText
    Touch.InteractiveGestures = [igPan, igPressAndTap]
    Touch.InteractiveGestureOptions = [igoPanSingleFingerHorizontal, igoPanSingleFingerVertical, igoPanInertia, igoPanGutter, igoParentPassthrough]
    Columns = <
      item
        Position = 0
        Text = #1048#1084#1103
        Width = 90
      end
      item
        Position = 1
        Text = #1054#1087#1080#1089#1072#1085#1080#1077
        Width = 124
      end
      item
        Position = 2
        Text = #1055#1088#1077#1076#1087#1086#1083#1072#1075#1072#1077#1084#1099#1081' '#1088#1072#1079#1084#1077#1088
        Width = 152
      end>
  end
  object Button3: TButton
    Left = 8
    Top = 367
    Width = 89
    Height = 26
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1089#1090#1088#1086#1082#1091
    TabOrder = 4
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 112
    Top = 367
    Width = 89
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1041#1044
    TabOrder = 5
    OnClick = Button4Click
  end
end
