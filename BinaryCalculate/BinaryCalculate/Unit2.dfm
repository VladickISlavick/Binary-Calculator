object Form2: TForm2
  Left = 555
  Top = 177
  Caption = 'Form2'
  ClientHeight = 269
  ClientWidth = 290
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  OnClose = Close
  OnCreate = Load
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 164
    Top = 47
    Width = 31
    Height = 13
    Caption = 'Label1'
  end
  object Label2: TLabel
    Left = 148
    Top = 58
    Width = 31
    Height = 13
    Caption = 'Label2'
  end
  object Label3: TLabel
    Left = 164
    Top = 66
    Width = 31
    Height = 13
    Caption = 'Label3'
  end
  object Label4: TLabel
    Left = 164
    Top = 85
    Width = 31
    Height = 13
    Caption = 'Label4'
  end
  object Label5: TLabel
    Left = 101
    Top = 58
    Width = 31
    Height = 13
    Caption = 'Label5'
  end
  object Label6: TLabel
    Left = 8
    Top = 39
    Width = 31
    Height = 13
    Caption = 'Label6'
  end
  object Calc: TButton
    Left = 170
    Top = 222
    Width = 111
    Height = 41
    Caption = 'Calc'
    TabOrder = 0
    OnClick = CalcClick
  end
  object Edit1: TEdit
    Left = 8
    Top = 8
    Width = 273
    Height = 21
    TabOrder = 1
    Text = 'Edit1'
  end
  object Button0: TButton
    Left = 8
    Top = 222
    Width = 156
    Height = 41
    Caption = '0'
    TabOrder = 2
    OnClick = Button0Click
  end
  object Button3: TButton
    Left = 115
    Top = 191
    Width = 49
    Height = 25
    Caption = '3'
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 8
    Top = 160
    Width = 47
    Height = 25
    Caption = '4'
    TabOrder = 4
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 61
    Top = 160
    Width = 48
    Height = 25
    Caption = '5'
    TabOrder = 5
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 115
    Top = 160
    Width = 49
    Height = 25
    Caption = '6'
    TabOrder = 6
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 8
    Top = 129
    Width = 47
    Height = 25
    Caption = '7'
    TabOrder = 7
    OnClick = Button7Click
  end
  object Button1: TButton
    Left = 8
    Top = 191
    Width = 47
    Height = 25
    Caption = '1'
    TabOrder = 8
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 61
    Top = 191
    Width = 48
    Height = 25
    Caption = '2'
    TabOrder = 9
    OnClick = Button2Click
  end
  object Button8: TButton
    Left = 61
    Top = 129
    Width = 48
    Height = 25
    Caption = '8'
    TabOrder = 10
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 115
    Top = 129
    Width = 49
    Height = 25
    Caption = '9'
    TabOrder = 11
    OnClick = Button9Click
  end
  object ButtonDivision: TButton
    Left = 209
    Top = 175
    Width = 33
    Height = 41
    Caption = '/'
    TabOrder = 12
    OnClick = ButtonDivisionClick
  end
  object ButtonAdd: TButton
    Left = 209
    Top = 129
    Width = 33
    Height = 37
    Caption = '+'
    TabOrder = 13
    OnClick = ButtonAddClick
  end
  object ButtonSubt: TButton
    Left = 170
    Top = 129
    Width = 33
    Height = 37
    Caption = '-'
    TabOrder = 14
    OnClick = ButtonSubtClick
  end
  object ButtonMulti: TButton
    Left = 170
    Top = 175
    Width = 33
    Height = 41
    Caption = '*'
    TabOrder = 15
    OnClick = ButtonMultiClick
  end
  object ButtonCE: TButton
    Left = 248
    Top = 129
    Width = 33
    Height = 40
    Caption = 'CE'
    TabOrder = 16
    OnClick = ButtonCEClick
  end
  object ButtonClearSymbol: TButton
    Left = 249
    Top = 175
    Width = 32
    Height = 41
    Caption = 'C'
    TabOrder = 17
    OnClick = ButtonClearSymbolClick
  end
end
