echo Run Tesseract for Training.. 
tesseract.exe letter.font.exp0.tif letter.font.exp0 nobatch box.train 
 
echo Compute the Character Set.. 
unicharset_extractor.exe letter.font.exp0.box 
mftraining -F font_properties -U unicharset -O letter.unicharset letter.font.exp0.tr 


echo Clustering.. 
cntraining.exe letter.font.exp0.tr 

echo Rename Files.. 
rename normproto letter.normproto 
rename inttemp letter.inttemp 
rename pffmtable letter.pffmtable 
rename shapetable letter.shapetable  

echo Create Tessdata.. 
combine_tessdata.exe letter. 

echo. & pause