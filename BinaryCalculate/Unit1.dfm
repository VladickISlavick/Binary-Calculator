object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 147
  ClientWidth = 460
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 251
    Top = 35
    Width = 56
    Height = 13
    Caption = 'AAAAAAAA'
  end
  object Edit1: TEdit
    Left = 24
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 0
    Text = 'Edit1'
  end
  object Button1: TButton
    Left = 8
    Top = 35
    Width = 75
    Height = 25
    Caption = '1'
    TabOrder = 1
    OnClick = Button1Click
  end
  object ButtonSUBT: TButton
    Left = 8
    Top = 66
    Width = 75
    Height = 25
    Caption = '-'
    TabOrder = 2
    OnClick = ButtonSUBTClick
  end
  object ButtonPLUS: TButton
    Left = 8
    Top = 97
    Width = 75
    Height = 25
    Caption = '+'
    TabOrder = 3
    OnClick = ButtonPLUSClick
  end
  object ButtonDIV: TButton
    Left = 89
    Top = 97
    Width = 75
    Height = 25
    Caption = '/'
    TabOrder = 4
    OnClick = ButtonDIVClick
  end
  object ButtonMULTI: TButton
    Left = 89
    Top = 66
    Width = 75
    Height = 25
    Caption = '*'
    TabOrder = 5
    OnClick = ButtonMULTIClick
  end
  object ButtonCALC: TButton
    Left = 170
    Top = 97
    Width = 75
    Height = 25
    Caption = 'Calc'
    TabOrder = 6
    OnClick = ButtonCALCClick
  end
  object ButtonC: TButton
    Left = 170
    Top = 66
    Width = 75
    Height = 25
    Caption = 'C'
    TabOrder = 7
    OnClick = ButtonCClick
  end
  object ButtonCE: TButton
    Left = 170
    Top = 35
    Width = 75
    Height = 25
    Caption = 'CE'
    TabOrder = 8
    OnClick = ButtonCEClick
  end
  object Button0: TButton
    Left = 89
    Top = 35
    Width = 75
    Height = 25
    Caption = '0'
    TabOrder = 9
    OnClick = Button0Click
  end
  object Edit2: TEdit
    Left = 8
    Top = 8
    Width = 313
    Height = 21
    TabOrder = 10
  end
  object MainMenu1: TMainMenu
    Left = 8
    Top = 120
    object Normal1: TMenuItem
      Caption = 'Normal'
      OnClick = Normal1Click
    end
    object Close1: TMenuItem
      Caption = 'Close'
    end
  end
end
