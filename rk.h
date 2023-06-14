/* rk.h */

// MIT License
//
// Copyright (c) 2017 softwaredev
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//


  double gbl_birth_hour   ; // save in perdoc.c for excluding house-derived traits in perhtm.c
  double gbl_birth_minute ; // save in perdoc.c for excluding house-derived traits in perhtm.c
  double gbl_birth_am_pm  ; // save in perdoc.c for excluding house-derived traits in perhtm.c


//#define f_get_plt_in_12(i,k,m) (*(f_Plt_in_12+\
//(i)*NUM_HOUSES_CONSIDERED*NUM_SIGNS+\
//(k)*NUM_HOUSES_CONSIDERED+\
//(m)))


//#define APP_NAME "\"Me ooo oo BFFs\""
//#define APP_NAME "\"Me and my BFFs\""
//#define APP_NAME "iPhone App \"Me and my BFFs\""
//  #define APP_NAME "\"StarMeUp.html\""
//  #define APP_DESC "free app \"StarMeUp.html\""
//  #define APP_NAME "\"iGo2stars.html\""

// APP_NAME  not used  20210402
//
//  #define APP_NAME "free app from iGo2stars.org"
//  #define APP_DESC "free app, iGo2stars.html, from iGo2stars.org"
// APP_NAME  not used  20210402

//#define FAVICON_FOR_SMUP "<link href=\"data:image/x-icon;base64,iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAYAAABzenr0AAAEDWlDQ1BJQ0MgUHJvZmlsZQAAOI2NVV1oHFUUPrtzZyMkzlNsNIV0qD8NJQ2TVjShtLp/3d02bpZJNtoi6GT27s6Yyc44M7v9oU9FUHwx6psUxL+3gCAo9Q/bPrQvlQol2tQgKD60+INQ6Ium65k7M5lpurHeZe58853vnnvuuWfvBei5qliWkRQBFpquLRcy4nOHj4g9K5CEh6AXBqFXUR0rXalMAjZPC3e1W99Dwntf2dXd/p+tt0YdFSBxH2Kz5qgLiI8B8KdVy3YBevqRHz/qWh72Yui3MUDEL3q44WPXw3M+fo1pZuQs4tOIBVVTaoiXEI/MxfhGDPsxsNZfoE1q66ro5aJim3XdoLFw72H+n23BaIXzbcOnz5mfPoTvYVz7KzUl5+FRxEuqkp9G/Ajia219thzg25abkRE/BpDc3pqvphHvRFys2weqvp+krbWKIX7nhDbzLOItiM8358pTwdirqpPFnMF2xLc1WvLyOwTAibpbmvHHcvttU57y5+XqNZrLe3lE/Pq8eUj2fXKfOe3pfOjzhJYtB/yll5SDFcSDiH+hRkH25+L+sdxKEAMZahrlSX8ukqMOWy/jXW2m6M9LDBc31B9LFuv6gVKg/0Szi3KAr1kGq1GMjU/aLbnq6/lRxc4XfJ98hTargX++DbMJBSiYMIe9Ck1YAxFkKEAG3xbYaKmDDgYyFK0UGYpfoWYXG+fAPPI6tJnNwb7ClP7IyF+D+bjOtCpkhz6CFrIa/I6sFtNl8auFXGMTP34sNwI/JhkgEtmDz14ySfaRcTIBInmKPE32kxyyE2Tv+thKbEVePDfW/byMM1Kmm0XdObS7oGD/MypMXFPXrCwOtoYjyyn7BV29/MZfsVzpLDdRtuIZnbpXzvlf+ev8MvYr/Gqk4H/kV/G3csdazLuyTMPsbFhzd1UabQbjFvDRmcWJxR3zcfHkVw9GfpbJmeev9F08WW8uDkaslwX6avlWGU6NRKz0g/SHtCy9J30o/ca9zX3Kfc19zn3BXQKRO8ud477hLnAfc1/G9mrzGlrfexZ5GLdn6ZZrrEohI2wVHhZywjbhUWEy8icMCGNCUdiBlq3r+xafL549HQ5jH+an+1y+LlYBifuxAvRN/lVVVOlwlCkdVm9NOL5BE4wkQ2SMlDZU97hX86EilU/lUmkQUztTE6mx1EEPh7OmdqBtAvv8HdWpbrJS6tJj3n0CWdM6busNzRV3S9KTYhqvNiqWmuroiKgYhshMjmhTh9ptWhsF7970j/SbMrsPE1suR5z7DMC+P/Hs+y7ijrQAlhyAgccjbhjPygfeBTjzhNqy28EdkUh8C+DU9+z2v/oyeH791OncxHOs5y2AtTc7nb/f73TWPkD/qwBnjX8BoJ98VVBg/m8AAAAJcEhZcwAACxMAAAsTAQCanBgAAAILaVRYdFhNTDpjb20uYWRvYmUueG1wAAAAAAA8eDp4bXBtZXRhIHhtbG5zOng9ImFkb2JlOm5zOm1ldGEvIiB4OnhtcHRrPSJYTVAgQ29yZSA1LjQuMCI+CiAgIDxyZGY6UkRGIHhtbG5zOnJkZj0iaHR0cDovL3d3dy53My5vcmcvMTk5OS8wMi8yMi1yZGYtc3ludGF4LW5zIyI+CiAgICAgIDxyZGY6RGVzY3JpcHRpb24gcmRmOmFib3V0PSIiCiAgICAgICAgICAgIHhtbG5zOnRpZmY9Imh0dHA6Ly9ucy5hZG9iZS5jb20vdGlmZi8xLjAvIj4KICAgICAgICAgPHRpZmY6UmVzb2x1dGlvblVuaXQ+MjwvdGlmZjpSZXNvbHV0aW9uVW5pdD4KICAgICAgICAgPHRpZmY6Q29tcHJlc3Npb24+NTwvdGlmZjpDb21wcmVzc2lvbj4KICAgICAgICAgPHRpZmY6T3JpZW50YXRpb24+MTwvdGlmZjpPcmllbnRhdGlvbj4KICAgICAgICAgPHRpZmY6UGhvdG9tZXRyaWNJbnRlcnByZXRhdGlvbj4yPC90aWZmOlBob3RvbWV0cmljSW50ZXJwcmV0YXRpb24+CiAgICAgIDwvcmRmOkRlc2NyaXB0aW9uPgogICA8L3JkZjpSREY+CjwveDp4bXBtZXRhPgqG0q4kAAAGqElEQVRYCe2WS2xcVxnHf/c5c8czHo89Hie2ievYsuNUbWicqrRdmEUrwaaw6RKBKliA1EqVgBWvNRKbdluxgE2XLiAoaRMFsACDs0BKxYbWCXHaODhjex73/eA7dzymduzQVELZcGbunLnn3vN9//P/nhrTZDzEoT9E3bnqhw7A/FQMHGc07cGlPRiAvmKlqH8pnWq9f6n7BwByPIC+MiVwb2iGhm4bmJaBbhqoezWyNCONU5IoJgkSsmRv8ycAci8AtVc2OmYJQ9NJMxGcJYR2iFGycEpFTMcUIDq60XMhBSAJExI/IXZjQjck8eIc2H9j4yAAUV6xKwyYA6QiMI1SNFPDqJrYQzYMaAIkQrN0TPnkp89/hIEBAZrExN0Is2MStkOCtk8Wi9D7MHEAwKA5SGu3RXuznQvf/5mRf5ZcJRgvnaJcLsNQhlkx0UR40k2Jm0q5MKCYKgQ5cKU42BUQyiTHgNgHUNErtJotTgyM8eIrLzIzN0PRKRKkAVvuFi2vzba3wzX7PYI5l+ojgxSqhdwMUTfG3fDwrgWE62IeU0yjkIlepTxo+T0nPQKEqV6qWBWiMKJm1fjOt7/L177yVYZrI/sEqD+xPL904xI/bH6PdDxhaLBKwR7ANG3C2MMa34HJGFZF4N8cskw5ppgxFHZCcU7xiaOGrgAUjAK+63P6M6d5+nNP58rTNMnfD6OQmx9t8Nfba1w23+WD4avU9FFBpGNnDg6DWImDmdpYdYPsSQ99PqNSGmSgUkYv6VhFYUXvMXIYhK5s48c+VTnR1b9fZWVlBd8XIbqRv7tx+5+8+tNXeebKM/y4+RMa0YycLiXTUqIslL1dYpkz+Wi+RI2TEM273K1ukekZtaFhzKJFKv+1IxzBoMaPwjTEsRx8z2d15c9MTU0xOzuLbQm9Ycja1hprlTXODS/k4ZkaaQ+gAImSgDgW20cBfujh+h18ujwSzvDejWvsNLc5aZ2EUA4q8jmU/HMAOQuJT6M2SnNjm+W3l2k0GoxPjjMxNsH5mfNiz5jl1q/wjX8xYo1haRZJKjGfSLgp5YFLEPp4QZeb3l1+MPd9vn72G3ibHqt/WhVfMVFR5kXegYjoAVBkiym6kUv9xAhuyePtK79l19+hWHGYH5/n+YnneVR7lA1vkz/4q3SSbbF/SexvEEcRQeDnIJIwY6fV4aXJl/jSuS+zePYC9YERLi6/g7frcaI+RkfM1rfGfwDsgXCFxlq1xuipUX538/f88oPfkBoR1XqVZ8ee5Qu1L7JoLOL5Ie92r3Dd26AVbCIYJBUnmKFipiXhqLHgLHBm+gxPnDvP/Mwcb11+i86tLvVGHTd2cxAHASgiJH691ENzdCZOTmLpNr9wl7nIr8WGAQ27wYXaBZ4bfo4XSi9wTnscMyjyl85VdjtdyRUtYQOurVzjqfJTnJ1eoOSUWDizwGRjkkt/vExb70jGLefm0+7piCQsVaEpDBcoNIrU63XKJyu0F3Z4v/Z+jvqV+sssjS6xUFtguDiMcuK7QZM73Tsyb+G5HuVWmcWpRabGp0iTFNsusLO7zTdf/hZv/vxNGmca3Anu7CV0Rf/HRppIApHCgp/RlgyY3M2ofjjE4uBn2S5s8drt13lt83U+X1piaWiJx4YeY646x+LoeaqFKqY46IHRi2hhJiBQkSBDha0a9zKgVhULUu2ckVJ+FWuOpN0izilJNtNSisuZhJrPR/EGzaTnUE/Yj7OoP8msP8uEPclQqcZgoYxjSwFJodlscvGdi7zxszdoFVqUZF35wbEAlJfaZZvisEMOYFBMUilij9oYJzTMQamIBVNKtiEnC2nu7nDj1jrckgNIVh4NRjmdTFPWKmRSVdevr7P+j+swAeViWaKok5vzaAB7LGiSPm1RXKwVKchsCSDLsbFLAmJAGpKCoJSvHuoYrmR1NyOU6Oi02uxu7dD+UKqq6MyTj5SWelW8P3H3I0CpOR6AeiqmUF2PXRGlAkAxYjoWhi0nN8QUew1JInUjkUQVSxhmnviORBhd2axyTtwDGUvSaodt1KxA98d+Oe4vHJjlxV45lQ5HhCci3CxFGKq4SMnVVUum3lEtmdCsOqLIi/C7HqkrhlcFsK9Mzf3rY0ruz0D/RTmMGooNoyA9oW3lDUefgX5PqMpu3klJf6hloq2vvLd93/P3bvPpkwHo79gD0j+J8hE1VO3Po0oOnY9DivdWj5zub4LDW/qCFRClU6g/MPrPDyze/+bBAPRlfQpF/a2H50PV+fDj//39/wH8G8Yr1EMjZXOAAAAAAElFTkSuQmCC\" rel=\"icon\" type=\"image/x-icon\" />"


/* ptr to end of str s (last char- not \0)  bbb */
//#define PENDSTR(s) (&(s)[strlen((s))-1])
/* do as v (any lvalue) (can be ptr) goes from lo to hi inclusive */
#define RKDO(v,lo,hi) for((v)=(lo);(v)<=(hi);(v)++)
/* return 1 if v is between lo and hi inclusive */
#define RKISBETWEEN(v,lo,hi) ((((v)>=(lo))&&((v)<=(hi)))?1:0)

/******* BIT STUFF 
*   conventions u is an unsigned quantity, mask is hex like below
*       *** masks ***
*   #define _FILE_MODIFIED  0x10
*   #define _USED      0x40
*   #define _FILE_BUSY    0x80
******/
/* sets to 1 in u the bits that are set to 1 in mask */
#define RKBITON(u,mask) ((u)=(u)|(mask))
/* sets to 0 in u the bits that are set to 1 in mask */
#define RKBITOFF(u,mask) ((u)=(u)&~(mask))
/* returns 1 if bit is on, 0 if bit is off. */
#define RKBITTST(u,mask) ((((u)&(mask))==0)?0:1)

#define rkequal(s1,s2) ((strcmp(s1,s2)==0)?1:0)

/***
fread(buf,size,nitems,fp) returns num items successfully read
fget returns number of bytes read (0 for eof)
fput returns number of bytes written
***/
/* #define fget(buf,size,fp) fread (buf,1,size,fp) */
#define fput(buf,size,fp) fwrite(buf,1,size,fp)

/* to replace qnx "abort(msg)" */
#define rkabort(msg) {fprintf(stderr,"%s", msg); exit(1);}

/* #define _eq_ == */
/* #define _ne_ != */
/* #define _gt_ > */
/* #define _ge_ >= */
/* #define _lt_ < */
/* #define _le_ <= */
/* #define _andif_ && */
/* #define _orif_ || */
/* #define NULLPTR ((char *)0) */
/* #define RKYES 1 */
/* #define RKNO 0 */

/* is tab or space */
/* #define ISTS(c) ((strchr(" \t",(c))==NULL)?0:1) */
/* is tab or space or newline */
/* #define ISTSN(c) ((strchr(" \t\n",(c))==NULL)?0:1) */
/* copies a struct to another struct of the same type */
/* (make sure they're the same type) */
/* #define CPYSTRUCT(d,s) memcpy((&d),(&s),sizeof(s)); */
/* step thru string until null */
/* #define SSTEP(s,prk) for((prk)=(s);(*prk)!='\0';(prk)++) */
/* sleep for v ticks (other tasks get cpu during sleep) */
/* #define SLEEPTICK(v) (set_timer(TIMER_WAKEUP,ABSOLUTE,(v)) */
/* puts num chars = c into buffer s.  Adds '\0' at end */
/* #define SFILL(s,num,c) {memset(s,c,num);*(s+num)='/0';} */
/************
* WARNING: this fgetline #define does not return the number of chars read.
* fgets returns NULL at eof, fgetline returns 0 (chars read)
************/
/* #define fgetline(fp,buf,maxlen) fgets(buf,maxlen+1,fp) */

/* end of rk.h */
