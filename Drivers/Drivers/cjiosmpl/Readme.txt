Please use PLCTools.mdb 
to update a standard template of the workbench (monoresource) 
with the definitions of the devices you want to test.

(see procedure in the ProIO on-line help provided) 

this is the folder where you can prepare your PRJLIBRARY.MDB file 
before copying it to the Tpl directory of the workbench.

You may also use a plc.txt file with your IO device definitions.
The import utility PLCI.exe (found in Exe directory of the workbench)
or the File / Import command can then be used to import definitions 
in a project database.

The format of this file is completely documented (target, network)
in the ProDk on-line help.

Here is the syntax for IO devices definitions:
----------------------------------------------

Lines beginning with ; are ignored. 
All texts between brackets ‘[]’ must begin with a small letter. 
All keywords before the ‘=’ sign must begin with an upper-case letter.


The file must be begin with a target update instruction:
--------------------------------------------------------
The target must already exist in the project database.

[targetUpdate] TargetName 128 char max

The definitions that follow this instruction will add IO device definitions
to the mentioned target.

I/O Simple Device
-----------------
Declaration format
[device] <DeviceName> 128 char max
PackageName=text
DriverName=text
Type=<TypeName> any type except arrays (standard or already defined)
Direction=<Direction> it can be Input or Output
LowerChannel=<number> 
UpperChannel=<number> 
   lower and upper can be equal if strict number of channels.
   (usefull for "memory" devices for example)
SingleTextLine=text 255 char max
Comment=text multi-line comment
Help=Text command line to help
Keyword=Text 
[end]

; The parameters (decribed below) must follow the device they depend on.

[deviceParam] <ParamName> 128 char max
Format=<paramFormat>

ParamFormat can be
Word: 16 bit word expressed in decimal
Long: 32 bit long expressed in decimal
WordHexa: 16 bit word expressed in hexadecimal
LongHexa: 32 bit long expressed in hexadecimal
Bool: boolean, 1 or 0
Char: single character
String: string (15 char max + /0 character)
Float: float

Access=<paramAccess>

ParamAccess can be
User defined
Read only
Hidden: hidden  constant defined by the PLC manufacturer

Default=<defaultValue> Text, default value of the parameter
SingleTextLine=text 255 char max
[end]


I/O Complex Device
------------------
Declaration format
[complex] <ComplexName> 128 char max
PackageName=text
DriverName=text
Comment=<filename> multi-line comment included in a text file
SingleTextLine=text 255 char max
Help=Text command line to help
Keyword=Text 
Devices=device1,device,device3 
    list of simple devices of the complex device. 
    Simple devices must be defined earlier in the file and use 
    the same package and driver names.
[end]

[deviceParam] .<ParamName> 128 char max
same fields as for simple devices parameters
[end]





