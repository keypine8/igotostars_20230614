igotostars.org   source code
See for yourself by direct personal experience if astrology works.

This README.md file is under construction.

the 20230312 files are the latest (hashockey players)

for now, see "makekprod.sh" and "cfns.sh"

EMCC NOTE

to compile all C language code to Javascript code assumes the 14,000 files of emscripten are present
"emcc.sh" compiles all of the C language files- output file is emcc.js

then copy emcc.js into the working file per_emcc_my2.html AFTER these lines ============================================================================================



// --------------------------------------------------------------------------------------------------------------------
// what file runs?   local html or "official" godaddy html file 
// --------------------------------------------------------------------------------------------------------------------
// 
// looks like the lines below work like THIS:
//  1.  if you click on local file "igotostars.html", or whatever it is named,   it runs the local version
//  2.  if you type "igotostars.org" in browser,      it runs the "official" godaddy version index.html (USING HTTPS) 
// 
console.log('setting re-direct from HTTP  to  HTTPS');
var myLoc = window.location.href+'';
if (myLoc.indexOf('http://')==0){
    window.location.href = myLoc.replace('http://','https://');
}
// --------------------------------------------------------------------------------------------------------------------
// what file runs?   local html or "official" godaddy html file 
// --------------------------------------------------------------------------------------------------------------------



// NOTE: per_emcc.js   output of sh emcc.sh  script to compile all C to JS  GOES BELOW HERE 
// START OF MY C CODE plus JQuery

//   ig2s_4_START  emcc.js  C CODE compiled to javascript

// =======================================================================================================
// NOTE:  emcc.js GOES HERE   vvvvv  (jquery-3.2.1.js  or  jquery-3.2.1.min.js)  OR
// NOTE:  emcc.js GOES HERE   vvvvv  (jquery-3.3.1.js  or  jquery-3.3.1.min.js)
AFTER the above lines ============================================================================================

and BEFORE these lines ============================================================================================

// NOTE: per_emcc.js   output of sh per_emcc.sh  script to compile all C to JS  GOES ABOVE HERE 
// =======================================================================================================
// NOTE:  emcc.js GOES HERE   ^^^^^  (jquery-3.2.1.js  or  jquery-3.2.1.min.js)  OR
// NOTE:  emcc.js GOES HERE   ^^^^^  (jquery-3.3.1.js  or  jquery-3.3.1.min.js)
// =======================================================================================================

//   ig2s_4_END    emcc.js  C CODE compiled to javascript
====================================================================================================================


