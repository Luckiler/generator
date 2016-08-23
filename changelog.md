# Changelog

Link to the releases https://drive.google.com/drive/folders/0BxaYKfNl27draHJNc05udHdqeUU?usp=sharing

## 18/08/2016	
 - added explanation comments in the source code
 - tweaked the border avoidance values (decreased fom 40% 30% 20% to 30% 20% 10%)
 - added proximity to previous printed tile detector
 - added teleportation if stuck for too many time (with 'T' indicator)
 - modified the stuckTest() so it doesn't check inexistent tiles
 - modified the "skip iteration" if so it doesn't check inexistent tiles

## 19/08/2016
 - added progress bar
 - tweaked the previous printed neighbors check values
 - tweaked a lot of values fgor a lot of things so it looks nicer

## 23/08/2016
 - Made the printChars as variables (so they can be customized)
 - Implemented the following menus : 
	- Main menu
	- Generation menu
	- Generation configurations changer menu
 - Resolved all the build warning (and the stability too). No more signed int when it doesn't needs to