# TSV_Sheets_Newline_Fixer
Google Sheets' .tsv export replaces all newline characters with spaces. This program detects when a CR LF has fallen victim to this and restores it.
Currently, outputs the result as a .txt file, since that is the format I need them as.

To use the program, simply download a tsv file from whichever source you desire, and then drag it onto the TSV_Fixer.exe program. A text file with the matching name should appear.

Compilation of this program should be simple, since there's no external libraries or anything of the sort involved.
-Simply make sure your compiler supports C++ 14 or later.
