/* perhtm.c */

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

int C_calc_MOSM_score_1_99_for(char *arg_trait_scores_CSV ); // arg_trait_scores_CSV is 5 PR scores like "56,34,08,13,87"

  // read from input docin_lines string array
  // format and write an html output file            bbb
  // format and write to js-malloc'd  memory
  //
  char *gbl_space_for_HTML_per; // space malloc'ed in js,  passed into mamb_report_personality(), then here


#define GBL_HTML_HAS_NEWLINES 1
/* #define GBL_HTML_HAS_NEWLINES 0 */

//char *gbl_HTML_code_for_per;  // gbl smup html code written at this location
int   gbl_is_first_p_fn_prtlin;
int   gbl_put_html_here;

int gbl_are_in_per_htm_webview;      /* 1 = yes, 0 = no */
int gbl_we_are_in_PRE_block_content; /* 1 = yes, 0 = no */

//char gbl_person_name[64];  // "p_" because same var in objC code
char gbl_p_person_name[64];  // "p_" because same var in objC code

// smup char gbl_pfnameHTML[2024];
//
char gbl_instructions[128];

#include "rkdebug_externs.h"

#include "rk.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "perhtm.h"

/* #define APP_NAME "Astrology for Me" */
/* #define APP_NAME "Astrology by Measurement" */
/* #define APP_NAME "Me & My BFFs" */
/* #define APP_NAME "\"Me & my BFFs\"" */
/* #define APP_NAME "\"My BFFs and I\"" */
//#define APP_NAME "Me and my BFFs"

/* file extension for group sharing will be ".mamb" */

#define MAX_STARS 82  /* in perdoc.h also */
#define GRH_CHAR '*'  /* in perdoc.h also */

/* int rkdb = 0; */ /* 0=no, 1=yes */



void add_all_benchmark_lines(void);
void write_html_for_trait_table(void);
void write_TBLRPT_trait_data(void);            // !!!!  TBLRPT  instead of html for webview  !!!!! 
// smup void write_webview_html_for_trait_table(void);

struct trait_table_line {
  char    trait[16];
  char    score[6];
  char    influence[16];
};
struct trait_table_line trait_lines[12];  /* need 11 */

int Func_compare_trait_line_scores(
  struct trait_table_line *line1,
  struct trait_table_line *line2
);
typedef int (*compareFunc_trait) (const void *, const void *);



void p_fn_prtlin(char *lin);
void p_fn_prtlin_aspect(char *lin);  /* no \n at end */
void p_fn_prtlin_stars(char *starline);

char  swork33[4048];


double calc_percentile_rankD(double in_score, double sc_hi, double sc_lo, double pr_hi, double pr_lo);  // use doubles

/* in mambutil.o */
//extern int calc_percentile_rank(int in_score, int sc_hi, int sc_lo, int pr_hi, int pr_lo);
extern char *csv_get_field(char *csv_string, char *delim, int want_fieldnum);
extern void strsubg(char *s, char *replace_me, char *with_me);
extern int  sfind(char s[], char c);
extern int scharcnt(char *s, int c);
extern int sall(char *s, char *set);
extern char *mkstr(char *s, char *begarg, char *end);
extern void scharout(char *s, int c);
extern void put_br_every_n(char *instr, int line_not_longer_than_this);
extern void fn_right_pad_with_hidden(char *s_to_pad, int num_to_pad);
extern int binsearch_asp(char *asp_code, struct aspect tab[], int num_elements);
/* in mambutil.o */


extern void p_docin_free(void);   /* in grpdoc.o */


void p_docin_get(char *in_line);   

char doclin[512];

/* -------------------------- */
int    global_max_docin_idx;
char **global_docin_lines;
int    global_read_idx;
int    global_n;
char  *global_p = &swork33[0];
/* -------------------------- */


// smup FILE *Fp_p_HTML_file;
//

/* char s1[512]; */
/* char s2[512]; */
/* char s3[512]; */
/* char s4[512]; */
/* char s5[512]; */
/* char s6[512]; */
char writebuf[4048];
char workbuf[4048];



// smup #define MAX_WK 10
// smup struct {
// smup   char wk[133]; 
// smup } wks[MAX_WK];
//
//#define arr(nn) (wks[nn].wk)  /* arr arr arr arr arr  HERE */
/* wks is array of struct size 133 chars
* 
*  (wks[k].wk)  <==>   arr(k)
*   
*  this expression:  (wks[k].wk)  
*  gives you the kth 133-char buffer in array wks.
*
*  With the *define* below, you can say this: 
*  arr(k) for the same buffer.
*/



void do_orig_trait_graph(void);
void do_benchmark_trait_graph(void);
void p_fn_output_top_of_html_file(void);
// smup void p_fn_webview_output_top_of_html_file(void);

char aspect_code[10];
void p_fn_browser_aspect_text(char *aspect_code);
// smup void p_fn_webview_aspect_text(char *aspect_code);

int is_first_p_docin_get;  /* 1=yes, 0=no */



// smup int make_per_htm_file_webview(
// smup   char *in_html_filename,
// smup   char *in_docin_lines[],
// smup   int   in_docin_last_idx);
//

int make_per_htm_file_browser( 
//  char *in_html_filename,
  char *arg_space_for_HTML_per, // space malloc'ed in js,  passed into mamb_report_personality()
  char *in_docin_lines[],
  int   in_docin_last_idx);


/* invocation
*
* retval = make_per_htm_file(html_output_filename, docin_lines, docin_idx);
*
*  output entire ".html" file
*/
// smup int make_per_htm_file(      // =========================================
//
//char *make_per_htm_file(      // =========================================
int make_per_htm_file(      // =========================================
//  char *in_html_filename,
  char *arg_space_for_HTML_per, // space malloc'ed in js,  passed into mamb_report_personality()
  char *in_docin_lines[],
  int   in_docin_last_idx,
  char *instructions
)
{
//tn();trn("in make_per_htm_file()");
/* ksn(instructions); */
/* ksn(in_html_filename); */

  gbl_is_first_p_fn_prtlin        = 1;  /* init to true */
  gbl_space_for_HTML_per          = arg_space_for_HTML_per;

  is_first_p_docin_get            = 1;  /* init to true */
  gbl_we_are_in_PRE_block_content = 0;  /* init to false */

// smup   strcpy(gbl_pfnameHTML, in_html_filename);
//

  int  retval;

  global_max_docin_idx = in_docin_last_idx;
  global_docin_lines   = in_docin_lines;
  strcpy(gbl_instructions, instructions);

// smup   if (strstr(gbl_instructions, "make html for webview") != NULL) {
// smup /* tn();trn("make html for webview");ksn(in_html_filename); */
// smup     gbl_are_in_per_htm_webview = 1;
// smup     retval = make_per_htm_file_webview (
// smup       in_html_filename,
// smup       in_docin_lines,
// smup       in_docin_last_idx
// smup     );
// smup     if (retval != 0) return 1;
// smup   }
  if (strstr(gbl_instructions, "make html for browser") != NULL) {
/* tn();trn("make html for browser");ksn(in_html_filename); */
    gbl_are_in_per_htm_webview = 0;

//trn("calling make_per_htm_file_browser()");
    retval = make_per_htm_file_browser ( // smup - now writes code to char array at char *gbl_HTML_code_for_per
//      in_html_filename,
      arg_space_for_HTML_per, // space malloc'ed in js,  passed into mamb_report_personality()
      in_docin_lines,
      in_docin_last_idx
    );
//trn("finished make_per_htm_file_browser()");
//    if (retval != 0) return "got error in per";
    if (retval != 0) return 17;
  }
// smup   return 0;

//int lenret; lenret = strlen(arg_space_for_HTML_per);
//kin(lenret);
//int lenret2; lenret2 = strlen(gbl_HTML_code_for_per);
//kin(lenret2);
//trn("finished make_per_htm_file()");

//  return arg_space_for_HTML_per;
 return 0;

} // end of  make_per_htm_file()  // =========================================



// smup int make_per_htm_file_webview(      
// smup   char *in_html_filename,
// smup   char *in_docin_lines[],
// smup   int   in_docin_last_idx)
// smup {
// smup //
// smup /* tn();trn("in make_per_htm_file_webview"); */
// smup /* ksn(in_html_filename); */
// smup   is_first_p_docin_get = 1;       /* init to true */
// smup   gbl_we_are_in_PRE_block_content = 0;  /* init to false */
// smup 
// smup   strcpy(gbl_pfnameHTML, in_html_filename);
// smup 
// smup   int i;
// smup /* trn("in make_per_htm_file()"); */
// smup /* tn();b(160);ksn(in_html_filename); */
// smup 
// smup   global_max_docin_idx = in_docin_last_idx;
// smup   global_docin_lines   = in_docin_lines;
// smup 
// smup   /* open output HTML file
// smup   */
// smup     tn();trn("will do FOPEN");ksn(in_html_filename);
// smup   if ( (Fp_p_HTML_file = fopen(in_html_filename, "w")) == NULL ) {
// smup       //fprintf(stderr,"fopen() error=[%s]\n", strerror(errno));
// smup       rkabort("Error  on   perhtm.c.  fopen().");
// smup   }
// smup /* tn();b(10); */
// smup 
// smup /* for test */
// smup /* p_fn_prtlin("hey owieurw0093203");
// smup * p_docin_get(doclin);
// smup * p_fn_prtlin(doclin);
// smup * p_docin_get(doclin);
// smup * p_fn_prtlin(doclin);
// smup * p_docin_get(doclin);
// smup * p_fn_prtlin(doclin);
// smup */
// smup /* for test */
// smup 
// smup // now tblrpt1
// smup //  /* in this fn is the first p_docin_get
// smup //  */
// smup //  /* output the css, headings etc. */
// smup //  p_fn_webview_output_top_of_html_file();
// smup //
// smup //
// smup 
// smup   // this used to be in   p_fn_webview_output_top_of_html_file();
// smup   // have to get name
// smup   //
// smup   /* 1. read until [beg_topinfo1]  (name)  (skipping [beg_program])
// smup   */
// smup   for (i=0; ; i++) {
// smup     p_docin_get(doclin);
// smup     if (strstr(doclin, "[beg_topinfo1]") != NULL) break;
// smup   }
// smup   p_docin_get(doclin);
// smup   strcpy(gbl_p_person_name, doclin);
// smup 
// smup 
// smup 
// smup 
// smup /* b(11); */
// smup   /*  read until [beg_graph]
// smup    */
// smup   for (i=0; ; i++) {
// smup     p_docin_get(doclin);
// smup     if (strstr(doclin, "[beg_graph]") != NULL) break;
// smup   }
// smup 
// smup /*   p_fn_prtlin("  <div> Stand out character traits.</div>"); */
// smup 
// smup   /*  old graph   do_orig_trait_graph(); */
// smup //  p_fn_prtlin("<div> </div>");
// smup 
// smup   do_benchmark_trait_graph();    /* !!!!!!!!!!!!!!!!!!!  trait table printed here !!! */
// smup //  do_TBLRPT_benchmark_trait_graph();    /* !!!!!!!!!!!!!!!!!!!  trait table printed here !!! */
// smup 
// smup /* b(12); */
// smup 
// smup   /*   p_fn_prtlin("\n<h3> </h3>"); */
// smup //  p_fn_prtlin("<div><br></div>");
// smup //
// smup //  p_fn_prtlin("</table>");
// smup 
// smup 
// smup   /* DO PARAGRAPHS HERE */
// smup 
// smup   /* read until
// smup   */
// smup   for (i=0; ; i++) {
// smup     p_docin_get(doclin);
// smup     if (strstr(doclin, "[beg_aspects]") != NULL) break;
// smup   }
// smup 
// smup 
// smup   /* now read and print aspects until we hit [end_aspects] 
// smup   */
// smup   for (i=0; ; i++) {
// smup     p_docin_get(doclin);
// smup     if (strlen(doclin) == 0) continue;
// smup     if (strstr(doclin, "[end_aspects]") != NULL) break;
// smup     
// smup     strcpy(aspect_code, doclin);
// smup //    p_fn_browser_aspect_text(aspect_code);    /* output the aspect text */
// smup     p_fn_webview_aspect_text(aspect_code);
// smup     
// smup   }  /* read and print aspects until we hit [end_aspects] */
// smup 
// smup /* b(14); */
// smup 
// smup 
// smup   for (i=0; ; i++) {  /* read until  */
// smup     p_docin_get(doclin);
// smup     if (strstr(doclin, "[end_program]") != NULL) break;
// smup   }
// smup 
// smup //
// smup ///*   p_fn_prtlin("<div> </div>"); */
// smup //  p_fn_prtlin("<div><br></div>");
// smup //
// smup //  /* put trait descriptions
// smup //  */
// smup //  //p_fn_prtlin("<pre class=\"traitDesc\">");
// smup //  p_fn_prtlin("<div class=\"traitDesc\">");
// smup //  gbl_we_are_in_PRE_block_content = 1;  /* true */
// smup //  p_fn_prtlin("    *trait");
// smup //  p_fn_prtlin("");
// smup //  p_fn_prtlin("     Assertive     - competitive, authoritative, outspoken  ");
// smup //  p_fn_prtlin("     Emotional     - protective, sensitive, possessive");
// smup //  p_fn_prtlin("     Restless      - versatile, changeable, independent");
// smup //  p_fn_prtlin("     Down-to-earth - stable, practical, ambitious");
// smup //  p_fn_prtlin("     Passionate    - intense, relentless, enthusiastic");
// smup //  p_fn_prtlin("     Ups and Downs - having very high ups ");
// smup //  p_fn_prtlin("                     and very low downs in life "); 
// smup //  p_fn_prtlin("");
// smup ///*   p_fn_prtlin(""); */
// smup //
// smup ///*   p_fn_prtlin("  Check out reports \"Most Assertive\", \"Most Emotional\" ...  "); */
// smup ///*   p_fn_prtlin("  which use trait scores to compare with other group members  "); */
// smup //  p_fn_prtlin("  Check out the group trait reports like \"Most Assertive\" ");
// smup //  p_fn_prtlin("  and \"Most Emotional\" which use these trait scores ");
// smup //  p_fn_prtlin("  to compare with other group members  ");
// smup //
// smup //  p_fn_prtlin("");
// smup //  gbl_we_are_in_PRE_block_content = 0;  /* false */
// smup //  p_fn_prtlin("</div>");
// smup //
// smup 
// smup //  p_fn_prtlin("<div> </div>");
// smup 
// smup /*   p_fn_prtlin("<pre>"); */
// smup /*   gbl_we_are_in_PRE_block_content = 1; */
// smup /*   p_fn_prtlin(""); */
// smup /*   p_fn_prtlin(" Check out group reports \"Most Assertive\", \"Most Emotional\" etc. "); */
// smup /*   p_fn_prtlin("     which use these scores to compare with other group members.     "); */
// smup /*   p_fn_prtlin("  Check out group reports \"Most Assertive\", \"Most Emotional\" etc.  "); */
// smup /*   p_fn_prtlin("  which use these trait scores to compare with other group members.  "); */
// smup /*   p_fn_prtlin(""); */
// smup /*   gbl_we_are_in_PRE_block_content = 0; */
// smup /*   p_fn_prtlin("</pre>"); */
// smup 
// smup //  p_fn_prtlin("<div><br></div>");
// smup 
// smup   // put trait descriptions
// smup   //
// smup 
// smup 
// smup //  p_fn_prtlin("<pre class=\"willpower\"> ");
// smup //background-color: #fcfce0;
// smup 
// smup //  gbl_we_are_in_PRE_block_content = 1; 
// smup //  p_fn_prtlin( "<span style=\"background-color: #fcfce0;\">Your3intense willpower can overcome  </span>");
// smup /*   p_fn_prtlin( "                                       "); */
// smup 
// smup //  p_fn_prtlin( "                                       ");
// smup //p_fn_prtlin( "       Your intense willpower can overcome  ");
// smup //p_fn_prtlin( "        bad traits and magnify good ones    ");
// smup //  p_fn_prtlin( "     Your intense willpower can overcome    ");
// smup //  p_fn_prtlin( "  challenging traits and magnify good ones  ");
// smup //  p_fn_prtlin( "                                            ");
// smup 
// smup //  p_fn_prtlin( "            ");
// smup //p_fn_prtlin( "     Your intense willpower can overcome    ");
// smup //p_fn_prtlin( "  challenging traits and magnify good ones  ");
// smup 
// smup //  p_fn_prtlin( "               Your intense willpower          ");   // webview
// smup //  p_fn_prtlin( "          can overcome challenging traits      ");
// smup //  p_fn_prtlin( "            and magnify favorable ones         ");
// smup //  p_fn_prtlin( "                                               ");
// smup //
// smup   sprintf(writebuf, "fill|before willpower");
// smup   p_fn_prtlin(writebuf);
// smup   sprintf(writebuf, "fill|in willpower at beg");
// smup   p_fn_prtlin(writebuf);
// smup   sprintf(writebuf, "will|            Your intense willpower          ");   // webview
// smup   p_fn_prtlin(writebuf);
// smup   sprintf(writebuf, "will|       can overcome challenging traits      ");
// smup   p_fn_prtlin(writebuf);
// smup   sprintf(writebuf, "will|         and magnify favorable ones         ");
// smup   p_fn_prtlin(writebuf);
// smup   sprintf(writebuf, "fill|in willpower at end");
// smup   p_fn_prtlin(writebuf);
// smup 
// smup //  gbl_we_are_in_PRE_block_content = 0;  /* false */
// smup //  p_fn_prtlin("</pre>");
// smup 
// smup 
// smup /*   sprintf(writebuf, "<h5><br><br><br>produced by iPhone/iPad app named %s</h5>", APP_NAME); */
// smup /*   sprintf(writebuf, "<h5><br><br><br>produced by iPhone app %s</h5>", APP_NAME); */
// smup 
// smup /*   sprintf(writebuf, "<h5><br>produced by iPhone app %s</h5>", APP_NAME); */
// smup /*   p_fn_prtlin(writebuf); */
// smup /*   p_fn_prtlin("<div><br></div>"); */
// smup 
// smup 
// smup 
// smup /*   p_fn_prtlin("<span class=\"appBy\"> "); */
// smup //  p_fn_prtlin("<pre class=\"appBy\"> ");
// smup //  gbl_we_are_in_PRE_block_content = 1; 
// smup ///*   sprintf(writebuf, "<pre class=\"appBy\">produced by iPhone app %s</pre>", APP_NAME); */
// smup //  sprintf(writebuf, "produced by iPhone app %s", APP_NAME);
// smup //  p_fn_prtlin(writebuf);
// smup //  gbl_we_are_in_PRE_block_content = 0;  /* false */
// smup //  p_fn_prtlin("</pre>");
// smup 
// smup   sprintf(writebuf, "fill|before produced by");
// smup   p_fn_prtlin(writebuf);
// smup   sprintf(writebuf, "prod|produced by iPhone app %s", APP_NAME);
// smup   p_fn_prtlin(writebuf);
// smup 
// smup 
// smup /*   p_fn_prtlin(""); */
// smup 
// smup /*   p_fn_prtlin("<h4><span style=\"background-color:#FFBAC7;\">&nbsp&nbsp&nbsp&nbsp&nbsp  This report is for entertainment purposes only.&nbsp&nbsp&nbsp&nbsp&nbsp  </span></h4>"); */
// smup /*   p_fn_prtlin("<h4><span style=\"background-color:#FFBAC7;\">&nbspThis report is for entertainment purposes only.&nbsp</span></h4>"); */
// smup 
// smup 
// smup //  p_fn_prtlin("<pre class=\"entertainment\">");
// smup //  gbl_we_are_in_PRE_block_content = 1; 
// smup //  sprintf(writebuf, "This report is for entertainment purposes only.");
// smup //  p_fn_prtlin(writebuf);
// smup //  gbl_we_are_in_PRE_block_content = 0;  /* false */
// smup //  p_fn_prtlin("</pre>");
// smup //  p_fn_prtlin("<div><br><br></div>");
// smup 
// smup   sprintf(writebuf, "fill|before entertainment");
// smup   p_fn_prtlin(writebuf);
// smup   sprintf(writebuf, "purp|This report is for entertainment purposes only.");
// smup   p_fn_prtlin(writebuf);
// smup 
// smup 
// smup 
// smup //  p_fn_prtlin("\n</body>\n");
// smup //  p_fn_prtlin("</html>");
// smup 
// smup 
// smup   fflush(Fp_p_HTML_file);
// smup   /* close output HTML file
// smup   */
// smup   if (fclose(Fp_p_HTML_file) == EOF) {
// smup     ;
// smup /* trn("FCLOSE FAILED !!!   #1  "); */
// smup   } else {
// smup     ;
// smup /* trn("FCLOSE SUCCESS !!!  #1  "); */
// smup   };
// smup 
// smup   return 0;
// smup } // make_per_htm_file_webview      
//



//  note: per was changed from html on iphone to tableview
//
/* output the css, headings etc.
*/
//void p_fn_webview_output_top_of_html_file(void)  // =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//{
//  int i;
///* trn("in p_fn_webview_output_top_of_html_file()"); */
//
//  /* 1. read until [beg_topinfo1]  (name)  (skipping [beg_program])
//  */
//  for (i=0; ; i++) {
//    p_docin_get(doclin);
//    if (strstr(doclin, "[beg_topinfo1]") != NULL) break;
//  }
//
///* b(20); */
//  /* then save lines until graph until [end_topinfo1] 
//  * then put out html 
//  */
//  for (i=0; ; i++) {
//    p_docin_get(doclin);
//    if (strstr(doclin, "[end_topinfo1]") != NULL) break;
//    strcpy(arr(i), doclin);
//  }
///* b(25); */
//
///*   at end, change to STRICT  */
//  p_fn_prtlin( "<!doctype html public \"-//w3c//dtd html 4.01 transitional//en\" ");
///* b(26); */
//  p_fn_prtlin( "  \"http://www.w3.org/TR/html4/loose.dtd\">");
//
//  p_fn_prtlin( "<html>");
//  p_fn_prtlin( "\n<head>");
//
///*   sprintf(writebuf, "  <title>%s- Personality, produced by iPhone app %s.</title>",arr(0), APP_NAME); */
//
//  /* if HTML filename, gbl_pfnameHTML, has any slashes, grab the basename
//  */
//  char myBaseName[256], *myptr;
//  if (sfind(gbl_pfnameHTML, '/')) {
//    myptr = strrchr(gbl_pfnameHTML, '/');
//    strcpy(myBaseName, myptr + 1);
//  } else {
//    strcpy(myBaseName, gbl_pfnameHTML);
//  }
//  sprintf(writebuf, "  <title>%s</title>", myBaseName);
//  p_fn_prtlin(writebuf);
///* b(27); */
//  
//  /* HEAD  META
//  */
//  sprintf(writebuf, "  <meta name=\"description\" content=\"Personality report produced by iPhone app %s\"> ",  APP_NAME);
//  p_fn_prtlin(writebuf);
//
//
//  p_fn_prtlin( "  <meta http-equiv=\"Content-Type\" content=\"text/html\"; charset=\"iso-8859-1\">"); 
//  /*   p_fn_prtlin( "  <meta name=\"Author\" content=\"Author goes here\">"); */
//
//
///*   p_fn_prtlin( "  <meta name=\"keywords\" content=\"group,member,astrology,personality,future,past,year in the life,compatibility,GMCR\">  */
///*   p_fn_prtlin( "  <meta name=\"keywords\" content=\"measure,group,member,best,match,calendar,year,passionate,personality\"> "); */
///*   p_fn_prtlin( "  <meta name=\"keywords\" content=\"BFF,astrology,compatibility,group,best,match,calendar,year,stress,personality\"> "); */
//
///*   p_fn_prtlin( "  <meta name=\"keywords\" content=\"women,woman,female,BFF,compatibility,group,best,match,personality,stress,calendar,year\"> "); */ /* 86 chars */ 
//  p_fn_prtlin( "  <meta name=\"keywords\" content=\"women,woman,female,BFF,me,compatibility,group,best,match,personality,stress,calendar,year\"> ");  /* 89 chars */
//
//
//  /* get rid of CHROME translate "this page is in Galician" 
//  * do you want to translate?
//  */
//  p_fn_prtlin("  <meta name=\"google\" content=\"notranslate\">");
//  p_fn_prtlin("  <meta http-equiv=\"Content-Language\" content=\"en\" />");
//
//
//  /* Using the Viewport Meta Tag  (in iOS webView)
//  * https://developer.apple.com/library/safari/documentation/AppleApplications/Reference/SafariWebContent/UsingtheViewport/UsingtheViewport.html#//apple_ref/doc/uid/TP40006509-SW25
//  *
//  * For example, TO SET THE VIEWPORT WIDTH TO THE WIDTH OF THE DEVICE, add this to your HTML file:
//  * <meta name="viewport" content="width=device-width"> 
//  * To set the initial scale to 1.0, add this to your HTML file:
//  * <meta name="viewport" content="initial-scale=1.0"> 
//  * To set the initial scale and to turn off user scaling, add this to your HTML file:
//  * <meta name="viewport" content="initial-scale=2.3, user-scalable=no">
//  */
//
//
////  p_fn_prtlin("  <meta name=\"viewport\" content=\"initial-scale=1.0; \"> ");           //   browser view
////  p_fn_prtlin("  <meta name=\"viewport\" content=\"initial-scale=0.5; \"> ");           //   browser view
//
////  p_fn_prtlin("  <meta name=\"viewport\" content=\"initial-scale=0.44 minimum-scale=0.44; \"> ");           //   browser view  OK
//
//// p_fn_prtlin("  <meta name=\"viewport\" content=\"width=320 initial-scale=0.44 \" />");  // webview   OK
//
////  p_fn_prtlin("  <meta name=\"viewport\" content=\"width=device-width initial-scale=0.44 minimum-scale=0.44; \" />");  // webview  OK  4s=no
//
//
//
////  p_fn_prtlin("  <meta name=\"viewport\" content=\"width=320 initial-scale=0.44 minimum-scale=0.44 ; \" />");  // webview  OK  4s=no
//
//
//
////  p_fn_prtlin("  <meta name=\"viewport\" content=\"width=320 ; \" />");  // webview  OK  4s=no
//
////  p_fn_prtlin("  <meta name=\"viewport\" content=\"width=320 minimum-scale=0.44 maximum-scale=0.44 ; \" />");  // webview  5=no
//
////  p_fn_prtlin("  <meta name=\"viewport\" content=\"width=980 initial-scale=1.0 ; \" />");  // webview  6=big
//// try no viewport
//
//
//
//
////  p_fn_prtlin("  <meta name=\"viewport\" content=\"width=device-width  \" />");  // webview   ORIG    6s=skinny, all lesser OK
////  p_fn_prtlin("  <meta name=\"viewport\" content=\"width=device-width initial-scale=0.44 minimum-scale=0.44; \" />");  // webview  OK  4s=no
////  p_fn_prtlin("  <meta name=\"viewport\" content=\"width=device-width initial-scale=0.44 minimum-scale=0.44; \" />");  // webview  OK <6=no
//
////  p_fn_prtlin("  <meta name=\"viewport\" content=\"width=device-width initial-scale=0.44 minimum-scale=0.44 maximum-scale=0.44;\" />");  // webview  OK <6=no   GOLD GOLD for 6+
//
//
//  p_fn_prtlin("  <meta name=\"viewport\" content=\"width=device-width initial-scale=0.44 minimum-scale=0.44 maximum-scale=0.44;\" />");
//
//
//
//
//  p_fn_prtlin("  <meta name = \"format-detection\" content = \"telephone=no\">");
//
////  p_fn_prtlin( "  <meta name=\"viewport\" content=\"width=device-width, initial-scale=0.44, minimum-scale=0.44 \" />");  // webview  for 6,6s
////  p_fn_prtlin( "  <meta name=\"viewport\" content=\"width=device-width, initial-scale=0.44, minimum-scale=0.44, maximum-scale=0.44\" />");  // webview  for 6,6s
//
//
//  /* HEAD   STYLE/CSS
//  */
//  p_fn_prtlin( "\n  <style type=\"text/css\">");
//
////
////
////  //  http://stephen.io/mediaqueries/#iPhone
////  // code for portrait, landscape ->   and (orientation : portrait) { /* STYLES GO HERE */ }
////  // iPhone 6 in portrait & landscape
////  //@media only screen 
////  //and (min-device-width : 375px) 
////  //and (max-device-width : 667px) { /* 6   STYLES GO HERE */
////  //}
////  //@media only screen 
////  //and (min-device-width : 414px) 
////  //and (max-device-width : 736px) { /* 6s  STYLES GO HERE */}
////  //  iphone 5,4,3...  min-device-width = 320
////  //
//////  p_fn_prtlin( "@media screen and (min-device-width: 350px) {  "); // CSS for iphone 6,6s, and bigger
//////  p_fn_prtlin( "  <meta name=\"viewport\" content=\"width=device-width initial-scale=0.44 minimum-scale=0.44 \" />");  // webview  for 6,6s
//////  p_fn_prtlin( "} "); // CSS for iphone 6,6s, and bigger
////
////
////
////  p_fn_prtlin( "@media screen and (min-device-width: 350px) {  "); // CSS for iphone 6,6s, and bigger
////
////  p_fn_prtlin( "      background-color: #cc0000;");
////  p_fn_prtlin( "@viewport { ");
////  p_fn_prtlin( "    width: device-width;");
////  p_fn_prtlin( "    initial-scale: 1.0;");
////  p_fn_prtlin( "    minimum-scale: 1.0;");
////  p_fn_prtlin( "}");
////  p_fn_prtlin( "}");
////
////  p_fn_prtlin( "@media screen and not (min-device-width: 350px) ){  "); // CSS for iphone 5,4,3,...
////  p_fn_prtlin( "      background-color: #00cc00;");
////  p_fn_prtlin( "@viewport{");
////  p_fn_prtlin( "    width: device-width;");
////  p_fn_prtlin( "}");
////  p_fn_prtlin( "}");
////
////
//
//  p_fn_prtlin( "    BODY {");   // BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
//  p_fn_prtlin( "      background-color: #F7ebd1;");
////  p_fn_prtlin( "      background-color: #cc0000;");
//  p_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New;");
//  p_fn_prtlin( "      font-size:   medium;");
//  p_fn_prtlin( "      font-weight: normal;");
//  p_fn_prtlin( "      text-align:  center;");  /* stupid, for IE */
//  /* example comment out */
//  /*   p_fn_prtlin( "    <!-- "); */
//  /*   p_fn_prtlin( "      background-image: url('mkgif1g.gif');"); */
//  /*   p_fn_prtlin( "    --> "); */
//  p_fn_prtlin( "    }");  // BODY
//
//
//
//
//
///*   p_fn_prtlin( "    H1 { font-size: 137%; font-weight: bold;   line-height: 95%; text-align: center;}"); */
///*   p_fn_prtlin( "    H2 { font-size: 125%;                      line-height: 25%; text-align: center;}"); */
///*   p_fn_prtlin( "    H3 { font-size: 110%; font-weight: normal; line-height: 30%; text-align: center;}"); */
//
///*   p_fn_prtlin( "    H5 { font-size:  55%; font-weight: normal; line-height: 90%; text-align: center;}"); */
///*   p_fn_prtlin( "    H4 { font-size:  85%; font-weight: bold;   line-height: 30%; text-align: center;}"); */
///*   p_fn_prtlin( "    H5 { font-size:  70%; font-weight: normal; line-height: 30%; text-align: center;}"); */
//
///*   p_fn_prtlin( "    H4 { font-size:  75%; font-weight: bold;   line-height: 30%; text-align: center;}"); */
///*   p_fn_prtlin( "    H5 { font-size:  70%; font-weight: normal; line-height: 30%; text-align: center;}"); */
///*   p_fn_prtlin( "    H4 { font-size:  150%; font-weight: bold;   line-height: 100%; text-align: center;}"); */
///*   p_fn_prtlin( "    H5 { font-size:  150%; font-weight: normal; line-height: 100%; text-align: center;}"); */
//
//  p_fn_prtlin( "    PRE {");    // webview
//
////  p_fn_prtlin( "     overflow-x: hidden; ");    // webview
//
//  p_fn_prtlin( "      background-color: #fcfce0;");
//  p_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New;");
//  p_fn_prtlin( "      font-weight: normal;");
//  p_fn_prtlin( "      font-size: 0.9em;"); 
//  p_fn_prtlin( "      line-height: 70%;");
///*   p_fn_prtlin( "      text-align:  left;"); */
///*   p_fn_prtlin( "      display: inline-block;"); */
///*   p_fn_prtlin( "      border-style: solid;"); */
///*   p_fn_prtlin( "      border-color: black;"); */
///*   p_fn_prtlin( "      border-width: 2px;"); */
///*   p_fn_prtlin( "      border-color: #e4dfae; "); */
///*   p_fn_prtlin( "      border-width: 5px;"); */
//
///*   p_fn_prtlin( "      border-spacing: 0;"); */
///*   p_fn_prtlin( "      border: none;"); */
///*   p_fn_prtlin( "      border-collapse: collapse;"); */
///*   p_fn_prtlin( "      border-spacing: 0;"); */
//
///*   p_fn_prtlin( "      font-family: Andale Mono, Menlo, Monospace, Courier New;"); */
///*   p_fn_prtlin( "      line-height: 70%;"); */
///*   p_fn_prtlin( "      line-height: 100%;"); */
///*   p_fn_prtlin( "      line-height: 108%;"); */
///*   p_fn_prtlin( "      font-size: 85%;"); */
////  p_fn_prtlin( "      font-size: 160%;");  /*  */
///*   p_fn_prtlin( "      margin:0 auto;"); */
//  p_fn_prtlin( "    }");
//
////   p_fn_prtlin( "    PRE.myTitle {");
//// /*   p_fn_prtlin( "      width: 300%;"); */
//// /*   p_fn_prtlin( "      margin-left: 30%;"); */
//// /*   p_fn_prtlin( "      margin-right:30%;"); */
//// /*   p_fn_prtlin( "      width: 0%;"); */
////   p_fn_prtlin( "      margin-left: 70%;");
//// /*   p_fn_prtlin( "      margin-right:30%;"); */
////   p_fn_prtlin( "      text-align: center;");
////   p_fn_prtlin( "      background-color: #F7ebd1;");
////   p_fn_prtlin( "      font-size: 500%;");  /*  */
////   p_fn_prtlin( "      font-weight: bold;");  /*  */
////   p_fn_prtlin( "    }");
////   p_fn_prtlin( "    PRE.scoreExpl {");
//
//
//  p_fn_prtlin( "    .myTitle {");
//  p_fn_prtlin( "      margin-top: 0.5em;");
//  p_fn_prtlin( "      margin-bottom: 1.2em;");
//  p_fn_prtlin( "      margin-left: 4em;");
////  f_fn_prtlin( "      text-align: center;");      // GOLD order #1
//  p_fn_prtlin( "      text-align: left;");      // GOLD order #1
//     // are putting spaces in code to center
//  p_fn_prtlin( "      width: 300%;");             // GOLD order #2
//  p_fn_prtlin( "      font-size: 3em;");         // GOLD order #3
//  p_fn_prtlin( "      font-weight: bold;"); 
//  p_fn_prtlin( "      background-color: #F7ebd1;");
//  p_fn_prtlin( "      white-space: pre ; display: block; unicode-bidi: embed");
//  p_fn_prtlin( "    }");
//
////  p_fn_prtlin( "    PRE.scoreExpl {");
////  p_fn_prtlin( "      background-color: #fcfce0;");
////  p_fn_prtlin( "      margin-top: 0.1em;");
////  p_fn_prtlin( "      margin-left: 3em;");
////  p_fn_prtlin( "      text-align: left;");      // GOLD order #1
////  p_fn_prtlin( "      width: 240%;");             // GOLD order #2
////  p_fn_prtlin( "      font-size: 1.4em;");  /* gold order #3 */
////  p_fn_prtlin( "      line-height: 130%;");  /*  */
////  p_fn_prtlin( "      white-space: pre ; display: block; unicode-bidi: embed");
////  p_fn_prtlin( "    }");
////
////
//
////  p_fn_prtlin( "    PRE.willpower {");
//  p_fn_prtlin( "    PRE.scoreExpl {");
//  p_fn_prtlin( "     overflow-x: hidden; ");    // webview
//  p_fn_prtlin( "      width: 300%;");             // GOLD order #2
//  p_fn_prtlin( "      width: 270%;");             // GOLD order #2
//
////  p_fn_prtlin( "      font-size: 1.8em;");  /*  */
////  p_fn_prtlin( "      font-size: 1.2em;");  /*  */
////  p_fn_prtlin( "      font-size: 1.6em;");  /*  */
////  p_fn_prtlin( "      font-size: 1.7em;");  /*  */
////  p_fn_prtlin( "      font-size: 2.0em;");  /*  */
////  p_fn_prtlin( "      font-size: 1.8em;");  /*  */
//  p_fn_prtlin( "      font-size: 1.7em;");  /*  */
//
//  p_fn_prtlin( "      background-color: #fcfce0;");
//  p_fn_prtlin( "      text-align: left;");      // GOLD order #1
//  p_fn_prtlin( "      line-height: 1.2em;");  /*  */
//  p_fn_prtlin( "    }");
//
//
//
//
//
//
//  p_fn_prtlin( "    .aspectPara {");
//  p_fn_prtlin( "      background-color: #F7ebd1;");
// // p_fn_prtlin( "      margin-left: 2.5em;");
//  p_fn_prtlin( "      margin-left: 0.5em;");
//  p_fn_prtlin( "      margin-right: 0.5em;"); 
//  p_fn_prtlin( "      margin-top: 2em;");
//  p_fn_prtlin( "      line-height: 130%;");  /*  */
//  p_fn_prtlin( "      text-align: left;");      // GOLD order #1
////  p_fn_prtlin( "      width: 333%;");             // GOLD order #2
//  p_fn_prtlin( "      width: 300%;");             // GOLD order #2
//  p_fn_prtlin( "      font-size: 1.25em;");  /* gold order #3 */
//  p_fn_prtlin( "      white-space: pre ; display: block; unicode-bidi: embed");
//  p_fn_prtlin( "    }");
//
//
//  //p_fn_prtlin( "    PRE.traitDesc {");
//  p_fn_prtlin( "    .traitDesc {");
//
////  p_fn_prtlin( "     overflow-x: hidden; ");    // webview
//
//  p_fn_prtlin( "      background-color: #fcfce0;");
//  p_fn_prtlin( "      margin-left: 1.5em;");
//  p_fn_prtlin( "      text-align: left;");      // GOLD order #1
//  //p_fn_prtlin( "      width: 260%;");             // GOLD order #2
//  p_fn_prtlin( "      width: 270%;");             // GOLD order #2
////  p_fn_prtlin( "      width: 240%;");             // GOLD order #2
//  //p_fn_prtlin( "      font-size: 1.25em;");  /* gold order #3 */
//
////  p_fn_prtlin( "      font-size: 1.2em;");  /* gold order #3 */
//  p_fn_prtlin( "      font-size: 1.45em;");  /* gold order #3 */
//  p_fn_prtlin( "      line-height: 130%;");  /*  */
//  p_fn_prtlin( "      white-space: pre ; display: block; unicode-bidi: embed");
//  p_fn_prtlin( "    }");
//
//  p_fn_prtlin( "    PRE.willpower {");
//
//  p_fn_prtlin( "     overflow-x: hidden; ");    // webview
//
////  p_fn_prtlin( "      width: 170%;");             // GOLD order #2
////  p_fn_prtlin( "      font-size: 1.4em;");  /*  */
////  p_fn_prtlin( "      width: 100%;");             // GOLD order #2
////  p_fn_prtlin( "      width: 400%;");             // GOLD order #2
////  p_fn_prtlin( "      width: 250%;");             // GOLD order #2
////  p_fn_prtlin( "      width: 350%;");             // GOLD order #2
//  p_fn_prtlin( "      width: 300%;");             // GOLD order #2
//  p_fn_prtlin( "      font-size: 1.8em;");  /*  */
//
//  p_fn_prtlin( "      background-color: #fcfce0;");
////  p_fn_prtlin( "      margin-left: 8em;");
//  p_fn_prtlin( "      text-align: left;");      // GOLD order #1
//
//  p_fn_prtlin( "      line-height: 1.2em;");  /*  */
//  p_fn_prtlin( "    }");
//
//
////   p_fn_prtlin( "    PRE.appBy {");
//// /*   p_fn_prtlin( "      width: 100%;"); */
//// /*   p_fn_prtlin( "      margin-left: 60%;"); */
//// /*   p_fn_prtlin( "      margin-right:60%;"); */
////   p_fn_prtlin( "      margin-left: 70%;");
//// 
////   p_fn_prtlin( "      background-color: #F7ebd1;");
////   p_fn_prtlin( "      font-size: 200%;");  /*  */
////   p_fn_prtlin( "    }");
//// 
////   p_fn_prtlin( "    PRE.entertainment {");
//// 
//// /*   p_fn_prtlin( "      width: 300%;"); */
//// /*   p_fn_prtlin( "      margin-left: 30%;"); */
//// /*   p_fn_prtlin( "      margin-right:30%;"); */
////   p_fn_prtlin( "      margin-left: 40%;");
//// 
//// /*   p_fn_prtlin( "      background-color:#FFBAC7;"); */
////   p_fn_prtlin( "      background-color: #F7ebd1;");
////   p_fn_prtlin( "      color:#FF0000;");
////   p_fn_prtlin( "      font-size: 150%;");  /*  */
////   p_fn_prtlin( "    }");
//
//
//  p_fn_prtlin( "    PRE.appBy {");
//
////  p_fn_prtlin( "      margin-left:13.2em;");
////  p_fn_prtlin( "      margin-left: 5em;");
//  p_fn_prtlin( "      margin-left: 6.5em;");
//
//  p_fn_prtlin( "      text-align: left;");
///*   p_fn_prtlin( "      font-size: 130%;"); */
//  p_fn_prtlin( "      width: 150%;");             // GOLD order #2
//
////  p_fn_prtlin( "      font-size: 2em;");
////  p_fn_prtlin( "      font-size: 2.4em;");
////  p_fn_prtlin( "      font-size: 3.4em;");
////  p_fn_prtlin( "      font-size: 1.2em;");
////  p_fn_prtlin( "      font-size: 1.8em;");
//  p_fn_prtlin( "      font-size: 1.5em;");
//
//  p_fn_prtlin( "      background-color: #F7ebd1;");
//  p_fn_prtlin( "    }");
//  p_fn_prtlin( "    PRE.entertainment {");
////  p_fn_prtlin( "      line-height: 1.4em;"); 
////  p_fn_prtlin( "      margin-left: 9.5em;");
////  p_fn_prtlin( "      margin-left: 7em;");
////  p_fn_prtlin( "      margin-left: 5em;");
//  p_fn_prtlin( "      margin-left: 3em;");
//
//  p_fn_prtlin( "      text-align: left;");
//
//  p_fn_prtlin( "      width: 150%;");             // GOLD order #2
//
////  p_fn_prtlin( "      font-size: 1.5em;");
////  p_fn_prtlin( "      font-size: 1.2em;");
////  p_fn_prtlin( "      font-size: 1.4em;");
//  p_fn_prtlin( "      font-size: 1.6em;");
//
//  p_fn_prtlin( "      font-weight: bold;");
//
//  p_fn_prtlin( "      background-color: #F7ebd1;");
//  p_fn_prtlin( "      color:#FF0000;");
///*   p_fn_prtlin( "      font-size: 130%;");  */
//  p_fn_prtlin( "    }");
//
//
//  p_fn_prtlin( "    P { ");
///*   p_fn_prtlin( "      font-family: Andale Mono, Menlo, Monospace, Courier New;"); */
//  p_fn_prtlin( "      font-family: Courier, Menlo, Andale Mono, Monospace, Courier New;");
//  p_fn_prtlin( "      width: auto;");
///*   p_fn_prtlin( "      font-size:   93%;"); */
///*   p_fn_prtlin( "      font-size:   150%;"); */
//  p_fn_prtlin( "      font-size:   165%;");
///*   p_fn_prtlin( "      margin-top: 0;"); */
///*   p_fn_prtlin( "      margin-bottom: 0;"); */
///*   p_fn_prtlin( "      margin-left: auto;"); */
///*   p_fn_prtlin( "      margin-right:auto;"); */
///*   p_fn_prtlin( "      padding-left: 5%;"); */
///*   p_fn_prtlin( "      padding-right:5%;"); */
///*   p_fn_prtlin( "      text-align: center;"); */
//  p_fn_prtlin( "      text-align: left;");
///*   p_fn_prtlin( "      margin-left: 0.5em;"); */
//  p_fn_prtlin( "      margin-right: 0.5em;");
//  p_fn_prtlin( "    }");
//
//
///* for table: */
//
///*   p_fn_prtlin( "div.centered  { text-align: center; }"); */
///*   p_fn_prtlin( "div.centered table  { margin: 0 auto;  text-align: left; }"); */
///* then, */
///* <div class="centered"> */
///*     <table> */
///*     … */
///*     </table> */
///* </div> */
//
//
//
///*       border: 2px solid black; */
///*       cellspacing: 0; */
///*       border-top: 0; */
///*       border-bottom: 0; */
//  p_fn_prtlin( "    table {");
///*   p_fn_prtlin( "      text-align: center;"); */
///*   p_fn_prtlin( "      border: none;"); */
///*   p_fn_prtlin( "      border-collapse: collapse;"); */
///*   p_fn_prtlin( "      border-spacing: 0;"); */
///*   p_fn_prtlin( "      width: 300%;"); */
///*   p_fn_prtlin( "      margin-left: auto;"); */
///*   p_fn_prtlin( "      margin-right:auto;"); */
///*   p_fn_prtlin( "      margin: auto;"); */
//
///*   p_fn_prtlin( "      text-align: left;"); */
///*   p_fn_prtlin( "      margin-left: 12em;"); */
//
//  p_fn_prtlin( "      margin-left: 7em;");
//  p_fn_prtlin( "      margin-top: 0.1em;");
//  p_fn_prtlin( "      margin-bottom: 0.1em;");
//  p_fn_prtlin( "      border-spacing: 0;");
//  p_fn_prtlin( "    }");
//
///*   p_fn_prtlin( "    table.center {"); */
///*   p_fn_prtlin( "      margin: 11px;"); */
///*   p_fn_prtlin( "      font-size:   120%;"); */
///*   p_fn_prtlin( "    }"); */
///*   p_fn_prtlin( "      margin-left: auto;"); */
///*   p_fn_prtlin( "      margin-right:auto;"); */
///*   p_fn_prtlin( "      margin: auto;"); */
///*   p_fn_prtlin( "      margin-left: 100px;"); */
///*   p_fn_prtlin( "      margin-left:auto;"); */
///*   p_fn_prtlin( "      margin-right:auto;"); */
///*   p_fn_prtlin( "      width: 300%;"); */
///*   p_fn_prtlin( "      margin-left: 15%;"); */
///*   p_fn_prtlin( "      margin-right:15%;"); */
//
//  p_fn_prtlin( "    TD {");
///*   p_fn_prtlin( "      border: none;"); */
///*   p_fn_prtlin( "      border-spacing: 0;"); */
//  p_fn_prtlin( "      white-space: nowrap;");
//  p_fn_prtlin( "      margin-top: 0.1em;");
//  p_fn_prtlin( "      margin-bottom: 0.1em;");
//  p_fn_prtlin( "      padding: 0;");
//  p_fn_prtlin( "    }");
//
///*   p_fn_prtlin( "    .cLineGood   { background-color:#c3fdc3; }"); */
//  p_fn_prtlin( "    .cLineStress { background-color:#ffbac7; }");
//  p_fn_prtlin( "    .row4        { background-color:#f8f0c0; }");
//
///*   p_fn_prtlin( "    .cGr2        { background-color:#d0fda0; }"); */
///*   p_fn_prtlin( "    .cGr2        { background-color:#8bfd87; }"); */
///*   p_fn_prtlin( "    .cGr2        { background-color:#66ff33; }"); */
//
///*   p_fn_prtlin( "    .cGre        { background-color:#e1fdc3; }"); */
///*   p_fn_prtlin( "    .cGre        { background-color:#ccffb9; }"); */
///*   p_fn_prtlin( "    .cRed        { background-color:#ffd9d9; }"); */
///*   p_fn_prtlin( "    .cRed        { background-color:#ffcccc; }"); */
///*   p_fn_prtlin( "    .cRe2        { background-color:#fcb9b9; }"); */
///*   p_fn_prtlin( "    .cRe2        { background-color:#fc8888; }"); */
///*   p_fn_prtlin( "    .cRe2        { background-color:#fc6094; }"); */
///*   p_fn_prtlin( "    .cRe2        { background-color:#ff3366; }"); */
//
///*    GREEN   */
///*     .cGr2        { background-color:#a3f275; } */
///*     .cGre        { background-color:#bbf699; } */
///*     .cNeu        { background-color:#d3f9bd; } */
///*     .cRed        { background-color:#bbf699; } */
///*     .cRe2        { background-color:#a3f275; } */
//
//
///*   p_fn_prtlin( "    .cGr2        { background-color:#66ff33; }"); */
///*   p_fn_prtlin( "    .cGr2        { background-color:#a3f275; }"); */
///*   p_fn_prtlin( "    .cGre        { background-color:#84ff98; }"); */
///*   p_fn_prtlin( "    .cGre        { background-color:#a8ff98; }"); */
///*   p_fn_prtlin( "    .cGre        { background-color:#bbf699; }"); */
///*   p_fn_prtlin( "    .cNeu        { background-color:#e1ddc3; }"); */
///*   p_fn_prtlin( "    .cNeu        { background-color:#d3f9bd; }"); */
///*   p_fn_prtlin( "    .cNeu        { background-color:#fcfce0; }"); */
///*   p_fn_prtlin( "    .cNeu        { background-color:#e6fbda; }"); */
///*   p_fn_prtlin( "      background-color: #fcfce0;"); */
///*   p_fn_prtlin( "    .cRed        { background-color:#ff98a8; }"); */
///*   p_fn_prtlin( "    .cRed        { background-color:#bbf699; }"); */
///*   p_fn_prtlin( "    .cRe2        { background-color:#ff4477; }"); */
///*   p_fn_prtlin( "    .cRe2        { background-color:#a3f275; }"); */
//
///*   p_fn_prtlin( "    .cGr2        { background-color:#a3f275; }"); */
///*   p_fn_prtlin( "    .cGre        { background-color:#a3f275; }"); */
///*   p_fn_prtlin( "    .cNeu        { background-color:#a3f275; }"); */
///*   p_fn_prtlin( "    .cRed        { background-color:#a3f275; }"); */
///*   p_fn_prtlin( "    .cRe2        { background-color:#a3f275; }"); */
//
///*   p_fn_prtlin( "    .cGr2,.cGre,.cNeu,.cRed,.cRe2 {background-color: #a3f275;}"); */
//
//
//
//
//  // color for entire TABLE of trait scores
////  p_fn_prtlin( "    .cGr2,.cGre,.cNeu,.cRed,.cRe2 {background-color: #eef7ff;}"); // try blue
////  p_fn_prtlin( "    .cGr2,.cGre,.cNeu,.cRed,.cRe2 {background-color: #d3ffa5;}");
////  p_fn_prtlin( "    .cGr2,.cGre,.cNeu,.cRed,.cRe2 {background-color: #007aff;}");  // apple blue
////  p_fn_prtlin( "    .cGr2,.cGre,.cNeu,.cRed,.cRe2 {color: #007aff; background-color: #ffffff}");  // apple blue on  white
////  p_fn_prtlin( "    .cGr2,.cGre,.cNeu,.cRed,.cRe2 {color: #007aff; background-color: #fcfce0}");  // apple blue on  
////  p_fn_prtlin( "    .cGr2,.cGre,.cNeu,.cRed,.cRe2 {                background-color: #fcfce0}");  // apple blue on  
//
////  p_fn_prtlin( "    .cGr2,.cGre,.cNeu,.cRed,.cRe2 {background-color: #d3ffa5;}"); // light green
////  p_fn_prtlin( "    .cPerGreen1 {background-color: #d3ffa5;}"); // alternate colors
////  p_fn_prtlin( "    .cPerGreen2 {background-color: #e6ffcc;}");
//
////    p_fn_prtlin( "    .cPerGreen1 {background-color: #ceffa0;}");  
////    p_fn_prtlin( "    .cPerGreen2 {background-color: #dfffbb;}"); 
//
////    p_fn_prtlin( "    .cPerGreen1 {background-color: #d3ffa5;}");  // same
////    p_fn_prtlin( "    .cPerGreen2 {background-color: #d3ffa5;}"); // same
////
////    p_fn_prtlin( "    .cPerGreen1 {background-color: #e5e2c7;}");  // same as cNeu (e5e2c7)
//
//
//
//// this is webview   webview   webview   webview   webview   webview   webview   webview   webview   webview   webview  
//tn();trn("webview");
//  // try  5 green colors again
//
////    p_fn_prtlin( "    .cPerGreen1 {background-color: #edebd8;}");  // same as cNeu (edebd8)
////    p_fn_prtlin( "    .cPerGreen2 {background-color: #edebd8;}");  // same as cNeu (edebd8)
////    p_fn_prtlin( "    .cPerGreen1 {background-color: #66ff33;}");  // green
////    p_fn_prtlin( "    .cPerGreen2 {background-color: #f0f5f0;}");  // whiteish
//
//
//    p_fn_prtlin( "    .cPerGreen1 {background-color: #0080ff;}");  
//    p_fn_prtlin( "    .cPerGreen2 {background-color: #f2f7ff;}");  
//
//
//
//  // try  5 green colors again
//  //
////  p_fn_prtlin( "    .cPerGreen5 {background-color: #b9ff82;}");  // 5 different greens
////  p_fn_prtlin( "    .cPerGreen4 {background-color: #ceffa0;}");  // 5 different greens
////  p_fn_prtlin( "    .cPerGreen3 {background-color: #dfffbb;}");  // 5 different greens
////  p_fn_prtlin( "    .cPerGreen2 {background-color: #ecffd3;}");  // 5 different greens
////  p_fn_prtlin( "    .cPerGreen1 {background-color: #f6ffe6;}");  // 5 different greens
//
//
//
//
//
//
//  p_fn_prtlin("    .cNam        { color:#3f3ffa;");
//  p_fn_prtlin("                   background-color: #F7ebd1;");
//  p_fn_prtlin("                   font-size: 133%;");
//  p_fn_prtlin("    }");
//
//  p_fn_prtlin( "    table.trait {");                   // webview
///*   p_fn_prtlin( "      margin: auto;"); */
///*   p_fn_prtlin( "      margin-left: 100px;"); */
//
//
//
///*   p_fn_prtlin( "      margin-left: 66%;"); */
///*   p_fn_prtlin( "      width: 0%;"); */
///*   p_fn_prtlin( "      margin-left: 70%;"); */
///*   p_fn_prtlin( "      margin-right:30%;"); */
//
//
///*   p_fn_prtlin( "      font-size: 285%;");  */
///*   p_fn_prtlin( "      font-size: 240%;");  */
//
////  p_fn_prtlin( "      font-size: 175%;"); 
//
///*   p_fn_prtlin( "      width: 300%;"); */
///*   p_fn_prtlin( "      margin-left: auto;"); */
///*   p_fn_prtlin( "      margin-right:auto;"); */
///*   p_fn_prtlin( "      font-family: Andale Mono, Monospace, Courier New;"); */
//  p_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New;");
//  p_fn_prtlin( "      text-align: left;");
//  p_fn_prtlin( "      bottom-margin: 0.1em;");
//
///*   p_fn_prtlin( "      border: 1px solid black;"); */
///*   p_fn_prtlin( "      border: none;"); */
///*   p_fn_prtlin( "      border-spacing: 0;"); */
///*   p_fn_prtlin( "      border-collapse: collapse;"); */
///*   p_fn_prtlin( "      border-spacing: 0;"); */
//
///*   p_fn_prtlin( "      padding-right:2%;"); */
///*   p_fn_prtlin( "      padding-left:2%;"); */
//  p_fn_prtlin( "    }");
//  p_fn_prtlin( "    table.trait td {");
///*   p_fn_prtlin( "      font-family: Andale Mono, Monospace, Courier New;"); */
//  p_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New;");
//  p_fn_prtlin( "      white-space: pre;");
//
////  p_fn_prtlin( "      font-size: 90%;");
////  p_fn_prtlin( "      font-size: 2em;");
////  p_fn_prtlin( "      font-size: 2.5em;");
////  p_fn_prtlin( "      font-size: 2.0em;");
////  p_fn_prtlin( "      font-size: 2.3em;");
//  p_fn_prtlin( "      font-size: 2.2em;");
//
//  p_fn_prtlin( "      text-align: left;");
//
///*   p_fn_prtlin( "      border: 1px solid black;"); */
////  p_fn_prtlin( "      border: none;");
////  p_fn_prtlin( "      border: 1px gray;");
////  p_fn_prtlin( "      border: 1px solid black;"); 
////  p_fn_prtlin( "      border: 6px solid #404040;");
////  p_fn_prtlin( "      border: 6px solid green;");
////  p_fn_prtlin( "      border: 1px solid green;");
//
////  p_fn_prtlin( "      border: 1px solid #c0e8c0;");   TAKE AWAY BORDER (alternating green colors instead)
//
//  p_fn_prtlin( "      border-spacing: 0;");
//  p_fn_prtlin( "      border-collapse: collapse;");
//  p_fn_prtlin( "      border-spacing: 0;");
//
///*   p_fn_prtlin( "      padding-left: 2px; "); */
///*   p_fn_prtlin( "      padding-right: 2px; "); */
////  p_fn_prtlin( "      padding-left: 10px; ");
////  p_fn_prtlin( "      padding-right: 10px; ");
////  p_fn_prtlin( "      padding-left: 2em; ");
////  p_fn_prtlin( "      padding-right: 2em; ");
//
////  p_fn_prtlin( "      padding-left: 0.7em; ");
////  p_fn_prtlin( "      padding-right: 0.7em; ");
////  p_fn_prtlin( "      padding-left:  0.25em; ");
////  p_fn_prtlin( "      padding-right: 0.25em; ");
//  p_fn_prtlin( "      padding-left:  0.18em; ");
//  p_fn_prtlin( "      padding-right: 0.18em; ");
//
//  p_fn_prtlin( "      padding-top: 2px; ");
//  p_fn_prtlin( "      padding-bottom: 2px; ");
///*   p_fn_prtlin( "      padding-top: 1px; "); */
///*   p_fn_prtlin( "      padding-bottom: 1px; "); */
//
//  p_fn_prtlin( "    }");
//  p_fn_prtlin( "    table.trait th { ");
///*   p_fn_prtlin( "      font-family: Trebuchet MS, Arial, Verdana, sans-serif;"); */
//  p_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New;");
//
////  p_fn_prtlin( "      font-size: 90%;");
////  p_fn_prtlin( "      font-size: 2em;");
////  p_fn_prtlin( "      font-size: 2.5em;");
////  p_fn_prtlin( "      font-size: 2.0em;");
////  p_fn_prtlin( "      font-size: 2.3em;");
//  p_fn_prtlin( "      font-size: 2.2em;");
//
///*   p_fn_prtlin( "      padding-left: 10px; "); */
///*   p_fn_prtlin( "      padding-right: 10px; "); */
//  p_fn_prtlin( "      padding: 10px; ");
//
///*   p_fn_prtlin( "      background-color: #e1fdc3 ;"); */
//
//
////  p_fn_prtlin( "      background-color: #fcfce0 ;"); 
//  p_fn_prtlin( "      background-color: #00f0ff ;");   // dark apl blue (chevron)
//
//
//
///*   p_fn_prtlin( "      border: 1px solid black;"); */
//  p_fn_prtlin( "      border: none;");
//  p_fn_prtlin( "      border-spacing: 0;");
//
//  p_fn_prtlin( "      text-align: center;");
//  p_fn_prtlin( "    } ");
//
////  p_fn_prtlin( "    table.trait tfoot { ");
////  p_fn_prtlin( "      background-color: #ff0000 ;");
////  p_fn_prtlin( "      font-size: 0.9em;");
////  p_fn_prtlin( "      font-weight: normal;");
////  p_fn_prtlin( "    } ");
////
//
//
//  p_fn_prtlin( "    table.trait       td { text-align: left; }");
//  p_fn_prtlin( "    table.trait    td+td { text-align: right; }");
//  p_fn_prtlin( "    table.trait td+td+td { text-align: left; }");
//
//  p_fn_prtlin( "  </style>");
//
//    
//    /* put in favicon */
//
//    
//    
//
//
//  p_fn_prtlin( "</head>");
//  p_fn_prtlin( " ");
//  p_fn_prtlin("\n<body>");
//
//  /*   p_fn_prtlin( "<body background=\"file:///mkgif1g.gif\">"); */
//  /*   p_fn_prtlin( "<body background=\"file:///C/USR/RK/html/mkgif1g.gif\">"); */
//
//  /* "Personality"   output here */
///* 
//*   sprintf(writebuf, "\n  <h1>Personality</h1>");
//*   p_fn_prtlin(writebuf);
//*   sprintf(writebuf, "\n  <h2>of %s<br></h2>", arr(0) ); * of Fred  *
//*   p_fn_prtlin(writebuf);
//*/
//
///*   sprintf(writebuf, "\n  <h1>Personality <span style=\"font-size:80%%;\">of %s</span><br></h1>", arr(0) );  */
///*   sprintf(writebuf, "\n  <h1>Personality of %s<br></h1>", arr(0) ); * of Fred  * */
//
///*   p_fn_prtlin("<div><br></div>"); */
//
////  sprintf(writebuf, "\n  <h1>Personality for <span class=\"cNam\">%s</span><br></h1>", arr(0) ); /* of Fred  */
///*   p_fn_prtlin(writebuf); */
//
//  //strcpy(gbl_person_name, arr(0));
//  strcpy(gbl_p_person_name, arr(0));
//
////  p_fn_prtlin("<div><pre class=\"myTitle\">");
////  gbl_we_are_in_PRE_block_content = 1; 
////  sprintf(writebuf, "Personality for" ); /* of Fred  */
////  p_fn_prtlin(writebuf);
////  sprintf(writebuf, "%s", arr(0) ); /* of Fred  */
////  p_fn_prtlin(writebuf);
////  gbl_we_are_in_PRE_block_content = 0;  /* false */
////  p_fn_prtlin("</pre></div>");
//
//
////
////  p_fn_prtlin("<pre class=\"myTitle\">");
////  gbl_we_are_in_PRE_block_content = 1; 
////
/////*   sprintf(writebuf, "Calendar Year %s",  arr(2) ); */
/////*   f_fn_prtlin(writebuf); */
////
////  // want 6 sp left margin
////  // then max 15 char name centered in 15 char field
////  // extra sp on left
//////  long namelen1 = strlen(gbl_person_name);
////  long namelen1 = strlen(gbl_p_person_name);
////  char mynam[32];
////  //strcpy(mynam, gbl_person_name);
////  strcpy(mynam, gbl_p_person_name);
////  char char15toprint[32];
////       if (namelen1 ==  1) sprintf(char15toprint, "       %s       ", mynam); 
////  else if (namelen1 ==  2) sprintf(char15toprint, "       %s      ", mynam); 
////  else if (namelen1 ==  3) sprintf(char15toprint, "      %s      ", mynam);
////  else if (namelen1 ==  4) sprintf(char15toprint, "      %s     ", mynam); 
////  else if (namelen1 ==  5) sprintf(char15toprint, "     %s     ", mynam); 
////  else if (namelen1 ==  6) sprintf(char15toprint, "     %s    ", mynam); 
////  else if (namelen1 ==  7) sprintf(char15toprint, "    %s    ", mynam); 
////  else if (namelen1 ==  8) sprintf(char15toprint, "    %s   ", mynam); 
////  else if (namelen1 ==  9) sprintf(char15toprint, "   %s   ", mynam); 
////  else if (namelen1 == 10) sprintf(char15toprint, "   %s  ", mynam); 
////  else if (namelen1 == 11) sprintf(char15toprint, "  %s  ", mynam); 
////  else if (namelen1 == 12) sprintf(char15toprint, "  %s ", mynam); 
////  else if (namelen1 == 13) sprintf(char15toprint, " %s ", mynam); 
////  else if (namelen1 == 14) sprintf(char15toprint, " %s", mynam); 
////  else if (namelen1 == 15) sprintf(char15toprint, "%s", mynam); 
////  else                    sprintf(char15toprint,"%s", mynam);
////  //  sprintf(writebuf, "     %s", arr(1) );     // just name
////  //sprintf(writebuf, "      %s", char15toprint );  // just name   6sp on left
////  sprintf(writebuf, "%s", char15toprint );  // just name   6sp on left
////
////  p_fn_prtlin(writebuf);
////  gbl_we_are_in_PRE_block_content = 0; 
////  p_fn_prtlin("</pre>");
////
////
//
//
//
//  p_fn_prtlin("<div><br></div>");
//
///* b(29); */
//} /* end of  p_fn_webview_output_top_of_html_file() */
//
//


int make_per_htm_file_browser( // smup - now writes code to char array at char *gbl_HTML_code_for_per
//  char *in_html_filename,
  char *arg_space_for_HTML_per, // space malloc'ed in js,  passed into mamb_report_personality()
  char *in_docin_lines[],
  int   in_docin_last_idx)
{

  gbl_space_for_HTML_per          = arg_space_for_HTML_per;

//tn();trn("in make_per_htm_file_browser"); 
/* ksn(in_html_filename); */
  int i; 



/* for test */
/* p_fn_prtlin("hey owieurw0093203");
* p_docin_get(doclin);
* p_fn_prtlin(doclin);
* p_docin_get(doclin);
* p_fn_prtlin(doclin);
* p_docin_get(doclin);
* p_fn_prtlin(doclin);
*/
/* for test */


  /* in this fn is the first p_docin_get
  */
  p_fn_output_top_of_html_file();  /* output the css, headings etc. */




/* b(11); */
  /*  read until [beg_graph]
   */
  for (i=0; ; i++) {
    p_docin_get(doclin);
    if (strstr(doclin, "[beg_graph]") != NULL) break;
  }

/*   p_fn_prtlin("  <div> Stand out character traits.</div>"); */

//  /*  old graph   do_orig_trait_graph(); */
//  p_fn_prtlin("<div> </div>");
//
//  do_benchmark_trait_graph();    /* !!!!!!!!!!!!!!!!!!!  trait table printed here !!! */
//
///* b(12); */
//
//  /*   p_fn_prtlin("\n<h3> </h3>"); */
//  p_fn_prtlin("<div><br></div>");
//
//  p_fn_prtlin("</table>");
//



 do_benchmark_trait_graph();    /* !!!!!!!!!!!!!!!!!!!  trait table collected into trait_lines here !!! - NOT printed yet  (see bottom) */


// see tfoot instead of this
//  //p_fn_prtlin("<pre>");
//  p_fn_prtlin("<pre style=\"font-size: 1.1em;\">");
//  gbl_we_are_in_PRE_block_content = 1; /* 1 = yes, 0 = no */
//
////  p_fn_prtlin("");
//
//
///*   p_fn_prtlin("  A score measures how high or low the influence  "); */
//
////  p_fn_prtlin("  A score from 1 to 99 measures how influential  ");                   // browser view
////  sprintf(writebuf, "  the trait is in the personality of %s.  ", gbl_p_person_name);
////  p_fn_prtlin(writebuf);
////
//
//  p_fn_prtlin(      "    A score from 1 to 99 measures \"how much\"");
//  sprintf(writebuf, "    of that trait %s has.  ", gbl_p_person_name);
//  p_fn_prtlin(      "    A score does NOT measure \"good\" or \"bad\".");
//
//
//  p_fn_prtlin("");
///*   p_fn_prtlin("  The score does NOT measure \"good\" or \"bad\", "); */
//
//  //p_fn_prtlin("  The score here does NOT measure \"good\" or \"bad\",  ");
//  p_fn_prtlin("  This score does NOT measure \"good\" or \"bad\",  ");
//
//  p_fn_prtlin("    which can be found in the paragraphs below: ");
//  p_fn_prtlin("");
//  gbl_we_are_in_PRE_block_content = 0; /* 1 = yes, 0 = no */
//  p_fn_prtlin("</pre>");
//
//

//
//  p_fn_prtlin("<div> </div>");
//


  // intense willpower nugget
//  p_fn_prtlin("<div class=\"cssDIVnugget BGimageNUGGETs\" >");
//  p_fn_prtlin( "           Your <span class='yellowShine'>intense willpower</span>          ");
//  p_fn_prtlin( "      can overcome challenging traits      ");
//  p_fn_prtlin( "        and magnify favorable ones         ");
//  p_fn_prtlin( "</div>");
//
  p_fn_prtlin("<div class=\"cssDIVnugget BGimageNUGGETs\" >");
  p_fn_prtlin( "Your <span class='yellowShine'>intense willpower</span> can<br>overcome challenging traits<br>and magnify favorable ones  ");
  p_fn_prtlin( "</div>");


  // intense willpower nugget


  /* DO PARAGRAPHS HERE */

  /* read until
  */
  for (i=0; ; i++) {
    p_docin_get(doclin);
    if (strstr(doclin, "[beg_aspects]") != NULL) break;
  }


  /* now read and print aspects until we hit [end_aspects] 
  */
  for (i=0; ; i++) {
    p_docin_get(doclin);
    if (strlen(doclin) == 0) continue;
    if (strstr(doclin, "[end_aspects]") != NULL) break;
    
    strcpy(aspect_code, doclin);
    p_fn_browser_aspect_text(aspect_code);    /* output the aspect text */
    
  }  /* read and print aspects until we hit [end_aspects] */

/* b(14); */


  for (i=0; ; i++) {  /* read until  */
    p_docin_get(doclin);
    if (strstr(doclin, "[end_program]") != NULL) break;
  }


/*   p_fn_prtlin("<div> </div>"); */
//  p_fn_prtlin("<div><br></div>");

// smup   p_fn_prtlin("<pre style=\"font-size: 1.0em\">");
//
// smup   p_fn_prtlin("<pre style=\"font-size: 1.0em\">");
//

//  p_fn_prtlin("<pre style=\"font-size: 0.70em; font-weight: bold;\">");
//  p_fn_prtlin("<pre style=\"font-size: 75%; font-weight: bold;\"> ");


// CSS now in per_emcc_my2.html
//  p_fn_prtlin("<pre style=\"font-size: 75%; font-weight: bold;\"> ");

//  p_fn_prtlin("<pre class=\"RPPE_pre\" style=\"font-size: 75%; font-weight: bold; background-color: inherit; margin-top: 0vh; margin-bottom: 0vh; \">    *trait categories</pre>");
// CSS now in per_emcc_my2.html



//  gbl_we_are_in_PRE_block_content = 1;  /* true */

//  p_fn_prtlin("    *trait");
//  p_fn_prtlin("</pre>");

//  p_fn_prtlin("     Assertive     - competitive, authoritative, outspoken  ");
//  p_fn_prtlin("     Emotional     - protective, sensitive, possessive");
//  p_fn_prtlin("     Restless      - versatile, changeable, independent");
//  p_fn_prtlin("     Down-to-earth - stable, practical, ambitious");
//  p_fn_prtlin("     Passionate    - intense, relentless, enthusiastic");

//  p_fn_prtlin( "  <span class=\"cPerGreen1\" >  Assertive                              </span>  ");
//  p_fn_prtlin( "  <span class=\"cPerGreen1\" >  - competitive, authoritative, outspoken</span>  ");
//  p_fn_prtlin( "  <span class=\"cPerGreen2\" >  Emotional                              </span>  ");
//  p_fn_prtlin( "  <span class=\"cPerGreen2\" >  - protective, sensitive, possessive    </span>  ");
//  p_fn_prtlin( "  <span class=\"cPerGreen1\" >  Restless                               </span>  ");
//  p_fn_prtlin( "  <span class=\"cPerGreen1\" >  - versatile, changeable, independent   </span>  ");
//  p_fn_prtlin( "  <span class=\"cPerGreen2\" >  Down-to_earth                          </span>  ");
//  p_fn_prtlin( "  <span class=\"cPerGreen2\" >  - stable, practical, ambitious         </span>  ");
//  p_fn_prtlin( "  <span class=\"cPerGreen1\" >  Passionate                             </span>  ");
//  p_fn_prtlin( "  <span class=\"cPerGreen1\" >  - intense, relentless, enthusiastic    </span>  ");
//

//  p_fn_prtlin("<div style=\"margin-right: 2vw; margin-left: 2vw;  border-style: solid; border-width: 0.33vw; border-color: rgb(42,32,8); \" >");
//  p_fn_prtlin( "  <p class=\"cPerGreen1 RPPE_p\" style=\"margin-top: 0vh; margin-bottom: 0vh;  margin-right: 0vw; margin-left: 0vw; \" >  Assertive<br>                            ");
//  p_fn_prtlin( "   - competitive, authoritative, outspoken</p>  ");
//  p_fn_prtlin( "  <p class=\"cPerGreen2 RPPE_p\" style=\"margin-top: 0vh; margin-bottom: 0vh;  margin-right: 0vw; margin-left: 0vw; \" >  Emotional<br>                            ");
//  p_fn_prtlin( "   - protective, sensitive, possessive    </p>  ");
//  p_fn_prtlin( "  <p class=\"cPerGreen1 RPPE_p\" style=\"margin-top: 0vh; margin-bottom: 0vh;  margin-right: 0vw; margin-left: 0vw; \"  >  Restless<br>                             ");
//  p_fn_prtlin( "   - versatile, changeable, independent   </p>  ");
//  p_fn_prtlin( "  <p class=\"cPerGreen2 RPPE_p\" style=\"margin-top: 0vh; margin-bottom: 0vh;  margin-right: 0vw; margin-left: 0vw; \"  >  Down-to-earth<br>                        ");
//  p_fn_prtlin( "   - stable, practical, ambitious         </p>  ");
//  p_fn_prtlin( "  <p class=\"cPerGreen1 RPPE_p\" style=\"margin-top: 0vh; margin-bottom: 0vh;  margin-right: 0vw; margin-left: 0vw; \"  >  Passionate<br>                           ");
//  p_fn_prtlin( "   - intense, relentless, enthusiastic    </p>  ");
//  p_fn_prtlin("</div>");
//


//  p_fn_prtlin("<div style=\" margin-left: auto;  margin-right: auto;   border-style: solid; border-width: 0.33vw; border-color: rgb(42,32,8); text-align: center; background-color: rgb(255,255,255); font-size: 75%; width: 80%; \" >");




//  p_fn_prtlin("<div style=\" margin-left: auto;  margin-right: auto; margin-bottom: 5vh; border-style: solid; border-width: 0.33vw; border-color: rgb(42,32,8); text-align: center; background-color: rgb(255,255,255); font-size: 65%; font-weight: bold; width: 80%; \" >");

//  p_fn_prtlin("<div style=\"padding: 3vh; margin-left: auto;  margin-right: auto; margin-bottom: 5vh; border-style: solid; border-width: 0.33vw; border-color: rgb(42,32,8); text-align: center; background-color: rgb(255,255,255); font-size: 75%; font-weight: normal; width: 80%; \" >");


//
//  // intense willpower nugget
//  p_fn_prtlin("<div class=\"cssPwillP\" >");
//
//  p_fn_prtlin( "           Your <span style=' text-shadow: 2px 2px 0 rgb(255,255,2), -2px -2px 0 rgb(255,255,2), -2px  2px 0 rgb(255,255,2),  2px -2px 0 rgb(255,255,2) ; '>intense willpower</span>          ");
//  p_fn_prtlin( "      can overcome challenging traits      ");
//  p_fn_prtlin( "        and magnify favorable ones         ");
//  p_fn_prtlin( "</div>");
//  // intense willpower nugget
//
//

//<.>
//  g_fn_prtlin("<div style=\"padding: 3vh; margin-left: auto;  margin-right: auto; margin-bottom: 5vh; border-style: solid; border-width: 0.33vw; border-color: rgb(42,32,8); text-align: left; background-color: rgb(255,255,255); font-size: 65%; font-weight: bold; width: 80%; \" >");
//<.>
//




  // trait score  table goes here
  //
  /*  old graph   do_orig_trait_graph(); */
  p_fn_prtlin("<div> </div>");


  // NOTE: do_benchmark_trait_graph();    is done at top



  //  write_html_for_trait_table(); // write the html for the table
  //
  if (gbl_are_in_per_htm_webview == 1) write_TBLRPT_trait_data();        /* now TBLRPT */
  else                                 write_html_for_trait_table();




/* b(12); */

  /*   p_fn_prtlin("\n<h3> </h3>"); */
  p_fn_prtlin("<div><br></div>");

  p_fn_prtlin("</table>");


  p_fn_prtlin("<div> </div>");

  //
  // trait score  table goes here



  /* put trait descriptions
  */
//  p_fn_prtlin("<div class=\"RPPE_pre\" style=\"font-size: 75%; font-weight: bold; background-color: inherit; margin-top: 0vh; margin-bottom: 0vh; text-align: center; \">    *trait categories</pre></div>");

//  p_fn_prtlin("<div class=\"RPPE_traits\">    *trait categories</pre></div>");


//  p_fn_prtlin("<div style=\" margin-left: auto;  margin-right: auto;   border-style: solid; border-width: 0.33vw; border-color: rgb(42,32,8); width; auto; display: table; font-size: 75%;  \" >");
////  p_fn_prtlin("<div style=\"margin-right: 2vw; margin-left: 2vw;   \" >");
//  p_fn_prtlin( "  <p id=\"traitCat_E\" class=\"cTrait_50 RPPE_p\" style=\"color: rgb(0,0,0); margin-top: 0vh; margin-bottom: 0vh;  margin-right: 0vw; margin-left: 0vw; \" >  Emotional<br>     ");
//  p_fn_prtlin( "   - protective, sensitive, possessive    </p>  ");
//
//  p_fn_prtlin( "  <p id=\"traitCat_A\" class=\"cTrait_50 RPPE_p\" style=\"color: rgb(0,0,0); padding-top: 1em; margin-top: 0vh; margin-bottom: 0vh;  margin-right: 0vw; margin-left: 0vw; \" >  Assertive<br>     ");
//  p_fn_prtlin( "   - competitive, authoritative, outspoken</p>  ");
//
//  p_fn_prtlin( "  <p id=\"traitCat_P\" class=\"cTrait_50 RPPE_p\" style=\"color: rgb(0,0,0); padding-bottom: 1em; margin-top: 0vh; margin-bottom: 0vh;  margin-right: 0vw; margin-left: 0vw; \" >  Passionate<br>    ");
//  p_fn_prtlin( "   - intense, relentless, enthusiastic    </p>  ");
//
//  p_fn_prtlin( "  <p id=\"traitCat_R\" class=\"cTrait_50 RPPE_p\" style=\"color: rgb(0,0,0); margin-top: 0vh; margin-bottom: 0vh;  margin-right: 0vw; margin-left: 0vw; \" >  Restless<br>      ");
//  p_fn_prtlin( "   - versatile, changeable, independent   </p>  ");
//
//  p_fn_prtlin( "  <p id=\"traitCat_D\" class=\"cTrait_50 RPPE_p\" style=\"color: rgb(0,0,0); margin-top: 0vh; margin-bottom: 0vh;  margin-right: 0vw; margin-left: 0vw; \" >  Down-to-earth<br> ");
//  p_fn_prtlin( "   - stable, practical, ambitious         </p>  ");
//
//  p_fn_prtlin("</div>");
//

//  p_fn_prtlin("<div style=\"margin-right: 2vw; margin-left: 2vw;   \" >");
//background-color: RGB(146,255,189); 



  // 20191101  put description table images in same order  AND BG color as trait score table images
  // 20191101  put description table images in same order  AND BG color as trait score table images

//FYI  trait names
//      if (strcmp(trait_lines[i].trait, "Emotional")     == 0)  strcpy(rowTrait_ID, "rowTrait_ID_E");
//      if (strcmp(trait_lines[i].trait, "Assertive")     == 0)  strcpy(rowTrait_ID, "rowTrait_ID_A");
//      if (strcmp(trait_lines[i].trait, "Passionate")    == 0)  strcpy(rowTrait_ID, "rowTrait_ID_P");
//      if (strcmp(trait_lines[i].trait, "Restless")      == 0)  strcpy(rowTrait_ID, "rowTrait_ID_R");
//      if (strcmp(trait_lines[i].trait, "Down-to-earth") == 0)  strcpy(rowTrait_ID, "rowTrait_ID_D");

// fyi all trait lines
//    per_emcc_my2.html:87124 _i=[1]___trait_lines[i].trait=[Assertive]__
//    per_emcc_my2.html:87124 _i=[2]___trait_lines[i].trait=[zzzzzzzzzzzz]__
//    per_emcc_my2.html:87124 _i=[3]___trait_lines[i].trait=[zzzzzzzzzzzz]__
//    per_emcc_my2.html:87124 _i=[4]___trait_lines[i].trait=[Restless]__
//    per_emcc_my2.html:87124 _i=[5]___trait_lines[i].trait=[Down-to-earth]__
//    per_emcc_my2.html:87124 _i=[6]___trait_lines[i].trait=[Emotional]__
//    per_emcc_my2.html:87124 _i=[7]___trait_lines[i].trait=[Passionate]__
//    per_emcc_my2.html:87124 _i=[8]___trait_lines[i].trait=[            ]__
//    per_emcc_my2.html:87124 _i=[9]___trait_lines[i].trait=[            ]__
//    per_emcc_my2.html:87124 _i=[10]___trait_lines[i].trait=[]__
//    per_emcc_my2.html:87124 _i=[11]___trait_lines[i].trait=[]__
//

//  p_fn_prtlin("<div class=\"cTrait_50 RPPE_p\"  style=\" margin-left: auto;  margin-right: auto;   border-style: solid; border-width: 0.33vw; border-color: rgb(32,32,32); width; auto; display: table; font-size: 75%; padding: 0.5em  \" >");
// try bg = 32 32 32
  p_fn_prtlin("<div class=\"RPPE_p\"  style=\"background-color: rgb(64,64,64);  margin-left: auto;  margin-right: auto;   border-style: solid; border-width: 0.33vw; border-color: rgb(32,32,32); border-radius: 6px; width; auto; display: table; font-size: 75%; padding: 0.5em  \" >");

  char traitBGcolorClass[32];
  char topRowClass[64];
  int  traitWasPrinted = 0;
  int  sscore_int2;

  strcpy(topRowClass, "topRowMarginTop");     // it is  margin-top: 0.5em;

  for (int i = 0; i <= 10; i++) {
//ki(i); ks(trait_lines[i].score); ksn(trait_lines[i].trait);

    sscore_int2 = atoi(trait_lines[i].score);

    // get score denoted by 90, 75, 50, 25, 10
    // use score to specify class for bg color of trait description
    if (sscore_int2 >= 90                       ) strcpy(traitBGcolorClass, "cTrait_90PER");
    if (sscore_int2 >= 75  && sscore_int2 <  90 ) strcpy(traitBGcolorClass, "cTrait_75PER");
    if (sscore_int2 >  25  && sscore_int2 <  75 ) strcpy(traitBGcolorClass, "cTrait_50PER");
    if (sscore_int2 >  10  && sscore_int2 <= 25 ) strcpy(traitBGcolorClass, "cTrait_25PER");
    if (                      sscore_int2 <= 10 ) strcpy(traitBGcolorClass, "cTrait_10PER");

    // first one gets  margin-top: 0.5em;


    if (strcmp(trait_lines[i].trait, "Assertive")     == 0) {
//      sprintf(writebuf, "<p id=\"traitCat_A\" class=\"%s %s RPPE_p\" style=\"color: rgb(0,0,0); padding-bottom: 1em;  margin: 0.2em; \" > competitive, bossy, outspoken      </p>  " , traitBGcolorClass, topRowClass );
//    sprintf(writebuf, "<p id=\"traitCat_A\" class=\"%s %s RPPE_p\" style=\"padding: 0.5em;  margin: auto; \" >&nbsp;competitive, bossy,<br>&nbsp;outspoken      </p>  " , traitBGcolorClass, topRowClass );
      sprintf(writebuf, "<p id=\"traitCat_A\" class=\"%s %s RPPE_p\" style=\"padding: 0.5em;  margin: auto; \" >&nbsp;competitive, outspoken,<br>&nbsp;bossy      </p>  " , traitBGcolorClass, topRowClass );
      p_fn_prtlin(writebuf);
      traitWasPrinted = 1 ;
    }
    if (strcmp(trait_lines[i].trait, "Emotional")     == 0) {
//    sprintf(writebuf, "<p id=\"traitCat_E\" class=\"%s %s RPPE_p\" style=\"padding: 0.5em;  margin: auto; \"  >&nbsp;caring, possessive,<br>&nbsp;sensitive     </p>  ", traitBGcolorClass, topRowClass  );
      sprintf(writebuf, "<p id=\"traitCat_E\" class=\"%s %s RPPE_p\" style=\"padding: 0.5em;  margin: auto; \"  >&nbsp;caring, sensitive,<br>&nbsp;possessive     </p>  ", traitBGcolorClass, topRowClass  );
      p_fn_prtlin(writebuf);
      traitWasPrinted = 1 ;
    }
    if (strcmp(trait_lines[i].trait, "Passionate")    == 0) {
//    sprintf(writebuf, "<p id=\"traitCat_P\" class=\"%s %s RPPE_p\" style=\"padding: 0.5em;  margin: auto; \" >&nbsp;intense, relentless,<br>&nbsp;enthusiastic  </p>  ", traitBGcolorClass, topRowClass  );
      sprintf(writebuf, "<p id=\"traitCat_P\" class=\"%s %s RPPE_p\" style=\"padding: 0.5em;  margin: auto; \" >&nbsp;intense, enthusiastic,<br>&nbsp;relentless  </p>  ", traitBGcolorClass, topRowClass  );
      p_fn_prtlin(writebuf);
      traitWasPrinted = 1 ;
    }
    if (strcmp(trait_lines[i].trait,"Restless")      == 0) {
//    sprintf(writebuf, "<p id=\"traitCat_R\" class=\"%s %s RPPE_p\" style=\"padding: 0.5em;  margin: auto; \" >&nbsp;versatile, changeable,<br>&nbsp;independent </p>  ", traitBGcolorClass, topRowClass  );
      sprintf(writebuf, "<p id=\"traitCat_R\" class=\"%s %s RPPE_p\" style=\"padding: 0.5em;  margin: auto; \" >&nbsp;versatile, independent,<br>&nbsp;changeable </p>  ", traitBGcolorClass, topRowClass  );
      p_fn_prtlin(writebuf);
      traitWasPrinted = 1 ;
    }
    if (strcmp(trait_lines[i].trait, "Down-to-earth") == 0) {
//    sprintf(writebuf, "<p id=\"traitCat_D\" class=\"%s %s RPPE_p\" style=\"padding: 0.5em;  margin: auto; \" >&nbsp;stable, fussy,<br>&nbsp;practical           </p>  ", traitBGcolorClass, topRowClass  );
      sprintf(writebuf, "<p id=\"traitCat_D\" class=\"%s %s RPPE_p\" style=\"padding: 0.5em;  margin: auto; \" >&nbsp;stable, practical,<br>&nbsp;fussy           </p>  ", traitBGcolorClass, topRowClass  );
      p_fn_prtlin(writebuf);
      traitWasPrinted = 1 ;
    }


//ki(i); ksn( topRowClass);
    if (traitWasPrinted == 1) strcpy(topRowClass, ""); // only for top row

  } // for each trait_lines

//old
//  p_fn_prtlin( "<p id=\"traitCat_A\" class=\"cTrait_50 RPPE_p\" style=\"color: rgb(0,0,0); padding-top: 1em;  margin-top: 0vh; margin-bottom: 0vh;  margin-right: 0vw; margin-left: 0vw; \" > competitive, authoritative, outspoken </p>  ");
//
//
//  p_fn_prtlin( "<p id=\"traitCat_E\" class=\"cTrait_50 RPPE_p\" style=\"color: rgb(0,0,0); margin-top: 0vh;   margin-bottom: 0vh;  margin-right: 0vw; margin-left: 0vw; \" >  protective, sensitive, possessive </p> " );
//
//
//  p_fn_prtlin( "<p id=\"traitCat_P\" class=\"cTrait_50 RPPE_p\" style=\"color: rgb(0,0,0); padding-top: 1em;  margin-top: 0vh; margin-bottom: 0vh;  margin-right: 0vw; margin-left: 0vw; \" > intense, relentless, enthusiastic    </p>  ");
//
//  p_fn_prtlin( "<p id=\"traitCat_R\" class=\"cTrait_50 RPPE_p\" style=\"color: rgb(0,0,0); padding-top: 1em;  margin-top: 0vh; margin-bottom: 0vh;  margin-right: 0vw; margin-left: 0vw; \" > versatile, changeable, independent   </p>  ");
//
//  p_fn_prtlin( "<p id=\"traitCat_D\" class=\"cTrait_50 RPPE_p\" style=\"color: rgb(0,0,0); padding-top: 1em;  padding-bottom: 0.5em;  margin-top: 0vh; margin-bottom: 0vh;  margin-right: 0vw; margin-left: 0vw; \" > stable, practical, ambitious   </p>  ");
//

  p_fn_prtlin("</div>");
//<.>

//  p_fn_prtlin("");
//  p_fn_prtlin("");

//  p_fn_prtlin("  Check out reports \"Most Assertive\", \"Most Emotional\" ...  ");
//  p_fn_prtlin("  which use trait scores to compare with other group members  ");
//  p_fn_prtlin( "  Check out reports \"Most Assertive\",        ");
//  p_fn_prtlin( "  \"Most Emotional\" etc, which use trait      ");
//  p_fn_prtlin( "  scores to compare with other people        ");
//  p_fn_prtlin( "<pre class=\"RPPE_pre\" text-align: center; >Check out reports \"Most Assertive\",");


//  p_fn_prtlin("<div style=\"text-align: center;\" ><pre class=\"RPPE_p\" style=\"text-align: center; margin-top: 4vh; font-size: 75%;\" >");
//  p_fn_prtlin( "<span style=\"text-align: center;\" >Check out reports \"Most Assertive\",</span>");
//  p_fn_prtlin( "\"Most Emotional\" etc, which use trait");
//  p_fn_prtlin( "scores to compare with other people");
//  p_fn_prtlin("</pre></div>");
//

//  p_fn_prtlin("<div style=\" font-size: 75%; margin-top: 4vh; padding-left: 3vw; padding-right: 3vw; \" >");
//  p_fn_prtlin( "Check out reports \"Most Assertive\", \"Most Emotional\" etc, which use trait scores to compare with other people");
//  p_fn_prtlin("</div>");


//  p_fn_prtlin("<div style=\" margin-left: auto;  margin-right: auto;   border-style: solid; border-width: 0.33vw; border-color: rgb(42,32,8); text-align: center; background-color: rgb(255,255,255); font-size: 75%; width: 80%; \" >");

  // same as intense willpower but no box
  p_fn_prtlin("<div style=\" margin-left: auto;  margin-right: auto;  margin-top: 3vh; margin-bottom: 3vh; text-align: center;  font-size: 66%; width: 80%; \" >");
//  p_fn_prtlin( "Check out reports \"Most Assertive\", \"Most Emotional\" etc, which use trait scores to compare with other people");
  p_fn_prtlin( "Check out Group reports \"Most Assertive\", \"Most Emotional\" etc, which use trait scores to compare with other people");
  p_fn_prtlin("</div>");


  p_fn_prtlin("");
  gbl_we_are_in_PRE_block_content = 0;  /* false */
  p_fn_prtlin("</pre>");

  p_fn_prtlin("<div> </div>");

/*   p_fn_prtlin("<pre>"); */
/*   gbl_we_are_in_PRE_block_content = 1; */
/*   p_fn_prtlin(""); */
/*   p_fn_prtlin(" Check out group reports \"Most Assertive\", \"Most Emotional\" etc. "); */
/*   p_fn_prtlin("     which use these scores to compare with other group members.     "); */
/*   p_fn_prtlin("  Check out group reports \"Most Assertive\", \"Most Emotional\" etc.  "); */
/*   p_fn_prtlin("  which use these trait scores to compare with other group members.  "); */
/*   p_fn_prtlin(""); */
/*   gbl_we_are_in_PRE_block_content = 0; */
/*   p_fn_prtlin("</pre>"); */

//  p_fn_prtlin("<div><br></div>");

// smup   p_fn_prtlin("<pre style=\"font-size: 1.0em\">");
//
// smup   p_fn_prtlin("<pre style=\"font-size: 0.70em; font-weight: bold\">");
//


// CSS now in per_emcc_my2.html
//  p_fn_prtlin("<pre style=\"font-size: 1.0em\">");
//  p_fn_prtlin("<pre style=\"font-size: 75%\">");
//  p_fn_prtlin("<pre class=\"RPPE_pre\" style=\"font-size: 75%; margin-left: auto; margin-right: auto; \">");
//  p_fn_prtlin("<div style=\"font-size: 75%; font-weight: bold; width: 100%; margin-left: auto; margin-right: auto;\" ><pre class=\"RPPE_pre\">");
//  p_fn_prtlin("<div style=\"font-weight: bold; width: 100%; margin-left: auto; margin-right: auto;\" ><pre class=\"RPPE_pre\" style=\"font-size: 75%; font-weight: bold; \" >");

//  p_fn_prtlin("<div style=\"font-weight: bold; width: 100%; text-align: center; \" ><pre class=\"RPPE_pre\" style=\"font-size: 75%; font-weight: bold; \" >");

//  gbl_we_are_in_PRE_block_content = 1; 

//  p_fn_prtlin( "                                       ");
//  p_fn_prtlin( "  Your intense willpower can overcome  ");
//  p_fn_prtlin( "   bad traits and magnify good ones    ");
//  p_fn_prtlin( "                                       ");

//p_fn_prtlin( "     Your intense willpower can overcome    ");
//p_fn_prtlin( "  challenging traits and magnify good ones  ");
//  p_fn_prtlin( "            Your intense willpower          ");
//  p_fn_prtlin( "       can overcome challenging traits      ");
//  p_fn_prtlin( "         and magnify favorable ones         ");
//  p_fn_prtlin( "                                            ");
//
//  p_fn_prtlin( "                                           ");
//  p_fn_prtlin( "           Your intense willpower          ");
//  p_fn_prtlin( "      can overcome challenging traits      ");
//  p_fn_prtlin( "        and magnify favorable ones         ");
//  p_fn_prtlin( "                                           ");
//  gbl_we_are_in_PRE_block_content = 0;  /* false */
//  p_fn_prtlin("</pre></div>");


//  p_fn_prtlin("<div style=\"margin-right: 2vw; margin-left: 2vw;  border-style: solid; border-width: 0.33vw; border-color: rgb(42,32,8); text-align: center; background-color: rgb(252,232,180); font-size: 75%; width: 80%; \" >");


// intense willpower used to be here


  //sprintf(writebuf, "<h5 style=\"font-size: 1.0em\"><br>produced by iPhone app %s</h5>", APP_NAME);
//  sprintf(writebuf, "<div style=\"font-size: 1.0em\"><br>produced by iPhone app %s</div>", APP_NAME);
//  p_fn_prtlin(writebuf);
//  p_fn_prtlin("");
//  p_fn_prtlin("<div style=\"font-size: 0.9em; font-weight: bold; color:#FF0000;\">&nbspThis report is for entertainment purposes only.&nbsp</span></div>");

//  p_fn_prtlin("<div> <span style=\"font-size: 1.0em\"><br>produced by iPhone app Me and my BFFs</span><br><br><span style=\"font-size: 0.9em; font-weight: bold; color:#FF0000;\">This report is for entertainment purposes only.</span></div><div><br></div>");

  char workProducedBy[256];
//  sprintf(workProducedBy,
//    "<div> <span style=\"font-size: 1.0em\"><br>produced by iPhone app %s</span><br><br><span style=\"font-size: 0.9em; font-weight: bold; color:#FF0000;\">This report is for entertainment purposes only.</span></div><div><br></div>" ,
//    "<div> <span style=\"font-size: 1.0em\"><br>produced by %s</span><br><br><span style=\"font-size: 0.9em; font-weight: bold; color:#FF0000;\">This report is for entertainment purposes only.</span></div><div><br></div>" ,
//    APP_DESC
//  ); 
//  p_fn_prtlin( workProducedBy );


//  p_fn_prtlin( "<div> <span style=\"margin-left: auto; margin-right: auto; font-size: 75%\"><br>produced by free app from iGo2stars.org</span><br><span style=\"margin-left: auto; margin-right: auto; font-size: 66%; font-weight: bold; color:#FF0000;\">This report is for entertainment purposes only</span></div><div><br></div>" );
//  p_fn_prtlin( "<div style=\"margin-left: auto; margin-right: auto;\" > <span style=\"font-size: 75%\"><br>produced by free app from iGo2stars.org</span><br><span style=\"font-size: 66%; font-weight: bold; color:#FF0000;\">This report is for entertainment purposes only</span></div><div><br></div>" );


//  p_fn_prtlin( "<br><div style=\"width: 100%; margin-left: auto; margin-right: auto; font-size: 75%; \" >produced by free app from iGo2stars.org</div>");
//  p_fn_prtlin( "<div style=\"text-align: center; font-size: 66%; margin-top: 2vh; \" >produced by free app from iGo2stars.org</div>");
//  p_fn_prtlin( "<div style=\"text-align: center; font-size: 66%; margin-top: 2vh; \" >produced by free app igotostars.org</div>");
  p_fn_prtlin( "<div class=\"iHaveAPP_DESC\" style=\"text-align: center; font-size: 66%; margin-top: 2vh; \" >produced by appDESCgoesHERE</div>");

  



//  p_fn_prtlin( "<br><div style=\"margin-left: auto; margin-right: auto; font-size: 66%; font-weight: bold; color:#FF0000;\">This report is for entertainment purposes only</span></div><div><br></div>" );
//  p_fn_prtlin( "<div style=\"text-align: center; font-size: 66%; font-weight: bold; color:#FF0000;\">This report is for entertainment purposes only</div><br>" );
  p_fn_prtlin( "<div style=\"text-align: center; font-size: 66%; font-weight: normal; color:#FF0000;\">This report is for entertainment purposes only</div><div><br></div>" );

//  p_fn_prtlin( "<div style=\"text-align: center; font-size: 66%; font-weight: bold; color:#FF0000;\">This report is for entertainment purposes only</div><div><br></div>" );


// CSS now in per_emcc_my2.html
//  p_fn_prtlin("\n</body>\n");
//  p_fn_prtlin("</html>");
// CSS now in per_emcc_my2.html


// smup   fflush(Fp_p_HTML_file);
// smup   /* close output HTML file
// smup   */
// smup   if (fclose(Fp_p_HTML_file) == EOF) {
// smup     ;
// smup /* trn("FCLOSE FAILED !!!   #1  "); */
// smup   } else {
// smup     ;
// smup /* trn("FCLOSE SUCCESS !!!  #1  "); */
// smup   };
//
/* b(15); */
//tn();trn("finished make_per_htm_file_browser"); 
trn("finished make_per_htm_file_browser"); 
  return(0);

} // end of make_per_htm_file_browser      // browser



/* output the css, headings etc.
*/
void p_fn_output_top_of_html_file(void)                        // browser view
{
  int i;
//trn("in p_fn_output_top_of_html_file()");

  /* 1. read until [beg_topinfo1]  (name)  (skipping [beg_program])
  */
  for (i=0; ; i++) {
    p_docin_get(doclin);
    if (strstr(doclin, "[beg_topinfo1]") != NULL) break;
  }

/* b(20); */
  /* then save lines until graph until [end_topinfo1] 
  * then put out html 
  */
  for (i=0; ; i++) {
    p_docin_get(doclin);
//kin(i);
//ksn(doclin);
    if (strstr(doclin, "[end_topinfo1]") != NULL) break;
//    strcpy(arr(i), doclin);
    strcpy(gbl_p_person_name, doclin);
//ksn(gbl_p_person_name);
  }
//ksn(gbl_p_person_name);
//

/* b(25); */


// CSS now in per_emcc_my2.html
///*   at end, change to STRICT  */
//  p_fn_prtlin( "<!doctype html public \"-//w3c//dtd html 4.01 transitional//en\" ");
///* b(26); */
//  p_fn_prtlin( "  \"http://www.w3.org/TR/html4/loose.dtd\">");
//
//  p_fn_prtlin( "<html>");
//  p_fn_prtlin( "\n<head>");
//
///*   sprintf(writebuf, "  <title>%s- Personality, produced by iPhone app %s.</title>",arr(0), APP_NAME); */
//
// CSS now in per_emcc_my2.html



// smup   /* if HTML filename, gbl_pfnameHTML, has any slashes, grab the basename
// smup   */
// smup   char myBaseName[256], *myptr;
// smup   if (sfind(gbl_pfnameHTML, '/')) {
// smup     myptr = strrchr(gbl_pfnameHTML, '/');
// smup     strcpy(myBaseName, myptr + 1);
// smup   } else {
// smup     strcpy(myBaseName, gbl_pfnameHTML);
// smup   }
// smup   sprintf(writebuf, "  <title>%s</title>", myBaseName);
// smup   p_fn_prtlin(writebuf);
//

  
  /* HEAD  META
  */

//
////  sprintf(writebuf, "  <meta name=\"description\" content=\"Personality report produced by iPhone app %s\"> ",  APP_NAME);
////  sprintf(writebuf, "  <meta name=\"description\" content=\"Personality report produced by %s\"> ",  APP_DESC);
//  sprintf(writebuf, "  <meta name=\"description\" content=\"%s\"> ",  APP_DESC);
//  p_fn_prtlin(writebuf);
//
//
////  p_fn_prtlin( "  <meta http-equiv=\"Content-Type\" content=\"text/html\"; charset=\"iso-8859-1\">"); 
//  p_fn_prtlin( "  <meta http-equiv=\"Content-Type\" content=\"text/html\" charset=\"iso-8859-1\">"); 
//  /*   p_fn_prtlin( "  <meta name=\"Author\" content=\"Author goes here\">"); */
//
//
///*   p_fn_prtlin( "  <meta name=\"keywords\" content=\"group,member,astrology,personality,future,past,year in the life,compatibility,GMCR\">  */
///*   p_fn_prtlin( "  <meta name=\"keywords\" content=\"measure,group,member,best,match,calendar,year,passionate,personality\"> "); */
///*   p_fn_prtlin( "  <meta name=\"keywords\" content=\"BFF,astrology,compatibility,group,best,match,calendar,year,stress,personality\"> "); */
//
///*   p_fn_prtlin( "  <meta name=\"keywords\" content=\"women,woman,female,BFF,compatibility,group,best,match,personality,stress,calendar,year\"> "); */ /* 86 chars */ 
//  p_fn_prtlin( "  <meta name=\"keywords\" content=\"women,woman,female,BFF,me,compatibility,group,best,match,personality,stress,calendar,year\"> ");  /* 89 chars */
//
//
//  /* get rid of CHROME translate "this page is in Galician" 
//  * do you want to translate?
//  */
//  p_fn_prtlin("  <meta name=\"google\" content=\"notranslate\">");
//  p_fn_prtlin("  <meta http-equiv=\"Content-Language\" content=\"en\"/>");
//
//
//  /* Using the Viewport Meta Tag  (in iOS webView)
//  * https://developer.apple.com/library/safari/documentation/AppleApplications/Reference/SafariWebContent/UsingtheViewport/UsingtheViewport.html#//apple_ref/doc/uid/TP40006509-SW25
//  *
//  * For example, TO SET THE VIEWPORT WIDTH TO THE WIDTH OF THE DEVICE, add this to your HTML file:
//  * <meta name="viewport" content="width=device-width"> 
//  * To set the initial scale to 1.0, add this to your HTML file:
//  * <meta name="viewport" content="initial-scale=1.0"> 
//  * To set the initial scale and to turn off user scaling, add this to your HTML file:
//  * <meta name="viewport" content="initial-scale=2.3, user-scalable=no">
//  */
//
//  //f_fnBIG_prtlin("  <meta name=\"viewport\" content=\"initial-scale=1.0; \"> ");       //   browser view
//  //p_fn_prtlin("  <meta name=\"viewport\" content=\"width=device-width\" />");
////  p_fn_prtlin("  <meta name=\"viewport\" content=\"initial-scale=1.0\"> ");           //   browser view
//
//
//  p_fn_prtlin("  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">"); //   browser view
//  p_fn_prtlin("  <meta name = \"format-detection\" content = \"telephone=no\">");
//
//
//  /* HEAD   STYLE/CSS
//  */
//  p_fn_prtlin( "\n  <style type=\"text/css\">");
//  p_fn_prtlin( "    BODY {");
//
///*  p_fn_prtlin( "      background-color: #F5 EF CF;"); */
///*  g_fn_prtlin( "      background-color: #F5EFCF;"); */
//  p_fn_prtlin( "      background-color: #F7ebd1;");
//
///*   p_fn_prtlin( "      font-family: Trebuchet MS, Arial, Verdana, sans-serif;"); */
//  p_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New;");
//
////  p_fn_prtlin( "      font-size:   medium;");
//  p_fn_prtlin( "      font-size:   4.8vw;");    // BODY font-size
//
//  p_fn_prtlin( "      font-weight: normal;");
//  p_fn_prtlin( "      text-align:  center;");
//  /* example comment out */
//  /*   p_fn_prtlin( "    <!-- "); */
//  /*   p_fn_prtlin( "      background-image: url('mkgif1g.gif');"); */
//  /*   p_fn_prtlin( "    --> "); */
//  p_fn_prtlin( "    }");
//
//  p_fn_prtlin( "    H1 { font-size: 137%; font-weight: bold;   line-height: 95%; text-align: center;}");
//  p_fn_prtlin( "    H2 { font-size: 125%;                      line-height: 25%; text-align: center;}");
//  p_fn_prtlin( "    H3 { font-size: 110%; font-weight: normal; line-height: 30%; text-align: center;}");
//
///*   p_fn_prtlin( "    H5 { font-size:  55%; font-weight: normal; line-height: 90%; text-align: center;}"); */
///*   p_fn_prtlin( "    H4 { font-size:  85%; font-weight: bold;   line-height: 30%; text-align: center;}"); */
///*   p_fn_prtlin( "    H5 { font-size:  70%; font-weight: normal; line-height: 30%; text-align: center;}"); */
//
//  p_fn_prtlin( "    H4 { font-size:  75%; font-weight: bold;   line-height: 30%; text-align: center;}");
//  p_fn_prtlin( "    H5 { font-size:  70%; font-weight: normal; line-height: 30%; text-align: center;}");
//
//


// CSS now in per_emcc_my2.html
//
//  p_fn_prtlin( "    PRE {");          // browser view
//
//  p_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New;");
////  p_fn_prtlin( "      white-space: pre ; display: block; unicode-bidi: embed");
//  p_fn_prtlin( "      display: inline-block;");
//
//  p_fn_prtlin( "      background-color: #fcfce0;");
//  p_fn_prtlin( "      text-align:  left;");
///*   p_fn_prtlin( "      font-size:   90%;"); */
///*   p_fn_prtlin( "      border-style: solid;"); */
///*   p_fn_prtlin( "      border-color: black;"); */
///*   p_fn_prtlin( "      border-width: 2px;"); */
///*   p_fn_prtlin( "      border-color: #e4dfae; "); */
///*   p_fn_prtlin( "      border-width: 5px;"); */
//
//  p_fn_prtlin( "      border-spacing: 0;");
//  p_fn_prtlin( "      border: none;");
//  p_fn_prtlin( "      border-collapse: collapse;");
//  p_fn_prtlin( "      border-spacing: 0;");
///*   p_fn_prtlin( "      font-family: Andale Mono, Menlo, Monospace, Courier New;"); */
//  p_fn_prtlin( "      font-weight: normal;");
///*   p_fn_prtlin( "      line-height: 70%;"); */
///*   p_fn_prtlin( "      line-height: 100%;"); */
///*   p_fn_prtlin( "      line-height: 108%;"); */
//
////  p_fn_prtlin( "      font-size: 85%;");
//
///*   p_fn_prtlin( "      margin:0 auto;"); */
//  p_fn_prtlin( "    }");
//
//
//  p_fn_prtlin( "    P { ");
//
//// smup   p_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New;");
//// smup   p_fn_prtlin( "      width: auto;");
//// smup   p_fn_prtlin( "      width: 400px;");
//// smup   p_fn_prtlin( "      font-size:   93%;");
//// smup   p_fn_prtlin( "      margin-top: 0;");
//// smup   p_fn_prtlin( "      margin-bottom: 0;");
//// smup   p_fn_prtlin( "      margin-left: auto;");
//// smup   p_fn_prtlin( "      margin-right:auto;");
//// smup /*   p_fn_prtlin( "      padding-left: 5%;"); */
//// smup /*   p_fn_prtlin( "      padding-right:5%;"); */
//// smup /*   p_fn_prtlin( "      text-align: center;"); */
//// smup   p_fn_prtlin( "      text-align: left;");
////
//
//  p_fn_prtlin( "      width: 400px;");
//  p_fn_prtlin( "      left-margin: auto;");
//  p_fn_prtlin( "      right-margin: auto;");
//  p_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New;");
//
////  p_fn_prtlin( "      font-size: 85%;");
//  p_fn_prtlin( "      font-size: 75%;");
//
//  p_fn_prtlin( "      font-weight: bold;   ");
//  p_fn_prtlin( "      text-align: left;");
//
//  p_fn_prtlin( "    }"); // P'
//
///* for table: */
///*       border: 2px solid black; */
///*       cellspacing: 0; */
///*       border-top: 0; */
///*       border-bottom: 0; */
//  p_fn_prtlin( "    table {");
//  p_fn_prtlin( "      border: none;");
//  p_fn_prtlin( "      border-collapse: collapse;");
//  p_fn_prtlin( "      border-spacing: 0;");
//  p_fn_prtlin( "    }");
//
//  p_fn_prtlin( "    table.center {");
////  p_fn_prtlin( "      margin-left:auto;");
////  p_fn_prtlin( "      margin-right:auto;");
//
//  p_fn_prtlin( "    }");
//  p_fn_prtlin( "    TD {");
//  p_fn_prtlin( "      border: none;");
//  p_fn_prtlin( "      border-spacing: 0;");
//
//// smup   p_fn_prtlin( "      white-space: nowrap;");
////
//  p_fn_prtlin( "      white-space: wrap;");
//
//  p_fn_prtlin( "      padding: 0;");
//  p_fn_prtlin( "    }");
//
///*   p_fn_prtlin( "    .cLineGood   { background-color:#c3fdc3; }"); */
//  p_fn_prtlin( "    .cLineStress { background-color:#ffbac7; }");
//  p_fn_prtlin( "    .row4        { background-color:#f8f0c0; }");
//
///*   p_fn_prtlin( "    .cGr2        { background-color:#d0fda0; }"); */
///*   p_fn_prtlin( "    .cGr2        { background-color:#8bfd87; }"); */
///*   p_fn_prtlin( "    .cGr2        { background-color:#66ff33; }"); */
//
///*   p_fn_prtlin( "    .cGre        { background-color:#e1fdc3; }"); */
///*   p_fn_prtlin( "    .cGre        { background-color:#ccffb9; }"); */
///*   p_fn_prtlin( "    .cRed        { background-color:#ffd9d9; }"); */
///*   p_fn_prtlin( "    .cRed        { background-color:#ffcccc; }"); */
///*   p_fn_prtlin( "    .cRe2        { background-color:#fcb9b9; }"); */
///*   p_fn_prtlin( "    .cRe2        { background-color:#fc8888; }"); */
///*   p_fn_prtlin( "    .cRe2        { background-color:#fc6094; }"); */
///*   p_fn_prtlin( "    .cRe2        { background-color:#ff3366; }"); */
//
///*    GREEN   */
///*     .cGr2        { background-color:#a3f275; } */
///*     .cGre        { background-color:#bbf699; } */
///*     .cNeu        { background-color:#d3f9bd; } */
///*     .cRed        { backgro;und-color:#bbf699; } */
///*     .cRe2        { background-color:#a3f275; } */
//
//
///*   p_fn_prtlin( "    .cGr2        { background-color:#66ff33; }"); */
///*   p_fn_prtlin( "    .cGr2        { background-color:#a3f275; }"); */
///*   p_fn_prtlin( "    .cGre        { background-color:#84ff98; }"); */
///*   p_fn_prtlin( "    .cGre        { background-color:#a8ff98; }"); */
///*   p_fn_prtlin( "    .cGre        { background-color:#bbf699; }"); */
///*   p_fn_prtlin( "    .cNeu        { background-color:#e1ddc3; }"); */
///*   p_fn_prtlin( "    .cNeu        { background-color:#d3f9bd; }"); */
///*   p_fn_prtlin( "    .cNeu        { background-color:#fcfce0; }"); */
///*   p_fn_prtlin( "    .cNeu        { background-color:#e6fbda; }"); */
///*   p_fn_prtlin( "      background-color: #fcfce0;"); */
///*   p_fn_prtlin( "    .cRed        { background-color:#ff98a8; }"); */
///*   p_fn_prtlin( "    .cRed        { background-color:#bbf699; }"); */
///*   p_fn_prtlin( "    .cRe2        { background-color:#ff4477; }"); */
///*   p_fn_prtlin( "    .cRe2        { background-color:#a3f275; }"); */
//
///*   p_fn_prtlin( "    .cGr2        { background-color:#a3f275; }"); */
///*   p_fn_prtlin( "    .cGre        { background-color:#a3f275; }"); */
///*   p_fn_prtlin( "    .cNeu        { background-color:#a3f275; }"); */
///*   p_fn_prtlin( "    .cRed        { background-color:#a3f275; }"); */
///*   p_fn_prtlin( "    .cRe2        { background-color:#a3f275; }"); */
//
//
///*   p_fn_prtlin( "    .cGr2,.cGre,.cNeu,.cRed,.cRe2 {background-color: #a3f275;}"); */
////  p_fn_prtlin( "    .cGr2,.cGre,.cNeu,.cRed,.cRe2 {background-color: #d3ffa5;}");
////  p_fn_prtlin( "    .cGr2,.cGre,.cNeu,.cRed,.cRe2 {color: #007aff; background-color: #ffffff}");  // apple blue on  white
////  p_fn_prtlin( "    .cGr2,.cGre,.cNeu,.cRed,.cRe2 {color: #007aff; background-color: #fcfce0}");  // apple blue on  
////  p_fn_prtlin( "    .cGr2,.cGre,.cNeu,.cRed,.cRe2 {                background-color: #fcfce0}");  // black on cHed 
//
////  p_fn_prtlin( "    .cGr2,.cGre,.cNeu,.cRed,.cRe2 {background-color: #d3ffa5;}"); // light green
////  p_fn_prtlin( "    .cPerGreen1 {background-color: #d3ffa5;}");
////  p_fn_prtlin( "    .cPerGreen2 {background-color: #e6ffcc;}");
//
////  p_fn_prtlin( "    .cGr2,.cGre,.cNeu,.cRed,.cRe2 {background-color: #d3ffa5;}"); // light green
////    p_fn_prtlin( "    .cPerGreen1 {background-color: #ceffa0;}");  
////    p_fn_prtlin( "    .cPerGreen2 {background-color: #dfffbb;}"); 
//
////    p_fn_prtlin( "    .cPerGreen1 {background-color: #e5e2c7;}");  // same as cNeu (new)  e5e2c7
//
//
////tn();trn("browser");
//// this is browser   browser   browser   browser   browser   browser   browser   browser   browser   browser   browser  
//
//
//
////    p_fn_prtlin( "    .cPerGreen1 {background-color: #66ff33;}");  // green
////    p_fn_prtlin( "    .cPerGreen2 {background-color: #f0f5f0;}");  // whiteish
//
//    p_fn_prtlin( "    .cAplDarkBlue {background-color: #0080ff;}");  // dark blue chevron color
////    p_fn_prtlin( "    .cPerGreen1 {background-color:   #f2f7ff;}");  // light blue
//    p_fn_prtlin( "    .cPerGreen1 {background-color:   #f0f8ff;}");  // light blue
////    p_fn_prtlin( "    .cPerGreen2 {background-color:   #a0d8ff;}");  // mid blue
//    p_fn_prtlin( "    .cPerGreen2 {background-color:   #c0e0ff;}");  // mid blue
//
//
////    p_fn_prtlin( "    .cPerGreen1 {background-color: #edebd8;}");  // same as cNeu (new)  edebd8
////    p_fn_prtlin( "    .cPerGreen2 {background-color: #edebd8;}");  // same as cNeu (new)  edebd8
//
//  // try  5 green colors again
//  // try  5 green colors again
//  //
////  p_fn_prtlin( "    .cPerGreen5 {background-color: #b9ff82;}");  // 5 different greens
////  p_fn_prtlin( "    .cPerGreen4 {background-color: #ceffa0;}");  // 5 different greens
////  p_fn_prtlin( "    .cPerGreen3 {background-color: #dfffbb;}");  // 5 different greens
////  p_fn_prtlin( "    .cPerGreen2 {background-color: #ecffd3;}");  // 5 different greens
////  p_fn_prtlin( "    .cPerGreen1 {background-color: #f6ffe6;}");  // 5 different greens
//
//
//
//
////  p_fn_prtlin("    .cNam        { color:#3f3ffa;");
//  p_fn_prtlin("    .cNam        { color:#000000;");
//  p_fn_prtlin("                   background-color: #F7ebd1;");
////  p_fn_prtlin("                   font-size: 133%;");
////  p_fn_prtlin("                   font-size: 100%;");
//  p_fn_prtlin("    }");
//
//  p_fn_prtlin( "    table.trait {");          // browser view
//
//  //p_fn_prtlin( "      font-size: 1.7em;");
//  //p_fn_prtlin( "      font-size: 1.2em;");
//
//// smup   p_fn_prtlin( "      font-size: 1.45em;");
////
////  p_fn_prtlin( "      font-size: 110%;");
//  p_fn_prtlin( "      font-size: 100%;");
//
//  p_fn_prtlin( "      margin-left: auto;");
//  p_fn_prtlin( "      margin-right:auto;");
///*   p_fn_prtlin( "      font-family: Andale Mono, Monospacae, Courier New;"); */
//  p_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New;");
//
//  //p_fn_prtlin( "      text-align: left;");
//  p_fn_prtlin( "      text-align: center;");
//
///*   p_fn_prtlin( "      border: 1px solid black;"); */
//  p_fn_prtlin( "      border: none;");
//  p_fn_prtlin( "      border-spacing: 0;");
//  p_fn_prtlin( "      border-collapse: collapse;");
//  p_fn_prtlin( "      border-spacing: 0;");
//
///*   p_fn_prtlin( "      padding-right:2%;"); */
///*   p_fn_prtlin( "      padding-left:2%;"); */
//  p_fn_prtlin( "    }");
//  p_fn_prtlin( "    table.trait td {");
///*   p_fn_prtlin( "      font-family: Andale Mono, Monospace, Courier New;"); */
//  p_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New;");
//
//// smup   p_fn_prtlin( "      white-space: pre;");
//// smup   p_fn_prtlin( "      font-size: 90%;");
////
//  p_fn_prtlin( "      text-align: left;");
//
///*   p_fn_prtlin( "      border: 1px solid black;"); */
//  p_fn_prtlin( "      border: none;");
//  p_fn_prtlin( "      border-spacing: 0;");
//  p_fn_prtlin( "      border-collapse: collapse;");
//  p_fn_prtlin( "      border-spacing: 0;");
//
//  p_fn_prtlin( "      padding-left: 10px; ");
//  p_fn_prtlin( "      padding-right: 10px; ");
//
///*   p_fn_prtlin( "      padding-top: 2px; "); */
///*   p_fn_prtlin( "      padding-bottom: 2px; "); */
//  p_fn_prtlin( "      padding-top: 1px; ");
//  p_fn_prtlin( "      padding-bottom: 1px; ");
//
//  p_fn_prtlin( "    }");
//  p_fn_prtlin( "    table.trait th{");
///*   p_fn_prtlin( "      font-family: Trebuchet MS, Arial, Verdana, sans-serif;"); */
//  p_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New;");
//
//// smup   p_fn_prtlin( "      font-size: 90%;");
////
////  p_fn_prtlin( "      font-size: 85%;");
//
//
///*   p_fn_prtlin( "      padding-left: 10px; "); */
///*   p_fn_prtlin( "      padding-right: 10px; "); */
//  p_fn_prtlin( "      padding: 10px; ");
//
///*   p_fn_prtlin( "      background-color: #e1fdc3 ;"); */
////  p_fn_prtlin( "      background-color: #fcfce0 ;");
//  p_fn_prtlin( "      background-color: #0080ff ;");   // dark apl blue (chevron)
//
//// browser   browser   browser   browser   browser   browser   browser   browser   browser   browser   browser   browser   browser  
//
//
///*   p_fn_prtlin( "      border: 1px solid black;"); */
//  p_fn_prtlin( "      border: none;");
//  p_fn_prtlin( "      border-spacing: 0;");
//
//  p_fn_prtlin( "      text-align: center;");
//  p_fn_prtlin( "    }");
//  p_fn_prtlin( "    table.trait       td { text-align: left; }");
//  p_fn_prtlin( "    table.trait    td+td { text-align: right; }");
//  p_fn_prtlin( "    table.trait td+td+td { text-align: left; }");
//
//  p_fn_prtlin( "  </style>");
//
//    
//// NO   p_fn_prtlin(FAVICON_FOR_SMUP); /* put in favicon */
//
//
// CSS now in per_emcc_my2.html



// CSS now in per_emcc_my2.html
//  p_fn_prtlin( "</head>");
//  p_fn_prtlin( " ");
//  p_fn_prtlin("\n<body>");
//
// CSS now in per_emcc_my2.html

  /*   p_fn_prtlin( "<body background=\"file:///mkgif1g.gif\">"); */
  /*   p_fn_prtlin( "<body background=\"file:///C/USR/RK/html/mkgif1g.gif\">"); */

  /* "Personality"   output here */
/* 
*   sprintf(writebuf, "\n  <h1>Personality</h1>");
*   p_fn_prtlin(writebuf);
*   sprintf(writebuf, "\n  <h2>of %s<br></h2>", arr(0) ); * of Fred  *
*   p_fn_prtlin(writebuf);
*/

/*   sprintf(writebuf, "\n  <h1>Personality <span style=\"font-size:80%%;\">of %s</span><br></h1>", arr(0) );  */
/*   sprintf(writebuf, "\n  <h1>Personality of %s<br></h1>", arr(0) ); * of Fred  * */

//  sprintf(writebuf, "\n  <h1>Personality of <span class=\"cNam\">%s</span><br></h1>", arr(0) ); /* of Fred  */
//trn("in p_fn_output_top_of_html_file() BEFORE  OF TRUMP");
//ksn(gbl_p_person_name);
//  sprintf(writebuf, "\n  <h1>Personality of <span class=\"cNam\">%s</span><br></h1>", gbl_p_person_name); /* of Fred  */
//  p_fn_prtlin(writebuf);

// title now in igo2stars.html

//  p_fn_prtlin("<div><br></div>");
//  p_fn_prtlin( "<h1><span style=\"height: 72px\"></h1>" );
//  p_fn_prtlin( "<div><span style=\"height: 72px\"></div>" );
//  p_fn_prtlin( "<div style=\"height: 12vh\"></div>" );


//  p_fn_prtlin( "<div style=\"height: 15vh\"></div>" ); // NOW IN JS  // add a div of height = height of divNAVB  +  2vh
//  p_fn_prtlin("<div id=\"smup_underNAVB\" style=\"position: relative; width: 100%; \"> </div>" ); // NOW IN JS, height is added (navbar * 1.25) 


// CSS now in per_emcc_my2.html


//  strcpy(gbl_p_person_name, arr(0));

  p_fn_prtlin(" ");

/* b(29); */
} /* end of  p_fn_output_top_of_html_file() */


/* arg in_docin_last_idx  is pointing at the last line written.
* Therefore, the current docin_lines written
* run from index = 0 to index = arg in_docin_last_idx.
*/
void p_docin_get(char *in_line)
{
  
/* tr("in p_docin_get");  ksn(in_line); */
  if (is_first_p_docin_get == 1) global_read_idx = 0;
  else                           global_read_idx++;
  
  is_first_p_docin_get = 0;  /* set to false */

  if (global_read_idx > global_max_docin_idx) {
    p_docin_free();
    rkabort("Error. perhtm.c walked off end of docin_lines array");
  }

  strcpy(in_line, global_docin_lines[global_read_idx] );

  scharout(in_line,'\n');   /* remove newlines */

//tn(); kin(global_read_idx);
//ksn(in_line);

} /* end of p_docin_get */


/* ************************************************************
*
* ************************************************************/
void p_fn_browser_aspect_text(char *aspect_code) {
  int nn;

/* tr("in p_fn_browser_aspect_text()"); */



  // if birth time is 12:01 (unknown birth time> do not print house-derived traits
  // birth time

  // NOTE: house-derived traits in rpt -   position 4 is "2" in trait asp_code
  //        {"p01211", "You can attract many friends and you enjoy working in groups of people ."},
//trn("in p_fn_browser_aspect_text(char *aspect_code) ");
//kd(gbl_birth_hour);   kd(gbl_birth_minute);   kdn(gbl_birth_am_pm);
//ks(aspect_code);
  char aspect_code_desc[32];
  char birth_time_desc[32];

  if (*(aspect_code + 3) == '2') {
    strcpy(aspect_code_desc , "IS house-derived trait");
//trn(" IS house-derived trait");
  }
  if (    gbl_birth_hour   == 12
      &&  (    gbl_birth_minute == 1
           ||  gbl_birth_minute == 0
          )
      &&  gbl_birth_am_pm  == 1 
  ) {
    strcpy(birth_time_desc, "unknown birth time");
//trn(" IS unknown birth time");
  }
  if (    strcmp(aspect_code_desc , "IS house-derived trait") == 0
      &&  strcmp(birth_time_desc, "unknown birth time")       == 0 ) {
//tr("\nDO NOT PRINT ");ksn(aspect_code);
     return;
  }

  //
  // if birth time is 12:01 (unknown birth time> do not print house-derived traits



  nn = binsearch_asp(aspect_code, p_asptab, NKEYS_ASP);

  if (nn < 0) return;  /* do not print any aspect text at all for this aspect_code */

  strcpy(my_aspect_text, p_asptab[nn].asp_text); // my_aspect_text is gbl in perhtm.h


  /* wrap lines at 80 chars with <br> */
/*   put_br_every_n(my_aspect_text, 80);  */

// smup   put_br_every_n(my_aspect_text, 65); 
//

  char para_beg[133];
  char para_end[133];


// CSS now in per_emcc_my2.html
//  strcpy(para_beg, "<table class=\"center\"><tr><td><p>");
//  strcpy(para_beg, "<table class=\"RPPE_table\"><tr><td><p>");
  strcpy(para_beg, "<table class=\"RPPE_table\"><tr><td class=\"RPPE_td\"><p class=\"RPPE_p\">");


// CSS now in per_emcc_my2.html
//  strcpy(para_end, "</p></td></tr><br></table>");
  strcpy(para_end, "</p></td></tr></table>");  // no <br>




  sprintf(writebuf, "  %s%s%s\n", para_beg, my_aspect_text, para_end);

  p_fn_prtlin(writebuf);

}  /* end of p_fn_browser_aspect_text(); */

// smup void p_fn_webview_aspect_text(char *aspect_code){
// smup   int nn;
// smup /* tr("in p_fn_webview_aspect_text()"); */
// smup 
// smup   nn = binsearch_asp(aspect_code, p_asptab, NKEYS_ASP);
// smup 
// smup   if (nn < 0) return;  /* do not print any aspect text at all  */
// smup 
// smup   strcpy(my_aspect_text, p_asptab[nn].asp_text);
// smup 
// smup   /* wrap lines at 80 chars with <br> */
// smup   /*   put_br_every_n(my_aspect_text, 80);  */
// smup   /*   put_br_every_n(my_aspect_text, 65);  */
// smup //  put_br_every_n(my_aspect_text, 40);          // <=====----
// smup 
// smup //tn();ksn(my_aspect_text);
// smup 
// smup   // print lines in my_aspect_text wrapped to line_not_longer_than_this
// smup   // 
// smup   char *pNewWord;
// smup   int len_new_word, lenbuf, line_not_longer_than_this;
// smup   char mybuf[8192];
// smup 
// smup   line_not_longer_than_this = 40;
// smup   strcpy(mybuf, "");
// smup 
// smup   sprintf(writebuf, "fill|before para");
// smup   p_fn_prtlin(writebuf);
// smup 
// smup   // NOTE here that strtok overwrites my_aspect_text to get the words,
// smup   pNewWord = strtok (my_aspect_text, " ");  /* get ptr to first word */
// smup 
// smup   while (pNewWord != NULL)  /* for all words */
// smup   {
// smup     lenbuf       = (int)strlen(mybuf);
// smup     len_new_word = (int)strlen(pNewWord);
// smup 
// smup     if (lenbuf + len_new_word >= line_not_longer_than_this) {
// smup 
// smup       while (strlen(mybuf) < line_not_longer_than_this) { // add spaces at end to fill up to line_not_longer_than_this  chars
// smup         sprintf(mybuf, "%s ", mybuf);  // add a space at the end
// smup       }
// smup       sprintf(writebuf, "para|  %s",  mybuf);
// smup       p_fn_prtlin(writebuf);
// smup       
// smup       strcpy(mybuf, "");                    /* init  mybuf */
// smup     } /* write out since line too long */
// smup 
// smup     sprintf(mybuf, "%s%s%s", mybuf, pNewWord, " "); /* add new word to mybuf */
// smup 
// smup     pNewWord = strtok (NULL, " ");                  /* get ptr to next word */
// smup 
// smup   }  /* for all words */
// smup 
// smup   /* here no more words in aspect desc (mybuf has last line to add) */
// smup   if (strlen(mybuf) != 0) {
// smup 
// smup     mybuf[ strlen(mybuf) - 1] = '\0'; /* but remove sp at end */
// smup 
// smup     while (strlen(mybuf) < line_not_longer_than_this) { // add spaces at end to fill up to line_not_longer_than_this  chars
// smup       sprintf(mybuf, "%s ", mybuf);  // add a space at the end
// smup     }
// smup     sprintf(writebuf, "para|  %s",  mybuf);
// smup     p_fn_prtlin(writebuf);
// smup   }
// smup   //
// smup   // end of print lines in my_aspect_text wrapped to line_not_longer_than_this
// smup 
// smup } // end of  p_fn_webview_aspect_text()
//


//
////  // wrap: take a long input line and wrap it into multiple lines
////  void wrap(char s[], const int wrapline)
////  {
//      int i, k, wraploc, lastwrap;
//
//      lastwrap = 0; // saves character index after most recent line wrap
//      wraploc = 0; // used to find the location for next word wrap
//
//      for (i = 0; my_aspect_text[i] != '\0'; ++i, ++wraploc) {
//
//          if (wraploc >= wrapline) {
//              for (k = i; k > 0; --k) {
//                  // make sure word wrap doesn't overflow past maximum length
//                  if (k - lastwrap <= wrapline && my_aspect_text[k] == ' ') {
//                      my_aspect_text[k] = '\n';
//                      lastwrap = k+1;
//                      break;
//                  }
//              }
//              // wraploc = 0;
//              wraploc = i-lastwrap;
//          }
//      } // end main loop
//
////      for (i = 0; i < wrapline; ++i) printf(" ");
////      printf("|\n");
////      printf("%s\n", my_aspect_text);
////  }
//ksn(my_aspect_text); tn();
//
//      sprintf(writebuf, "para|%s",  my_aspect_text);
//      p_fn_prtlin(writebuf);
//





/* show "stars" in graph as green line
*  Must change all "*" to " ";
*/
void p_fn_prtlin_stars(char *starline)
{
//tr("in p_fn_prtlin_stars()  ");

  char *pBegStar;
  char *pEndStar;
  char beforeStars[512];
  char allStars[512];  /* assume stars start at startline[0] */
  char afterStars[512];

  if (sall(starline, " ") == 1) {
    return;
  }

  if (scharcnt(starline, GRH_CHAR) == MAX_STARS) {
    sprintf(writebuf,
      "<span style=\"background-color:#e1fdc3;\">%s</span>", starline);
    p_fn_prtlin(writebuf);   /* write star line here */
    return;
  }


  pBegStar = strchr (starline, GRH_CHAR);
  pEndStar = strrchr(starline, GRH_CHAR);
  if (starline[0] == GRH_CHAR) {
    strcpy(beforeStars, "");
    mkstr(allStars,    pBegStar, pEndStar);
    mkstr(afterStars,  pEndStar + 1, starline + strlen(starline) - 1);
  } else {
    mkstr(beforeStars, starline, pBegStar - 1);
    mkstr(allStars,    pBegStar, pEndStar);
    strcpy(afterStars, "");
  }

  sprintf(writebuf,
    "%s<span style=\"background-color:#e1fdc3;\">%s</span>%s",
    beforeStars,
    allStars,
    afterStars
  ); 

//ksn(writebuf);
  p_fn_prtlin(writebuf);   /* write star line here */

} /* end of p_fn_prtlin_stars() */

void p_fn_prtlin(char *lin) {
//tr("in p_fn_prtlin()        ");
  char myEOL[8];
/* tn();
* tn();
* kin(GBL_HTML_HAS_NEWLINES);
* ksn(lin);
* kin(strlen(lin));
*/
  strcpy(myEOL, "\n");
  if (GBL_HTML_HAS_NEWLINES == 1)             strcpy(myEOL, "\n");
  if (GBL_HTML_HAS_NEWLINES == 0) {
/* tn();b(30);trn("calling scharout"); */
/*    scharout(lin,'\n'); */ /* remove newlines */
/* tn();b(31);trn("back from calling scharout"); */
/* ks(lin); */
    if (gbl_we_are_in_PRE_block_content == 1) strcpy(myEOL, "<br>");
    else                                      strcpy(myEOL, "");
  }
/* ksn(myEOL); */
  global_n = sprintf(global_p,"%s%s", lin, myEOL);
//ksn(global_p);

  if (gbl_is_first_p_fn_prtlin == 1) {
    gbl_put_html_here        = 0;  // beg of js malloc'd mem
    gbl_is_first_p_fn_prtlin = 0;  // not first any more
  }

// smup   fput(global_p, global_n, Fp_p_HTML_file);
//
  // char *gbl_space_for_HTML_per; // space malloc'ed in js,  passed into mamb_report_personality(), then here
  //
  // e.g.  memcpy(out_rank_lines[*out_rank_line_idx], &line, sizeof(struct rank_report_line));
  memcpy(gbl_space_for_HTML_per + gbl_put_html_here, global_p, global_n);
//  char *tempptr;
//  int tempint;
//  void *tempptr = memcpy(gbl_space_for_HTML_per, global_p, global_n);
//    gbl_space_for_HTML_per = strncpy(gbl_space_for_HTML_per + gbl_put_html_here, global_p, global_n);
//    strncpy(gbl_space_for_HTML_per + gbl_put_html_here, global_p, global_n);

  gbl_put_html_here = gbl_put_html_here + global_n;
//tn();
//kin(gbl_put_html_here);
//ksn(gbl_space_for_HTML_per);

// smup <.>
} 


void p_fn_prtlin_aspect(char *lin) {  /* no \n at end  ( UNUSED ) */
//tr("in p_fn_prtlin_aspect() ");
  global_n = sprintf(global_p,"%s", lin);
//ksn(global_p);

// smup fput(global_p, global_n, Fp_p_HTML_file);
  memcpy(gbl_space_for_HTML_per + gbl_put_html_here, global_p, global_n);
}  

// smup <.>
//
// smup 
// smup /* ----------------------- */
// smup #define DOCIN_ARRAY_MAX 512  
// smup char *docin_lines[DOCIN_ARRAY_MAX];
// smup int   docin_idx;
// smup char  errbuf[256];
// smup void p_docin_put(char *line, int length);
// smup void p_docin_free(void); 
// smup int docn;
// smup char *docp = &Swk[0];
// smup /* ----------------------- */
// smup //
// smup 
// smup /* add a line to the array of docin_lines
// smup *  replaces this:  fput(p,n,Fp_docin_file); 
// smup *  
// smup *  eg 1
// smup *  * fput(p,n,Fp_docin_file); * 
// smup * p_docin_put(docp,docn);
// smup *    
// smup *  eg 2
// smup *  *fprintf(pFP_DOCIN_FILE,"\n[end_program]\n"); *
// smup *  ndoc = sprintf(p,"\n[end_program]\n");
// smup *  p_docin_put(docp, docn);
// smup */
// smup void p_docin_put(char *line, int length)
// smup {
// smup   
// smup // smup   if (strcmp(gbl_output_instructions, "no output, csv string only") == 0) return; 
// smup 
// smup   if (is_first_p_docin_put == 1) docin_idx = 0;
// smup   else                           docin_idx++;
// smup 
// smup   docin_lines[docin_idx] = malloc(length + 1);
// smup 
// smup   if (docin_lines[docin_idx] == NULL) {
// smup     sprintf(errbuf, "malloc failed, arridx=%d, linelen=%d, line=[%s]\n",
// smup       docin_idx, length, line);
// smup     rkabort(errbuf);
// smup   }
// smup 
// smup   strcpy(docin_lines[docin_idx], line);
// smup 
// smup   is_first_p_docin_put = 0;  /* set to no */
// smup   
// smup   /* When this function finishes,
// smup   * the index docin_idx points at the last line written.
// smup   * Therefore, the current docin_lines written
// smup   * run from index = 0 to index = docin_idx. (see p_docin_free() below)
// smup   */
// smup }
// smup 
// smup /* Free the memory allocated for every member of docin_lines array.
// smup */
// smup void p_docin_free(void)
// smup {
// smup   int i;
// smup /* tn(); trn("in p_docin_free()");ki(docin_idx); */
// smup /* tn(); */
// smup   for (i = 0; i <= docin_idx; i++) {
// smup     free(docin_lines[i]);    docin_lines[i] = NULL;
// smup   }
// smup   docin_idx = 0;  /* pts to last array index populated */
// smup }
// smup 
//
// smup <.>
//


#ifdef PUT_BACK_COMMENTED_OUT_STUFF /****************************************/
* void do_orig_trait_graph(void)
* {
* int i;
* 
*   /*  read until [beg_graph]
*    */
*   for (i=0; ; i++) {
*     p_docin_get(doclin);
*     if (strstr(doclin, "[beg_graph]") != NULL) break;
*   }
* 
*   p_fn_prtlin("  <div> Stand out character traits.</div>");
*  
*   p_fn_prtlin("<pre>");  /* start of graphs */
* 
*   gbl_we_are_in_PRE_block_content = 1;  /* true */
* 
*   p_fn_prtlin("  ");
* 
*   p_fn_prtlin("          less important                   important                     remarkable ");
*   p_fn_prtlin("               |                           |                             |          ");
*   p_fn_prtlin("  ");
*   p_fn_prtlin("  <span style=\"background-color:#fdfbe1\">ASSERTIVE </span> competitive, confident, enthusiastic                                     ");
* 
* 
*   /* ================================================================= */
*   /*  read until [beg_agrsv]   */
*   for (i=0; ; i++) {
*     p_docin_get(doclin);
*     if (strstr(doclin, "[beg_agrsv]") != NULL) break;
*   }
* 
*   for (i=0; ; i++) {  /* print until [end_agrsv] */
*     p_docin_get(doclin);
*     if (strstr(doclin, "[end_agrsv]") != NULL) break;
* 
*     scharout(doclin, '|');  /* remove pipes (for old sideline)    */
*     p_fn_prtlin_stars(doclin);  
*   }
*   p_fn_prtlin("  ");
* 
*   /* ================================================================= */
* 
*   /* ================================================================= */
*   for (i=0; ; i++) {
*     p_docin_get(doclin);
*     if (strstr(doclin, "[beg_sensi]") != NULL) break;
*   }
* 
*   p_fn_prtlin("  <span style=\"background-color:#fdfbe1\">EMOTIONAL </span> protective, sensitive, intuitive,                                        ");
* 
*   for (i=0; ; i++) {  /* print until [end_sensi] */
*     p_docin_get(doclin);
*     if (strstr(doclin, "[end_sensi]") != NULL) break;
*     scharout(doclin, '|');  /* remove pipes (for old sideline)    */
*     p_fn_prtlin_stars(doclin);  
*   }
*   p_fn_prtlin("  ");
* 
*   /* ================================================================= */
*   for (i=0; ; i++) {
*     p_docin_get(doclin);
*     if (strstr(doclin, "[beg_restl]") != NULL) break;
*   }
* 
*   p_fn_prtlin("  <span style=\"background-color:#fdfbe1\">RESTLESS </span> versatile, changeable, drawn to new things                                ");
* 
*   for (i=0; ; i++) {
*     p_docin_get(doclin);
*     if (strstr(doclin, "[end_restl]") != NULL) break;
*     scharout(doclin, '|');  /* remove pipes (for old sideline)    */
*     p_fn_prtlin_stars(doclin);  
*   }
*   p_fn_prtlin("  ");
* 
*   /* ================================================================= */
*   for (i=0; ; i++) {
*     p_docin_get(doclin);
*     if (strstr(doclin, "[beg_earth]") != NULL) break;
*   }
* 
*   p_fn_prtlin("  <span style=\"background-color:#fdfbe1\">DOWN-TO-EARTH </span> stable, practical, dependable                                        ");
* 
*   for (i=0; ; i++) { 
*     p_docin_get(doclin);
*     if (strstr(doclin, "[end_earth]") != NULL) break;
*     scharout(doclin, '|');  /* remove pipes (for old sideline)    */
*     p_fn_prtlin_stars(doclin);  
*   }
*   p_fn_prtlin("  ");
* 
*   /* ================================================================= */
*   for (i=0; ; i++) {
*     p_docin_get(doclin);
*     if (strstr(doclin, "[beg_sexdr]") != NULL) break;
*   }
* 
*   p_fn_prtlin("  <span style=\"background-color:#fdfbe1\">DRIVE </span> intense, passionate, relentless                                              ");
* 
*   for (i=0; ; i++) { 
*     p_docin_get(doclin);
*     if (strstr(doclin, "[end_sexdr]") != NULL) break;
*     scharout(doclin, '|');  /* remove pipes (for old sideline)    */
*     p_fn_prtlin_stars(doclin);  
*   }
*   p_fn_prtlin("  ");
* 
*   /* ================================================================= */
* /* me and my big mouth   removed jun2013
* */
* #ifdef PUT_BACK_COMMENTED_OUT_STUFF /****************************************/
* *   for (i=0; ; i++) {
* *     p_docin_get(doclin);
* *     if (strstr(doclin, "[beg_bgmth]") != NULL) break;
* *   }
* * 
* * /*   p_fn_prtlin(" ME AND MY BIG MOUTH                                                                             ");
* * */
* *   p_fn_prtlin("  <span style=\"background-color:#fdfbe1\">ME AND MY BIG MOUTH </span>  talky, chat-loving, forthcoming                               ");
* * 
* *   for (i=0; ; i++) {
* *     p_docin_get(doclin);
* *     if (strstr(doclin, "[end_bgmth]") != NULL) break;
* * /*     p_fn_prtlin(doclin); */
* *     scharout(doclin, '|');  /* remove pipes (for old sideline)    */
* *     p_fn_prtlin_stars(doclin);  
* *   }
* *   p_fn_prtlin("  ");
* * /*   p_fn_prtlin(" A high score shows a talky person who loves to chat and might talk first and think later.       ");
* * *   p_fn_prtlin("                                                                                                 ");
* * *   p_fn_prtlin("                                                                                                 ");
* * */
* #endif /* ifdef PUT_BACK_COMMENTED_OUT_STUFF ********************************/
* 
*   /* ================================================================= */
*   for (i=0; ; i++) {
*     p_docin_get(doclin);
*     if (strstr(doclin, "[beg_upndn]") != NULL) break;
*   }
* 
*   p_fn_prtlin("  <span style=\"background-color:#fdfbe1\">UPS AND DOWNS IN LIFE </span> having very high ups and very low downs                      ");
* 
*   for (i=0; ; i++) {
*     p_docin_get(doclin);
*     if (strstr(doclin, "[end_upndn]") != NULL) break;
*     scharout(doclin, '|');  /* remove pipes (for old sideline)    */
*     p_fn_prtlin_stars(doclin);  
*   }
*   p_fn_prtlin("  ");
*   p_fn_prtlin("  ");
* 
* 
*   /* read until
*   */
*   for (i=0; ; i++) {
*     p_docin_get(doclin);
*     if (strstr(doclin, "[end_graph]") != NULL) break;
*   }
* 
*   gbl_we_are_in_PRE_block_content = 0;  /* false */
*   p_fn_prtlin("</pre>\n");
* 
* } /* end of do_orig_trait_graph(void) */
#endif /* ifdef PUT_BACK_COMMENTED_OUT_STUFF ********************************/



/* ============================================================================ */
void do_benchmark_trait_graph(void)
{
/* ============================================================================ */
  int i;
//trn("\nin do_benchmark_trait_graph(void)  trait table collected into trait_lines here !!! - NOT printed yet  (see bottom) */"); 
trn("in do_benchmark_trait_graph(void)  trait table collected into trait_lines here !!! - NOT printed yet  (see bottom) */"); 


  /* start the graph (now table  201309) 
  */

/*   p_fn_prtlin(" <div><br></div>"); */
/*   p_fn_prtlin("  <table class=\"trait\">"); */
/*   p_fn_prtlin("    <tr> <th>Trait</th> <th>Score</th> <th>Influence</th> </tr>"); */


  /* 1. add the 5 benchmark lines to array (they will sort in themselves)
  * 1b. add the 6 trait lines to array 
  *  2. sort array of structs   (by score,trait)
  *  3. print html
  */
  add_all_benchmark_lines();

//  int score_I;
//    //    75    95
//    //  A 1.5   2.0
//    //  R 1.3   1.5
//    //  P 0.7   1.2
//    //  E 0.5   0.8 
//    //
//  double increaseFactor = 0.0;
//  double totTraitSCORE;
//  totTraitSCORE = 0.0;

  /*  read until [beg_agrsv]   */
  for (i=0; ; i++) {
    p_docin_get(doclin);
    if (strstr(doclin, "[beg_agrsv]") != NULL) break;
  }

  for (i=0; ; i++) {  /* print until [end_agrsv] */
    p_docin_get(doclin);
    if (strstr(doclin, "[end_agrsv]") != NULL) break;

    strcpy(trait_lines[5].trait, "Assertive");
    strcpy(trait_lines[5].score, doclin);
    strcpy(trait_lines[5].influence, "");
//
//    // convert score to int  and  add to total
//    score_I = atoi(doclin);
//    increaseFactor = 0.0;
//    if(score_I >= 75  && score_I <  90 )  increaseFactor = 1.5 ;
//    if(                  score_I >= 90 )  increaseFactor = 2.0 ;
//    totTraitSCORE = totTraitSCORE + score_I + (score_I * increaseFactor) ;
////tn();tr("Assertive");kdn(totTraitSCORE );
////kin(score_I); kd(increaseFactor); kdn(score_I + (score_I * increaseFactor)) ;
//tn();tr("Assertive");kdn(increaseFactor); 
//    // convert score to int  and  add to total
  }

  for (i=0; ; i++) {
    p_docin_get(doclin);
    if (strstr(doclin, "[beg_sensi]") != NULL) break;
  }

  for (i=0; ; i++) { 
    p_docin_get(doclin);
    if (strstr(doclin, "[end_sensi]") != NULL) break;

    strcpy(trait_lines[6].trait, "Emotional");
    strcpy(trait_lines[6].score, doclin);
    strcpy(trait_lines[6].influence, "");

//    score_I = atoi(doclin);
//    increaseFactor = 0.0;
//    if(score_I >= 75  && score_I <  90 )  increaseFactor = 0.5 ;
//    if(                  score_I >= 90 )  increaseFactor = 0.8 ;
//    totTraitSCORE = totTraitSCORE + score_I + (score_I * increaseFactor) ;
////tn();tr("Emotional");kdn(totTraitSCORE );
////kin(score_I); kd(increaseFactor); kdn(score_I + (score_I * increaseFactor)) ;
//tn();tr("Emotional");kdn(increaseFactor); 
  }

  for (i=0; ; i++) {
    p_docin_get(doclin);
    if (strstr(doclin, "[beg_restl]") != NULL) break;
  }

  for (i=0; ; i++) {
    p_docin_get(doclin);
    if (strstr(doclin, "[end_restl]") != NULL) break;

    strcpy(trait_lines[7].trait, "Restless");
    strcpy(trait_lines[7].score, doclin);
    strcpy(trait_lines[7].influence, "");

//
////    score_I = atoi(trait_lines[7].score);
////    totTraitSCORE = totTraitSCORE +  score_I ;
//    score_I = atoi(doclin);
//    increaseFactor = 0.0;
//    if(score_I >= 75  && score_I <  90 )  increaseFactor = 1.3 ;
//    if(                  score_I >= 90 )  increaseFactor = 1.5 ;
//    totTraitSCORE = totTraitSCORE + score_I + (score_I * increaseFactor) ;
////tn();tr("Restless");kdn(totTraitSCORE );
////kin(score_I); kd(increaseFactor); kdn(score_I + (score_I * increaseFactor)) ;
//tn();tr("Restless");kdn(increaseFactor); 
  }

  for (i=0; ; i++) {
    p_docin_get(doclin);
    if (strstr(doclin, "[beg_earth]") != NULL) break;
  }

  for (i=0; ; i++) { 
    p_docin_get(doclin);
    if (strstr(doclin, "[end_earth]") != NULL) break;

    strcpy(trait_lines[8].trait, "Down-to-earth");
    strcpy(trait_lines[8].score, doclin);
    strcpy(trait_lines[8].influence, "");

//    score_I = atoi(trait_lines[8].score);
//    totTraitSCORE = totTraitSCORE +  score_I ;
////tn();ki(score_I); 
////trn("Down-to-earth");kdn(totTraitSCORE );
//tn();tr("Down-to-earth");
  }

  for (i=0; ; i++) {
    p_docin_get(doclin);
    if (strstr(doclin, "[beg_sexdr]") != NULL) break;
  }

  for (i=0; ; i++) { 
    p_docin_get(doclin);
    if (strstr(doclin, "[end_sexdr]") != NULL) break;

    strcpy(trait_lines[9].trait, "Passionate");
    strcpy(trait_lines[9].score, doclin);
    strcpy(trait_lines[9].influence, "");

//
////    score_I = atoi(trait_lines[9].score);
////    totTraitSCORE = totTraitSCORE +  score_I ;
//    score_I = atoi(doclin);
//    increaseFactor = 0.0;
//    if(score_I >= 75  && score_I <  90 )  increaseFactor = 0.7 ;
//    if(                  score_I >= 90 )  increaseFactor = 1.2 ;
//    totTraitSCORE = totTraitSCORE + score_I + (score_I * increaseFactor) ;
//tn();tr("Passionate");kdn(increaseFactor); 
////kdn(totTraitSCORE );
////kin(score_I); kdn(score_I + (score_I * increaseFactor)) ;
  }

  for (i=0; ; i++) {
    p_docin_get(doclin);
    if (strstr(doclin, "[beg_upndn]") != NULL) break;
  }

  for (i=0; ; i++) {
    p_docin_get(doclin);
    if (strstr(doclin, "[end_upndn]") != NULL) break;

//    strcpy(trait_lines[10].trait, "Ups and Downs");
//    strcpy(trait_lines[10].score, doclin);
//    strcpy(trait_lines[10].influence, "");
  }

//
//tr("collect tts");ks(gbl_p_person_name);kdn(totTraitSCORE );
//
////
////// smup FILE *Fp_p_HTML_file;
////// smup   if ( (Fp_p_HTML_file = fopen(in_html_filename, "w")) == NULL ) {
////// smup       //fprintf(stderr,"fopen() error=[%s]\n", strerror(errno));
////// smup       rkabort("Error  on   perhtm.c.  fopen().");
////// smup   }
//////
////FILE *Fp_p_MYST_log;
////Fp_p_MYST_log = fopen("MYST_log", "a");
////fprintf(Fp_p_MYST_log,"MYST|%s=%d\n", gbl_p_person_name, totTraitSCORE );
////
////
//
//    strcpy(trait_lines[10].trait, "Mystery trait");
////    strcpy(trait_lines[9].score, doclin);
//    sprintf(trait_lines[10].score, "%d", (int)totTraitSCORE );
//    strcpy(trait_lines[10].influence, "");
//

  /* read until
  */
  for (i=0; ; i++) {
    p_docin_get(doclin);
    if (strstr(doclin, "[end_graph]") != NULL) break;
  }


  // JUST BEFORE SORTin trait_lines ...
  // for MOSM, add "??" trait score

  // for test
  //  strcpy(trait_lines[10].score, "75");
  //  strcpy(trait_lines[10].trait, "??");
  //  strcpy(trait_lines[10].influence, "" );

      // fyi
        //  itbuff=[idx=0 score=[90] trait=[zzzzzzzzzzzz] influence=[Very High]]__
        //  itbuff=[idx=1 score=[75] trait=[zzzzzzzzzzzz] influence=[High]]__
        //  itbuff=[idx=2 score=[71] trait=[Down-to-earth] influence=[]]__
        //  itbuff=[idx=3 score=[57] trait=[Assertive] influence=[]]__
        //  itbuff=[idx=4 score=[50] trait=[zzzzzzzzzzzz] influence=[Average]]__
        //  itbuff=[idx=5 score=[38] trait=[Passionate] influence=[]]__
        //  itbuff=[idx=6 score=[25] trait=[            ] influence=[Low]]__
        //  itbuff=[idx=7 score=[25] trait=[Emotional] influence=[]]__
        //  itbuff=[idx=8 score=[13] trait=[Restless] influence=[]]__
        //  itbuff=[idx=9 score=[10] trait=[            ] influence=[Very Low]]__
        //  itbuff=[idx=10 score=[] trait=[] influence=[]]__                      
        //

  // get MOSM_trait_scores_CSV  to use for function C_calc_MOSM_score_1_99_for( arg_trait_scores_CSV )  // arg_trait_scores_CSV is 5 PR scores like "56,34,08,13,87"
  char MOSM_trait_scores_CSV[128]; 
  char imbuff[128];
  int  im;
  int  numWritten;
  numWritten = 0;
  for (im=0; im < 11; im++) {

    if ( strlen(trait_lines[im].influence) != 0 )  continue;

    sprintf(imbuff, "%02d", atoi( trait_lines[im].score ) ); 
    if (numWritten == 0) sprintf(MOSM_trait_scores_CSV, "%s"                          , imbuff);
    else                 sprintf(MOSM_trait_scores_CSV, "%s,%s", MOSM_trait_scores_CSV, imbuff);
//ksn(MOSM_trait_scores_CSV);
    numWritten = numWritten + 1;
    if (numWritten == 5) break;
  }
//ksn(MOSM_trait_scores_CSV);
  // get MOSM_trait_scores_CSV  to use for function C_calc_MOSM_score_1_99_for( arg_trait_scores_CSV )  // arg_trait_scores_CSV is 5 PR scores like "56,34,08,13,87"



  int MOSM_score_1_99;
  MOSM_score_1_99 = C_calc_MOSM_score_1_99_for(MOSM_trait_scores_CSV); // arg_trait_scores_CSV is 5 PR scores like "56,34,08,13,87"

//  MOSM_score_1_99 = 7; // for test

  sprintf(imbuff, "%02d", MOSM_score_1_99);
//ksn(imbuff);
  strcpy(trait_lines[10].score,     imbuff);  // put in the MOSM_score_1_99
//  strcpy(trait_lines[10].trait,     "??"  );
  strcpy(trait_lines[10].trait,     "Zing"  );
  strcpy(trait_lines[10].influence, ""    );



  /* sort the trait_lines by score,trait
  */
  qsort(
    trait_lines,
    11,           /* number of elements */
//    12,           /* number of elements */
    sizeof(struct trait_table_line),
    (compareFunc_trait)Func_compare_trait_line_scores
  );




// for test show all trait_lines
//
//struct trait_table_line {
//  char    trait[16];
//  char    score[6];
//  char    influence[16];
//};
//struct trait_table_line trait_lines[12];  /* need 11 */
int it;
char itbuff[1024];
//tn();trn("after sort");
//for (it=0; it < 11; it++) {
//  sprintf(itbuff, "idx=%d score=[%s] trait=[%s] influence=[%s]",
//  it,
//  trait_lines[it].score,
//  trait_lines[it].trait,
//  trait_lines[it].influence  );
//ksn(itbuff);
//}
//tn();






      //    in write_html_for_trait_table())__
      //    _i=[0]___trait_lines[i].score=[90]___trait_lines[i].trait=[zzzzzzzzzzzz]__
      //    _i=[1]___trait_lines[i].score=[75]___trait_lines[i].trait=[zzzzzzzzzzzz]__
      //    _i=[2]___trait_lines[i].score=[71]___trait_lines[i].trait=[Down-to-earth]__
      //    _i=[3]___trait_lines[i].score=[57]___trait_lines[i].trait=[Assertive]__
      //    _i=[4]___trait_lines[i].score=[50]___trait_lines[i].trait=[zzzzzzzzzzzz]__
      //    _i=[5]___trait_lines[i].score=[38]___trait_lines[i].trait=[Passionate]__
      //    _i=[6]___trait_lines[i].score=[25]___trait_lines[i].trait=[            ]__
      //    _i=[7]___trait_lines[i].score=[25]___trait_lines[i].trait=[Emotional]__
      //    _i=[8]___trait_lines[i].score=[13]___trait_lines[i].trait=[Restless]__
      //    _i=[9]___trait_lines[i].score=[10]___trait_lines[i].trait=[            ]__
      //    _i=[10]___trait_lines[i].score=[]___trait_lines[i].trait=[]__              
      //
//
// for test show all trait_lines





  // NOTE: done at bottom of report now, instead of the top
    //
    //  //  write_html_for_trait_table(); // write the html for the table
    //  //
    //  if (gbl_are_in_per_htm_webview == 1) write_TBLRPT_trait_data();        /* now TBLRPT */
    //  else                                 write_html_for_trait_table();
    //
  // NOTE: done at bottom of report now, instead of the top

} /* end of do_benchmark_trait_graph() */



int C_calc_MOSM_score_1_99_for(char *arg_trait_scores_CSV )  // arg_trait_scores_CSV is 5 PR scores like "56,34,08,13,87"
{
      //    MOSM  raw scores =     480,416,333,264,200    // magical trait   
      //    BENCHMARK scores =      90, 75, 50, 25, 10    // these are percentile ranks (PRs)
      //
trn("in C perhtm.c   in C_calc_MOSM_score_1_99_for()");
ksn(arg_trait_scores_CSV);
  double score_input;
  double score_power;
  double score_RAW;
  double score_RAW_TOT = 0.0;
  double percentileRank_MOSM;
  int    returnINT;
  char   strbuff[1024];
  int    idxInCSV;
  // take arg_trait_scores_CSV and calc score_RAW_TOT  for this person
  //
  for (idxInCSV = 1; idxInCSV <= 5; idxInCSV++)
  {
//kin(idxInCSV );
        // char *csv_get_field(char *csv_string, char *delim, int want_fieldnum) lb   // fieldnum is one-based
    strcpy(strbuff,  csv_get_field(arg_trait_scores_CSV, ",", idxInCSV )  );
//ksn(strbuff);

    score_input = atof(strbuff);
//kdn(score_input);

    // strategy:
    // score of  1 is   mutliplied by  1
    // score of 99 is   mutliplied by  1.618
    //
    score_power = 1   +   ( (score_input / 99 ) * 0.618 );
//kdn(score_power);

    score_RAW = pow(score_input, score_power);
//kdn(score_RAW);

    score_RAW_TOT = score_RAW_TOT + score_RAW;
//kdn(score_RAW_TOT);
  }
kdn(score_RAW_TOT);


  // turn score_RAW_TOT into a percentile rank score (PR)   turn score_RAW_TOT into a percentile rank score (PR)  
  // here we have score_RAW_TOT for the person
  //
//kdn(score_RAW_TOT );
    // edge cases
    if      (score_RAW_TOT <=    1)                      percentileRank_MOSM =  1; 
    else if (score_RAW_TOT >= 4736)                      percentileRank_MOSM = 99;

    /* return exact hits */
    else if (score_RAW_TOT == 2930)                      percentileRank_MOSM = 90;
    else if (score_RAW_TOT == 2244)                      percentileRank_MOSM = 75;
    else if (score_RAW_TOT == 1418)                      percentileRank_MOSM = 50;
    else if (score_RAW_TOT ==  968)                      percentileRank_MOSM = 25;
    else if (score_RAW_TOT ==  487)                      percentileRank_MOSM = 10;

    else if (score_RAW_TOT <  487 && score_RAW_TOT >    1) percentileRank_MOSM = calc_percentile_rankD(score_RAW_TOT,  487,   1,  10,  1);
    else if (score_RAW_TOT <  968 && score_RAW_TOT >  487) percentileRank_MOSM = calc_percentile_rankD(score_RAW_TOT,  968,  487, 25, 10);
    else if (score_RAW_TOT < 1418 && score_RAW_TOT >  968) percentileRank_MOSM = calc_percentile_rankD(score_RAW_TOT, 1418,  968, 50, 25);
    else if (score_RAW_TOT < 2244 && score_RAW_TOT > 1418) percentileRank_MOSM = calc_percentile_rankD(score_RAW_TOT, 2244, 1418, 75, 50);
    else if (score_RAW_TOT < 2930 && score_RAW_TOT > 2244) percentileRank_MOSM = calc_percentile_rankD(score_RAW_TOT, 2930, 2244, 90, 75);
    else if (score_RAW_TOT < 4736 && score_RAW_TOT > 2930) percentileRank_MOSM = calc_percentile_rankD(score_RAW_TOT, 4736, 2930, 99, 90);
    //
    //  manually calculate CONVERSION   of MOSM raw scores to percentile rank score
  //
  // turn score_RAW_TOT into a percentile rank score (PR)   turn score_RAW_TOT into a percentile rank score (PR)  

//kdn(percentileRank_MOSM);

  returnINT = (int)(percentileRank_MOSM + 0.5);  // round up double

ki(returnINT); trn("return percentileRank_MOSM\n\n");
  return( returnINT );  


} // end of C_calc_MOSM_score_1_99_for()


    //
    ///* e.g. int calculated_percentile_rank(in_score, 41, 18, 25, 10)
    //*  e.g. maps in_score between 41 and 18 to percentile ranks between 25 and 10
    //*/
    //int calc_percentile_rank(int in_score, int sc_hi, int sc_lo, int pr_hi, int pr_lo)
    //{
    //  /* return (10 + ( (25 - 10) *   (in_score - 18) / (41 - 18)  ); */
    //  return (pr_lo + ( (pr_hi - pr_lo) *   (in_score - sc_lo) / (sc_hi - sc_lo) ) );
    //}; /* end of calculated_percentile_rank() */

// make it use doubles D
double calc_percentile_rankD(double in_score, double sc_hi, double sc_lo, double pr_hi, double pr_lo)
{
  /* return (10 + ( (25 - 10) *   (in_score - 18) / (41 - 18)  ); */
  return (pr_lo + ( (pr_hi - pr_lo) *   (in_score - sc_lo) / (sc_hi - sc_lo) ) );
}; 


void write_TBLRPT_trait_data(void) {    /* !!!!  TBLRPT  !!!!!  trait table data output here !!! */

  int i;
  int score_int;
  char rowcolor[128];

  sprintf(writebuf, "fill|filler line #1 at top");
  p_fn_prtlin(writebuf);
  sprintf(writebuf, "fill|before table head");
  p_fn_prtlin(writebuf);
  sprintf(writebuf, "head|How Much");
  p_fn_prtlin(writebuf);
  sprintf(writebuf, "head|of each trait");
  p_fn_prtlin(writebuf);
  sprintf(writebuf, "head|does %s have?", gbl_p_person_name);
  p_fn_prtlin(writebuf);
  sprintf(writebuf, "fill|after table head1");
  p_fn_prtlin(writebuf);
  sprintf(writebuf, "fill|after table head2");
  p_fn_prtlin(writebuf);

//  for (i=0; i <= 10; i++)    // ups and downs OUT = 1 less
  for (i=0; i <= 9; i++)    // ups and downs OUT = 1 less
  {

    if (strcmp(trait_lines[i].influence, "Very High") == 0) {
//        strcpy(writebuf, "<tr class=\"cPerGreen2\"><td></td><td> 90 </td><td>Great Deal</td></tr>");

//      strcpy(writebuf, "tabl|                          90  Great Deal  ");
//      strcpy(writebuf, "tabl|                    90  Great Deal  ");
      strcpy(writebuf, "tabl|                    90  Great Deal  |cPerGreen1");
      p_fn_prtlin(writebuf);
      continue;
    }
    if (strcmp(trait_lines[i].influence, "High") == 0) {
      strcpy(writebuf, "tabl|                    75  A Lot       |cPerGreen2");
      p_fn_prtlin(writebuf);
      continue;
    }
    if (strcmp(trait_lines[i].influence, "Average") == 0) {
      strcpy(writebuf, "tabl|                    50  Average     |cPerGreen1");
      p_fn_prtlin(writebuf);
      continue;
    }
    if (strcmp(trait_lines[i].influence, "Low") == 0) {
      strcpy(writebuf, "tabl|                    25  Little      |cPerGreen2");
      p_fn_prtlin(writebuf);
      continue;
    }
    if (strcmp(trait_lines[i].influence, "Very Low") == 0) {
      strcpy(writebuf, "tabl|                    10  Very Little |cPerGreen1");
      p_fn_prtlin(writebuf);
      continue;
    }

    // put ROWCOLOR
    score_int = atoi(trait_lines[i].score);
    
//    if (score_int >= 90) strcpy(rowcolor, " class=\"cGr2\"");
//    if (score_int <  90 &&
//        score_int >= 75) strcpy(rowcolor, " class=\"cGre\"");
//    if (score_int <  75 &&
//        score_int >= 25) strcpy(rowcolor, " class=\"cNeu\"");
//    if (score_int <= 25 &&
//        score_int >  10) strcpy(rowcolor, " class=\"cRed\"");
//    if (score_int <= 10) strcpy(rowcolor, " class=\"cRe2\"");
//
    char rowcolorToPass[128];
    if (score_int >= 90)  { strcpy(rowcolor, " class=\"cPerGreen1\""); strcpy(rowcolorToPass, "cPerGreen1"); }
    if (score_int <  90 &&
        score_int >= 75)  { strcpy(rowcolor, " class=\"cPerGreen2\""); strcpy(rowcolorToPass, "cPerGreen2"); }
    if (score_int <  75 &&
        score_int >= 25)  { strcpy(rowcolor, " class=\"cPerGreen1\""); strcpy(rowcolorToPass, "cPerGreen1"); }
    if (score_int <= 25 &&
        score_int >  10)  { strcpy(rowcolor, " class=\"cPerGreen2\""); strcpy(rowcolorToPass, "cPerGreen2"); }
    if (score_int <= 10)  { strcpy(rowcolor, " class=\"cPerGreen1\""); strcpy(rowcolorToPass, "cPerGreen1"); }
    

//    sprintf(writebuf,  "gbl_color_cNeu|  %22s  %2s  %14s",
//      trait_lines[i].trait,
//      trait_lines[i].score,
//      " "
//    );
//    sprintf(writebuf,  "tabl|  %22s  %2s  %14s",
//    sprintf(writebuf,  "tabl|  %16s  %2s  %14s",
//    sprintf(writebuf,  "tabl|  %16s  %2s  %12s",
    sprintf(writebuf,  "tabl|  %16s  %2s  %12s|%s",
      trait_lines[i].trait,
      trait_lines[i].score,
      " ",
      rowcolorToPass
    );
    p_fn_prtlin(writebuf);

  } /* for all 11 table data lines */

  sprintf(writebuf, "fill|before table foot1");
  p_fn_prtlin(writebuf);
  sprintf(writebuf, "fill|before table foot2");
  p_fn_prtlin(writebuf);

//  sprintf(writebuf, "foot|This score does NOT measure");
//  p_fn_prtlin(writebuf);
//  sprintf(writebuf, "foot|challenging or favorable.");
//  p_fn_prtlin(writebuf);

//  sprintf(writebuf, "foot|These scores are all favorable");
//  p_fn_prtlin(writebuf);


//  sprintf(writebuf, "foot|All the traits are favorable.");
//  p_fn_prtlin(writebuf);
  sprintf(writebuf, "fill|after table foot");
  p_fn_prtlin(writebuf);

} /* end of write_TBLRPT_trait_data() */



/* for the sort of array of struct trait_table_line by score and trait
* 
* int Func_compare_trait_line_scores( const void *line1, const void *line2);
* typedef int (*compareFunc_trait) (const void *, const void *);
* 
*/
int Func_compare_trait_line_scores(
  struct trait_table_line *line1,
  struct trait_table_line *line2
)
{

/* trn(" in  Func_compare_trait_line_scores()"); */
  /* sorted high to low
  */

  /* sort is on 1. score   2. trait
  */
  if ( strcmp( line2->score , line1->score ) == 0) {
    return ( strcmp(line1->trait, line2->trait ) );
  } else {
    return ( atoi(line2->score) - atoi(line1->score));
  }
}

/* <table>
* <tr> <th>Trait</th> <th>Score</th> <th>Influence</th> </tr>
* <tr class="cGr2"><td></td><td>373 </td><td>Very High</td></tr>
* <tr><td>Emotional</td><td>477 </td><td></td></tr>
* <tr><td>Passionate</td><td>300 </td><td></td></tr>
* <tr class="cGre"><td></td><td>213 </td><td>High</td></tr>
* <tr><td>Down-to-earth</td><td>150 </td><td></td></tr>
* <tr class="cNeu"><td></td><td>100 </td><td>Median</td></tr>
* <tr class="cRed"><td></td><td>42 </td><td>Low</td></tr>
* <tr><td>Restless</td><td>47 </td><td></td></tr>
* <tr><td>Assertive</td><td>33 </td><td></td></tr>
* <tr class="cRe2"><td></td><td>18 </td><td>Very Low</td></tr>
* <tr><td>Ups and Downs</td><td>15 </td><td></td></tr>
* </table>
*/


    //void write_html_for_trait_table(void);
    //void write_webview_html_for_trait_table(void);

void write_html_for_trait_table(void)
{  // browser version   
// browser   browser   browser   browser   browser   browser   browser   browser   browser   browser   browser   browser   browser  
//trn("\n\nin write_html_for_trait_table()");
trn("in write_html_for_trait_table()");
  int i, score_int;
  char rowcolor[32];
  char rowTrait_ID[32];

/* then, */
/* <div class="centered"> */
/*     <table> */
/*     … */
/*     </table> */
/* </div> */
/* p_fn_prtlin("<div class=\"centered\"> "); */

// browser   browser   browser   browser   browser   browser   browser   browser   browser   browser   browser   browser   browser  


// CSS now in per_emcc_my2.html
//  p_fn_prtlin("<table class=\"trait\" class=\"center\">");
//  p_fn_prtlin("<table class=\"RPPE_tblTrait\" class=\"center\">");



//strcat(string_for_table_only, "<div style=\"overflow-x:auto;\">"); // for responsive table
  p_fn_prtlin( "<div style=\"overflow-x:auto;\">"); // for responsive table



  p_fn_prtlin("<table class=\"RPPE_tblTrait\" style=\"margin-left: auto; margin-right: auto;\" >");

// CSS now in per_emcc_my2.html


  // new col hdr  20150510
//  p_fn_prtlin("<tr> <th>Trait*</th> <th>Score</th> <th></th> </tr>");
//  sprintf(writebuf, "    <tr><th colspan=\"3\" \"><span style=\"font-size: 0.9em; font-weight: normal; \">How Much<br>of each trait<br>does %s have?<br></span></th></tr>", gbl_p_person_name);


// smup   sprintf(writebuf, "    <tr><th colspan=\"3\" \"><span style=\"font-size: 0.9em; font-weight: bold; color: white; background-color: #0080ff; \">How Much<br>of each trait<br>does %s have?<br></span></th></tr>", gbl_p_person_name);
//


// CSS now in per_emcc_my2.html
//  sprintf(writebuf, "    <tr><th colspan=\"3\" \"><span style=\"font-weight: bold; color: white; background-color: #0080ff; \">How Much<br>of each trait<br>does %s have?<br></span></th></tr> ", gbl_p_person_name);
//  sprintf(writebuf, "    <tr><th class=\"RPPE_th_Trait\" colspan=\"3\"><span style=\"font-weight: bold; color: white; background-color: #0080ff; \">How Much<br>of each trait<br>does %s have?<br></span></th></tr> ", gbl_p_person_name);

//  sprintf(writebuf, "    <tr><th class=\"RPPE_th_Trait\"  colspan=\"3\"><span style=\"font-weight: bold; color: white;  \">How Much<br>of each trait<br>does %s have?<br></span></th></tr> ", gbl_p_person_name);
  sprintf(writebuf, "    <tr><th class=\"RPPE_th_Trait\"  colspan=\"3\">How Much<br>of each trait<br>does %s have?<br></th></tr> ", gbl_p_person_name);
// CSS now in per_emcc_my2.html


  p_fn_prtlin(writebuf);


// table footer OUT 20150510
//  // table footer
//  p_fn_prtlin("  <tfoot>");
//  sprintf(writebuf, "    <tr><th colspan=\"3\" \"><span style=\"font-size: 0.9em; font-weight: normal; \">The score from 1 to 99 measures<br>\"how much\" of that trait<br>%s has.<br><br>The score does NOT measure<br>\"good\" or \"bad\".<br></span></th></tr>", gbl_p_person_name);
//  p_fn_prtlin(writebuf);
//  p_fn_prtlin("  </tfoot>");
//
//sprintf(writebuf, "    <tr><th colspan=\"3\" \"><span style=\"font-size: 0.9em; font-weight: normal; \">The score from 1 to 99 measures<br>\"how much\" of that trait<br>%s has.<br><br>The score does NOT measure<br>\"good\" or \"bad\".<br></span></th></tr>", gbl_p_person_name);



// NOTE: no more footer  20191031
//
//
//  // table footer
//  p_fn_prtlin("  <tfoot>");
//    //   sprintf(writebuf, "    <tr><th colspan=\"3\" \"><span style=\"font-size: 0.9em; font-weight: normal; \">The score does NOT measure<br>\"good\" or \"bad\".<br></span></th></tr>", gbl_p_person_name);
//
////    sprintf(writebuf, "    <tr><th colspan=\"3\" \"><span style=\"font-size: 0.9em; font-weight: normal; \">The score does NOT measure<br>\"good\" or \"bad\".<br></span></th></tr>");
////    sprintf(writebuf, "    <tr><th colspan=\"3\" \"><span style=\"font-size: 0.5em; font-weight: normal; \">The score does NOT measure<br>challenging or favorable.<br></span></th></tr>");
//
//
//// smup     sprintf(writebuf, "    <tr><th colspan=\"3\" \"><span style=\"font-size: 0.7em; font-weight: bold; color: white; background-color: #0080ff; \">The score does NOT measure<br>challenging or favorable.<br></span></th></tr>");
////
//
//
//// CSS now in per_emcc_my2.html
////    sprintf(writebuf, "    <tr><th colspan=\"3\" \"><span style=\"font-weight: bold; color: white; background-color: #0080ff; \">The score does NOT measure<br>challenging or favorable.<br></span></th></tr>");
////    sprintf(writebuf, "    <tr><th class=\"RPPE_th_Trait\" colspan=\"3\"><span style=\"font-weight: bold; color: white; background-color: #0080ff; \">The score does NOT measure<br>challenging or favorable.<br></span></th></tr>");
////    sprintf(writebuf, "    <tr><th class=\"RPPE_th_Trait\" colspan=\"3\"><span style=\"font-weight: bold; color: white;  \">The score does NOT measure<br>challenging or favorable.<br></span></th></tr>");
////    sprintf(writebuf, "    <tr><th class=\"RPPE_th_Trait\" colspan=\"3\">The score does NOT measure<br>challenging or favorable.<br></th></tr>");
//
//
//
////    sprintf(writebuf, "    <tr><th class=\"RPPE_th_Trait\" colspan=\"3\">These scores do NOT measure<br>challenging or favorable.<br></th></tr>");
//
////    sprintf(writebuf, "    <tr><th class=\"RPPE_th_Trait\" colspan=\"3\">These scores are all favorable.<br></th></tr>");
//
//
//
//// CSS now in per_emcc_my2.html
//
//
//  p_fn_prtlin(writebuf);
//  p_fn_prtlin("  </tfoot>");
////
////sprintf(writebuf, "    <tr><th colspan=\"3\" \"><span style=\"font-size: 0.9em; font-weight: normal; \">The score from 1 to 99 measures<br>\"how much\" of that trait<br>%s has.<br><br>The score does NOT measure<br>\"good\" or \"bad\".<br></span></th></tr>", gbl_p_person_name);
//
//
//
// NOTE: no more footer  20191031


//for (i=0; i <=10; i++) 
//  for (i=0; i <= 9; i++)     // ups and downs OUT = 1 less
  for (i=0; i <= 10; i++)     // ups and downs OUT = 1 less
  {

    if (strcmp(trait_lines[i].influence, "Very High") == 0) {
//    sprintf(writebuf, "  <tr class=\"cGr2\"><td></td><td>90 </td><td>Very High</td></tr>");
//      sprintf(writebuf, "  <tr class=\"cGr2\"><td></td><td>90 </td><td>Great Deal</td></tr>");

//      if (i % 2 == 0)
//        strcpy(writebuf, "<tr class=\"cPerGreen1\"><td></td><td> 90 </td><td>Great Deal</td></tr>");
//      else
//        strcpy(writebuf, "<tr class=\"cPerGreen2\"><td></td><td> 90 </td><td>Great Deal</td></tr>");


// CSS now in per_emcc_my2.html   (span)
//      strcpy(writebuf, "<tr class=\"cPerGreen1\"><td></td><td> 90 </td><td>Great Deal</td></tr>");
//      strcpy(writebuf, "<tr class=\"cPerGreen1\"><td></td><td class=\"RPPE_td_Trait\" ><span style=\"text-align: right;\"> 90 </span> </td><td style=\"text-align: left; white-space: pre; \"> Great Deal</td></tr>");
      strcpy(writebuf, "<tr class=\"cTrait_90PER\"><td></td><td class=\"RPPE_td_Trait\" ><span style=\"text-align: right;\"> 90 </span> </td><td style=\"text-align: left; white-space: pre; \"> Great Deal</td></tr>");
// CSS now in per_emcc_my2.html

      p_fn_prtlin(writebuf);
      continue;
    }
    if (strcmp(trait_lines[i].influence, "High") == 0) {
//    sprintf(writebuf, "  <tr class=\"cGre\"><td></td><td>75 </td><td>High</td></tr>");
//      sprintf(writebuf, "  <tr class=\"cGre\"><td></td><td>75 </td><td>A Lot</td></tr>");

//      if (i % 2 == 0)
//        strcpy(writebuf, "<tr class=\"cPerGreen1\"><td></td><td> 75 </td><td>A Lot</td></tr>");
//      else
//        strcpy(writebuf, "<tr class=\"cPerGreen2\"><td></td><td> 75 </td><td>A Lot</td></tr>");
//      strcpy(writebuf, "<tr class=\"cPerGreen2\"><td></td><td class=\"RPPE_td_Trait\" ><span style=\"text-align: right;\">  75 </span></td><td style=\"text-align: left; white-space: pre; \"> A Lot</td></tr>");
      strcpy(writebuf, "<tr class=\"cTrait_75PER\"><td></td><td class=\"RPPE_td_Trait\" ><span style=\"text-align: right;\">  75 </span></td><td style=\"text-align: left; white-space: pre; \"> A Lot</td></tr>");


      p_fn_prtlin(writebuf);
      continue;
    }
    if (strcmp(trait_lines[i].influence, "Average") == 0) {
//      sprintf(writebuf, "  <tr class=\"cNeu\"><td></td><td>50 </td><td>Average</td></tr>");

//      if (i % 2 == 0)
//        strcpy(writebuf, "<tr class=\"cPerGreen1\"><td></td><td> 50 </td><td>Average</td></tr>");
//      else
//        strcpy(writebuf, "<tr class=\"cPerGreen2\"><td></td><td> 50 </td><td>Average</td></tr>");
//      strcpy(writebuf, "<tr class=\"cPerGreen1\"><td></td><td class=\"RPPE_td_Trait\" ><span style=\"text-align: right;\">  50 </span></td><td style=\"text-align: left; white-space: pre; \"> Average</td></tr>");
      strcpy(writebuf, "<tr class=\"cTrait_50PER\"><td></td><td class=\"RPPE_td_Trait\" ><span style=\"text-align: right;\">  50 </span></td><td style=\"text-align: left; white-space: pre; \"> Average</td></tr>");

      p_fn_prtlin(writebuf);
      continue;
    }
    if (strcmp(trait_lines[i].influence, "Low") == 0) {
//    sprintf(writebuf, "  <tr class=\"cRed\"><td></td><td>25 </td><td>Low</td></tr>");
//      sprintf(writebuf, "  <tr class=\"cRed\"><td></td><td>25 </td><td>Little</td></tr>");

//      if (i % 2 == 0)
//        strcpy(writebuf, "<tr class=\"cPerGreen1\"><td></td><td> 25 </td><td>Little</td></tr>");
//      else
//        strcpy(writebuf, "<tr class=\"cPerGreen2\"><td></td><td> 25 </td><td>Little</td></tr>");
//      strcpy(writebuf, "<tr class=\"cPerGreen2\"><td></td><td class=\"RPPE_td_Trait\" ><span style=\"text-align: right;\">  25 </span></td><td style=\"text-align: left; white-space: pre; \"> Little</td></tr>");
      strcpy(writebuf, "<tr class=\"cTrait_25PER\"><td></td><td class=\"RPPE_td_Trait\" ><span style=\"text-align: right;\">  25 </span></td><td style=\"text-align: left; white-space: pre; \"> Little</td></tr>");
      p_fn_prtlin(writebuf);
      continue;
    }
    if (strcmp(trait_lines[i].influence, "Very Low") == 0) {
//    sprintf(writebuf, "  <tr class=\"cRe2\"><td></td><td>10 </td><td>Very Low</td></tr>");
//      sprintf(writebuf, "  <tr class=\"cRe2\"><td></td><td>10 </td><td>Very Little</td></tr>");

//      if (i % 2 == 0)
//        strcpy(writebuf, "<tr class=\"cPerGreen1\"><td></td><td> 10 </td><td>Very Little</td></tr>");
//      else
//        strcpy(writebuf, "<tr class=\"cPerGreen2\"><td></td><td> 10 </td><td>Very Little</td></tr>");
//      strcpy(writebuf, "<tr class=\"cPerGreen1\"><td></td><td class=\"RPPE_td_Trait\" ><span style=\"text-align: right;\">  10 </span></td><td style=\"text-align: left; white-space: pre; \"> Very Little </td></tr>");
      strcpy(writebuf, "<tr class=\"cTrait_10PER\"><td></td><td class=\"RPPE_td_Trait\" ><span style=\"text-align: right;\">  10 </span></td><td style=\"text-align: left; white-space: pre; \"> Very Little </td></tr>");

      p_fn_prtlin(writebuf);
      continue;
    }
    

    score_int = atoi(trait_lines[i].score);

    /* put ROWCOLOR
    */
    //    if (score_int >= 90) strcpy(rowcolor, " class=\"cGr2\"");
    //    if (score_int <  90 &&
    //        score_int >= 75) strcpy(rowcolor, " class=\"cGre\"");
    //    if (score_int <  75 &&
    //        score_int >= 25) strcpy(rowcolor, " class=\"cNeu\"");
    //    if (score_int <= 25 &&
    //        score_int >  10) strcpy(rowcolor, " class=\"cRed\"");
    //    if (score_int <= 10) strcpy(rowcolor, " class=\"cRe2\"");
    //

    // put ROWCOLOR
    //
//    if (i % 2 == 0)
//      strcpy(rowcolor, " class=\"cPerGreen1\"");
//    else
//      strcpy(rowcolor, " class=\"cPerGreen2\"");

    // put ROWCOLOR
    //
//    if (score_int >= 90) strcpy(rowcolor, " class=\"cPerGreen1\"");
//    if (score_int <  90 &&
//        score_int >= 75) strcpy(rowcolor, " class=\"cPerGreen2\"");
//    if (score_int <  75 &&
//        score_int >= 25) strcpy(rowcolor, " class=\"cPerGreen1\"");
//    if (score_int <= 25 &&
//        score_int >  10) strcpy(rowcolor, " class=\"cPerGreen2\"");
//    if (score_int <= 10) strcpy(rowcolor, " class=\"cPerGreen1\"");
//
    
    if (score_int >= 90) strcpy(rowcolor, " class=\"cTrait_90PER\"");
    if (score_int <  90 &&
        score_int >= 75) strcpy(rowcolor, " class=\"cTrait_75PER\"");
    if (score_int <  75 &&
        score_int >= 25) strcpy(rowcolor, " class=\"cTrait_50PER\"");
    if (score_int <= 25 &&
        score_int >  10) strcpy(rowcolor, " class=\"cTrait_25PER\"");
    if (score_int <= 10) strcpy(rowcolor, " class=\"cTrait_10PER\"");

    // THIS LINE IS THE SCORE OF THE PERSON
    //

    // determine rowTrait_ID
    //
        // char rowTrait_ID[32];
          //    strcpy(trait_lines[5].trait, "Assertive");
          //    strcpy(trait_lines[6].trait, "Emotional");
          //    strcpy(trait_lines[7].trait, "Restless");
          //    strcpy(trait_lines[8].trait, "Down-to-earth");
          //    strcpy(trait_lines[9].trait, "Passionate");
          //
      if (strcmp(trait_lines[i].trait, "Emotional")     == 0)  strcpy(rowTrait_ID, "rowTrait_ID_E");
      if (strcmp(trait_lines[i].trait, "Assertive")     == 0)  strcpy(rowTrait_ID, "rowTrait_ID_A");
      if (strcmp(trait_lines[i].trait, "Passionate")    == 0)  strcpy(rowTrait_ID, "rowTrait_ID_P");
      if (strcmp(trait_lines[i].trait, "Restless")      == 0)  strcpy(rowTrait_ID, "rowTrait_ID_R");
      if (strcmp(trait_lines[i].trait, "Down-to-earth") == 0)  strcpy(rowTrait_ID, "rowTrait_ID_D");
//      if (strcmp(trait_lines[i].trait, "Mystery trait") == 0)  strcpy(rowTrait_ID, "rowTrait_ID_M");
//      if (strcmp(trait_lines[i].trait, "??")            == 0)  strcpy(rowTrait_ID, "rowTrait_ID_M");
      if (strcmp(trait_lines[i].trait, "Zing")            == 0)  strcpy(rowTrait_ID, "rowTrait_ID_M");
    //
    // determine rowTrait_ID




// CSS now in per_emcc_my2.html
//    sprintf(writebuf,  "  <tr %s><td>%s</td><td>%s </td><td></td></tr>",
//   sprintf(writebuf,  "  <tr %s><td>%s</td><td class=\"RPPE_td_Trait\" ><span ><span ><span style=\"text-align: right;\">  %s </span></td><td></td></tr>",
//   sprintf(writebuf,  "  <tr %s><td>%s</td><td class=\"RPPE_td_Trait\" ><span ><span ><span style=\"text-align: right; font-weight: bold; background-color: white;\">  %s </span></td><td></td></tr>",

//   sprintf(writebuf,  "  <tr %s><td>%s</td><td class=\"RPPE_td_Trait\" ><span ><span ><span style=\"text-align: right; font-weight: bold; background-color: white;\">  %s </span></td><td></td></tr>",
//   sprintf(writebuf,  "  <tr %s><td>%s</td><td class=\"RPPE_td_Trait\" ><span ><span ><span style=\"text-align: right; font-weight: bold; \">  %s </span></td><td></td></tr>",


   sprintf(writebuf,  "  <tr %s><td id=\"%s\" style=\"text-align: right; white-space: pre; \" > %s </td><td class=\"RPPE_td_Trait\" style=\"text-align: right; font-weight: bold; \">  %s </td><td></td></tr>",

      rowcolor,
      rowTrait_ID,
//      "style=\"background-color: white; \" ",
      trait_lines[i].trait,
      trait_lines[i].score
    );
    p_fn_prtlin(writebuf);

  } /* for all 11 table data lines */


//
//  // space at bottom
//  sprintf(writebuf,  "  <tr id=\"botsp\" class=\"cTrait_10PER\"  style=\"line-height: 0.5em; text-align: right; white-space: pre; \" >  </td><td class=\"RPPE_td_Trait\" style=\"text-align: right; font-weight: bold; \">  </td><td></td></tr>");
//  p_fn_prtlin(writebuf);
//




  p_fn_prtlin("</table>");

p_fn_prtlin("</div>");  // for repsonsive div // for responsive table


/* p_fn_prtlin("</div> "); */
// browser   browser   browser   browser   browser   browser   browser   browser   browser   browser   browser   browser   browser  

} /* end of write_html_for_trait_table(void) */  // for browser

//
//void write_webview_html_for_trait_table(void) {   // NOT called ??  20150510
//  int i, score_int;
//  char rowcolor[32];
//
//  p_fn_prtlin("<table class=\"trait\" class=\"center\">");
//    //
///*   p_fn_prtlin("<tr> <th>Trait *</th> <th>Score</th> <th>Benchmark</th> </tr>"); */
////  p_fn_prtlin("<tr> <th>Trait*</th> <th>Score</th> <th></th> </tr>");
//  p_fn_prtlin("<tr> <th>Trait</th> <th>Score</th> <th></th> </tr>");
//
////for (i=0; i <=10; i++) 
//  for (i=0; i <= 9; i++) {   // ups and downs OUT = 1 less
//
//    if (strcmp(trait_lines[i].influence, "Very High") == 0) {
////      sprintf(writebuf, "  <tr class=\"cGr2\"><td></td><td>90 </td><td>Very High</td></tr>");
//      if (i % 2 == 0)
//        strcpy(writebuf, "<tr class=\"cPerGreen1\"><td></td><td> 90 </td><td>Very High</td></tr>");
//      else
//        strcpy(writebuf, "<tr class=\"cPerGreen2\"><td></td><td> 90 </td><td>Very High</td></tr>");
//      p_fn_prtlin(writebuf);
//      continue;
//    }
//    if (strcmp(trait_lines[i].influence, "High") == 0) {
////      sprintf(writebuf, "  <tr class=\"cGre\"><td></td><td>75 </td><td>High</td></tr>");
//      if (i % 2 == 0)
//        strcpy(writebuf, "<tr class=\"cPerGreen1\"><td></td><td> 75 </td><td>High</td></tr>");
//      else
//        strcpy(writebuf, "<tr class=\"cPerGreen2\"><td></td><td> 75 </td><td>High</td></tr>");
//      p_fn_prtlin(writebuf);
//      continue;
//    }
//    if (strcmp(trait_lines[i].influence, "Average") == 0) {
////      sprintf(writebuf, "  <tr class=\"cNeu\"><td></td><td>50 </td><td>Average</td></tr>");
//      if (i % 2 == 0)
//        strcpy(writebuf, "<tr class=\"cPerGreen1\"><td></td><td> 50 </td><td>Average</td></tr>");
//      else
//        strcpy(writebuf, "<tr class=\"cPerGreen2\"><td></td><td> 50 </td><td>Average</td></tr>");
//      p_fn_prtlin(writebuf);
//      continue;
//    }
//    if (strcmp(trait_lines[i].influence, "Low") == 0) {
////      sprintf(writebuf, "  <tr class=\"cRed\"><td></td><td>25 </td><td>Low</td></tr>");
//      if (i % 2 == 0)
//        strcpy(writebuf, "<tr class=\"cPerGreen1\"><td></td><td> 25 </td><td>Low</td></tr>");
//      else
//        strcpy(writebuf, "<tr class=\"cPerGreen2\"><td></td><td> 25 </td><td>Low</td></tr>");
//      p_fn_prtlin(writebuf);
//      continue;
//    }
//    if (strcmp(trait_lines[i].influence, "Very Low") == 0) {
////      sprintf(writebuf, "  <tr class=\"cRe2\"><td></td><td>10 </td><td>Very Low</td></tr>");
//      if (i % 2 == 0)
//        strcpy(writebuf, "<tr class=\"cPerGreen1\"><td></td><td> 10 </td><td>Very Little</td></tr>");
//      else
//        strcpy(writebuf, "<tr class=\"cPerGreen2\"><td></td><td> 10 </td><td>Very Little</td></tr>");
//      p_fn_prtlin(writebuf);
//      continue;
//    }
//    
//
//    score_int = atoi(trait_lines[i].score);
//
//    /* put ROWCOLOR
//    */
//    //    if (score_int >= 90) strcpy(rowcolor, " class=\"cGr2\"");
//    //    if (score_int <  90 &&
//    //        score_int >= 75) strcpy(rowcolor, " class=\"cGre\"");
//    //    if (score_int <  75 &&
//    //
//    ///*         score_int >= 25) strcpy(rowcolor, " class=\"cNeu\""); */
//    //        score_int >  25) strcpy(rowcolor, " class=\"cNeu\"");
//    //
//    //    if (score_int <= 25 &&
//    //        score_int >  10) strcpy(rowcolor, " class=\"cRed\"");
//    //    if (score_int <= 10) strcpy(rowcolor, " class=\"cRe2\"");
//    //
//    if (i % 2 == 0)
//      strcpy(rowcolor, " class=\"cPerGreen1\"");
//    else
//      strcpy(rowcolor, " class=\"cPerGreen2\"");
//
//
//    sprintf(writebuf,  "  <tr %s><td>%s</td><td>%s </td><td></td></tr>",
//      rowcolor,
//      trait_lines[i].trait,
//      trait_lines[i].score
//    );
//    p_fn_prtlin(writebuf);
//
//  } /* for all 11 table data lines */
//
//
//  p_fn_prtlin("</table>");
//
//} // end of  write_webview_html_for_trait_table() 
//
//

void add_all_benchmark_lines(void)
{
/* trn(" in void add_all_benchmark_lines(void)"); */
  strcpy(trait_lines[0].trait, "zzzzzzzzzzzz"); /* sort below ties with 373 */
  strcpy(trait_lines[0].score, "90");
  strcpy(trait_lines[0].influence, "Very High");

  strcpy(trait_lines[1].trait, "zzzzzzzzzzzz"); /* sort below ties with 213 */
  strcpy(trait_lines[1].score, "75");
  strcpy(trait_lines[1].influence, "High");

  strcpy(trait_lines[2].trait, "zzzzzzzzzzzz"); /* sort below ties with 100 */
  strcpy(trait_lines[2].score, "50");
  strcpy(trait_lines[2].influence, "Average");  /* not median */

  strcpy(trait_lines[3].trait, "            "); /* sort above ties with  42 */
  strcpy(trait_lines[3].score, "25");
  strcpy(trait_lines[3].influence, "Low");

  strcpy(trait_lines[4].trait, "            "); /* sort above ties with  18 */
  strcpy(trait_lines[4].score, "10");
  strcpy(trait_lines[4].influence, "Very Low");
}


/* end of perhtm.c */
