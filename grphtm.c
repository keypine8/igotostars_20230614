/* grphtm.c */

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

/* For just_2 rpt, read from input docin_lines string array  
* format and write an html output file
* For group rpts, input is 
*    struct rank_report_line  *in_rank_lines[],
*    int   in_rank_lines_last_idx )
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "rk.h"
#include "rkdebug_externs.h"
#include "grphtm.h"
/* #include "incocoa.h" */

 
//#define GRP_FLAT_CSV_ARRAY_RECSIZ 48
#define GRP_FLAT_CSV_ARRAY_RECSIZ 128

//#define MAX_PERSONS_IN_GROUP 333      /* defined in incocoa.c and grpdoc.c and grphtm.c */
//char gbl_grpFlatArrayOfCSVs[ GRP_FLAT_CSV_ARRAY_RECSIZ *  MAX_PERSONS_IN_GROUP ]; 
char gbl_grpFlatArrayOf_2_CSVs[ GRP_FLAT_CSV_ARRAY_RECSIZ *  2 ];   // for  use in mamb_report_just_2_people()


    //  real   real   real   real   real real   real   real   real   real real   real   real   real   real real   real   real   real   real 
int gbl_RPCO_score;  // for the NEW "real" string_for_table_only   



int get_how_many(char *in_doclin);

int gbl_db_code;
char gbl_are_in_just2[128];  // = "we are in make_html_file_just_2_people"  or not

int  gbl_is_grpone_or_grpall;  //  ensure full color in all lines in case filename has "webview"
char gbl_just2PersonA[64];
char gbl_just2PersonB[64];
char gbl_aspect_code[32];
void g_fn_browser_aspect_text(char *aspect_code);
void g_fn_webview_aspect_text(char *aspect_code);
void  prtRedGreenPlusMinus(int numplusminus, int is_webview_version);

 
int  gbl_kingpin_is_in_group;   /* 0/1 no/yes  for fmt col hdr */
char gbl_g_in_html_filename[2024];


void prtStarsAs2lines(char *writebuf);
//int  gbl_thisIs1stMinusLine; // 0/1 false/true
//int  gbl_thisIsNextMinusLine; // 0/1 false/true  #2, #3, etc...
int  gbl_countMinusLines;     // of consecutive minus lines in star lines

void put_ios_top_of_just2_group_rpt(void); /* just_2 rpt */
char gbl_person_A_first_pair[32];  // for "only html" return
char gbl_person_B_first_pair[32];  // for "only html" return

int  gbl_we_are_in_webview_version;  // 1/0 yes/no

char gbl_ptofview_name[128];   // for point of view line


/* these are in rkdebug.o */
//extern void fopen_fpdb_for_debug(void);
//extern void fclose_fpdb_for_debug(void);


/* #define APP_NAME "Astrology by Measurement" */
/* #define APP_NAME "Me & My BFFs" */
//#define APP_NAME "Me and my BFFs"
/* #define APP_NAME "\"My BFFs and I\"" */
/* file extension for group sharing will be ".mamb" */



  // read from input docin_lines string array
  // format and write an html output file            bbb
  // format and write to js-malloc'd  memory
  //
  char *gbl_space_for_HTML_ju2; // space malloc'ed in js,  passed into mamb_report_personality(), then here



#define GBL_HTML_HAS_NEWLINES 1 
//#define GBL_HTML_HAS_NEWLINES 0

char *gbl_HTML_code_for_ju2;  // gbl smup html code written at this location
int   gbl_is_first_g_fn_prtlin;
int   gbl_put_html_here;



int gbl_we_are_in_PRE_block; /* 1 = yes, 0 = no */
int gbl_avg_score_this_member; /* for report bottom */
char gbl_gfnameHTML[256];




/* rank_report_line array declarations */  /* copied from incocoa.c */
/* trait_report_line array declarations */
#define MAX_SIZE_PERSON_NAME  15
struct trait_report_line {
  int  rank_in_group;
  int  score;
  char person_name[MAX_SIZE_PERSON_NAME+1];
/*  char hex_color[8]; */  /* like "66ff33" */
};
struct rank_report_line {
  int  rank_in_group;
  int  score;
  char person_A[MAX_SIZE_PERSON_NAME+1];
  char person_B[MAX_SIZE_PERSON_NAME+1];
};
struct avg_report_line {
  int  rank_in_group;
  int  avg_score;
  char person_name[MAX_SIZE_PERSON_NAME+1];
/*  char hex_color[8]; */  /* like "66ff33" */
};
struct grp_personality {
  int  avg_score;
  char html_line[2048];
};
struct grp_personality arr_grp_personality[16];
struct grp_personality my_grp_personality;

/* int Func_compare_grp_personality_scores(const void *line1, const void *line2); */
int Func_compare_grp_personality_scores(
  struct grp_personality *score1,
  struct grp_personality *score2  );
typedef int (*compareFunc_grp_per) (const void *, const void *);


/* Define the array of ranking report line data.
*   (Rank  Score  person_a  person_b)
*
*   assuming MAX_PERSONS_IN_GROUP = 250, num pairs max is  31,125 
*   (5 sec to run on pc/gcc , 1 sec on mac/llvm )
*/
//#define MAX_PERSONS_IN_GROUP 200   /* also defined incocoa.c and grpdoc.c */
#define MAX_PERSONS_IN_GROUP 258   /* also defined incocoa.c and grpdoc.c */
#define MAX_IN_RANK_LINE_ARRAY \
( ( (MAX_PERSONS_IN_GROUP * (MAX_PERSONS_IN_GROUP - 1) / 2) ) + 64 )
struct rank_report_line *out_rank_lines[MAX_IN_RANK_LINE_ARRAY];
int out_rank_idx;  /* pts to current line in out_rank_lines */

/* end of rank_report_line array declarations */  /* copied from incocoa.c */



      // NOTE: writebuf2  is names  of person_A  and  person_B 

#define CO_SCORELINE_cGr2 \
      sprintf(writebuf3,\
          "<tr class='cGr2 subjectcss ' >"\
            "<td class='cGr2'></td>"\
            "<td id='scoreCOamt'> %d  </td>"\
            "<td></td>"\
            "<td> %s</td>"\
            "<td><span style='visibility:hidden;'>X</span></td>"\
            "<td></td>"\
          "</tr>"\
        , gbl_RPCO_score\
        , writebuf2\
      );\
      strcat(string_for_table_only, writebuf3); 


#define CO_SCORELINE_cGre \
      sprintf(writebuf3,\
          "<tr class='cGre subjectcss ' >"\
            "<td class='cGre'></td>"\
            "<td id='scoreCOamt'> %d  </td>"\
            "<td></td>"\
            "<td> %s</td>"\
            "<td><span style='visibility:hidden;'>X</span></td>"\
            "<td></td>"\
          "</tr>"\
        , gbl_RPCO_score\
        , writebuf2\
      );\
      strcat(string_for_table_only, writebuf3); 

#define CO_SCORELINE_cNeu \
      sprintf(writebuf3,\
          "<tr class='cNeu subjectcss ' >"\
            "<td class='cNeu'></td>"\
            "<td id='scoreCOamt'> %d  </td>"\
            "<td></td>"\
            "<td> %s</td>"\
            "<td><span style='visibility:hidden;'>X</span></td>"\
            "<td></td>"\
          "</tr>"\
        , gbl_RPCO_score\
        , writebuf2\
      );\
      strcat(string_for_table_only, writebuf3); 

#define CO_SCORELINE_cRed \
      sprintf(writebuf3,\
          "<tr class='cRed subjectcss ' >"\
            "<td class='cRed'></td>"\
            "<td id='scoreCOamt'> %d  </td>"\
            "<td></td>"\
            "<td> %s</td>"\
            "<td><span style='visibility:hidden;'>X</span></td>"\
            "<td></td>"\
          "</tr>"\
        , gbl_RPCO_score\
        , writebuf2\
      );\
      strcat(string_for_table_only, writebuf3); 

#define CO_SCORELINE_cRe2 \
      if (gbl_RPCO_score < 10) strcpy(s1, "&nbsp;"); \
      else                     strcpy(s1, ""); \
      sprintf(writebuf3,\
          "<tr class='cRe2 subjectcss ' >"\
            "<td class='cRe2'></td>"\
            "<td id='scoreCOamt'> %s%d </td>"\
            "<td></td>"\
            "<td> %s</td>"\
            "<td><span style='visibility:hidden;'>X</span></td>"\
            "<td></td>"\
          "</tr>"\
        , s1\
        , gbl_RPCO_score\
        , writebuf2\
      );\
      strcat(string_for_table_only, writebuf3); 






#define CO_BENCHLINE_cGr2 \
      strcat(string_for_table_only,\
        "<tr class='cGr2 benchline'>"\
        "  <td id='tdIMG02zC'></td>"\
        "  <td class='cssBenchmarkText'> 90 </td>"\
        "  <td class='cssBenchmarkText'>Great</td>"\
        "  <td></td>"\
        "  <td></td>"\
        "  <td id='tdIMG02'> </td>"\
        "</tr>"\
      );

#define CO_BENCHLINE_cGre \
      strcat(string_for_table_only,\
        "<tr class='cGre benchline'>"\
        "  <td id='tdIMG04zC'></td>"\
        "  <td class='cssBenchmarkText'> 75  </td>"\
        "  <td class='cssBenchmarkText'>Good</td>"\
        "  <td></td>"\
        "  <td></td>"\
        "  <td id='tdIMG04'> </td>"\
        "</tr>"\
      );

#define CO_BENCHLINE_cNeu \
      strcat(string_for_table_only,\
        "<tr class='cNeu benchline'>"\
        "  <td id='tdIMG06zC'></td>"\
        "  <td class='cssBenchmarkText'> 50  </td>"\
        "  <td class='cssBenchmarkText'>Average</td>"\
        "  <td></td>"\
        "  <td></td>"\
        "  <td id='tdIMG06'> </td>"\
        "</tr>"\
      );


#define CO_BENCHLINE_cRed \
      strcat(string_for_table_only,\
        "<tr class='cRed benchline'>"\
        "  <td id='tdIMG08zC'></td>"\
        "  <td class='cssBenchmarkText'> 25  </td>"\
        "  <td class='cssBenchmarkText'>Stress</td>"\
        "  <td></td>"\
        "  <td></td>"\
        "  <td id='tdIMG08'> </td>"\
        "</tr>"\
      );

#define CO_BENCHLINE_cRe2 \
      strcat(string_for_table_only,\
        "<tr class='cRe2 benchline'>"\
        "  <td id='tdIMG10zC'></td>"\
        "  <td class='cssBenchmarkText'> 10  </td>"\
        "  <td class='cssBenchmarkText'>OMG</td>"\
        "  <td></td>"\
        "  <td></td>"\
        "  <td id='tdIMG10'> </td>"\
        "</tr>"\
      );



int out_rank_idx;  /* pts to current line in out_rank_lines */
char *mamb_csv_arr[2];  /* only 2 persons */

/* in grpdoc.c */
//extern int mamb_report_whole_group(    /* called from cocoa */
//  char *html_file_name,
//  char *group_name,
//
////  char *in_csv_person_arr[],  /* fmt= "Fred,3,21,1987,11,58,1,5,80.34" */
//  char *in_GRP_FLAT_CSV_ARRAY,
//
//  int  num_persons_in_grp,
//                                   //  struct rank_report_line *rank_lines[],
//                                   //  int  *rank_idx,
//  char *instructions,
//  char *string_for_table_only,  /* 1024 chars max (its 9 lines formatted) */
//  char out_group_report_PSVs[],   /* array of output report data to pass to cocoa */
//  int  *out_group_report_idx       /* ptr to int having last index written */
//);
//


      // fyi
      //      char *mamb_report_whole_group(    /* called from cocoa */
      //        char *html_file_name,
      //        char *group_name,
      //        char *in_GRP_FLAT_CSV_ARRAY,
      //        int  num_persons_in_grp,
      //        char *instructions,
      //        char *string_for_table_only, /* 1024 chars max (its 9 lines formatted) */
      //        char *gbm_returnSTRING_work_space   // text data for JS to build html with
      //      );
      //
      //
/* in grpdoc.c */
char *mamb_report_whole_group(    /* called from cocoa */
  char *html_file_name,
  char *group_name,
  char *in_GRP_FLAT_CSV_ARRAY,
  char *num_persons_in_grp,
  char *instructions,
  char *string_for_table_only, /* 1024 chars max (its 9 lines formatted) */
  char *gbm_returnSTRING_work_space   // text data for JS to build html with
);



extern void g_rank_line_free(
  struct rank_report_line *out_rank_lines[],  /* output param returned */
  int rank_line_last_used_idx
);
/* in grpdoc.c */
//extern int  mamb_report_person_in_group(  /* in grpdoc.o */ 
//  char *html_file_name,
//  char *group_name,
//  char *in_csv_person_arr[],
//  int  num_persons_in_grp,
//  char *compare_everyone_with,   /* fmt= "Fred,3,21,1987,11,58,1,5,80.34" */
//  struct rank_report_line *rank_lines[],   /* array of output report data */
//  int  *rank_idx           /* ptr to int having last index written */
//);
//

//extern int  mamb_report_person_in_group(  /* in grpdoc.o */ 
//  char *html_file_name,
//  char *group_name,
//  char *in_csv_person_arr[],
//  int  num_persons_in_grp,
//  char *compare_everyone_with,   /* fmt= "Fred,3,21,1987,11,58,1,5,80.34" */
//  struct rank_report_line *out_rank_lines[],   /* array of output report data */
//  int  *out_rank_line_idx,                     /* ptr to int having last index written */
//  char out_group_report_PSVs[],   /* array of output report data to pass to cocoa */
//  int  *out_group_report_idx ,      /* ptr to int having last index written */
//  int  kingpin_is_in_group
//);
//


extern char * mamb_report_person_in_group   /* in grpdoc.o */ 
(
  char *html_file_name,
  char *group_name,
  char *in_GRP_FLAT_CSV_ARRAY,
  char *arg_num_persons_in_grp,
  char *compare_everyone_with,   /* fmt= "Fred,3,21,1987,11,58,1,5,80.34" */
  char *pbm_returnSTRING_work_space,  // text data for JS to build html with
  char *arg_kingpin_is_in_group
);
/* in grpdoc.c */





/* #include "grphtm.h" */
/* int rkdb = 0; */ /* 0=no, 1=yes */

void g_fn_prtlin(char *lin);
void g_fn_prtlin_stars(char *starline);

/* in mambutil.o */
extern int binsearch_asp(char *asp_code, struct g_aspect tab[], int num_elements);
extern void strsubg(char *s, char *replace_me, char *with_me); // on str s (max 2048) does  :s/replace_me/with_me/g
extern int mapBenchmarkNumToPctlRank(int benchmark_num);
extern int sfind(char s[], char c);
extern char *scapwords(char *s);
extern void scharswitch(char *s, char ch_old, char ch_new);
extern char *csv_get_field(char *csv_string, char *delim, int want_fieldnum);
extern char *strim(char *s, char *set);
extern void commafy_int(char *dest, long intnum, int sizeofs);
extern int sall(char *s, char *set);
extern char *mkstr(char *s, char *begarg, char *end);
extern void scharout(char *s, int c);
extern int  scharcnt(char *s, int c);
extern void put_br_every_n(char *instr, int line_not_longer_than_this);
extern void fn_right_pad_with_hidden(char *s_to_pad, int num_to_pad);
extern void sfill(char *s, int num, int c);

/* in mambutil.o */

void do_average_trait_score_group(char *group_name, int average_trait_score);



// make_html_file_whole_group() not used  20210402
//
//int make_html_file_whole_group( /* produce actual html file */
//  char *group_name,
//  int   num_persons_in_grp,
//  char *in_html_filename,           /* in grphtm.c */
//  struct rank_report_line  *in_rank_lines[],
//  int   in_rank_lines_last_idx,
//  char *instructions,
//  char *string_for_table_only   /* 1024 chars max (its 9 lines formatted) */
//);
//
//int make_html_file_whole_group( /* produce actual html file */
//  char *group_name,
//  int   num_persons_in_grp,
//  char *in_html_filename,           /* in grphtm.c */
//  struct rank_report_line  *in_rank_lines[],
//  int   in_rank_lines_last_idx,
//  char *instructions,
//  char *string_for_table_only   /* 1024 chars max (its 9 lines formatted) */
//);
//
//
// make_html_file_whole_group() not used  20210402





/* NOTE: this repor is NO LONGER USED    (Jul 2014)
*  so there is no new "one-string" avg_lines format
*  like rank_lines and trait_lines arrays
*/
#ifdef PUT_BACK_COMMENTED_OUT_STUFF /****************************************/
* int make_html_file_avg_scores( /* produce actual html file */
*   char *group_name,
*   int   num_persons_in_grp,
*   char *in_html_filename,           /* in grphtm.c */
*   struct avg_report_line  *in_avg_lines[],
*   int   in_avg_lines_last_idx
* );
#endif /* ifdef PUT_BACK_COMMENTED_OUT_STUFF ********************************/


// make_html_file_trait_rank() not used  20210402
//int make_html_file_trait_rank( /* in grphtm.c */
//  char *group_name,
//  int   num_persons_in_grp,
//  char *trait_name,
//  char *in_html_filename,           /* in grphtm.c */
//  struct trait_report_line  *in_trait_lines[],
//  int   in_trait_lines_last_idx,
//  char *grp_average_trait_scores_csv
//);
//
// make_html_file_trait_rank() not used  20210402


extern void g_docin_free(void);   /* in grpdoc.o */

void g_docin_get(char *in_line);   

char doclin[4048];
char swork33[4048];



int    g_global_max_docin_idx;
char **g_global_docin_lines;
int    g_global_read_idx;
int    g_global_n;
char  *g_global_p = &swork33[0];

/* for calling mamb_report_whole_group() from make_html_just_2_people()
*  in order to get the table to show on bottom of just_2 HTML.
*/

char global_instructions[512];
char gbl_compare_everyone_with[512];
char gbl_format_as[512];
char gbl_trait_name[512];
char gblGrpAvgTraitScoresCSV2[64];

FILE *Fp_g_HTML_file;

char s1[512];
char s2[512];
char s3[512];
char s4[512];
char s5[512];
char s6[512];
/* char writebuf[2024]; */
/* char writebuf2[2024]; */
/* char writebuf3[2024]; */
char writebuf[4048];
char writebuf2[4048];
char writebuf3[4048];
/* char workbuf[512]; */


#define MAX_WK 10
struct {
  char wk[133]; 
} wks[MAX_WK];
#define g_arr(nn) (wks[nn].wk)  /* arr arr arr arr arr  HERE */
/* wks is array of struct size 133 chars
* 
*  (wks[k].wk)  <==>   arr(k)
*   
*  this expression:  (wks[k].wk)  
*  gives you the kth 133-char buffer in array wks.
*
*  With the *define* after, you can say this: 
*  arr(k) for the same buffer.
*/


/* void g_fn_output_top_of_html_file(void); */
void put_top_of_just2_group_rpt(void); /* just_2 rpt */  // browser version

// put_top_of_html_group_rpt() not used  20210402
//
//void put_top_of_html_group_rpt(char *group_name);
//
// put_top_of_html_group_rpt() not used  20210402
void put_category_label(char *category_text, int len);

int is_first_g_docin_get;  /* 1=yes, 0=no */


/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @@@@@@@@@@@@@@@@  person_in_group  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */



// make_html_file_person_in_group() not used  20210402
//

//int make_html_file_person_in_group( /* produce actual html file */
//  char *group_name,
//  int   num_persons_in_grp,
//  char *html_file_name,                    /* in grphtm.c */
//  struct rank_report_line  *in_rank_lines[],  /* array of report data */
//  int   in_rank_lines_last_idx,   /* int having last index written */
//  int avg_score_this_member)      /* for report bottom */
//
//int make_html_file_person_in_group( /* produce actual html file */
//  char *group_name,
//  int   num_persons_in_grp,
//  char *html_file_name,                    /* in grphtm.c */
//  struct rank_report_line  *in_rank_lines[],  /* array of report data */
//  int   in_rank_lines_last_idx,   /* int having last index written */
//  int avg_score_this_member,      /* for report bottom */
//  int  arg_kingpin_is_in_group    /* for fmt col hdr */
//)
//{
//trn("in  make_html_file_person_in_group()");
//
//  strcpy(gbl_gfnameHTML, html_file_name);
//
//  gbl_is_grpone_or_grpall = 1;   // ensure full color in all lines in case filename has "webview"
// 
//  gbl_avg_score_this_member = avg_score_this_member; /* for report bottom */
//  gbl_we_are_in_PRE_block = 0;  /* init to false */
//  gbl_kingpin_is_in_group = arg_kingpin_is_in_group;      /* for fmt col hdr */
////kin(gbl_kingpin_is_in_group);
//
//  /* try just calling whole_group html creation function
//  * with "format as person_in_group"  instructions
//  * in make_html_file_whole_group()
//  */
//  char string_for_table_only[4096];
//
//  /* trn("instructions for make_html_file_whole_group() = format as person_in_group"); */
//
////trn("doing ... make_html_file_whole_group()  in  make_html_file_person_in_group()");
//  strcpy(string_for_table_only, "abc");
//  int retval;
//  retval = make_html_file_whole_group( /* produce actual html file */
//    group_name,
//    num_persons_in_grp,
//    html_file_name,                     /* in grphtm.c */
//    in_rank_lines,            /* array of report data */
//    in_rank_lines_last_idx,   /* int having last index written */
//    "format as person_in_group",  /* maybe INSTRUCTIONS for table-only */
//    string_for_table_only   /* 1024 chars max (its 9 lines formatted) */
//                            /* buf to hold html for table */
//  );
////trn("finished ... make_html_file_whole_group()  in  make_html_file_person_in_group()");
//
//  gbl_is_grpone_or_grpall = 0;  // re-init
//
//  if (retval != 0) {
//    g_docin_free();      /* free all allocated array elements */
//    rkabort("Error: html file (grphtm, one person) was not produced");
//    return(1);
//  }
//
//  return(0);
//} /* end of make_html_file_person_in_group() */
//
//
// make_html_file_person_in_group() not used  20210402



/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
/* %%%%%%%%%%%%%%%%%%%%%%%  just_2 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */

//int make_html_file_just_2_people()     /* old main() */
char *make_html_file_just_2_people(      /* old main() */
//  char *in_html_filename,  // browser html or webview html
  char *arg_space_for_HTML_ju2, // space malloc'ed in js,  passed into mamb_report_just_2_people
  char *in_docin_lines[],
  int   in_docin_last_idx,
  char *person_1_csv,        /* fmt= "Fred,3,21,1987,11,58,1,5,80.34" */
  char *person_2_csv         /* used for whole grp table at bot of report */
)
{
tn();trn("in make_html_file_just_2_people()");
ksn(person_1_csv);
ksn(person_2_csv);
/*  char string_for_table_only[1024], mybuf[512], category_text[128]; */
// char ju2_string_for_table_only[4096], category_text[128];
 char *ju2_string_for_table_only;
 char category_text[128];
 int mylen;

//fopen_fpdb_for_debug(); 


  gbl_is_first_g_fn_prtlin        = 1;  /* init to true */
  gbl_space_for_HTML_ju2          = arg_space_for_HTML_ju2;

  strcpy(gbl_are_in_just2, "we are in make_html_file_just_2_people"); 
//  strcpy(gbl_gfnameHTML, in_html_filename);
//  strcpy(gbl_g_in_html_filename, in_html_filename);

  strcpy(gbl_just2PersonA, csv_get_field(person_1_csv, ",", 1));
  strcpy(gbl_just2PersonB, csv_get_field(person_2_csv, ",", 1));
//ksn(gbl_just2PersonB);
  is_first_g_docin_get = 1;  /* set to true */
  gbl_we_are_in_PRE_block = 0;  /* init to false */

  int i;
//tn();trn("in  make_html_file_just_2_people() "); 

  g_global_max_docin_idx = in_docin_last_idx;
  g_global_docin_lines   = in_docin_lines;

  /* open output HTML file
  */
//  if ( (Fp_g_HTML_file = fopen(in_html_filename, "w")) == NULL ) {
//    rkabort("Error  on just_2 grphtm.c. html fopen().");
//  }

  /* in this fn is the first g_docin_get for just_2 rpt
  */
//  if (strstr(in_html_filename, "webview") != NULL) {
//    gbl_we_are_in_webview_version = 1;
//    put_ios_top_of_just2_group_rpt(); /* output the css, headings etc. */
//  } else {
//    gbl_we_are_in_webview_version = 0;
//    put_top_of_just2_group_rpt(); /* output the css, headings etc. */
//  }
//

  // smup 
  //
  gbl_we_are_in_webview_version = 0;   // smup 

  /* TABLE with "Match Score"
  */



//  OUTPUT THE HTML FOR THE SCOREBOX TABLE =====  or not  ================================================================  
//  OUTPUT THE HTML FOR THE SCOREBOX TABLE =====  or not  ================================================================  

  /* Here, get into a string (1024 chars) the table-only html
  *  from the whole_group report (with colors).
  *  The group has only the two members. The table:
  *
  *        Rank  Score  Pair of Group Members
  *                373  Great
  *                213  Good
  *           1    152  barry   johnH
  *                100  Median
  *                 42  Not so good
  *                 18  OMG
  * 
  */
  /* ------------------------------------------- */




  // manually build array for group members arg in   mamb_report_whole_group() just below
  //
  //  mamb_csv_arr[0] = person_1_csv;   /* fmt= "Fred,3,21,1987,11,58,1,5,80.34" */
  //  mamb_csv_arr[1] = person_2_csv;   /* fmt= "Fred,3,21,1987,11,58,1,5,80.34" */
  //
  //  FYI  char gbl_grpFlatArrayOf_2_CSVs[ GRP_FLAT_CSV_ARRAY_RECSIZ *  2 ];   // for  use in mamb_report_just_2_people()
  //
  sfill(gbl_grpFlatArrayOf_2_CSVs, GRP_FLAT_CSV_ARRAY_RECSIZ *  2, '\0');
  //
  char my_just2CSV[128];  // max for csv is 48
  sfill(my_just2CSV, 127, ' ');                                                   // ensure trailing spaces up to 48
ksn(my_just2CSV);
  memcpy( my_just2CSV,  person_1_csv, GRP_FLAT_CSV_ARRAY_RECSIZ );               // copy csv
ksn(my_just2CSV);
  memcpy( gbl_grpFlatArrayOf_2_CSVs,  my_just2CSV, GRP_FLAT_CSV_ARRAY_RECSIZ );  // copy 48 chars
ksn(gbl_grpFlatArrayOf_2_CSVs);
  //
  sfill(my_just2CSV, 127, ' ');
ksn(my_just2CSV);
  memcpy( my_just2CSV,  person_2_csv, GRP_FLAT_CSV_ARRAY_RECSIZ ); 
ksn(my_just2CSV);
  memcpy( gbl_grpFlatArrayOf_2_CSVs + GRP_FLAT_CSV_ARRAY_RECSIZ,  my_just2CSV, GRP_FLAT_CSV_ARRAY_RECSIZ );
ksn(gbl_grpFlatArrayOf_2_CSVs);
  //
  // build array for arg in   mamb_report_whole_group() just below


//<.>
//  my_just2CSV[ GRP_FLAT_CSV_ARRAY_RECSIZ ] = '\0' ;                              // ensure siz=48
//    memcpy(current_person, in_GRP_FLAT_CSV_ARRAY + (kk * GRP_FLAT_CSV_ARRAY_RECSIZ), GRP_FLAT_CSV_ARRAY_RECSIZ); // read from GRP_FLAT_CSV_ARRAY 
//
///*   out_trait_lines[*out_trait_line_idx] = line; */
//  memcpy(out_trait_lines[*out_trait_line_idx], &line, sizeof(struct trait_report_line));
//
//<.>
//





//tn();trn("in make_html_file_just_2_people  BEFORE  report mamb_report_whole_group  for STRING");
//nksn(gbl_gfnameHTML);
//trn(" before report wholefor string"); nksn(in_html_filename);

//  sfill(ju2_string_for_table_only, 4096, ' ');
  out_rank_idx = 0;

//tn();b(10);ksn(ju2_string_for_table_only);

  char dummy_buf[128];  // for arg not used
  char dummy_buf2[128];  // for arg not used
  int  dummy_int;       // for arg not used
  strcpy(gbl_are_in_just2, "we are NOT in make_html_file_just_2_people"); 


  // here output the html for the score box  ->  "return only html for table in string",  /* instructions to return string only */
  // here output the html for the score box
  // here output the html for the score box
  //

      // fyi
      //      char *mamb_report_whole_group(    /* called from cocoa */
      //        char *html_file_name,
      //        char *group_name,
      //        char *in_GRP_FLAT_CSV_ARRAY,
      //        int  num_persons_in_grp,
      //        char *instructions,
      //        char *string_for_table_only, /* 1024 chars max (its 9 lines formatted) */
      //        char *gbm_returnSTRING_work_space   // text data for JS to build html with
      //      );
      //
      //
ju2_string_for_table_only = mamb_report_whole_group(    /* called from cocoa or just_2_people() in grphtm.c */
//mamb_report_whole_group(    /* called from cocoa or just_2_people() in grphtm.c */
//    "",              /* *html_file_name,*/

//    in_html_filename,              /* *html_file_name,*/  // HAS TO be there to act as flag for /webview/browser
   "in_html_filename",              /* *html_file_name,*/  // HAS TO be there to act as flag for /webview/browser

    "mambTempGroup", /* *group_name,*/

//    mamb_csv_arr,    /* fmt= "Fred,3,21,1987,11,58,1,5,80.34" */
    gbl_grpFlatArrayOf_2_CSVs, 
    dummy_buf,   /*  gbls_BMGR_STR_forC_work_space array of output report data to pass to cocoa */
    "2",               /* num_persons_in_grp,*/
//    out_rank_lines,  /* rank_report_line *out_rank_lines[],   output params returned (UNUSED HERE */
//                     /* (the array contents are not used here) */
//    &out_rank_idx,    /* UNUSED HERE */

    "return only html for table in string",  /* instructions to return string only */

//    string_for_table_only,              /* 4096 chars max (its 9 lines formatted) */
////    out_group_report_PSVs,   /* array of output report data to pass to cocoa */
////    out_group_report_idx     /* ptr to int having last index written */
//    &dummy_int     /* ptr to int having last index written */

//    ju2_string_for_table_only,              /* 4096 chars max (its 9 lines formatted) */
    dummy_buf2  //  for this arg     char *gbm_returnSTRING_work_space   // text data for JS to build html with
  );
  strcpy(gbl_are_in_just2, "we are in make_html_file_just_2_people"); 


tn();trn("in make_html_file_just_2_people AFTER report mamb_report_whole_group  for STRING");

ksn(global_instructions); 
kin(gbl_RPCO_score);
ksn(ju2_string_for_table_only);



  // return


//  OUTPUT THE HTML FOR THE SCOREBOX TABLE =====  or not  ================================================================  
//  OUTPUT THE HTML FOR THE SCOREBOX TABLE =====  or not  ================================================================  


//<.>
// NOTE: get just the score here (just2) for JS to use for scorebox
//<.>




// smup   if ( 
// smup          strstr(in_html_filename, "webview") != NULL     // or this is get string_for_table_only  instruction
// smup   )
// smup   lb  // webview version
//

// 20190312 comment out 
// smup 
// smup 
// smup //gbl_db_code = 1;   // = 1  , prints  lin
// smup // gbl_db_code = 0;     // = 0  no debug print
// smup 
// smup 
// smup 
// smup     sprintf(writebuf, "fill|filler line #1 at top");
// smup     g_fn_prtlin(writebuf);
// smup //    sprintf(writebuf, "fill|before table head");
// smup //    g_fn_prtlin(writebuf);
// smup //    sprintf(writebuf, "head|How Much");
// smup //    g_fn_prtlin(writebuf);
// smup 
// smup //    sprintf(writebuf, "head|before hdr lines");
// smup //    g_fn_prtlin(writebuf);
// smup 
// smup     sprintf(writebuf, "head|space above hdr line"); 
// smup     g_fn_prtlin(writebuf);
// smup     sprintf(writebuf, "head|Compatibility");    // right justify in cocoa
// smup     g_fn_prtlin(writebuf);
// smup //    sprintf(writebuf, "head|space below hdr line"); 
// smup //    g_fn_prtlin(writebuf);
// smup 
// smup     sprintf(writebuf, "head|space above hdr line"); 
// smup     g_fn_prtlin(writebuf);
// smup     sprintf(writebuf, "head|    Potential");
// smup     g_fn_prtlin(writebuf);
// smup //    sprintf(writebuf, "head|space below hdr line");
// smup //    g_fn_prtlin(writebuf);
// smup 
// smup //    sprintf(writebuf, "head|after hdr lines"); 
// smup //    g_fn_prtlin(writebuf);
// smup 
// smup //    sprintf(writebuf, "fill|after table head");
// smup //    g_fn_prtlin(writebuf);
// smup 
// smup 
// smup //trn("xxx");
// smup     for (i = 0; i <= 5; i++)   /* for all table data lines */
// smup     lb  // MAGIC  6 lines
// smup 
// smup       if (   out_rank_lines[i] == NULL
// smup           || strlen(out_rank_lines[i]->person_B) == 0
// smup       ) {
// smup         break;
// smup       }
// smup //tn();ki(i);ki(out_rank_lines[i]->rank_in_group);kin(out_rank_lines[i]->score);
// smup //ks(out_rank_lines[i]->person_A);ksn(out_rank_lines[i]->person_B);
// smup 
// smup       if (strstr(out_rank_lines[i]->person_B, " - top10") != NULL) {
// smup //        strcpy(writebuf, "tabl|                    90  Great       ");
// smup         sprintf(writebuf, "tabl|label@90@space above"); 
// smup         g_fn_prtlin(writebuf);
// smup         strcpy(writebuf, "tabl|label@90@filler");
// smup         g_fn_prtlin(writebuf);
// smup         sprintf(writebuf, "tabl|label@90@space below"); 
// smup         g_fn_prtlin(writebuf);
// smup         continue;
// smup       }
// smup       if (strstr(out_rank_lines[i]->person_B, " - good" ) != NULL) {
// smup //        strcpy(writebuf, "tabl|                    75  Good        ");
// smup         sprintf(writebuf, "tabl|label@75@space above"); 
// smup         g_fn_prtlin(writebuf);
// smup         strcpy(writebuf, "tabl|label@75@filler");
// smup         g_fn_prtlin(writebuf);
// smup         sprintf(writebuf, "tabl|label@75@space below"); 
// smup         g_fn_prtlin(writebuf);
// smup         continue;
// smup       }
// smup       if (strstr(out_rank_lines[i]->person_B, " - avg"  ) != NULL) {
// smup //        strcpy(writebuf, "tabl|                    50  Average     ");
// smup         sprintf(writebuf, "tabl|label@50@space above"); 
// smup         g_fn_prtlin(writebuf);
// smup         strcpy(writebuf, "tabl|label@50@filler");
// smup         g_fn_prtlin(writebuf);
// smup         sprintf(writebuf, "tabl|label@50@space below"); 
// smup         g_fn_prtlin(writebuf);
// smup         continue;
// smup       }
// smup       if (strstr(out_rank_lines[i]->person_B, " - bad"   ) != NULL) {
// smup //        strcpy(writebuf, "tabl|                    25  Not Good    ");
// smup         sprintf(writebuf, "tabl|label@25@space above"); 
// smup         g_fn_prtlin(writebuf);
// smup         strcpy(writebuf, "tabl|label@25@filler");
// smup         g_fn_prtlin(writebuf);
// smup         sprintf(writebuf, "tabl|label@25@space below"); 
// smup         g_fn_prtlin(writebuf);
// smup         continue;
// smup       }
// smup       if (strstr(out_rank_lines[i]->person_B, " - bot10")  != NULL) {
// smup //        strcpy(writebuf, "tabl|                    10  OMG         ");
// smup         sprintf(writebuf, "tabl|label@10@space above"); 
// smup         g_fn_prtlin(writebuf);
// smup         strcpy(writebuf, "tabl|label@10@filler");
// smup         g_fn_prtlin(writebuf);
// smup         sprintf(writebuf, "tabl|label@10@space below"); 
// smup         g_fn_prtlin(writebuf);
// smup         continue;
// smup       }
// smup 
// smup //      sprintf(writebuf,  "tabl|  %15s  %15s%2s%2d",
// smup //        out_rank_lines[i]->person_A,
// smup //        out_rank_lines[i]->person_B,
// smup //        " ",
// smup //        out_rank_lines[i]->score
// smup //      );
// smup //
// smup //      sprintf(writebuf, "tabl|pair@space above@@"); 
// smup       sprintf(writebuf,  "tabl|pair@%2d@space above@x",
// smup         out_rank_lines[i]->score
// smup       );
// smup       g_fn_prtlin(writebuf);
// smup       sprintf(writebuf,  "tabl|pair@%2d@%s@%s",
// smup         out_rank_lines[i]->score,
// smup         out_rank_lines[i]->person_A,
// smup         out_rank_lines[i]->person_B
// smup       );
// smup       g_fn_prtlin(writebuf);
// smup       sprintf(writebuf,  "tabl|pair@%2d@space below@x",
// smup         out_rank_lines[i]->score
// smup       );
// smup       g_fn_prtlin(writebuf);
// smup 
// smup // view all in out_rank_lines
// smup //
// smup //struct rank_report_line {
// smup //  int  rank_in_group;
// smup //  int  score;
// smup //  char person_A[MAX_SIZE_PERSON_NAME+1];
// smup //  char person_B[MAX_SIZE_PERSON_NAME+1];
// smup ///*  char hex_color[8]; */  /* like "66ff33" */
// smup //};
// smup //struct rank_report_line *out_rank_lines[MAX_IN_RANK_LINE_ARRAY];
// smup //int out_rank_idx;  /* pts to current line in out_rank_lines */
// smup //
// smup //for (i = 0; i <= 5; i++) {  // MAGIC  6 lines
// smup //tn();ki(out_rank_lines[i]->rank_in_group);kin(out_rank_lines[i]->score);
// smup //ks(out_rank_lines[i]->person_A);ksn(out_rank_lines[i]->person_B);
// smup //}
// smup //   output:
// smup //_out_rank_lines[i]->rank_in_group=[0]___out_rank_lines[i]->score=[90]__
// smup //_out_rank_lines[i]->person_A=[~~~~~~~~~~~~~~~]___out_rank_lines[i]->person_B=[qhilite - top10]__
// smup //
// smup //_out_rank_lines[i]->rank_in_group=[0]___out_rank_lines[i]->score=[75]__
// smup //_out_rank_lines[i]->person_A=[~~~~~~~~~~~~~~~]___out_rank_lines[i]->person_B=[qhilite - good]__
// smup //
// smup //_out_rank_lines[i]->rank_in_group=[0]___out_rank_lines[i]->score=[50]__
// smup //_out_rank_lines[i]->person_A=[~~~~~~~~~~~~~~~]___out_rank_lines[i]->person_B=[qhilite - avg]__
// smup //
// smup //_out_rank_lines[i]->rank_in_group=[1]___out_rank_lines[i]->score=[26]__
// smup //_out_rank_lines[i]->person_A=[~Emma]___out_rank_lines[i]->person_B=[~Anya]__
// smup //
// smup //_out_rank_lines[i]->rank_in_group=[0]___out_rank_lines[i]->score=[25]__
// smup //_out_rank_lines[i]->person_A=[               ]___out_rank_lines[i]->person_B=[qhilite - bad]__
// smup //
// smup //_out_rank_lines[i]->rank_in_group=[0]___out_rank_lines[i]->score=[10]__
// smup //_out_rank_lines[i]->person_A=[               ]___out_rank_lines[i]->person_B=[qhilite - bot10]__
// smup //
// smup     rb /* for all table data lines */
// smup 
//

// smup   rb else lb  // browser version rb
//

// browser version
//ksn(string_for_table_only);


//      || strcmp(gbl_are_in_just2, "we are in make_html_file_just_2_people") == 0




//tr("1st");ksn(ju2_string_for_table_only);
//
//  g_fn_prtlin(ju2_string_for_table_only); /* OUTPUT THE HTML FOR THE TABLE ========  */
//

//
//    g_fn_prtlin("<pre>");
//    gbl_we_are_in_PRE_block = 1;  /* true */
//    g_fn_prtlin("                                            ");
//
//  /*   g_fn_prtlin("  Check out the Best Match report    "); */
//    g_fn_prtlin("  Check out the Best Match in Group report  ");
//    g_fn_prtlin("   which uses this score to compare with    ");
////    g_fn_prtlin("      other pairs of group members          ");
//    g_fn_prtlin("           other pairs of people            ");
//
//    g_fn_prtlin("                                            ");
//  /*   g_fn_prtlin("                                                                     "); 
//  *   g_fn_prtlin("  Check out the group reports \"Best Match\" and \"Best Match For ...\"  ");
//  *   g_fn_prtlin("  which use this score to compare with other pairs of group members  ");
//  *   g_fn_prtlin("                                                                     ");
//  */
//    gbl_we_are_in_PRE_block = 0;  /* false */
//    g_fn_prtlin("<br><br><br></pre>");
//

// browser version

    /* when finished, free array elements 
    */
    g_rank_line_free(out_rank_lines, out_rank_idx);

    strcpy(global_instructions, "ok to write html now"); 

    g_fn_prtlin(ju2_string_for_table_only); /*  END   OF    OUTPUT THE HTML FOR THE TABLE ===========================  */

//
tr("2nd");ksn(ju2_string_for_table_only);

// smup   if (strstr(in_html_filename, "webview") == NULL)   // NOT webview version   i.e. browser version
// smup   {
// smup //    g_fn_prtlin("<div><br><br></div>");
// smup     g_fn_prtlin("<div><br><br></div>");
// smup   }
//

//    g_fn_prtlin("<div><br><br></div>");
//gbl_db_code = 0;




  /*  read until [beg_graph]
   */
  for (i=0; ; i++) {
    g_docin_get(doclin);
    if (strstr(doclin, "[beg_graph]") != NULL) break;
  }

//  char spanbeg[128],  spanend[128];  // used in web only
//  char spanbeg1[128], spanend1[128];  // used in web only





// smup   if (strstr(in_html_filename, "webview") != NULL)
// smup   lb  // webview version
//

// smup 
// smup     gbl_we_are_in_PRE_block = 1;  /* true */
// smup 
// smup 
// smup // START TABLE VERSION    (legacy)
// smup 
// smup     // this is webview version
// smup     //
// smup 
// smup     sprintf(writebuf, "fill|filler before how big");
// smup     g_fn_prtlin(writebuf);
// smup     sprintf(writebuf, "fill|before how big header");
// smup     g_fn_prtlin(writebuf);
// smup //  sprintf(writebuf, "howbighdr|   How Big");
// smup     sprintf(writebuf, "howbighdr|     How Big");
// smup     g_fn_prtlin(writebuf);
// smup //    sprintf(writebuf, "howbighdr|   are the  favorable   influences  +++  ");
// smup //    sprintf(writebuf, "howbighdr|     are the favorable   influences +++  ");
// smup     sprintf(writebuf, "howbighdr|     are the favorable   influences ++  ");
// smup     g_fn_prtlin(writebuf);
// smup //    sprintf(writebuf, "howbighdr|   and the  challenging influences  ---  ");
// smup //    sprintf(writebuf, "howbighdr|     and the challenging influences ---  ");
// smup     sprintf(writebuf, "howbighdr|     and the challenging influences --  ");
// smup //    sprintf(writebuf, "howbighdr| and the   challenging influences  qqqqq  ");
// smup     g_fn_prtlin(writebuf);
// smup //    sprintf(writebuf, "howbighdr|   in the 3 categories below");
// smup     sprintf(writebuf, "howbighdr|     in the 3 categories below?");
// smup     g_fn_prtlin(writebuf);
// smup     sprintf(writebuf, "fill|after how big header");
// smup     g_fn_prtlin(writebuf);
// smup 
// smup 
// smup 
// smup //  g_fn_prtlin( "<table class=\"category\" cellspacing=\"0\" celpadding=\"0\">");  // start of long category table
// smup //  g_fn_prtlin( "<table class=\"category\" >");  // start of long category table
// smup 
// smup   // this is webview version
// smup 
// smup   /*   sprintf(mybuf, "%-92s", "             <span class=\"cCat\">CLOSENESS </span>"); */
// smup   /*   sprintf(mybuf, "%-92s", "             <span class=\"cCat\">CLOSENESS </span>                          "); */
// smup 
// smup     /* put category string in field of 92 with 13 spaces at line beg
// smup     *  (not counting <span> characters)
// smup     */
// smup //    g_fn_prtlin( "<tr><td>                                                                                  </td></tr>"); // blank line
// smup 
// smup 
// smup   // this is webview version
// smup 
// smup //    sprintf(category_text, "%s", " 1. CLOSENESS ");
// smup     sprintf(category_text, "%s", "    Closeness ");
// smup 
// smup     put_category_label(category_text, (int)strlen(category_text)); 
// smup 
// smup     /* ================================================================= */
// smup     //  read until [beg_persn]     // this is PERSONAL CLOSENESS STARS
// smup     for (i=0; ; i++) {
// smup       g_docin_get(doclin);
// smup       if (strstr(doclin, "[beg_persn]") != NULL) break;
// smup     }
// smup 
// smup     gbl_countMinusLines = 0;     // of consecutive minus lines in star lines
// smup     for (i=0; ; i++) {   /* print star lines - has plus lines and minus lines */
// smup       g_docin_get(doclin);
// smup       if (strstr(doclin, "[end_persn]") != NULL) break;
// smup 
// smup tn();tr("closeness doclin=");ksn(doclin);
// smup       scharout(doclin, '|');  /* remove pipes (for old sideline)    */
// smup 
// smup //      sprintf(writebuf, "stars|%s", doclin);
// smup       sprintf(writebuf, "stars|%d", get_how_many(doclin));
// smup       g_fn_prtlin(writebuf);
// smup 
// smup //      g_fn_prtlin_stars(doclin);   prob do not need for tableview rpt
// smup     }
// smup     /* finished personal stars */
// smup 
// smup     sprintf(writebuf, "fill|after personal stars");
// smup     g_fn_prtlin(writebuf);
// smup     /* ================================================================= */
// smup 
// smup 
// smup     for (i=0; ; i++) {
// smup       g_docin_get(doclin);
// smup       if (strstr(doclin, "[beg_aview]") != NULL) break;
// smup     }
// smup 
// smup     // grab name for beg_aview
// smup     //
// smup     char beg_aview_name[128];
// smup     strcpy(beg_aview_name, csv_get_field(doclin, "|", 2));
// smup 
// smup     char *s;           /* capitalizes all chars in s */
// smup     s = &beg_aview_name[0];
// smup     for (; *s; ++s) *s = toupper( (int) *s);
// smup 
// smup 
// smup     // this is webview version  wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
// smup 
// smup 
// smup //    mylen = sprintf(category_text, " 2. FROM %s's POINT OF VIEW ", beg_aview_name );
// smup     mylen = sprintf(category_text, "    From %s's Point of View ", beg_aview_name );
// smup //    sprintf(category_text, " FROM %s's POINT OF VIEW ", beg_aview_name );
// smup     put_category_label(category_text, mylen); 
// smup 
// smup     gbl_countMinusLines = 0;     // of consecutive minus lines in star lines
// smup     for (i=0; ; i++) {  /* print until [end_sensi] */
// smup       g_docin_get(doclin);
// smup       if (strstr(doclin, "[end_aview]") != NULL) break;
// smup       scharout(doclin, '|');  /* remove pipes (for old sideline)    */
// smup 
// smup //      sprintf(writebuf, "stars|%s", doclin);
// smup       sprintf(writebuf, "stars|%d", get_how_many(doclin));
// smup       g_fn_prtlin(writebuf);
// smup       
// smup 
// smup //      g_fn_prtlin_stars(doclin);  
// smup     }
// smup 
// smup     sprintf(writebuf, "fill|after personA ptofview");
// smup     g_fn_prtlin(writebuf);
// smup     /* ================================================================= */
// smup 
// smup     for (i=0; ; i++) {
// smup       g_docin_get(doclin);
// smup       if (strstr(doclin, "[beg_bview]") != NULL) break;
// smup     }
// smup 
// smup     // grab name for beg_bview
// smup     //
// smup     char beg_bview_name[128];
// smup     strcpy(beg_bview_name, csv_get_field(doclin, "|", 2));
// smup 
// smup     // char *s;           /* capitalizes all chars in s */
// smup     s = &beg_bview_name[0];
// smup     for (; *s; ++s) *s = toupper( (int) *s);
// smup 
// smup //    mylen = sprintf(category_text, " 3. FROM %s's POINT OF VIEW ", beg_bview_name );
// smup     mylen = sprintf(category_text, "    From %s's Point of View ", beg_bview_name );
// smup //    sprintf(category_text, " FROM %s's POINT OF VIEW ", beg_bview_name );
// smup     put_category_label(category_text, mylen); 
// smup 
// smup     gbl_countMinusLines = 0;     // of consecutive minus lines in star lines
// smup     for (i=0; ; i++) { 
// smup       g_docin_get(doclin);
// smup       if (strstr(doclin, "[end_bview]") != NULL) break;
// smup       scharout(doclin, '|');  /* remove pipes (for old sideline)    */
// smup 
// smup //      sprintf(writebuf, "stars|%s", doclin);
// smup       sprintf(writebuf, "stars|%d", get_how_many(doclin));
// smup       g_fn_prtlin(writebuf);
// smup 
// smup //      g_fn_prtlin_stars(doclin);  
// smup     }
// smup 
// smup     sprintf(writebuf, "fill|after personB ptofview");
// smup     g_fn_prtlin(writebuf);
// smup     /* ================================================================= */
// smup 
// smup     for (i=0; ; i++) {
// smup       g_docin_get(doclin);
// smup       if (strstr(doclin, "[beg_ovral]") != NULL) break;
// smup     }
// smup //    sprintf(category_text, "OVERALL COMPATIBILITY ");
// smup //    put_category_label(category_text, (int)strlen(category_text)); 
// smup 
// smup     for (i=0; ; i++) {
// smup       g_docin_get(doclin);
// smup       if (strstr(doclin, "[end_ovral]") != NULL) break;
// smup   /*     g_fn_prtlin(doclin); */
// smup       scharout(doclin, '|');  /* remove pipes (for old sideline)    */
// smup //      g_fn_prtlin_stars(doclin);  
// smup     }
// smup     /*   g_fn_prtlin(" A combination of all the different factors of compatibility for this pair.                      "); */
// smup 
// smup     /* ================================================================= */
// smup 
// smup 
// smup     /* read until
// smup     */
// smup     for (i=0; ; i++) {
// smup       g_docin_get(doclin);
// smup       if (strstr(doclin, "[end_graph]") != NULL) break;
// smup     }
// smup 
// smup 
// smup //    sprintf(writebuf, "howbigftr|   Good indicators are a full line of +++ ");
// smup //    sprintf(writebuf, "howbigftr|   Good indicator is a full line of +++ ");
// smup //  sprintf(writebuf, "howbigftr|   Good signs are a full line of +++ ");
// smup //    sprintf(writebuf, "howbigftr|     Good signs are a full line of +++ ");
// smup 
// smup 
// smup //    sprintf(writebuf, "howbigftr|     Good signs are a full line of ++ ");
// smup //    g_fn_prtlin(writebuf);
// smup ////  sprintf(writebuf, "howbigftr|   and double the +++ compared to  --- ");
// smup ////    sprintf(writebuf, "howbigftr|     and double the +++ compared to --- ");
// smup //    sprintf(writebuf, "howbigftr|     and double the ++ compared to -- ");
// smup //    g_fn_prtlin(writebuf);
// smup //
// smup 
// smup 
// smup     sprintf(writebuf, "fill|after howbigftr");
// smup     g_fn_prtlin(writebuf);
// smup     sprintf(writebuf, "fill|filler after how big");
// smup     g_fn_prtlin(writebuf);
// smup 
// smup     // webview version
// smup 
// smup //g_fn_prtlin( "        you would like to see a full line of pluses       ");// these 3 lines have to be here to avoid weird right margin overflow
// smup //g_fn_prtlin( "        and double the pluses compared to minuses         ");
// smup //g_fn_prtlin( "                                                               ");
// smup //
// smup 
// smup     // webview version
// smup 
// smup     sprintf(writebuf, "fill|filler before paras");
// smup     g_fn_prtlin(writebuf);
// smup 
// smup //    g_fn_prtlin("                                                       ");
// smup //    g_fn_prtlin("                       How Much                        ");
// smup //    g_fn_prtlin("                of each influence below                ");
// smup //    g_fn_prtlin("                  is fully expressed?                  ");
// smup //    g_fn_prtlin("                           |                           ");
// smup //
// smup //    What Percentage
// smup //
// smup //    How Much
// smup //    of each influence below
// smup //    is fully expressed
// smup //    . (green) favorable                |100%
// smup //    . (red  ) challenging              |100%
// smup //
// smup //    How Strong is each influence below
// smup //    0%                                100%|
// smup //    0%                                100%|
// smup //
// smup // no no      OR put 0% -> 100%  in Info screen    20151201  decide to leave out
// smup 
// smup 
// smup     // here we start pco DETAIL paragraphs   YYYYYYYYYYY  webview version  YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY DO PARAGRAPHS HERE 
// smup 
// smup     /* DO PARAGRAPHS HERE */
// smup 
// smup     /* read until
// smup     */
// smup     for (i=0; ; i++) {
// smup       g_docin_get(doclin);
// smup       if (strstr(doclin, "[beg_aspects]") != NULL) break;
// smup     }
// smup 
// smup 
// smup     /* now read and print aspects until we hit [end_aspects] 
// smup     */
// smup     for (i=0; ; i++) {
// smup       g_docin_get(doclin);
// smup       if (strlen(doclin) == 0) continue;
// smup       if (strstr(doclin, "[end_aspects]") != NULL) break;
// smup       
// smup       strcpy(gbl_aspect_code, doclin);
// smup 
// smup       g_fn_webview_aspect_text(gbl_aspect_code); /* output the aspect text <<<QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ  */
// smup       
// smup     }  /* read and print aspects until we hit [end_aspects] */
// smup 
// smup 
// smup     for (i=0; ; i++) {  /* read until  */
// smup       g_docin_get(doclin);
// smup       if (strstr(doclin, "[end_program]") != NULL) break;
// smup     }
// smup 
//
// smup   rb // webview version  ----------------------------------------------------------------------------------------
//


//  else
//  lb  // browser version  ------------------------------------------------------------------------------
   // browser version  ----------------------------------------------------------------------------------------


//    g_fn_prtlin("<pre>");


//    g_fn_prtlin("<div class='RPCO_categories'>");
// e.g.   strcat(string_for_table_only, "<div id=\"scoreCOdiv\" class=\"scoreCOcss\" style=\"overflow-x:auto;\" >"); // -x for responsive table
    g_fn_prtlin("<div class='RPCO_categories' style=\"overflow-x:auto;\" >");   // -x for responsive table



//    g_fn_prtlin("<pre class=\"RPCO_PRE\">");
//    gbl_we_are_in_PRE_block = 1;  /* true */


//g_fn_prtlin("<div class='RPCO_cathdrftr'> ");
  // this is browser version
//    g_fn_prtlin("How Big are the<br><span class=\"cGre\" style=\"color: black\">&nbsp;favorable   influences  +++  </span><br>and<br><span class=\"cRed\" style=\"color: black\">&nbsp;challenging influences  ---  </span><br>in the 3 categories below? <br><br>");
//    g_fn_prtlin("How Big are the favorable influences and challenging influences in the 3 categories below? <br><br>");
//    g_fn_prtlin("Favorable influences<br>and challenging influences <br><br>");
//    g_fn_prtlin("<div class='RPCO_cathdrftr' style='padding-bottom: 1vh' >Favorable influences<br>and challenging influences<br> in 3 categories<br><br></div>");


//    g_fn_prtlin("<div class='RPCO_cathdrftr' style='padding-bottom: 1vh' >3 categories<br>Favorable influences <<br>Challenging influences<br><br></div>");

// 2 divs
//    g_fn_prtlin("<div id='cathdrTOP' class='RPCO_cathdrftr' >3 categories<br>Favorable influences&nbsp;</div>");
//    g_fn_prtlin("<div id='cathdrTOP' class='RPCO_cathdrftr' style='padding-top: 1em; ' >3 CATEGORIES<br>Favorable influences&nbsp;</div>");
    g_fn_prtlin("<div id='cathdrTOP' class='RPCO_cathdrftr'  >3 CATEGORIES<br>Favorable influences&nbsp;</div>");

    g_fn_prtlin("<div id='cathdrBOT' class='RPCO_cathdrftr' style='padding-bottom: 1em' >Challenging influences&nbsp;</div>");
//    g_fn_prtlin("<div><br></div>");


  // this is browser version
  
  char starbuf[1024];
  char linePluses[2048];
  char lineMinuses[2048];


  /*   sprintf(mybuf, "%-92s", "             <span class=\"cCat\">CLOSENESS </span>"); */
  /*   sprintf(mybuf, "%-92s", "             <span class=\"cCat\">CLOSENESS </span>                          "); */

    /* put category string in field of 92 with 13 spaces at line beg
    *  (not counting <span> characters)
    */
  /*   put_category_label(category_text);  */
//    put_category_label(category_text, (int)strlen(category_text)); 

//    sprintf(category_text, "%s", "CLOSENESS ");



// remove may 2019   put back
//    sprintf(category_text, "<div class='RPCO_cathdrftr'>CLOSENESS</div>" );
//    g_fn_prtlin(category_text);   // class=RPCO_cathdrftr;



    char collect_star_lines[4096];

    /* ================================================================= */
    /*  read until [beg_persn]   */
    for (i=0; ; i++) {
      g_docin_get(doclin);
      if (strstr(doclin, "[beg_persn]") != NULL) break;
    }
    strcpy(collect_star_lines, "");
    for (i=0; ; i++) {   /* print star lines */
      g_docin_get(doclin);
//tn();b(21);ks(doclin);
      
      strcat(collect_star_lines, doclin);
      if (strstr(doclin, "[end_persn]") != NULL) break;

  /*     g_fn_prtlin(doclin); */
//      scharout(doclin, '|');  /* remove pipes (for old sideline)    */
//      g_fn_prtlin_stars(doclin);   // for CLOSENESS
    }

    /* finished personal stars */

//tn();b(23);ks(collect_star_lines);
    int howManyPlusSigns;
    int howManyMinusSigns;
    howManyPlusSigns  = scharcnt(collect_star_lines, '+');
    howManyMinusSigns = scharcnt(collect_star_lines, '-');
//tn();b(24);ki(howManyPlusSigns);kin(howManyMinusSigns);

    /* sfill -   fill up string s with num chars, where char=c */
    // void sfill(char *s, int num, int c)
    sfill(linePluses , howManyPlusSigns,  '+'); 
    sfill(lineMinuses, howManyMinusSigns, '-'); 


//tn();b(24);ksn(linePluses);ksn(lineMinuses);
  // clos, ptva, ptvb

//    sprintf(starbuf, "<div id='RPCO_closG' class='RPCO_starbox'><div id='closGtext' class='centered'>My Name here</div> %s</div> ", linePluses); 
//    sprintf(starbuf, "<div id='RPCO_closG' class=\"RPCO_starbox\">%s</div>", linePluses); 
    sprintf(starbuf, "<div id='RPCO_closG' class=\"RPCO_Gstarbox\">%s</div>", linePluses); 
//tn();b(25);ksn(starbuf);
    g_fn_prtlin(starbuf);


//    sprintf(starbuf, "<div id='RPCO_closR' class=\"RPCO_starbox\">%s</div>", lineMinuses); 
    sprintf(starbuf, "<div id='RPCO_closR' class=\"RPCO_Rstarbox\">%s</div>", lineMinuses); 
//tn();b(26);ksn(starbuf);
    g_fn_prtlin(starbuf);

    /* ================================================================= */

    // NOTE: here we are in  browser version




    // NOTE: this is after CLOSENESS
//    g_fn_prtlin("<div><br><br><br></div>"); /* blank line */


//
//    // add Points of View   BUTTON  id=btn_RPCO_2POV
//    g_fn_prtlin("<div><br>\
//<div id='btn_RPCO_2POV' style='pointer-events: auto; display: inline-block; position: relative; width: 100px; height: 16px; line-height: 18px; font-size: 11px; text-align: center; color: rgb(2,41,2); background-color: rgb(233,233,128); border-style: ridge; border-radius: 5px; border-width: 2px; border-color: rgb(0,0,0); bottom: 2px;  background-image: linear-gradient( rgb(255,255,60), rgb(255,255,120), rgb(255,255,180), rgb(255,255,255) ); '>Points of View</div>\
//<br><br></div>"); /* blank line */
//
//    sprintf(starbuf, "<div id='RPCO_2POV' class=\"RPCO_2POV_class\">");    // ==============  CONTAINER for the 2 points of view
//    g_fn_prtlin(starbuf);
//


    /* ======   20200126  try with no POINT OF VIEWs   ================= */


    /* ================================================================= */
    /*  read until [beg_aview]   */
    for (i=0; ; i++) {
      g_docin_get(doclin);
      if (strstr(doclin, "[beg_aview]") != NULL) break;
    }

//
////    sprintf(category_text, "<div class='RPCO_cathdrftr'>FROM %s's<br>POINT OF VIEW</div>", gbl_just2PersonA );
//    sprintf(category_text, "<div class='RPCO_cathdrftr'>%s's<br>POINT OF VIEW</div>", gbl_just2PersonA );
//    g_fn_prtlin(category_text); 
//

    strcpy(collect_star_lines, "");
    for (i=0; ; i++) {  /* get star lines until [end_aview] */
      g_docin_get(doclin);
      strcat(collect_star_lines, doclin);
      if (strstr(doclin, "[end_aview]") != NULL) break;
    }

    /* finished  from personA's pt of view  */

    howManyPlusSigns  = scharcnt(collect_star_lines, '+');
    howManyMinusSigns = scharcnt(collect_star_lines, '-');

    /* sfill -   fill up string s with num chars, where char=c */
    // void sfill(char *s, int num, int c)
    sfill(linePluses , howManyPlusSigns,  '+'); 
    sfill(lineMinuses, howManyMinusSigns, '-'); 

//
//    // clos, ptva, ptvb
//    sprintf(starbuf, "<div id='RPCO_ptvaG' class=\"RPCO_Gstarbox\">%s</div>", linePluses); 
//    g_fn_prtlin(starbuf);
//
////    g_fn_prtlin("<div style='line-height: 66%; '>&nbsp;</div>"); /* blank line */
//
//    sprintf(starbuf, "<div id='RPCO_ptvaR' class=\"RPCO_Rstarbox\">%s</div>", lineMinuses); 
//    g_fn_prtlin(starbuf);
//
//    g_fn_prtlin("<div><br></div>"); /* blank line    end of  aview  */
//
    /* ================================================================= */


    /* ================================================================= */
    /*  read until [beg_bview]   */
    for (i=0; ; i++) {
      g_docin_get(doclin);
      if (strstr(doclin, "[beg_bview]") != NULL) break;
    }

//    sprintf(category_text, "<div class='RPCO_cathdrftr'>FROM %s's<br>POINT OF VIEW</div>", gbl_just2PersonB );
//ksn( gbl_just2PersonB);
    sprintf(category_text, "<div class='RPCO_cathdrftr'>%s's<br>POINT OF VIEW</div>", gbl_just2PersonB );
//    g_fn_prtlin(category_text);   // class=RPCO_cathdrftr;

    strcpy(collect_star_lines, "");
    for (i=0; ; i++) {  /* get star lines until [end_bview] */
      g_docin_get(doclin);
      strcat(collect_star_lines, doclin);
      if (strstr(doclin, "[end_bview]") != NULL) break;
    }

    /* finished  from personB's pt of view  */

    howManyPlusSigns  = scharcnt(collect_star_lines, '+');
    howManyMinusSigns = scharcnt(collect_star_lines, '-');

    /* sfill -   fill up string s with num chars, where char=c */
    // void sfill(char *s, int num, int c)
    sfill(linePluses , howManyPlusSigns,  '+'); 
    sfill(lineMinuses, howManyMinusSigns, '-'); 

//
//    // clos, ptva, ptvb
//    sprintf(starbuf, "<div id='RPCO_ptvbG' class=\"RPCO_Gstarbox\">%s</div>", linePluses); 
//    g_fn_prtlin(starbuf);
//
////    g_fn_prtlin("<div style='line-height: 66%; '>&nbsp;</div>"); /* blank line */
//
//    sprintf(starbuf, "<div id='RPCO_ptvbR' class=\"RPCO_Rstarbox\">%s</div>", lineMinuses); 
//    g_fn_prtlin(starbuf);
//
//    g_fn_prtlin("<div><br></div>"); /* blank line    end of  bview  */
//
    /* ================================================================= */


// nice try  may 2019   (going for ead and gre stars (from closeness) on each score line )   truns out  you nee all three   try yellow stars one line 1 - 99
//    sprintf(starbuf, "</div>  <!-- id=RPCO_2POV -->");    // ==============  CONTAINER for the 2 points of view
//    g_fn_prtlin(starbuf);
//
//



    /* read until end_graph   graph?
    */
    for (i=0; ; i++) {
      g_docin_get(doclin);
      if (strstr(doclin, "[end_graph]") != NULL) break;
    }


//    g_fn_prtlin( "<div class='RPCO_cathdrftr' style='padding-bottom: 1vh; ' >you would like to see<br>a full line of green and<br>double the green compared to red<br>");
//    g_fn_prtlin( "<div class='RPCO_cathdrftr' style='padding-bottom: 1vh; ' >You would like to see a full line of green AND double the green compared to red<br></div>");
//    g_fn_prtlin( "<div class='RPCO_cathdrftr' style='padding-bottom: 1vh; ' >You would like to see BOTH a full line of green AND double the green compared to red<br></div>");

// 20190314  put ID onto bottom text in cat box  so JS can insert green and red stars
    g_fn_prtlin( "<div id=catFOOTER class='RPCO_cathdrftr' style='padding-bottom: 1em; padding-top; 1em; ' >You would like to see BOTH a full line of green AND double the green compared to red<br></div>");
// 20190314  put ID onto bottom text in cat box  so JS can insert green and red stars


//    g_fn_prtlin( "<div class='RPCO_cathdrftr' style='padding-bottom: 1vh; ' >You would like to see all 3:<br>  1. a full line of green<br>  2. double the green compared to red<br>  3. no line full of red<br></div>");


g_fn_prtlin("</div>");   // class='RPCO_categories'>");

    // explain how much influence red/green for the aspect paras
    //

    // NOTE: here we are in  browser version

//    g_fn_prtlin("<div><br><br></div>");

//    g_fn_prtlin("<pre style=\"background-color: #f7ebd1\">");
//    g_fn_prtlin("<pre style=\"background-color: #f7ebd1;\">");
    g_fn_prtlin("<pre class=\"RPCO_PRE\" style=\"background-color: #f7ebd1;\">");

    gbl_we_are_in_PRE_block = 1;  /* true */

//    g_fn_prtlin("                                                       ");
//    g_fn_prtlin("                       How Much                        ");
//    g_fn_prtlin("                of each influence below                ");
//    g_fn_prtlin("                  is fully expressed?                  ");
//    g_fn_prtlin("                           |                           ");

//  g_fn_prtlin("<div class=\"linehite_0050\">  <span class=\"cRed\">                         </span>|<span class=\"cGre\">                         </span>  ");
//  g_fn_prtlin("  <span class=\"cRed\">100%                   0%</span>|<span class=\"cGre\">0%                   100%</span>  </div>");



//    g_fn_prtlin("<div class=\"linehite_0050\"> |<span class=\"cRed\">                         </span>|<span class=\"cGre\">                         </span>| ");
//    g_fn_prtlin(" |<span class=\"cRed\">100%                   0%</span>|<span class=\"cGre\">0%                   100%</span>| </div>");


    gbl_we_are_in_PRE_block = 0;  /* false */
//    g_fn_prtlin("<br><br><br></pre>");
    g_fn_prtlin("<br></pre>");


    // here we start pco DETAIL paragraphs   YYYYYYYYYYYYY  browser version  YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY DO PARAGRAPHS HERE 
    /* DO PARAGRAPHS HERE */

    /* read until
    */
    for (i=0; ; i++) {
      g_docin_get(doclin);
      if (strstr(doclin, "[beg_aspects]") != NULL) break;
    }


    /* now read and print aspects until we hit [end_aspects] 
    */
    for (i=0; ; i++) {
      g_docin_get(doclin);
      if (strlen(doclin) == 0) continue;
      if (strstr(doclin, "[end_aspects]") != NULL) break;
      
      strcpy(gbl_aspect_code, doclin);


      // NOTE:  try report with no aspect paragraphs  20200212
      //
      //  g_fn_browser_aspect_text(gbl_aspect_code); /* output the aspect text */ // NOTE:  try report with no aspect paragraphs  20200212






//    g_fn_prtlin("<div><br></div>");
      
    }  /* read and print aspects until we hit [end_aspects] */


  /*   gbl_we_are_in_PRE_block = 0; */
  /*   g_fn_prtlin("</pre>"); */

    for (i=0; ; i++) {  /* read until  */
      g_docin_get(doclin);
      if (strstr(doclin, "[end_program]") != NULL) break;
    }

    gbl_we_are_in_PRE_block = 0;
//    g_fn_prtlin("</pre>");


//  rb // browser version




// smup   if (strstr(in_html_filename, "webview") != NULL)
// smup   lb  // webview version
// smup
// smup 
// smup 
// smup //
// smup //    strcpy(spanbeg, "<span style=\"background-color: #fcfce0;\"> ");
// smup //    strcpy(spanend, "</span>");
// smup //
// smup //    sprintf(writebuf, "%s%s%s", spanbeg,
// smup //      "                                                  ",
// smup //      spanend);
// smup //    g_fn_prtlin(writebuf);
// smup //
// smup //
// smup //    sprintf(writebuf, "%s%s%s", spanbeg,
// smup //      "     a GOOD RELATIONSHIP usually has 2 things     ", // 
// smup //      spanend);
// smup //    g_fn_prtlin(writebuf);
// smup //
// smup //
// smup //    sprintf(writebuf, "%s%s%s", spanbeg,
// smup //      "  1. compatibility potential                      ",
// smup //      spanend);
// smup //    g_fn_prtlin(writebuf);
// smup //
// smup //    sprintf(writebuf, "%s%s%s", spanbeg,
// smup //       "  2. both sides show positive personality traits  ",
// smup //      spanend);
// smup //    g_fn_prtlin(writebuf);
// smup //
// smup //    sprintf(writebuf, "%s%s%s", spanbeg,
// smup //       "                                                  ",
// smup //      spanend);
// smup //    g_fn_prtlin(writebuf);
// smup //
// smup //    gbl_we_are_in_PRE_block = 0; /* 1 = yes, 0 = no */
// smup //    g_fn_prtlin("</div>");  // end of explrelationship
// smup //
// smup //
// smup //
// smup //    g_fn_prtlin("<div class=\"appby\">");
// smup //    sprintf(writebuf, "produced by iPhone app %s", APP_NAME);
// smup //    g_fn_prtlin(writebuf);
// smup //    g_fn_prtlin("</div>");  // end of appby
// smup //
// smup //    //g_fn_prtlin("<h4><span style=\"background-color:#FFBAC7;\">&nbspThis report is for entertainment purposes only.&nbsp</span></h4>");
// smup //
// smup //    g_fn_prtlin("<div class=\"entertainment\">");
// smup //    //g_fn_prtlin("<span style=\"background-color:#FFBAC7;\">&nbspThis report is for entertainment purposes only.&nbsp</span>");
// smup //    g_fn_prtlin("This report is for entertainment purposes only.");
// smup //    g_fn_prtlin("</div>");  // end of appby
// smup //    g_fn_prtlin("<div><br><br></div>");
// smup //
// smup 
// smup 
// smup     sprintf(writebuf, "fill|before goodrelationship");
// smup     g_fn_prtlin(writebuf);
// smup     sprintf(writebuf, "fill|in goodrelationship at beg");
// smup     g_fn_prtlin(writebuf);
// smup 
// smup //    sprintf(writebuf, "goodrelationship|details in cocoa");
// smup //    g_fn_prtlin(writebuf);
// smup 
// smup //    sprintf(writebuf, "will|            Your intense willpower          ");   // webview
// smup       sprintf(writebuf, "goodrelationship|             A Good Relationship            ");
// smup       g_fn_prtlin(writebuf);
// smup       sprintf(writebuf, "goodrelationship|             usually has 2 things           ");
// smup       g_fn_prtlin(writebuf);
// smup       sprintf(writebuf, "goodrelationship|           1. compatibility potential       ");
// smup       g_fn_prtlin(writebuf);
// smup       sprintf(writebuf, "goodrelationship|           2. both sides show positive      ");
// smup       g_fn_prtlin(writebuf);
// smup       sprintf(writebuf, "goodrelationship|              personality traits            ");
// smup       g_fn_prtlin(writebuf);
// smup 
// smup 
// smup     sprintf(writebuf, "fill|in goodrelationship at end");
// smup     g_fn_prtlin(writebuf);
// smup     sprintf(writebuf, "fill|before produced by");
// smup     g_fn_prtlin(writebuf);
// smup     sprintf(writebuf, "prod|produced by iPhone app %s", APP_NAME);
// smup     g_fn_prtlin(writebuf);
// smup     sprintf(writebuf, "fill|before entertainment");
// smup     g_fn_prtlin(writebuf);
// smup     sprintf(writebuf, "purp|This report is for entertainment purposes only.");
// smup     g_fn_prtlin(writebuf);
// smup 
//
// smup   rb  // webview version ends   ----------------------------------------------------------------
//
// smup   else
// smup   lb  // start browser version   ----------------------------------------------------------------
//


// start browser version   ---------- just_2  ---------------------------------------------

//    g_fn_prtlin("<div><br><br></div>");

trn("browser good relationship #1");

//    g_fn_prtlin("<pre>");
//    gbl_we_are_in_PRE_block = 1; /* 1 = yes, 0 = no */
//    g_fn_prtlin( "                                                  ");
//    g_fn_prtlin( "     a GOOD RELATIONSHIP usually has 2 things     "); // 
//    g_fn_prtlin( "  1. compatibility potential                      ");
//    g_fn_prtlin( "  2. both sides show positive personality traits  ");
//    g_fn_prtlin( "                                                  ");
//    gbl_we_are_in_PRE_block = 0; /* 1 = yes, 0 = no */
//    g_fn_prtlin("</pre>");


//  g_fn_prtlin("<div style=\"padding: 2em; color: rgb(0,0,0); margin-left: auto;  margin-right: auto; margin-bottom: 5vh; border-style: solid; border-width: 0.33vw; border-color: rgb(84,64,16); text-align: left; background-color: rgb(255,255,255); font-size: 75%; font-weight: normal; width: 80%; \" >");
//  g_fn_prtlin("<div class=\"cssCgoodrel\" >");

  g_fn_prtlin("<div class=\"cssDIVnugget BGimageNUGGETs\" >");

//  g_fn_prtlin( "<div style='text-align: center;'><span class=yellowShine>a GOOD RELATIONSHIP</span> has 21things<br></div>");
//    g_fn_prtlin( "<div style='text-align: center;'><span class=yellowShine>a GOOD RELATIONSHIP</span> has 2 things</div>");
    g_fn_prtlin( "<div style='text-align: center;'><span class=yellowShine>a GOOD RELATIONSHIP</span><br>has 2 things</div>");

    g_fn_prtlin( "<div id='good12Container' style='width: fit-content;  margin: 0 auto;' >");
      g_fn_prtlin( "<div style='text-align:   left; padding-left: 0.5em;'>1. compatibility potential<br></div>");
//      g_fn_prtlin( "<div style='text-align:   left; padding-left: 0.5em;'>2. both sides show positive personality traits</div>");
      g_fn_prtlin( "<div style='text-align:   left; padding-left: 0.5em;'>2. both sides show positive traits</div>");
  //  g_fn_prtlin( "</div>");

    g_fn_prtlin( "</div>"); // is = good12Container

  g_fn_prtlin( "</div>"); // class = cssDIVnugget

//<.>
//     //    HOW TO center a div horizontally   HOW TO center a div horizontally   HOW TO center a div horizontally   HOW TO center a div horizontally   HOW TO center a div horizontally   
//     //
//     //           width : 94% ;  margin: 0 auto ;
//     //         
//     //    Any width less than the containing <div> will work.
//     //    The margin: 0 auto is what does the actual centering.
//<!--  CITYPROVCOUN FIELD
//-->
//  <div id='DIV_cityprovcoun' 
//    style='
//color: RGB(253, 181, 49);
//      width: 80%;   margin: 0 auto;
//<.>
//


//  g_fn_prtlin( "<div style=\"text-align: center; font-size: 66%; margin-top: 2vh; \" >produced by free app from iGo2stars.org</div>");
  g_fn_prtlin( "<div class=\"iHaveAPP_DESC\" style=\"text-align: center; font-size: 66%; margin-top: 2vh; \" >produced by appDESCgoesHERE</div>");


  g_fn_prtlin( "<div style=\"text-align: center; font-size: 66%; font-weight: normal; color:#FF0000;\">This report is for entertainment purposes only</div><div><br></div>" );


//
//  p_fn_prtlin( "<div style=\"text-align: center; font-size: 66%; margin-top: 2vh; \" >produced by free app from iGo2stars.org</div>");
//  p_fn_prtlin( "<div style=\"text-align: center; font-size: 66%; font-weight: bold; color:#FF0000;\">This report is for entertainment purposes only</div><div><br></div>" );
//
//
//
//  p_fn_prtlin("<div style=\" margin-left: auto;  margin-right: auto; margin-bottom: 5vh; border-style: solid; border-width: 0.33vw; border-color: rgb(42,32,8); text-align: center; background-color: rgb(255,255,255); font-size: 66%; width: 80%; \" >");
//  p_fn_prtlin( "           Your intense willpower          ");
//  p_fn_prtlin( "      can overcome challenging traits      ");
//  p_fn_prtlin( "        and magnify favorable ones         ");
//  p_fn_prtlin( "</div>");
//
//
//
//


//trn("browser good relationship #2");
//    sprintf(writebuf, "<h5><br><br>produced by iPhone app %s</h5>", APP_NAME);
//    g_fn_prtlin(writebuf);
//    g_fn_prtlin("<h4><span style=\"background-color:#FFBAC7;\">&nbspThis report is for entertainment purposes only.&nbsp</span></h4>");


//    g_fn_prtlin("<div> <span style=\"font-size: 1.0em\"><br>produced by iPhone app Me and my BFFs</span><br><br><span style=\"font-size: 0.9em; font-weight: bold; color:#FF0000;\">This report is for entertainment purposes only.</span></div><div><br></div>");


//  char workProducedBy[256];
//  sprintf(workProducedBy,
//    "<div> <span style=\"font-size: 1.0em\"><br>produced by iPhone app %s</span><br><br><span style=\"font-size: 0.9em; font-weight: bold; color:#FF0000;\">This report is for entertainment purposes only.</span></div><div><br></div>" , 
//    APP_NAME
//  ); 
//
//  g_fn_prtlin( workProducedBy );



trn("browser good relationship #3");
//    g_fn_prtlin("\n</body>\n");
//    g_fn_prtlin("</html>");

//  rb // browser version  -----------------------------------------------------------------
// browser version  -----------------------------------------------------------------


//
//  fflush(Fp_g_HTML_file);
//  /* close output HTML file
//  */
//  if (fclose(Fp_g_HTML_file) == EOF) {
//    ;
///* trn("FCLOSE FAILED !!!   #1  "); */
//  } else {
///* trn("FCLOSE SUCCESS !!!  #1  "); */
//    ;
//  };
//


return (0);
trn("finished make_html_file_just_2_people()");

//  return arg_space_for_HTML_ju2;

} /* end of make_html_file_just_2_people() */ 



// input is like:
//        // lin=[stars|        easy ++++++++++++++++++++++++++++++                                                 ]__
//        // lin=[stars|   difficult ----------                                                                     ]__
// return positive number of '+' or negative number of '-
//
int get_how_many(char *in_doclin)
{
//ksn(in_doclin);
//  char mys[512];
//  char *mysp;
  int i,j,cnt;
  i = 0;
  j = 0;
                //  for (i=0; in_doclin[i]; in_doclin[i] == '+' ? i++ : *in_doclin++);
  cnt = 0;;
  for (i=0; in_doclin[i] != '\0'; i++) {
     if (in_doclin[i] == '+') cnt = cnt + 1;
  }
  if (cnt != 0) return cnt;

  cnt = 0;;
  for (i=0; in_doclin[i] != '\0'; i++) {
     if (in_doclin[i] == '-') cnt = cnt + 1;
  }
  if (cnt != 0) return (cnt * -1) ;

  return 1;  // 0 if not + or -
} // end of  get_how_many(char *in_doclin)



/* put label in field of 82, 2sp at end and beg
*/
void put_category_label(char *category_text, int inlen) 
{
tn();trn("CATEGORY OUTPUT"); ks(category_text);ki(inlen);
//  int len_label, num_spaces_at_end;
  int            num_spaces_at_end;
  char sformat[32], category_with_span[256];
 
/*   num_spaces_at_end = 92 - 13 - len_label + 1; */
/*   len_label = strlen(category_text); */
/*   num_spaces_at_end = 82 - 2 - len_label; */
  num_spaces_at_end = 82 - 2 - inlen;
//kin(num_spaces_at_end );
  sprintf(category_with_span,"<span class=\"cCat\">%s</span>", category_text);

  /* sformat is like "%13s%s%37s" where 37 is num_spaces_at_end
  */
/*   sprintf(sformat, "%%13s%%s%%%ds",  num_spaces_at_end); */

  char side_left[128];
  char side_right[128];
//  strcpy(side_left,  "<tr><td style=\"text-align: left; line-height: 1.8\">");  // 1.8 new for webview, ok on brow?
//  strcpy(side_left,  "<tr><td style=\"text-align: left; line-height: 1.8; font-weight: bold;\">");  // 1.8 new for webview, ok on brow?
//  strcpy(side_left,  "<tr><td style=\"text-align: left; line-height: 1.8; font-size: 1.8em;\">");  // 1.8 new for webview, ok on brow?

//  strcpy(side_left,  "<tr><td style=\"text-align: left; line-height: 1.8;\">");  // 1.8 new for webview, ok on brow?
//  strcpy(side_right, "</td></tr>");

//  strcpy(side_left,  "<tr><td style=\"text-align: left; line-height: 1.8;\"><span style=\"font-size: 1.2em; font-weight: bold;\">");




//  strcpy(side_left,  "<tr><td style=\"text-align: left;                 ;\"><span style=\"font-size: 1.2em; font-weight: bold;\">");
//  strcpy(side_left,  "<tr><td                                              ><span style=\"font-size: 1.2em; font-weight: bold;\">");
    strcpy(side_left,  "<tr><td style=\"text-align: center;                 ;\"><span style=\"font-size: 1.2em; font-weight: bold;\">");




  strcpy(side_right, "</span></td></tr>");


  if (strstr(gbl_g_in_html_filename, "webview") != NULL) {  // webview version
//    sprintf(sformat, "%%s%%2s%%s%%%ds%%s",  num_spaces_at_end);
//    sprintf(sformat, "%%s%%5s%%s%%%ds%%s",  num_spaces_at_end);
//    sprintf(sformat, "%%s%%4s%%s%%%ds%%s",  num_spaces_at_end);
//    sprintf(sformat, "%%s%%5s%%s%%%ds%%s",  num_spaces_at_end);
//    sprintf(sformat, "catlabel|%%s%%5s%%s%%%ds%%s",  num_spaces_at_end);
//    sprintf(sformat, "catlabel|%%%ds",  num_spaces_at_end);
    sprintf(sformat, "catlabel|%%s");
    sprintf(writebuf, sformat,
      category_text
    );

  } else {
//    sprintf(sformat, "%%s%%2s%%s%%%ds%%s",  num_spaces_at_end);
//    sprintf(writebuf, sformat,
//      side_left,
//      " ",
//      category_with_span,
//      " ",
//      side_right
//    );
//tn();trn("LABEL=");ks(writebuf);

// eg below
//<tr><td style="text-align: center;                 ;"><span style="font-size: 1.2em; font-weight: bold;">  <span class="cCat">CLOSENESS </span>                                                                      </span></td></tr>

    sprintf(writebuf, "<br><tr><td style=\"text-align: center;\"><span style=\"font-size: 1.2em; font-weight: bold;\">  <span class=\"cCat\">%s</span></span></td></tr>",  category_text);

  }



  g_fn_prtlin(writebuf);


} /* end of  put_category_label(category_text)  */



/* WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW */
/* WWWWWWWWWWWWWWWWWWWWWW  trait rank   WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW */
/* WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW */



// make_html_file_trait_rank() not used  20210402
//int make_html_file_trait_rank( /* in grphtm.c */
//  char *group_name,
//  int   num_persons_in_grp,
//  char *trait_name,         /* could be  "Best Calendar Year nnnn" */
//  char *in_html_filename,           /* in grphtm.c */
//  struct trait_report_line  *in_trait_lines[],
//  int   in_trait_lines_last_idx,
//  char *grp_average_trait_scores_csv
//)
//{
//  char rowcolor[128];
//  int i;
///*   char myyear[8], c; */
//  char c;
///*   int i, top_10, top_25, median, bot_25, bot_10; */
///*   int is_top_10_done; */
///*   int is_top_25_done; */
///*   int is_median_done;   */
///*   int is_bot_25_done;  */
///*   int is_bot_10_done;  */
///*   int is_print_good_milestone_at_end; * catch case- all scores are over good * */
///*   int num_pairs_to_rank; */
///*   int k,FORBIDDEN[64], ichk, rank_number, is_highlight_FORBIDDEN; */
//  int  rank_number;
//
//  strcpy(gbl_gfnameHTML, in_html_filename);
//
//trn("in make_html_file_trait_rank() 1");
////ksn(group_name); ki(num_persons_in_grp); ks(trait_name);
////ksn(in_html_filename); 
////ki(in_trait_lines_last_idx);
////ksn(grp_average_trait_scores_csv); 
//
//
//  strcpy(gbl_format_as, "trait rank");
///* b(30);ksn(trait_name); */
//  strcpy(gbl_trait_name, trait_name);
///* ksn(grp_average_trait_scores_csv); */
///* strcpy(gblGrpAvgTraitScoresCSV2, "abcxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"); */
///* ksn(gblGrpAvgTraitScoresCSV2); */
//  strcpy(gblGrpAvgTraitScoresCSV2, grp_average_trait_scores_csv);
//
///*   num_pairs_to_rank =  num_persons_in_grp * (num_persons_in_grp - 1) / 2; */
//  gbl_we_are_in_PRE_block = 0;  /* init to false */
//
//
//  /* open output HTML file
//  */
//  if ( (Fp_g_HTML_file = fopen(in_html_filename, "w")) == NULL ) {
//    rkabort("Error  on open html for trait rank grphtm.c.  fopen().");
//  }
//
//  put_top_of_html_group_rpt(group_name); 
//
//
//  /* '_' was for html filename */
///*   scharswitch(trait_name, '_', ' '); */
//
//  if (    strstr(trait_name, "Best Calendar Year") != NULL) {
//
//  g_fn_prtlin("  <div><br></div>");
//    sprintf(writebuf, "  <h1>%s</h1>", trait_name);
//    g_fn_prtlin(writebuf);
//    sprintf(writebuf, "\n  <h2>in Group \"%s\"</h2>", group_name);
//    g_fn_prtlin(writebuf);
//
///*     g_fn_prtlin("<pre>");
//*     gbl_we_are_in_PRE_block = 1;
//*     g_fn_prtlin("");
//*     strcpy(myyear, &trait_name[strlen(trait_name) - 4]);
//*     sprintf(writebuf, " Who has the best and worst %s ? ", myyear);
//*     g_fn_prtlin(writebuf);
//*     g_fn_prtlin("");
//*     gbl_we_are_in_PRE_block = 0;
//*     g_fn_prtlin("</pre>");
//*/
//
//  } else if (strstr(trait_name, "Best Day on") != NULL) {
//
//
///*     sprintf(writebuf, "  <h1>%s</h1>", trait_name);
//*     g_fn_prtlin(writebuf);
//*     sprintf(writebuf, "\n  <h2>in Group \"%s\"</h2>", group_name);
//*     g_fn_prtlin(writebuf);
//*/
//    /* sprintf(my_trait_name, "Best Day on |%s&nbsp %s %d %d", */
//    /*   <h1>Best Day on</h1> */
//    /*   <h2>Wed&nbsp May 21 2014</h2> */
//    /*   <h2>in Group "Ulli group"</h2> */
//
//    /* char *csv_get_field(char *csv_string, char *delim, int want_fieldnum); */
//  g_fn_prtlin("  <div><br></div>");
//    sprintf(writebuf, "  <h1>%s</h1>", csv_get_field(trait_name, "|", 1));
//    g_fn_prtlin(writebuf);
//    sprintf(writebuf, "  <h2>%s</h2>", csv_get_field(trait_name, "|", 2));
//    g_fn_prtlin(writebuf);
//
//    sprintf(writebuf, "\n  <h2>in Group \"%s\"</h2>", group_name);
//    g_fn_prtlin(writebuf);
//
//
//
///*     g_fn_prtlin("<pre>");
//*     gbl_we_are_in_PRE_block = 1;
//*     g_fn_prtlin("");
//*     g_fn_prtlin(" Who has the best and worst day? ");
//*     g_fn_prtlin("");
//*     gbl_we_are_in_PRE_block = 0;
//*     g_fn_prtlin("</pre>");
//*/
//
////  } else if (   strstr(trait_name, "ups and downs") != NULL
////             || strstr(trait_name, "Ups and downs") != NULL) {
/////*     sprintf(writebuf, "  <h1>Person with Most Ups and Downs</h1>"); */
////  g_fn_prtlin("  <div><br></div>");
////    sprintf(writebuf, "  <h1><span style=\"line-height:125%%;\">Person with Biggest<br>Ups and Downs in Life</span></h1>");
////    g_fn_prtlin(writebuf);
////    sprintf(writebuf, "\n  <h2>in Group \"%s\"</h2>", group_name);
////    g_fn_prtlin(writebuf);
//     
//  } else if (   strstr(trait_name, "down to earth") != NULL
//             || strstr(trait_name, "Down to earth") != NULL) {
//
//  g_fn_prtlin("  <div><br></div>");
//    sprintf(writebuf, "  <h1><span style=\"line-height:125%%;\">Most Down-to-earth Person</span></h1>");
//    g_fn_prtlin(writebuf);
//
//    sprintf(writebuf, "\n  <h2>in Group \"%s\"</h2>", group_name);
//    g_fn_prtlin(writebuf);
//
//  } else {
//    c = trait_name[0];
//    trait_name[0] = toupper(c); /* capitalize 1st ch */
//  g_fn_prtlin("  <div><br></div>");
//    sprintf(writebuf, "  <h1>Most %s Person</h1>", trait_name); 
//    g_fn_prtlin(writebuf);
//    sprintf(writebuf, "\n  <h2>in Group \"%s\"</h2>", group_name);
//    g_fn_prtlin(writebuf);
//  }
//
//
//  /* start of table of ranking data  ----------------------------------
//  */
//
//
//  /* here we output ranking data lines in the table
//  */
//    
//    
//  g_fn_prtlin(" ");
//  g_fn_prtlin( "<table>");
///*   g_fn_prtlin( "  <tr> <th>Rank</th> <th>Score</th> <th colspan=\"2\">Pair of Group Members</th> </tr>"); */
///*   g_fn_prtlin( "  <tr> <th>Rank in<br>Group</th> <th>Group Member</th> <th>Score</th> <th>Benchmark</th></tr>"); */
///*   g_fn_prtlin( "  <tr> <th>Rank</th> <th>Group Member</th> <th>Score</th> <th>Benchmark</th></tr>"); */
//
//  if (strcmp(gbl_format_as, "trait rank") == 0) {
//
///*  eg   g_fn_prtlin( "<tr class=\"cGr2\"><td></td><td></td><td> 373 </td><td>Very High</td></tr>"); */
//    g_fn_prtlin( "  <tr class=\"cPerGreen3\" > <th class=\"cPerGreen3\" ></th> <th class=\"cPerGreen3\" >Group Member</th> <th class=\"cPerGreen3\"> Score</th> <th class=\"cPerGreen3\" ></th></tr>");
////    g_fn_prtlin( "    .cPerGreen3 {background-color: #b0d0ff;}");  // darker blue for Most title and footer
//
//  } else {
//    g_fn_prtlin( "  <tr> <th></th> <th>Group Member</th> <th>Score</th> <th></th></tr>");
//  }
//
//
//
//#ifdef PUT_BACK_COMMENTED_OUT_STUFF /****************************************/
//*   /* Get FORBIDDEN rank numbers not to put highlight on every 4 because
//*   *  they are within 3 of a colored milestone line (avoid color clutter)
//*   */
//* 
//*   /* nums are percents of world-wide scores */
//* /*   top_10 = 203;
//* *   top_25 = 180;
//* *   median = 154;
//* *   bot_25 = 135;
//* *   bot_10 = 116;
//* */
//* /*   top_10 = 373;
//* *   top_25 = 213;
//* *   median = 100;
//* *   bot_25 =  42;
//* *   bot_10 =  18;
//* */
//* 
//*   top_10 = 90;
//*   top_25 = 75;
//*   median = 50;
//*   bot_25 = 25;
//*   bot_10 = 10;
//* 
//*   is_top_10_done = 0;  /* 0=no, 1=yes */
//*   is_top_25_done = 0;  /* 0=no, 1=yes */
//*   is_median_done = 0;  
//*   is_bot_25_done = 0; 
//*   is_bot_10_done = 0; 
//* 
//* 
//* 
//*   /* read thru all the avg_lines to get FORBIDDEN
//*   */
//*   int last_rank_number;
//*   for (ichk=0; ichk <=63; ichk++) FORBIDDEN[ichk] = 0;  /* init */
//*   k = 0;  /* INIT FORBIDDEN IDX */
//*   for (i=0; i <= in_trait_lines_last_idx; i++) {
//*     rank_number = in_trait_lines[i]->rank_in_group;
//* 
//*     if (rank_number != 0) {
//*       last_rank_number = rank_number;
//*       continue;
//*     }
//* /* trn("forwards");ki(last_rank_number); */
//*     /* here we are on a benchmark line reading forwards
//*     *  FORBID highlighting on rank_number and the two lines before that (3 lines tot)
//*     *  *and* the 3 lines after
//*     */
//*     FORBIDDEN[++k] = last_rank_number;
//*     if (last_rank_number-1 > 0) FORBIDDEN[++k] = last_rank_number-1;
//*     if (last_rank_number-2 > 0) FORBIDDEN[++k] = last_rank_number-2;
//*     if (last_rank_number+1 <= in_trait_lines_last_idx) FORBIDDEN[++k] = last_rank_number+1;
//*     if (last_rank_number+2 <= in_trait_lines_last_idx) FORBIDDEN[++k] = last_rank_number+2;
//*     if (last_rank_number+3 <= in_trait_lines_last_idx) FORBIDDEN[++k] = last_rank_number+3;
//*   }
//#endif /* ifdef PUT_BACK_COMMENTED_OUT_STUFF ********************************/
//
//
//  /* for each rank line
//  */
//  int total_trait_score, average_trait_score;
//  total_trait_score = 0;  /* init */
//  for (i=0; i <= in_trait_lines_last_idx; i++)  {  /* NOTE: this for() is 130 lines */
//
//    rank_number = in_trait_lines[i]->rank_in_group;
//
//    /* intercept milestone lines (already sorted),
//    *  and color appropriately
//    */
//
//    if (strcmp(in_trait_lines[i]->person_name, "~~~hilite-top10") == 0) {
///*       g_fn_prtlin( "<tr class=\"cGr2\"><td></td><td></td><td> 373 </td><td>Very High</td></tr>"); */
///*       g_fn_prtlin( "<tr class=\"cGr2\"><td></td><td></td><td> 90 </td><td>Very High</td></tr>"); */
///*       g_fn_prtlin( "<tr class=\"cGr2\"><td></td><td></td><td> 90 </td><td>Great</td></tr>"); */
//
//      /* if this is best cal year, use benchmark labels  great and OMG
//      */
//      if (    strstr(trait_name, "Best Calendar Year") != NULL
//           || strstr(trait_name, "Best Day on")        != NULL) {
//        g_fn_prtlin( "<tr class=\"cGr2\"><td></td><td></td><td> 90 </td><td>Great</td></tr>");
//        continue;
//      } else {
////        g_fn_prtlin( "<tr class=\"cGr2\"><td></td><td></td><td> 90 </td><td>Very High</td></tr>");
////        if (i % 2 == 0)
////          g_fn_prtlin( "<tr class=\"cPerGreen1\"><td></td><td></td><td> 90 </td><td>Very High</td></tr>");
////        else
////          g_fn_prtlin( "<tr class=\"cPerGreen2\"><td></td><td></td><td> 90 </td><td>Very High</td></tr>");
//
//        g_fn_prtlin( "<tr class=\"cPerGreen1\"><td></td><td></td><td> 90 </td><td>Very High</td></tr>");
//        continue;
//      }
//    }
//
////    if (strcmp(in_trait_lines[i]->person_name, "zzzhilite-good") == 0) 
//    if (strcmp(in_trait_lines[i]->person_name, "~~~hilite-good") == 0) {
///*       g_fn_prtlin( "<tr class=\"cGre\"><td></td><td></td><td>213 </td><td>High</td></tr>"); */
///*       g_fn_prtlin( "<tr class=\"cGre\"><td></td><td></td><td> 75 </td><td>High</td></tr>"); */
///*       g_fn_prtlin( "<tr class=\"cGre\"><td></td><td></td><td> 75 </td><td>Good</td></tr>"); */
//      if (    strstr(trait_name, "Best Calendar Year") != NULL
//           || strstr(trait_name, "Best Day on")        != NULL) {
//        g_fn_prtlin( "<tr class=\"cGre\"><td></td><td></td><td> 75 </td><td>Good</td></tr>");
//        continue;
//      } else {
////        if (i % 2 == 0)
////          g_fn_prtlin( "<tr class=\"cPerGreen1\"><td></td><td></td><td> 75 </td><td>Good</td></tr>");
////        else
////          g_fn_prtlin( "<tr class=\"cPerGreen2\"><td></td><td></td><td> 75 </td><td>Good</td></tr>");
//
//        g_fn_prtlin( "<tr class=\"cPerGreen2\"><td></td><td></td><td> 90 </td><td>Good</td></tr>");
//        continue;
//      }
//    }
//
//    if (strcmp(in_trait_lines[i]->person_name, "~~~hilite-trait") == 0) {
///*       g_fn_prtlin( "<tr class=\"cNeu\"><td></td><td></td><td> 100 </td><td>Median</td></tr>"); */
////      g_fn_prtlin( "<tr class=\"cNeu\"><td></td><td></td><td> 50 </td><td>Average</td></tr>");
////      continue;
//      if (    strstr(trait_name, "Best Calendar Year") != NULL
//           || strstr(trait_name, "Best Day on")        != NULL) {
//        g_fn_prtlin( "<tr class=\"cNeu\"><td></td><td></td><td> 50 </td><td>Average</td></tr>");
//        continue;
//      } else {
////        if (i % 2 == 0)
////          g_fn_prtlin( "<tr class=\"cPerGreen1\"><td></td><td></td><td> 50 </td><td>Average</td></tr>");
////        else
////          g_fn_prtlin( "<tr class=\"cPerGreen2\"><td></td><td></td><td> 50 </td><td>Average</td></tr>");
//
//        g_fn_prtlin( "<tr class=\"cPerGreen1\"><td></td><td></td><td> 90 </td><td>Average</td></tr>");
//        continue;
//      }
//    }
//
//    if (strcmp(in_trait_lines[i]->person_name, "   hilite-bad") == 0) {
///*       g_fn_prtlin( "<tr class=\"cRed\"><td></td><td></td><td> 42 </td><td>Low</td></tr>"); */
///*       g_fn_prtlin( "<tr class=\"cRed\"><td></td><td></td><td> 25 </td><td>Low</td></tr>"); */
///*       g_fn_prtlin( "<tr class=\"cRed\"><td></td><td></td><td> 25 </td><td>Low</td></tr>"); */
///*       g_fn_prtlin( "<tr class=\"cRed\"><td></td><td></td><td> 25 </td><td>Stress</td></tr>"); */
//      if (    strstr(trait_name, "Best Calendar Year") != NULL
//           || strstr(trait_name, "Best Day on")        != NULL) {
//        g_fn_prtlin( "<tr class=\"cRed\"><td></td><td></td><td> 25 </td><td>Stress</td></tr>");
//        continue;
//      } else {
////        if (i % 2 == 0)
////          g_fn_prtlin( "<tr class=\"cPerGreen1\"><td></td><td></td><td> 25 </td><td>Low</td></tr>");
////        else
////          g_fn_prtlin( "<tr class=\"cPerGreen2\"><td></td><td></td><td> 25 </td><td>Low</td></tr>");
//
//        g_fn_prtlin( "<tr class=\"cPerGreen2\"><td></td><td></td><td> 90 </td><td>Low</td></tr>");
//        continue;
//      }
//    }
//
//    if (strcmp(in_trait_lines[i]->person_name, "   hilite-bot10") == 0) {
///*       g_fn_prtlin( "<tr class=\"cRe2\"><td></td><td></td><td> 18 </td><td>Very Low</td></tr>"); */
///*       g_fn_prtlin( "<tr class=\"cRe2\"><td></td><td></td><td> 10 </td><td>Very Low</td></tr>"); */
///*       g_fn_prtlin( "<tr class=\"cRe2\"><td></td><td></td><td> 10 </td><td>OMG</td></tr>"); */
//      if (    strstr(trait_name, "Best Calendar Year") != NULL
//           || strstr(trait_name, "Best Day on")        != NULL) {
//        g_fn_prtlin( "<tr class=\"cRe2\"><td></td><td></td><td> 10 </td><td>OMG</td></tr>");
//        continue;
//      } else {
////        if (i % 2 == 0)
////          g_fn_prtlin( "<tr class=\"cPerGreen1\"><td></td><td></td><td> 10 </td><td>Very Low</td></tr>");
////        else
////          g_fn_prtlin( "<tr class=\"cPerGreen2\"><td></td><td></td><td> 10 </td><td>Very Low</td></tr>");
//
//        g_fn_prtlin( "<tr class=\"cPerGreen1\"><td></td><td></td><td> 90 </td><td>Very Low</td></tr>");
//        continue;
//      }
//    }
//
//
//
//      /* 201404  this is now distracting, with better colors up
//      */
//#ifdef PUT_BACK_COMMENTED_OUT_STUFF /****************************************/
// *     /* HIGHLIGHT every 5 rows, unless this rank_number is in FORBIDDEN list[]
// *     */
// *     strcpy(rowcolor, "");  /* default no highlight */
// * 
// *     if (in_trait_lines_last_idx + 1 > 36 &&  /* small rpt= no hilite */
// *         i != in_trait_lines_last_idx)        /* no highlight last line */
// *     {
// *       is_highlight_FORBIDDEN = 0;
// *       for (ichk=0; ichk <=63; ichk++) {
// *         if (rank_number == FORBIDDEN[ichk]) {
// *           is_highlight_FORBIDDEN = 1; /* no highlight, FORBIDDEN */
// *           break;
// *         }
// *       }
// * 
// *       /* change from every 4 to every 5
// *       */
// *       /* if (rank_number % 4 == 0  && is_highlight_FORBIDDEN == 0 )  */
// *       if (rank_number % 5 == 0  && is_highlight_FORBIDDEN == 0 ) {
// *         strcpy(rowcolor, " class=\"row4\"");
// *       } else {
// *         strcpy(rowcolor, "");
// *       }
// *     }
//#endif /* ifdef PUT_BACK_COMMENTED_OUT_STUFF ********************************/
//
//
//    /* output ranking line
//    */
//
////tn();tr("==================");ks(trait_name);tn();
///* tn();ks(trait_name);
//* int iiscore;
//* iiscore = in_trait_lines[i]->score ;tn();b(123);ki(iiscore);
//*/
//
///*  in_trait_lines[i]->score = mapBenchmarkNumToPctlRank(iiscore); */
///* iiscore = in_trait_lines[i]->score ;tn();b(124);ki(iiscore); */
//
//    /* put default ROWCOLOR
//    */
///* tn();trn("SETTING ROWCOLOR 11111");tn(); */
//    if (    strstr(trait_name, "Best Calendar Year") != NULL
//         || strstr(trait_name, "Best Day on")        != NULL) {
//
//      if (in_trait_lines[i]->score >= 90) strcpy(rowcolor, " class=\"cGr2\"");
//      if (in_trait_lines[i]->score <  90 &&
//          in_trait_lines[i]->score >= 75) strcpy(rowcolor, " class=\"cGre\"");
//      if (in_trait_lines[i]->score <  75 &&
//          in_trait_lines[i]->score >  25) strcpy(rowcolor, " class=\"cNeu\"");
//      if (in_trait_lines[i]->score <= 25 &&
//          in_trait_lines[i]->score >  10) strcpy(rowcolor, " class=\"cRed\"");
//      if (in_trait_lines[i]->score <= 10) strcpy(rowcolor, " class=\"cRe2\"");
//    } else {
////      if (i % 2 == 0)  // alternate colors
////        strcpy(rowcolor, " class=\"cPerGreen1\"");
////      else
////        strcpy(rowcolor, " class=\"cPerGreen2\"");
//
//      if (in_trait_lines[i]->score >= 90) strcpy(rowcolor, " class=\"cPerGreen1\"");
//      if (in_trait_lines[i]->score <  90 &&
//          in_trait_lines[i]->score >= 75) strcpy(rowcolor, " class=\"cPerGreen2\"");
//      if (in_trait_lines[i]->score <  75 &&
//          in_trait_lines[i]->score >  25) strcpy(rowcolor, " class=\"cPerGreen1\"");
//      if (in_trait_lines[i]->score <= 25 &&
//          in_trait_lines[i]->score >  10) strcpy(rowcolor, " class=\"cPerGreen2\"");
//      if (in_trait_lines[i]->score <= 10) strcpy(rowcolor, " class=\"cPerGreen1\"");
//
//    }
//
//
///*     sprintf(writebuf, "<tr%s><td>%d</td><td> %s</td><td>%d</td><td></td></tr>", */
///*     sprintf(writebuf, "<tr%s><td>%d</td><td>%s</td><td>%d</td><td></td></tr>", */
//   
//    char score_as_char[4];
//    if (in_trait_lines[i]->score == -1) {   /* exclude */
///*       strcpy(score_as_char, "xx"); */
//      strcpy(score_as_char, "na");
//    } else {
//      sprintf(score_as_char, "%d", in_trait_lines[i]->score);
//    }
///* tn();ksn(score_as_char); */
//
///*     sprintf(writebuf, "<tr%s><td>%d </td><td> %s</td><td>%d </td><td></td></tr>", */
//    sprintf(writebuf, "<tr%s><td>%d </td><td> %s</td><td>%s </td><td></td></tr>",
//      rowcolor,       
//      in_trait_lines[i]->rank_in_group,
//      in_trait_lines[i]->person_name,
///*       in_trait_lines[i]->score */
//      score_as_char
//    );
//    g_fn_prtlin(writebuf);
//
//    total_trait_score = total_trait_score + in_trait_lines[i]->score;
///* int sco; sco = in_trait_lines[i]->score; kin(sco); ki(total_trait_score); */
//
//  } /* for each rank_line */
//
//  average_trait_score = (int) floor (
//    ( (double)total_trait_score / (double)num_persons_in_grp )
//    + 0.5 );
//
//
//  g_fn_prtlin( "</table>");
//  g_fn_prtlin(" ");
//
//
//  if (    strstr(trait_name, "Best Calendar Year") != NULL) {
//    g_fn_prtlin("<pre>");
//    gbl_we_are_in_PRE_block = 1;  /* true */
//    g_fn_prtlin("");
//    g_fn_prtlin("  Check out the report \"Calendar Year\".  ");
//    g_fn_prtlin("");
//    gbl_we_are_in_PRE_block = 0;  /* false */
//    g_fn_prtlin("</pre>");
//
//    g_fn_prtlin("<div></div>");
//    g_fn_prtlin("<pre>");
//    gbl_we_are_in_PRE_block = 1;  
//    g_fn_prtlin("");
//    g_fn_prtlin( "  Your intense willpower can         ");
//    g_fn_prtlin( "  overcome and control your destiny  ");
//    g_fn_prtlin("");
//    gbl_we_are_in_PRE_block = 0; 
//    g_fn_prtlin("</pre>");
//
//  } else if ( strstr(trait_name, "Best Day on") != NULL) {
//
//
//    g_fn_prtlin("  <pre>");         
//    gbl_we_are_in_PRE_block = 1; 
//    g_fn_prtlin("");
//    g_fn_prtlin("  This measures short-term influences  ");
//    g_fn_prtlin("  lasting a few hours or a day or two.  ");
//    g_fn_prtlin("");
//    g_fn_prtlin("  More important long term influences are  ");
//    g_fn_prtlin("  in the graphical report \"Calendar Year\"  ");
//    g_fn_prtlin("  and in the group report \"Best Year\"  ");
//    g_fn_prtlin("");
//    gbl_we_are_in_PRE_block = 0; 
//    g_fn_prtlin("</pre>");
//
//
//  } else {
//    // trait
//// eg  g_fn_prtlin( "  <tr class=\"cPerGreen3\" > <th></th> <th>Group Member</th> <th>Score</th> <th></th></tr>");
//    g_fn_prtlin( "<pre class=\"cPerGreen3\"> ");
//    gbl_we_are_in_PRE_block = 1;  /* true */
//    g_fn_prtlin("");
////    sprintf( writebuf,"  Check out the report \"Personality\".  ");
////tn();trn("ttttttttttttttttttttttttttttttttttttttt");ksn(gbl_trait_name);
//      g_fn_prtlin("  The score measures HOW MUCH of the    ");
////    g_fn_prtlin("  trait "down to earth" the person has  "); // longest
//    sprintf(writebuf, "  trait \"%s\" the person has. ", gbl_trait_name);
//    g_fn_prtlin(writebuf);
//    g_fn_prtlin("");
//    g_fn_prtlin("  The score does NOT measure ");
////    g_fn_prtlin("  \"good\" or \"bad\".  ");
//    g_fn_prtlin("  challenging or favorable. ");
//    g_fn_prtlin("");
//    gbl_we_are_in_PRE_block = 0;  /* false */
//    g_fn_prtlin( "</pre>");
//    
//  }
//
//
//
///*   sprintf(writebuf, "<h5>produced by iPhone/iPad app named %s</h5>", APP_NAME); */
//  sprintf(writebuf, "<h5>produced by iPhone app %s</h5>", APP_NAME);
//  g_fn_prtlin(writebuf);
//
///*   g_fn_prtlin("<h4><span style=\"background-color:#FFBAC7;\">&nbsp&nbsp&nbsp&nbsp&nbsp  This report is for entertainment purposes only.&nbsp&nbsp&nbsp&nbsp&nbsp  </span></h4>"); */
//  g_fn_prtlin("<h4><span style=\"background-color:#FFBAC7;\">&nbspThis report is for entertainment purposes only.&nbsp</span></h4>");
//
//
//
//  g_fn_prtlin( "</body>");
//  g_fn_prtlin( "</html>");
//
//
//  fflush(Fp_g_HTML_file);
//  /* close output HTML file
//  */
//  if (fclose(Fp_g_HTML_file) == EOF) {
//    ;
///* trn("FCLOSE FAILED !!!   #2  "); */
//  } else {
//    ;
///* trn("FCLOSE SUCCESS !!!  #2  "); */
//  };
//
//  return(0);
//
//} /* end of make_html_file_trait_rank() */
//
// make_html_file_trait_rank() not used  20210402




/* &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& */
/* &&&&&&&&&&&&&&&&&&&&&&  whole_group  &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& */
/* &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& */



// make_html_file_whole_group() not used  20210402
//
//int make_html_file_whole_group( /* produce actual html file */
//  char *group_name,
//  int   num_persons_in_grp,
//  char *in_html_filename,           /* in grphtm.c */
//  struct rank_report_line  *in_rank_lines[],
//  int   in_rank_lines_last_idx,
//  char *instructions,      /* like "format as person_in_group" */
//                           /* like "return only html for table in string" */
//  char *string_for_table_only   /* 1024 chars max (its 9 lines formatted) */
//                                /* holds  html only  OR  compat score only */
//)
//

//int make_html_file_whole_group( /* produce actual html file */
//  char *group_name,
//  int   num_persons_in_grp,
//  char *in_html_filename,           /* in grphtm.c */
//  struct rank_report_line  *in_rank_lines[],
//  int   in_rank_lines_last_idx,
//  char *instructions,
//  char *string_for_table_only   /* 1024 chars max (its 9 lines formatted) */
//                                /* holds  html only  OR  compat score only */
//)
//{
//tn(); trn("in make_html_file_whole_group()   uuu");
//ksn(instructions);
//kin(num_persons_in_grp);
//
//kin(in_rank_lines_last_idx);
//                //    struct rank_report_line {
//                //      int  rank_in_group;
//                //      int  score;
//                //      char person_A[MAX_SIZE_PERSON_NAME+1];
//                //      char person_B[MAX_SIZE_PERSON_NAME+1];
//                //    };
//                //
//
//// for test                
//char myrnk[64]; 
//trn("at top of make_html_file_whole_group()   ");
//for (int ri = 0; ri <= in_rank_lines_last_idx; ri++ ) {
//sprintf(myrnk,"|%04d|%02d|%-15s|%-15s|",
//in_rank_lines[ri]->rank_in_group,  in_rank_lines[ri]->score,  in_rank_lines[ri]->person_A,  in_rank_lines[ri]->person_B );  
//ksn(myrnk);
//}
//// for test                
//
//                  // NOTE: there are 6 lines, score is in 1st line  (98)
//                //    per_emcc_my2.html:81525 _(in make_html_file_whole_group()   uuu)__
//                //    per_emcc_my2.html:81525 _instructions=[return only html for table in string]__
//                //    per_emcc_my2.html:81525 _num_persons_in_grp=[2]__
//                //    per_emcc_my2.html:81525 _in_rank_lines_last_idx=[5]__
//                //
//                //    _myrnk=[|0001|98|barron trump   |borje          |]__
//                //    _myrnk=[|0000|90|~~~~~~~~~~~~~~~|qhilite - top10|]__
//                //    _myrnk=[|0000|75|~~~~~~~~~~~~~~~|qhilite - good |]__
//                //    _myrnk=[|0000|50|~~~~~~~~~~~~~~~|qhilite - avg  |]__
//                //    _myrnk=[|0000|25|               |qhilite - bad  |]__
//                //    _myrnk=[|0000|10|               |qhilite - bot10|]__
//                //
//
//
//
//  gbl_is_grpone_or_grpall = 1;   // ensure full color in all lines in case filename has "webview"
//
//
///*   char group_report_type[32], */
//  char rowcolor[128];
//  int i;
///*   int top_10, top_25, median, bot_25, bot_10, s; */
///*   int is_top_10_done; */
///*   int is_top_25_done; */
///*   int is_median_done;   */
///*   int is_bot_25_done;  */
///*   int is_bot_10_done;  */
///*   int is_print_good_milestone_at_end; * catch case- all scores are over good * */
///*   int h,k,FORBIDDEN[64], rank_number; */
//  int h, rank_number;
//  int i_top_this_many, i_bot_this_many, num_pairs_to_rank;
//  int len_longest_name, lenA, lenB;
//  char sformat3[20];
//
//  strcpy(gbl_gfnameHTML, in_html_filename);
///* tn();tr("make_html_file_whole_group");ks(instructions); */
//
////  if (strstr(instructions, "return only") == NULL) {
////    trn("in make_html_file_whole_group()");
////  }  /* avoid dbmsg on non-rpt call */
//
//  i_top_this_many = 99999;  /* init to no top/bot restrictions */
//  i_bot_this_many = 99999;  /* init to no top/bot restrictions */
//  num_pairs_to_rank =  num_persons_in_grp * (num_persons_in_grp - 1) / 2;
//
//  gbl_we_are_in_PRE_block = 0;  /* init to false */
//  strcpy(global_instructions, instructions);
//  strcpy(gbl_format_as, instructions);
//
//
//
//
//  /* read thru all the rank_lines to get length of Longest Name for
//  *  formatting name pairs in one field
//  */
//  len_longest_name = 1;
//
//  for (i=0; i <= in_rank_lines_last_idx; i++) {
//
//    if (in_rank_lines[i]->rank_in_group == 0) continue;
//
//    // grab names for "html only" situation  (there is only 1 pair)
//    strcpy(gbl_person_A_first_pair, in_rank_lines[i]->person_A); // for "only html" return
//    strcpy(gbl_person_B_first_pair, in_rank_lines[i]->person_B); // for "only html" return
//
//    lenA = (int)strlen(in_rank_lines[i]->person_A);
//    lenB = (int)strlen(in_rank_lines[i]->person_B);
//    if(lenA > len_longest_name) len_longest_name = lenA;
//    if(lenB > len_longest_name) len_longest_name = lenB;
//  }
//
///* kin(len_longest_name);tn(); */
//
//  if (strcmp(global_instructions, "format as person_in_group") == 0) {
//    /* get name of compare_everyone_with
//    *  It will be person_A of first element where rank != 0
//    */
//    for(h=0; h <= in_rank_lines_last_idx; h++) {
//      if (in_rank_lines[h]->rank_in_group != 0) {
//        strcpy(gbl_compare_everyone_with,
//          in_rank_lines[h]->person_A);
//        /* for formatting name pairs
//         * (+1 avoids jammed appearance for person_in_group rpt)
//         */
//        len_longest_name = (int)strlen(gbl_compare_everyone_with) + 1;
//        break;
//      }
//    }
//  }
//
//
//  /* sprintf(instructions_for_top_bot,
//  *   "top_this_many=|%d|bot_this_many=|%d|", top_this_many, bot_this_many);
//  */
//  if (strstr(global_instructions, "top_this_many") != NULL) {
//    i_top_this_many = atoi(csv_get_field(global_instructions, "|", 2));
//    i_bot_this_many = atoi(csv_get_field(global_instructions, "|", 4));
//  }
//
//  /* Note:  incoming struct rank_report_line  *in_rank_lines[],
//  *  is sorted by score field
//  */
//
//  /* check for instructions to return string only
//  */
//  if (  strcmp(global_instructions, "return only html for table in string") == 0
//     || strcmp(global_instructions, "return only compatibility score"     ) == 0 ) {
//
//    ; /* DO NOT OPEN html file for write */
//
//  } else {
//    /* open output HTML file
//    */
//    if ( (Fp_g_HTML_file = fopen(in_html_filename, "w")) == NULL ) {
//      rkabort("Error  on grpall grphtm.c. html fopen().");
//    }
//  } /* check for instructions to return string only */
//
//  put_top_of_html_group_rpt(group_name); 
//
//
//  if (strcmp(global_instructions, "format as person_in_group") == 0) {
//    /* get name of compare_everyone_with
//    *  It will be person_A of first element where rank != 0
//    */
//    for(h=0; h <= in_rank_lines_last_idx; h++) {
//      if (in_rank_lines[h]->rank_in_group != 0) {
//        strcpy(gbl_compare_everyone_with, in_rank_lines[h]->person_A);
//        break;
//      }
//    }
///*     sprintf(writebuf, "  <h1>Best Match for %s</h1>", gbl_compare_everyone_with); */
//
///*     sprintf(writebuf, "  <h1>Best Match for <span class=\"cNam\">%s</span> </h1>", gbl_compare_everyone_with); */
///*     sprintf(writebuf, "  <h1>Best Match for %s </h1>", gbl_compare_everyone_with); */
//
//
//    g_fn_prtlin("<div><br></div>");
//    sprintf(writebuf, "  <h1>Best Match for %s </h1>", gbl_compare_everyone_with);
////    sprintf(writebuf, "  <h1>Best Match for <span class=\"cNam\">%s</span> </h1>", gbl_compare_everyone_with);
//
//    g_fn_prtlin(writebuf);
//
//    sprintf(writebuf, "\n  <h2>in Group \"%s\"</h2>", group_name);
//    g_fn_prtlin(writebuf);
//  } else {
//    g_fn_prtlin("  <div><br></div>");
//    g_fn_prtlin("  <h1>Best Match</h1>");
//    sprintf(writebuf, "\n  <h2>in Group \"%s\"</h2>", group_name);
//    g_fn_prtlin(writebuf);
//
//    if (strstr(global_instructions, "top_this_many") != NULL) {
//      g_fn_prtlin("  <h4><br><br><br>This report has over 300 lines, so<br><br><br><br><br>");
//
//      sprintf(writebuf, "we show only the Top %d and Bottom %d.</h4>",
//        i_top_this_many, i_bot_this_many);
//      g_fn_prtlin(writebuf);
//    }
//  }
//
//
//  /* start of table of ranking data  ----------------------------------
//  */
//
//  /* here we output ranking data lines in the table
//  */
//    
//  g_fn_prtlin(" ");
//  g_fn_prtlin( "<table>");
///*   g_fn_prtlin( "  <tr> <th>Rank</th> <th>Score</th> <th colspan=\"2\">Pair of Group Members</th> </tr>"); */
///*   g_fn_prtlin( "  <tr> <th>Rank in<br>Group</th>"); */
///*   g_fn_prtlin( "  <tr> <th>Rank</th>"); */
///*   g_fn_prtlin( "       <th>Compatibility<br>Score</th>"); */
///*   g_fn_prtlin( "       <th>Benchmark</th>  </tr>"); */
//
///*   g_fn_prtlin( "  <tr> <th></th>");
//*   g_fn_prtlin( "       <th>Pair of <br>Group Members</th>");
//*   g_fn_prtlin( "       <th>Score</th>");
//*   g_fn_prtlin( "       <th></th>  </tr>");
//*/
//
////struct rank_report_line {      /* info for html file production */
////  int  rank_in_group;
////  int  score;
////  char person_A[MAX_SIZE_PERSON_NAME+1];
////  char person_B[MAX_SIZE_PERSON_NAME+1];
////};
//
//
//  // for grpone, change column headers if kingpin ( compare_everyone_with ) is not in the group
//  //
//
////      int kingpin_is_in_group, num_persons_in_rank_lines;
////      kingpin_is_in_group       = 0;   // default = NO
////      num_persons_in_rank_lines = 0;
////
//////tn();kin(num_persons_in_grp);tr("-----LLLLLLLLLLLLLLLLLLLLLLLL");
////      if (strcmp(global_instructions, "format as person_in_group") == 0) {
////        for(h=0; h <= in_rank_lines_last_idx; h++) {
////          num_persons_in_rank_lines = num_persons_in_rank_lines + 1 ;
//////char myperA[128];
//////strcpy(myperA, in_rank_lines[h]->person_A);
//////ksn(myperA);
////        }
////      }
//////kin(num_persons_in_rank_lines);
//////kin(in_rank_lines_last_idx);
//////tn();
////
////      // this relies on concept that there is no compatibility comparison with yourself
////      // so kingpin person being in the group has one fewer rank lines than num_persons_in_grp
////      //
////      if (num_persons_in_rank_lines - 5 == num_persons_in_grp + 1) kingpin_is_in_group = 0; // NO  5 is 5 benchmark label lines
////      else                                                         kingpin_is_in_group = 1; // YES
////
////
//
////tn();trn("at colhdr!");kin(gbl_kingpin_is_in_group);
//
//      if (gbl_kingpin_is_in_group == 1) {
////nbn(1);
//          g_fn_prtlin("  <tr> <th></th> <th>Pair of <br>Group Members</th>");
//          g_fn_prtlin("       <th colspan=\"2\">Compatibility <br>Potential&nbsp</th> </tr>");
//      }
//      if (gbl_kingpin_is_in_group == 0) {
////nbn(2);
//          g_fn_prtlin("  <tr> <th></th> <th>Person and <br>Group Member</th>");
//          g_fn_prtlin("       <th colspan=\"2\">Compatibility <br>Potential&nbsp</th> </tr>");
//      }
//  //
//
//
//  /* check for instructions to return string only
//  */
//// nksn(instructions);
//// nksn(in_html_filename);
//// ksn(gbl_gfnameHTML);
//  if (strcmp(instructions, "return only html for table in string") == 0)
//  {
//    strcpy(string_for_table_only,"");  /* init table string */
//
//
//      //
//      // test below "brw" shows this goes to the html file that is emailed for sharing reports
//      //
//
//
//      strcat(string_for_table_only,
////        "<table>  <tr><th></th><th>Pair</th><th colspan=\"2\">Compatibility <br>Potential&nbsp</th></tr>");
////        "<table>  <tr><th></th><th>Pair</th><th colspan=\"2\">How Much<br>Potential for Compatibility</th></tr>");
////        "<table>  <tr><th></th><th colspan=\"3\">How brw Much<br>Potential for Compatibility</th></tr>");
////        "<table>  <tr><th></th><th colspan=\"3\">Compatibility<br>Potential</th></tr>");
//
////        "<table>  <tr><th></th><th style=\"text-align:right\" colspan=\"3\">Compatibility<br>Potential</th></tr>");
////        " <div> </div> <table class=\"RPCO_tblTrait\" style=\" background-color: black; margin-left: auto; margin-right: auto;\">\n");
//        " <div> </div> <table class=\"RPCO_tblTrait\" >\n");
//
//      strcat(string_for_table_only,
////        " <tr><th></th><th style=\"text-align:right\" colspan=\"3\">Compatibility<br>Potential</th></tr>\n");
//        " <tr><th></th><th class=\"RPCO_th\" colspan=\"3\">Compatibility<br>Potential</th></tr>\n");
//
//
//  }  /* if  "return only html for table in string" */
//
//
//  
///*   is_top_25_done = 0;  * 0=no, 1=yes *
//*   is_median_done = 0;  
//*   is_bot_25_done = 0; 
//*   is_print_good_milestone_at_end = 0;  * if=1, all scores are over good *
//*/
//  /* for each rank line
//  */
//  char trTemplate[256];
//  char linebuf[512];
//  for (i=0; i <= in_rank_lines_last_idx; i++) 
//  {
//
//tr("return only compatibility score 0");ki(i);kin(in_rank_lines[i]->score);
//
//    rank_number = in_rank_lines[i]->rank_in_group ;
//
///* tn();trn("COLOR milestone"); */
///* kin(i);ks(in_rank_lines[i]->person_B);  */
//
//
//
//    /* intercept milestone lines (already sorted),
//    * but remove person_B field and color appropriately 
//    */
//    if (strcmp(in_rank_lines[i]->person_B, "qhilite - top10") == 0) {
///*       g_fn_prtlin( "<tr class=\"cGr2\"><td></td><td></td><td>90   </td><td>Great</td></tr>"); */
//
//      //g_fn_prtlin( "<tr class=\"cGr2\"><td></td><td></td><td>90 </td><td>Great</td></tr>");
//      //g_fn_prtlin( "<tr class=\"cGr2\"><td></td><td>90 </td><td>Great</td></tr>");
////      g_fn_prtlin( "<tr class=\"cGr2tabonly\"><td></td><td></td><td> 90 </td><td>Great</td></tr>");
//      g_fn_prtlin( "<tr class=\"cGr2\"><td></td><td></td><td> 90 </td><td>Great</td></tr>");
//
//
//
//
//      strcpy(trTemplate, "<tr class=\"%s\"><td></td><td class=\"RPCO_td_pair\" >%s</td> <td class=\"RPCO_td_score\" >%s</td> <td class=\"RPCO_td_desc\" >%s</td> </tr>\n"); 
////<.>
////      sprintf(writebuf,
////        "<tr class=\"cHed\"><td></td><td> Bottom %d</td><td></td><td></td></tr>",
////        i_bot_this_many);
////      g_fn_prtlin(writebuf);
////<.>
//
//
//      if (strcmp(instructions, "return only html for table in string") == 0) {
//        if (strstr(gbl_g_in_html_filename, "webview") != NULL) {  // webview version
//          strcat(string_for_table_only, "<tr class=\"cGr2tabonly\"><td></td><td></td> <td>90 </td> <td>Great</td> </tr>");
//        } else {
////          strcat(string_for_table_only, "<tr class=\"cGr2\"><td></td><td></td> <td>90 </td> <td>Great</td> </tr>\n");
//
//          sprintf(linebuf, trTemplate, "cGr2", "", "90", "Great");   strcat(string_for_table_only, linebuf);
//        }
//      }
//      continue;
//    }
//
//
//
//    if (strcmp(in_rank_lines[i]->person_B, "qhilite - good") == 0) {
//
//      //g_fn_prtlin( "<tr class=\"cGre\"><td></td><td>75 </td><td>Good</td></tr>");
////      g_fn_prtlin( "<tr class=\"cGre\"><td></td><td></td><td>75 </td><td>Good</td></tr>");
////      g_fn_prtlin( "<tr class=\"cGretabonly\"><td></td><td></td><td>75 </td><td>Good</td></tr>");
//      g_fn_prtlin( "<tr class=\"cGre\"><td></td><td></td><td>75 </td><td>Good</td></tr>");
//
//      if (strcmp(instructions, "return only html for table in string") == 0) {
//        if (strstr(gbl_g_in_html_filename, "webview") != NULL) {  // webview version
//          strcat(string_for_table_only, "<tr class=\"cGretabonly\"><td></td><td></td> <td>75 </td> <td>Good</td> </tr>");
//        } else {
////          strcat(string_for_table_only, "<tr class=\"cGre\"><td></td><td></td> <td>75 </td> <td>Good</td> </tr>\n");
//          sprintf(linebuf, trTemplate, "cGre", "", "75", "Good");   strcat(string_for_table_only, linebuf);
//        }
//      }
//      continue;
//    }
//    if (strcmp(in_rank_lines[i]->person_B, "qhilite - avg") == 0) {
//
//      //g_fn_prtlin( "<tr class=\"cNeu\"><td></td><td>50 </td><td>Average</td></tr>");
//      g_fn_prtlin( "<tr class=\"cNeu\"><td></td><td></td><td>50 </td><td>Average</td></tr>");
//
//      if (strcmp(instructions, "return only html for table in string") == 0) {
//        if (strstr(gbl_g_in_html_filename, "webview") != NULL) {  // webview version
//          strcat(string_for_table_only, "<tr class=\"cNeutabonly\"><td></td><td></td> <td>50 </td> <td>Average</td> </tr>");
//        } else {
////          strcat(string_for_table_only, "<tr class=\"cNeu\"><td></td><td></td> <td>50 </td> <td>Average</td> </tr>\n");
//          sprintf(linebuf, trTemplate, "cNeu", "", "50", "Average");   strcat(string_for_table_only, linebuf);
//        }
//      }
//      continue;
//    }
//    if (strcmp(in_rank_lines[i]->person_B, "qhilite - bad") == 0) {
///*       g_fn_prtlin( "<tr class=\"cRed\"><td></td><td></td><td>25   </td><td>Not So Good</td></tr>"); */
//
//      //g_fn_prtlin( "<tr class=\"cRed\"><td></td><td>25 </td><td>Not Good </td></tr>");
//      g_fn_prtlin( "<tr class=\"cRed\"><td></td><td></td><td>25 </td><td>Not Good </td></tr>");
//
//      if (strcmp(instructions, "return only html for table in string") == 0) {
//        if (strstr(gbl_g_in_html_filename, "webview") != NULL) {  // webview version
//          strcat(string_for_table_only, "<tr class=\"cRedtabonly\"><td></td><td></td> <td>25 </td> <td>Not Good </td> </tr>");
//        } else {
////          strcat(string_for_table_only, "<tr class=\"cRed\"><td></td><td></td> <td>25 </td> <td>Not Good </td> </tr>\n");
//          sprintf(linebuf, trTemplate, "cRed", "", "25", "Not Good");   strcat(string_for_table_only, linebuf);
//        }
//      }
//      continue;
//    }
//    if (strcmp(in_rank_lines[i]->person_B, "qhilite - bot10") == 0) {
//
//      //g_fn_prtlin( "<tr class=\"cRe2\"><td></td><td>10 </td><td>OMG</td></tr>");
//      g_fn_prtlin( "<tr class=\"cRe2\"><td></td><td></td><td>10 </td><td>OMG</td></tr>");
//
//      if (strcmp(instructions, "return only html for table in string") == 0) {
//        if (strstr(gbl_g_in_html_filename, "webview") != NULL) {  // webview version
//          strcat(string_for_table_only, "<tr class=\"cRe2tabonly\"><td></td><td></td> <td>10 </td> <td>OMG</td> </tr>");
//        } else {
//          sprintf(linebuf, trTemplate, "cRe2", "", "10", "OMG");   strcat(string_for_table_only, linebuf);
//        }
//      }
//      continue;
//    }
////trn("after milestone");tn();
//
//    /* put default ROWCOLOR
//    */
////ksn(gbl_g_in_html_filename); trn("hey hey");
//kin(gbl_is_grpone_or_grpall);
//    if (gbl_is_grpone_or_grpall == 1)  // ensure full color in all lines in case filename has "webview"
//    {
//      if (in_rank_lines[i]->score >= 90) strcpy(rowcolor, " class=\"cGr2\"");
//      if (in_rank_lines[i]->score <  90 &&
//          in_rank_lines[i]->score >= 75) strcpy(rowcolor, " class=\"cGre\"");
//      if (in_rank_lines[i]->score <  75 &&
//          in_rank_lines[i]->score >  25) strcpy(rowcolor, " class=\"cNeu\"");
//      if (in_rank_lines[i]->score <= 25 &&
//          in_rank_lines[i]->score >  10) strcpy(rowcolor, " class=\"cRed\"");
//      if (in_rank_lines[i]->score <= 10) strcpy(rowcolor, " class=\"cRe2\"");
//    }
//    else if (strstr(gbl_g_in_html_filename, "webview") != NULL) {  // webview version
//      if (in_rank_lines[i]->score >= 90) strcpy(rowcolor, " class=\"cGr2tabonly\"");
//      if (in_rank_lines[i]->score <  90 &&
//          in_rank_lines[i]->score >= 75) strcpy(rowcolor, " class=\"cGretabonly\"");
//      if (in_rank_lines[i]->score <  75 &&
//          in_rank_lines[i]->score >  25) strcpy(rowcolor, " class=\"cNeutabonly\"");
//      if (in_rank_lines[i]->score <= 25 &&
//          in_rank_lines[i]->score >  10) strcpy(rowcolor, " class=\"cRedtabonly\"");
//      if (in_rank_lines[i]->score <= 10) strcpy(rowcolor, " class=\"cRe2tabonly\"");
//
//    } else { // browser view
//      if (in_rank_lines[i]->score >= 90) strcpy(rowcolor, " class=\"cGr2\"");
//      if (in_rank_lines[i]->score <  90 &&
//          in_rank_lines[i]->score >= 75) strcpy(rowcolor, " class=\"cGre\"");
//      if (in_rank_lines[i]->score <  75 &&
//          in_rank_lines[i]->score >  25) strcpy(rowcolor, " class=\"cNeu\"");
//      if (in_rank_lines[i]->score <= 25 &&
//          in_rank_lines[i]->score >  10) strcpy(rowcolor, " class=\"cRed\"");
//      if (in_rank_lines[i]->score <= 10) strcpy(rowcolor, " class=\"cRe2\"");
//    }
//ksn(rowcolor);
//
//
//    /* Here we print the ranking table lines  UNLESS
//    *  we have  top200/bot100-like instructions that apply 
//    *  and result in not printing the middle lines.
//    *
//    *  Check current rank against top200/bot100.
//    */
//
///*     if (in_rank_lines[i]->rank_in_group ==
//*         num_pairs_to_rank - i_bot_this_many + 1) {
//*     }
//*/
//    if (in_rank_lines[i]->rank_in_group > i_top_this_many  &&
//        in_rank_lines[i]->rank_in_group < num_pairs_to_rank - i_bot_this_many + 1)
//    {
//      continue;
//    }
//
//    /*  put out line for boundary of bottom 100 before outputting that line
//    */
//    if (in_rank_lines[i]->rank_in_group ==
//      num_pairs_to_rank - i_bot_this_many + 1) {
//
///*       sprintf(writebuf, "<tr><td></td><td></td><td></td></tr>"); */
//      sprintf(writebuf, "<tr><td></td><td></td><td></td><td></td></tr>");
//      g_fn_prtlin(writebuf);
//
//      sprintf(writebuf,
//        "<tr class=\"cHed\"><td></td><td> Bottom %d</td><td></td><td></td></tr>",
//        i_bot_this_many);
//      g_fn_prtlin(writebuf);
//    }
//
//
//
//    /* output ranking line
//    */
//
//    /* if report is "Best Match for ...", color kingpin person
//    */
////     char color_of_person_A_beg[128];
////     char color_of_person_A_end[128];
////     if (strcmp(global_instructions, "format as person_in_group") == 0) {
//// /*       strcpy(color_of_person_A_beg, "<span class=\"cNam2\">"); */
//// /*       strcpy(color_of_person_A_end, "</span>"); */
////       strcpy(color_of_person_A_beg, "");
////       strcpy(color_of_person_A_end, "");
////     } else {
////       strcpy(color_of_person_A_beg, "");
////       strcpy(color_of_person_A_end, "");
////     }
//
///*     sprintf(sformat3, "%%-%ds %%s", len_longest_name); */
//
//    if (  strcmp(global_instructions, "return only html for table in string") == 0) {
////      strcpy(sformat3, "%s  %s");
//      strcpy(sformat3, "%s<br>%s");
//    } else {
//      sprintf(sformat3, "%%-%ds %%s", len_longest_name);
//    }
//      
//      
////      sprintf(writebuf2,  sformat3,
////              in_rank_lines[i]->person_A,
////              in_rank_lines[i]->person_B
////              );
//      // to avoid confusion in space-separated pair of names on the line
//      char A_no_space[32]; // in the case of side-by-side names replace spaces with '_' in each name
//      char B_no_space[32];
//      strcpy(A_no_space, in_rank_lines[i]->person_A); /* names  of person_A  and  person_B */
//      strcpy(B_no_space, in_rank_lines[i]->person_B); /* names  of person_A  and  person_B */
//      scharswitch(A_no_space, ' ', '_');
//      scharswitch(B_no_space, ' ', '_');
//      
//      sprintf(writebuf2,  sformat3,  /* names  of person_A  and  person_B */
//              //      in_rank_lines[i]->person_A,
//              //      in_rank_lines[i]->person_B
//              A_no_space,
//              B_no_space
//              );
//      
//      
//
///*     sprintf(writebuf, "<tr%s><td>%d </td><td> %s</td><td>%d  </td></tr>", */
///*     sprintf(writebuf, "<tr%s><td>%d </td><td> %s</td><td>%d   </td><td></td></tr>", */
///*     sprintf(writebuf, "<tr%s><td>%d</td><td> %s</td><td>%d</td><td></td></tr>", */
//    sprintf(writebuf, "<tr%s><td>%d </td><td> %s</td><td>  %d </td><td></td></tr>",
//      rowcolor,       
//      in_rank_lines[i]->rank_in_group,
//      writebuf2,
//      in_rank_lines[i]->score
//    );
////ksn(writebuf);
//    g_fn_prtlin(writebuf);
//
//trn("try this");
//ksn(writebuf2);
//      gbl_RPCO_score = in_rank_lines[i]->score;  // save for NEW "real" string_for_table_only   below
//kin(i);
//tr("score from in_rank_lines[i]");kin(gbl_RPCO_score);
//trn("try this");
//
//
//    if (strcmp(instructions, "return only html for table in string") == 0) {
//
////      sprintf(writebuf3, "<tr%s class=\"cRPCOhilite\" ><td></td><td> %s</td><td> %d </td><td></td></tr>",
//
//      sprintf(writebuf3, "<tr%s><td></td><td> %s</td><td> %d </td><td></td></tr>",
////        rowcolor,       
//        " class=\"cRPCOhilite\" ",       
//        writebuf2,  /* names  of person_A  and  person_B */
//        in_rank_lines[i]->score
//      );
//
//      gbl_RPCO_score = in_rank_lines[i]->score;  // save for NEW "real" string_for_table_only   below
//tr("score 1");kin(gbl_RPCO_score);
//
////ksn(writebuf3);
////      sprintf(writebuf3, "<tr%s class=\"cRPCOhilite\" ><td></td><td> %s</td><td> %d </td><td></td></tr>",
////ksn(rowcolor);ksn(writebuf3);tn(); /// 333555
////int iii; iii = strlen(string_for_table_only); kin(iii);
////tn();
////
//      strcat(string_for_table_only, writebuf3);
//    }
//
//
//
//
//
//
//tr("return only compatibility score 7");kin(in_rank_lines[i]->score);
//
//
//    if (strcmp(global_instructions, "return only compatibility score") == 0 ) {
//
//      gbl_RPCO_score = in_rank_lines[i]->score;  // save for NEW "real" string_for_table_only   below
////
////      sprintf(string_for_table_only, "%d", in_rank_lines[i]->score);
/////* ksn(string_for_table_only); */
////      /* this actually serves as the string for compatibility score 
////      */
////
//tr("score 11"); kin(in_rank_lines[i]->score);
//tr("score 1");kin(gbl_RPCO_score);
//         
////<.>
//    }
//
//
//
//    /*  put out line for boundary of top 200 after outputting that line
//    */
//    if (in_rank_lines[i]->rank_in_group == i_top_this_many) {
//      sprintf(writebuf,
//        "<tr class=\"cHed\"><td></td><td> Top %d</td><td></td><td></td></tr>",
//        i_top_this_many);
//      g_fn_prtlin(writebuf);
//      sprintf(writebuf, "<tr><td></td><td></td><td><td></td></tr>");
//      g_fn_prtlin(writebuf);
//    }
//
//  } /* for each rank_line */
//
//
//  g_fn_prtlin( "</table>");
//  g_fn_prtlin(" ");
//
//
//
////  instructions, "return only html for table in string"    instructions, "return only html for table in string"
////  instructions, "return only html for table in string"    instructions, "return only html for table in string"
////  instructions, "return only html for table in string"    instructions, "return only html for table in string"
//trn("in whole_group  check for instructions = return only html for table in string ");
//ksn(instructions);
//  if (strcmp(instructions, "return only html for table in string") == 0)
//  {
////    strcat(string_for_table_only, "</table>");
//    strcat(string_for_table_only, "<br> </table>\n");
//
//
//    //
//    // ok, phew, we are now finished string_for_table_only
//    // now, 20180314, THROW string_for_table_only AWAY
//    // and format a new string_for_table_only with a great format (mamb what color report)
//    //
//
//
//    //  real   real   real   real   real real   real   real   real   real real   real   real   real   real real   real   real   real   real 
//    // NEW "real" string_for_table_only   STARTS HERE
//
//    strcpy(string_for_table_only, "");  // now, 20180314, THROW string_for_table_only AWAY
//      
////    strcat(string_for_table_only,
////      "<div id=\"smup_underNAVB\" style=\"position: relative; width: 100%; \"> </div>" ); // NOW IN JS, height is added (navbar * 1.25) 
//
//
////strcat(string_for_table_only, "<div id=\"scoreCOdiv\" class=\"scoreCOcss\"style=\"overflow-x:auto;\">"); // -x for responsive table
//strcat(string_for_table_only, "<div id=\"scoreCOdiv\" class=\"scoreCOcss\" style=\"overflow-x:auto;\"><br>"); // -x for responsive table
//
////      " <div> </div> <table class=\"RPCO_tblTrait\" style=\"background-color: black;  margin-left: auto; margin-right: auto;\">\n");
////      "<table class=\"RPCO_tblTrait\" style=\"background-color: black;  margin-left: auto; margin-right: auto;\">\n");
//    strcat(string_for_table_only,
//      "<table class=\"RPCO_tblTrait\" >\n");
//
//    strcat(string_for_table_only,
//      " <tbody>");
//
////    strcat(string_for_table_only,
////      " <tr><th id='SCOREstarSpace' ></th><th class=\"RPCO_th\" colspan=\"3\">Compatibility<br>Potential</th></tr>\n");
////      " <tr><th></th><th id='SCOREstarSpace' ></th><th class=\"RPCO_th\" colspan=\"2\">Compatibility<br>Potential</th></tr>\n");
//
////    strcat(string_for_table_only,
////      " <tr><th></th><th id='SCOREstarSpace' ></th><th class=\"RPCO_th\" colspan=\"2\">Compatibility<br>Potential</th></tr>\n");
//
//    char bufForTblHdr[512];
//
////    sprintf(bufForTblHdr,
////      "<div id='tblHdrDIV' style='display: inline-block; height: 64px; font-size: 14px; ' >"
////      "  <div style='position: relative; bottom: 12px;  display: inline-block; height: 64px; font-size: 14px; '>Compatibility<br>Potential</div>"
////      "  <div id='SCOREco_starSpace' style='position: relative; display: inline-block; height: 64px; line-height: 64px; font-size: 18px; '>"
////      "    <div style='position: relative; display: inline-block; height: 64px; line-height: 64px; font-size: 18px; bottom: 20px; '>"
////      "       %02d"
////      "    </div>"
////      "  </div>"
////      "</div>"
////      , gbl_RPCO_score
////    );
////
//
//    sprintf(bufForTblHdr,
//      "<div id='tblHdrDIV' style='display: inline-block; height: 64px; font-size: 14px; ' >"
//      "  <div style='position: relative; bottom: 12px;  display: inline-block; height: 64px; font-size: 14px; '>Compatibility<br>Potential</div>"
//      "  <div id='SCOREco_starSpace' style='position: relative; display: inline-block; height: 64px; line-height: 64px; font-size: 18px; '>"
//      "  </div>  <!-- id=SCOREco_starSpace -->"
//      "  <div id='SCOREco_scoreSpace' style='position: relative; display: inline-block; height: 64px; line-height: 64px; font-size: 18px; bottom: 20px; '>"
//      "     %02d"
//      "  </div>  <!-- id=SCOREco_scoreSpace-->"
//      "</div>  <!-- id=tblHdrDIV-->"
//      , gbl_RPCO_score
//    );
//
//
//    //   height: 30px;      line-height: 30px;  // TRICK to vertically align text in a div
//    //
//
//    strcat(string_for_table_only, bufForTblHdr);
//
//tr("score 2");kin(gbl_RPCO_score );
//ksn(bufForTblHdr);
//ksn(string_for_table_only);
//
//
//    char blank_cGr2_0[512] = "  <tr class=\"cGr2\" style=\"line-height: 0.5em; \" ><td id='tdIMG00'></td> <td><span style=\"visibility:hidden;\">X</span></td><td><span style=\"visibility:hidden;\">X</span></td><td><span style=\"visibility:hidden;\">X</span></td> <td><span style=\"visibility:hidden;\">X</span></td> <td></td></tr>"; 
////    char blank_cGr2[512] = "  <tr class=\"cGr2\"><td id='tdIMG01'></td> <td><span style=\"visibility:hidden;\">X</span></td><td><span style=\"visibility:hidden;\">X</span></td><td><span style=\"visibility:hidden;\">X</span></td> <td><span style=\"visibility:hidden;\">X</span></td> <td></td></tr>"; 
////    char blank_cGre[512] = "  <tr class=\"cGre\"><td id='tdIMG03'></td> <td><span style=\"visibility:hidden;\">X</span></td><td><span style=\"visibility:hidden;\">X</span></td><td><span style=\"visibility:hidden;\">X</span></td><td><span style=\"visibility:hidden;\">X</span></td> <td></td></tr>"; 
//    char blank_cNeuA[512] = "  <tr class=\"cNeu\"><td id='tdIMG05A' class='cNeu'></td> <td><span style=\"visibility:hidden;\">X</span></td><td><span style=\"visibility:hidden;\">X</span></td><td><span style=\"visibility:hidden;\">X</span></td> <td><span style=\"visibility:hidden;\">X</span></td> <td></td></tr>"; 
//
//    char blank_cNeuB[512] = "  <tr class=\"cNeu\"><td class='cNeu'></td> <td><span style=\"visibility:hidden;\">X</span></td><td><span style=\"visibility:hidden;\">X</span></td><td><span style=\"visibility:hidden;\">X</span></td> <td><span style=\"visibility:hidden;\">X</span></td> <td></td></tr>"; 
////    char blank_cRed[512] = "  <tr class=\"cRed\"><td id='tdIMG09'></td> <td><span style=\"visibility:hidden;\">X</span></td><td><span style=\"visibility:hidden;\">X</span></td><td><span style=\"visibility:hidden;\">X</span></td> <td><span style=\"visibility:hidden;\">X</span></td> <td></td></tr>"; 
////    char blank_cRe2[512] = "  <tr class=\"cRe2\"><td id='tdIMG11'></td> <td><span style=\"visibility:hidden;\">X</span></td><td><span style=\"visibility:hidden;\">X</span></td><td><span style=\"visibility:hidden;\">X</span></td> <td><span style=\"visibility:hidden;\">X</span></td> <td></td></tr>"; 
//    char blank_cRe2_12[512] = "  <tr class=\"cRe2\" style=\"line-height: 0.5em; \" ><td id='tdIMG12'></td> <td><span style=\"visibility:hidden;\">X</span></td><td><span style=\"visibility:hidden;\">X</span></td><td><span style=\"visibility:hidden;\">X</span></td> <td><span style=\"visibility:hidden;\">X</span></td> <td></td></tr>"; 
//
//
//    if ( gbl_RPCO_score >= 90)                                     // score is great cGr2   
//    {
//      // new scorebox
//      strcat(string_for_table_only, blank_cGr2_0);  // extra green spacing for top great scores
//      CO_SCORELINE_cGr2 
//      CO_BENCHLINE_cGr2 
//      CO_BENCHLINE_cGre 
//
//      strcat(string_for_table_only, blank_cNeuA);
//      CO_BENCHLINE_cNeu 
//      strcat(string_for_table_only, blank_cNeuB);
//
//      CO_BENCHLINE_cRed 
//      CO_BENCHLINE_cRe2 
//
//    } else if ( gbl_RPCO_score >= 75  &&  gbl_RPCO_score  < 90 )   // score is good cGre
//    {
//      // new scorebox
//      CO_BENCHLINE_cGr2 
//      CO_SCORELINE_cGre 
//      CO_BENCHLINE_cGre 
//
//      strcat(string_for_table_only, blank_cNeuA);
//      CO_BENCHLINE_cNeu 
//      strcat(string_for_table_only, blank_cNeuB);
//
//      CO_BENCHLINE_cRed 
//      CO_BENCHLINE_cRe2 
//
//    }
//    else if ( gbl_RPCO_score  < 75  &&  gbl_RPCO_score >= 50 )     // score is above avg cNeu
//    {
//      // these are #define s above
//      CO_BENCHLINE_cGr2 
//      CO_BENCHLINE_cGre 
//
//      CO_SCORELINE_cNeu 
//      CO_BENCHLINE_cNeu 
//      strcat(string_for_table_only, blank_cNeuB);
//
//      CO_BENCHLINE_cRed 
//      CO_BENCHLINE_cRe2 
//
//    }
//    else if ( gbl_RPCO_score  < 50  &&  gbl_RPCO_score >  25 )     // score is below avg cNeu
//    {
//      // these are #define s above
//      CO_BENCHLINE_cGr2 
//      CO_BENCHLINE_cGre 
//
//      strcat(string_for_table_only, blank_cNeuA);
//      CO_BENCHLINE_cNeu 
//      CO_SCORELINE_cNeu 
//
//      CO_BENCHLINE_cRed 
//      CO_BENCHLINE_cRe2 
//
//    }
//    else if ( gbl_RPCO_score  <= 25  &&  gbl_RPCO_score >  10 )    // score is stress cRed
//    {
//      // new scorebox
//      CO_BENCHLINE_cGr2 
//      CO_BENCHLINE_cGre 
//
//      strcat(string_for_table_only, blank_cNeuA);
//      CO_BENCHLINE_cNeu 
//      strcat(string_for_table_only, blank_cNeuB);
//
//      CO_BENCHLINE_cRed 
//      CO_SCORELINE_cRed
//      CO_BENCHLINE_cRe2 
//
//    }
//    else if ( gbl_RPCO_score  <= 10)                               // score is omg cRe2
//    {
//      // new scorebox
//      CO_BENCHLINE_cGr2 
//      CO_BENCHLINE_cGre 
//
//      strcat(string_for_table_only, blank_cNeuA);
//      CO_BENCHLINE_cNeu 
//      strcat(string_for_table_only, blank_cNeuB);
//
//      CO_BENCHLINE_cRed 
//      CO_BENCHLINE_cRe2 
//      CO_SCORELINE_cRe2 
//      strcat(string_for_table_only, blank_cRe2_12);  // extra green spacing for top great scores
//
//    } else {
//      ;
//    }
//
//
//  } // FINAL   if (strcmp(instructions, "return only html for table in string") == 0) 
//
//  //  instructions, "return only html for table in string"    instructions, "return only html for table in string"
//  //  instructions, "return only html for table in string"    instructions, "return only html for table in string"
//  //  instructions, "return only html for table in string"    instructions, "return only html for table in string"
//
//
//
//
////  strcat(string_for_table_only, "<div style='background-color: cyan;'><br><br></div></tbody></table>");
//  strcat(string_for_table_only, "</tbody></table>");
//
//strcat(string_for_table_only, "<br></div>");  // for responsive div
//
//    // NEW "real" string_for_table_only   ENDS   HERE
//    //  real   real   real   real   real real   real   real   real   real real   real   real   real   real real   real   real   real   real 
//
//
//
//  if (strcmp(global_instructions, "format as person_in_group") != 0) {
//
//
//    g_fn_prtlin( "<pre>");
//    gbl_we_are_in_PRE_block = 1;  /* true */
//
//    g_fn_prtlin(" ");
//    g_fn_prtlin("  To see all the scores for only one person,  ");
///*     g_fn_prtlin(" check out the report \"Best Match for ... \" "); */
//    g_fn_prtlin("  check out the report \"Best Match For ...\"  ");
///*     g_fn_prtlin("  To see all the scores for only one person,  "); */
///*     g_fn_prtlin(" check out the report "); */
///*     g_fn_prtlin(" Best Match for ... in Group ... "); */
//    g_fn_prtlin(" ");
//    gbl_we_are_in_PRE_block = 0;  /* false */
//    g_fn_prtlin( "</pre>");
//  }
//
//    g_fn_prtlin( "<div><br></div>");
//
//
//  g_fn_prtlin("<pre>");
//  gbl_we_are_in_PRE_block = 1; /* 1 = yes, 0 = no */
///*   g_fn_prtlin( "                                                     "); */
///*   g_fn_prtlin( "     Note: a GOOD RELATIONSHIP needs 2 things:       "); */
///*   g_fn_prtlin( "  1. compatibility potential (the score above)       "); */
///*   g_fn_prtlin( "  2. willpower to show positive personality traits   "); */
///*   g_fn_prtlin( "                                                     "); */
//
////  g_fn_prtlin( "                                                  ");
////  g_fn_prtlin( "     Note: a GOOD RELATIONSHIP needs 2 things:    "); // 
////  g_fn_prtlin( "  1. compatibility potential                      ");
////  g_fn_prtlin( "  2. both sides show positive personality traits  ");
////  g_fn_prtlin( "                                                  ");
////
//  g_fn_prtlin( "                                                  ");
////  g_fn_prtlin( "     a GOOD RELATIONSHIP                          "); // 
////  g_fn_prtlin( "     usually has 2 things                         "); // 
//
//
////  g_fn_prtlin( "     a GOOD RELATIONSHIP usually has 2 things     "); // 
////  g_fn_prtlin( "  1. compatibility potential                      ");
////  g_fn_prtlin( "  2. both sides show positive personality traits  ");
////  g_fn_prtlin( "                                                  ");
//
////  g_fn_prtlin( "<span class=yellowShine>a GOOD RELATIONSHIP</span> has 22things<br><span style='text-align:left;'>1. compatibility potential<br>2. both sides show positive personality traits </span></div>");
//  g_fn_prtlin( "<span class=yellowShine>a GOOD RELATIONSHIP</span> has 22things<br><span style='text-align:left;'> 1. compatibility potential</span><br><span style='text-align:left;'> 2. both sides show positive personality traits </span></div>");
//
//  gbl_we_are_in_PRE_block = 0; /* 1 = yes, 0 = no */
//  g_fn_prtlin("</pre>");
//
//
//
////    sprintf(writebuf, "<h5><br><br>produced by iPhone app %s</h5>", APP_NAME);
////    g_fn_prtlin(writebuf);
////  g_fn_prtlin("<h4><span style=\"background-color:#FFBAC7;\">&nbspThis report is for entertainment purposes only.&nbsp</span></h4>");
//
//
////  g_fn_prtlin("<div> <span style=\"font-size: 1.0em\"><br>produced by iPhone app Me and my BFFs</span><br><br><span style=\"font-size: 0.9em; font-weight: bold; color:#FF0000;\">This report is for entertainment purposes only.</span></div><div><br></div>");
//
//  char workProducedBy[256];
//  sprintf(workProducedBy,
//    "<div> <span style=\"font-size: 1.0em\"><br>produced by iPhone app %s</span><br><br><span style=\"font-size: 0.9em; font-weight: normal; color:#FF0000;\">This report is for entertainment purposes only.</span></div><div><br></div>" ,
//    APP_NAME
//  ); 
//
//  g_fn_prtlin( workProducedBy );
//
//
//
//
//  g_fn_prtlin( "</body>");
//  g_fn_prtlin( "</html>");
//
//
//  /* check for instructions to return string only
//  */
//  if (  strcmp(global_instructions, "return only html for table in string") == 0
//     || strcmp(global_instructions, "return only compatibility score"     ) == 0 ) {
//
//    ; /* DO NOT OPEN html file for write */
//
//  } else {
//    fflush(Fp_g_HTML_file);
//    /* close output HTML file
//    */
//    if (fclose(Fp_g_HTML_file) == EOF) {
//      ;
///* trn("FCLOSE FAILED !!!   #4  "); */
//    } else {
//      ;
///* trn("FCLOSE SUCCESS !!!  #4  "); */
//    };
//  }
//
//  if (strcmp(global_instructions, "return only compatibility score") == 0 ) {
//    strcpy(global_instructions, "");
//  }
//
////trn("at end of  make_html_file_whole_group()");
//
//  gbl_is_grpone_or_grpall = 0;  // re-init
//
//  return(0);
//
//} /* end of make_html_file_whole_group() */
//
//
// make_html_file_whole_group() not used  20210402




// put_top_of_html_group_rpt() not used  20210402
//
//void put_top_of_html_group_rpt(char *group_name) {
//
//  /* comments are    <!--  i am commented out  -->  */
//
//  /*   at end, change to STRICT  */
//  g_fn_prtlin( "<!doctype html public \"-//w3c//dtd html 4.01 transitional//en\" ");
//  g_fn_prtlin( "  \"http://www.w3.org/TR/html4/loose.dtd\">");
//
////  g_fn_prtlin( "<html>");
////  g_fn_prtlin( "\n<head>");
//
//
//
//  /* <title> shows up in the tab and tooltip when hover mouse ptr over chrome tab
//  */
//
//  /* if HTML filename, gbl_ffnameHTML, has any slashes, grab the basename
//  */
//  char myBaseName[256], *myptr;
//  if (sfind(gbl_gfnameHTML, '/')) {
//    myptr = strrchr(gbl_gfnameHTML, '/');
//    strcpy(myBaseName, myptr + 1);
//  } else {
//    strcpy(myBaseName, gbl_gfnameHTML);
//  }
//
//
//  if (strcmp(gbl_format_as, "trait rank") == 0) {
//
//    if (strstr(gbl_trait_name, "Best Day on") != NULL) {
///*       sprintf(writebuf, "  <title>%s, Best Day, produced by iPhone/iPad app named %s.</title>", group_name, APP_NAME); */
///*       sprintf(writebuf, "  <title>%s, Best Day, produced by iPhone app %s.</title>", group_name, APP_NAME); */
///*       g_fn_prtlin(writebuf); */
//
//      sprintf(writebuf, "  <title>%s</title>", myBaseName);
//      g_fn_prtlin(writebuf);
//
//    } else if (strstr(gbl_trait_name, "Best Calendar Year") != NULL) {
///*       sprintf(writebuf, "  <title>%s, Best Calendar Year, produced by iPhone app %s.</title>", group_name, APP_NAME); */
///*       g_fn_prtlin(writebuf); */
//      sprintf(writebuf, "  <title>%s</title>", myBaseName);
//      g_fn_prtlin(writebuf);
//
//    } else {
//      /* TRAITS here "most assertive" etc ... */
//
///*       sprintf(writebuf, "  <title>%s, %s, produced by iPhone app %s.</title>", group_name, gbl_trait_name, APP_NAME); */
///*       g_fn_prtlin(writebuf); */
//      sprintf(writebuf, "  <title>%s</title>", myBaseName);
//      g_fn_prtlin(writebuf);
//    }
//
//  }  /* trait stuff above */
//
//  else if (strcmp(gbl_format_as, "average scores") == 0) {
///*     sprintf(writebuf, "  <title>%s, Most Compatible Person, produced by iPhone app %s.</title>", group_name, APP_NAME); */
///*     g_fn_prtlin(writebuf); */
//      sprintf(writebuf, "  <title>%s</title>", myBaseName);
//      g_fn_prtlin(writebuf);
//
//  } else {
//    if (strcmp(global_instructions, "format as person_in_group") == 0) {
///*       sprintf(writebuf, "  <title>%s, %s Best Match, produced by iPhone app %s.</title>", */
///*         group_name, */
///*         gbl_compare_everyone_with, */
///*         APP_NAME */
///*       ); */
///*       g_fn_prtlin(writebuf); */
//      sprintf(writebuf, "  <title>%s</title>", myBaseName);
//      g_fn_prtlin(writebuf);
//
//    } else {
//      /* BEST MATCH in Group    here */
//
///*     sprintf(writebuf, "  <title>%s Best Match, produced by iPhone app %s.</title>", group_name, APP_NAME); */
///*       g_fn_prtlin(writebuf); */
//      sprintf(writebuf, "  <title>%s</title>", myBaseName);
//      g_fn_prtlin(writebuf);
//    }
//  }
//
//  
//
//
//  /* HEAD  META
//  */
//  if (strcmp(gbl_format_as, "trait rank") == 0) {
//
//    if (strstr(gbl_trait_name, "Best Day on") != NULL) {
//      sprintf(writebuf, "  <meta name=\"description\" content=\"Best Day in Group report produced by iPhone app %s\"> ", APP_NAME);
//      g_fn_prtlin(writebuf);
//
//    } else if (strstr(gbl_trait_name, "Best Calendar Year") != NULL) {
//      sprintf(writebuf, "  <meta name=\"description\" content=\"Best Calendar Year in Group report produced by iPhone app %s\"> ", APP_NAME);
//      g_fn_prtlin(writebuf);
//
//    } else {
//      sprintf(writebuf, "  <meta name=\"description\" content=\"Most %s in Group report produced by iPhone app %s\"> ", gbl_trait_name, APP_NAME);
//      g_fn_prtlin(writebuf);
//    }
//
//  } else if (strcmp(gbl_format_as, "average scores") == 0) {
//    sprintf(writebuf, "  <meta name=\"description\" content=\"Most Compatible Person in Group report produced by iPhone app %s\"> ", APP_NAME);
//    g_fn_prtlin(writebuf);
//
//  } else {
//    if (strcmp(global_instructions, "format as person_in_group") == 0) {
//      sprintf(writebuf, "  <meta name=\"description\" content=\"In Group, person is most compatibe with ... produced by iPhone app %s\"> ", APP_NAME);
//      g_fn_prtlin(writebuf);
//
//    } else {
//      sprintf(writebuf, "  <meta name=\"description\" content=\"Most compatible Pair in Group produced by iPhone app %s\"> ", APP_NAME);
//      g_fn_prtlin(writebuf);
//    }
//  }
//
///*   g_fn_prtlin( "  <meta http-equiv=\"Content-Type\" content=\"text/html\"; charset=\"iso-8859-1\">");  */
//  g_fn_prtlin( "  <meta http-equiv=\"Content-Type\" content=\"text/html\"; charset=\"UTF-8\">"); 
///*   g_fn_prtlin( "  <meta name=\"Author\" content=\"Author goes here\">"); */
//
//
///*   g_fn_prtlin( "  <meta name=\"keywords\" content=\"measure,group,member,best,match,calendar,year,passionate,personality\"> "); */
///*   g_fn_prtlin( "  <meta name=\"keywords\" content=\"BFF,astrology,compatibility,group,best,match,calendar,year,stress,personality\"> "); */
//
///*   g_fn_prtlin( "  <meta name=\"keywords\" content=\"women,woman,female,BFF,compatibility,group,best,match,personality,stress,calendar,year\"> "); */ /* 86 chars */ 
//  g_fn_prtlin( "  <meta name=\"keywords\" content=\"women,woman,female,BFF,me,compatibility,group,best,match,personality,stress,calendar,year\"> ");  /* 89 chars */
//
//
//  /* get rid of CHROME translate "this page is in Galician" 
//  * do you want to translate?
//  */
//  g_fn_prtlin("  <meta name=\"google\" content=\"notranslate\">");
//  g_fn_prtlin("  <meta http-equiv=\"Content-Language\" content=\"en\" />");
//  g_fn_prtlin("  <meta name = \"format-detection\" content = \"telephone=no\">");
//
//  /* HEAD   STYLE/CSS
//  */
//  g_fn_prtlin( "\n  <style type=\"text/css\">");
//
///*   g_fn_prtlin( "  @media print { BODY {font-size: 60% } }"); */
//  g_fn_prtlin( "    @media print { TABLE {font-size: 75%; } }");
//
//  g_fn_prtlin( "    BODY {");
///*  g_fn_prtlin( "      background-color: #F5EFCF;"); */
//  g_fn_prtlin( "      background-color: #f7ebd1;");
///*   g_fn_prtlin( "      font-family: Trebuchet MS, Arial, Verdana, sans-serif;"); */
////  g_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New;");
//  g_fn_prtlin( "  font-family: Menlo, Monaco, Consolas, \"Lucida Console\", \"Andale Mono\", Monospace, \"Courier New\" "); 
//  g_fn_prtlin( "      font-size:   medium;");
//  g_fn_prtlin( "      font-weight: normal;");
//  g_fn_prtlin( "      text-align:  center;");
///*   g_fn_prtlin( "    <!-- "); */
///*   g_fn_prtlin( "      background-image: url('mkgif1g.gif');"); */
///*   g_fn_prtlin( "    --> "); */
//  g_fn_prtlin( "    }");
//
///*   g_fn_prtlin( "    H1 { font-size: 137%; font-weight: bold;   line-height: 95%; text-align: center;}"); */
///*   g_fn_prtlin( "    H2 { font-size: 137%; font-weight: bold;   line-height: 25%; text-align: center;}"); */
///*   g_fn_prtlin( "    H3 { font-size: 110%; font-weight: normal; line-height: 30%; text-align: center;}"); */
//  g_fn_prtlin( "    H1 { font-size: 137%; font-weight: bold;   line-height: 15%; text-align: center;}");
//  g_fn_prtlin( "    H2 { font-size: 120%; font-weight: bold;   line-height: 95%; text-align: center;}");
//  g_fn_prtlin( "    H3 { font-size: 110%; font-weight: normal; line-height: 95%; text-align: center;}");
//
//
///*   g_fn_prtlin( "    H5 { font-size:  55%; font-weight: normal; line-height: 90%; text-align: center;}"); */
///*   g_fn_prtlin( "    H5 { font-size:  70%; font-weight: normal; line-height: 30%; text-align: center;}"); */
///*   g_fn_prtlin( "    H4 { font-size:  85%; font-weight: bold;   line-height: 30%; text-align: center;}"); */
//
//  g_fn_prtlin( "    H4 { font-size:  75%; font-weight: bold;   line-height: 30%; text-align: center;}");
//  g_fn_prtlin( "    H5 { font-size:  70%; font-weight: normal; line-height: 30%; text-align: center;}");
//
//
//  g_fn_prtlin( "    PRE {");
///*   g_fn_prtlin( "      padding: 1%;"); */
//  g_fn_prtlin( "      display: inline-table;");
//
///*   g_fn_prtlin( "      border-style: solid;"); */
///*   g_fn_prtlin( "      border-color: #e4dfae; "); */
///*   g_fn_prtlin( "      border-width: 5px;"); */
//
//  g_fn_prtlin( "      display: inline-block;");
//  g_fn_prtlin( "      background-color: #fcfce0;");
//  g_fn_prtlin( "      border: none;");
//  g_fn_prtlin( "      border-collapse: collapse;");
//  g_fn_prtlin( "      border-spacing: 0;");
//
///*   g_fn_prtlin( "      padding-left 10px;"); */
///*   g_fn_prtlin( "      padding-right 10px;"); */
//
///*   g_fn_prtlin( "      font-family: Andale Mono, Menlo, Monospace, Courier New;"); */
////  g_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New;");
//  g_fn_prtlin( "  font-family: Menlo, Monaco, Consolas, \"Lucida Console\", \"Andale Mono\", Monospace, \"Courier New\" "); 
//  g_fn_prtlin( "      font-weight: normal;");
//  g_fn_prtlin( "      font-size:   75%;");
///*   g_fn_prtlin( "      line-height: 110%;"); */
//  g_fn_prtlin( "      line-height: 131%;");
//  g_fn_prtlin( "    }");
//  g_fn_prtlin( "    P { ");
///*   g_fn_prtlin( "      font-family: Andale Mono, Menlo, Monospace, Courier New;"); */
////  g_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New;");
//  g_fn_prtlin( "  font-family: Menlo, Monaco, Consolas, \"Lucida Console\", \"Andale Mono\", Monospace, \"Courier New\" "); 
//  g_fn_prtlin( "      width: auto;");
//  g_fn_prtlin( "      font-size:   80%;");
//  g_fn_prtlin( "      margin-top: 0;");
//  g_fn_prtlin( "      margin-bottom: 0;");
//  g_fn_prtlin( "      margin-left: auto;");
//  g_fn_prtlin( "      margin-right:auto;");
///*   g_fn_prtlin( "      padding-left: 5%;"); */
///*   g_fn_prtlin( "      padding-right:5%;"); */
///*   g_fn_prtlin( "      text-align: center;"); */
//  g_fn_prtlin( "      text-align: left;");
//  g_fn_prtlin( "    }");
///* for table: */
///*       border: 2px solid black; */
///*       cellspacing: 0; */
///*       border-top: 0; */
///*       border-bottom: 0; */
///*   g_fn_prtlin( "    table.center {"); */
///*   g_fn_prtlin( "      margin-left:auto;"); */
///*   g_fn_prtlin( "      margin-right:auto;"); */
///*   g_fn_prtlin( "    }"); */
///*   g_fn_prtlin( "    table, th, td{"); */
///*   g_fn_prtlin( "      border: 1px solid black;"); */
///*   g_fn_prtlin( "      border-collapse: collapse;"); */
///*   g_fn_prtlin( "      border-spacing: 0;"); */
///*   g_fn_prtlin( "    }"); */
///*   g_fn_prtlin( "    TD {"); */
///*   g_fn_prtlin( "      white-space: nowrap;"); */
///*   g_fn_prtlin( "      padding: 0;"); */
///*   g_fn_prtlin( "    }"); */
//
//
//
//  //  this is browser version 
//
//  g_fn_prtlin( "    .linehite_0050 { ");          // stars line with countMinus >= 2 + lots of other lines
//  g_fn_prtlin( "      line-height: 0.5;");
//  g_fn_prtlin( "    }");
//
//
//  g_fn_prtlin( "    table {");
///*   g_fn_prtlin( "      font-family: Andale Mono, Menlo, Monospace, Courier New;"); */
////  g_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New;");
//  g_fn_prtlin( "  font-family: Menlo, Monaco, Consolas, \"Lucida Console\", \"Andale Mono\", Monospace, \"Courier New\" "); 
//  g_fn_prtlin( "      text-align: left;");
//
///*   g_fn_prtlin( "      border: 1px solid black;"); */
///*   g_fn_prtlin( "      border-collapse: collapse;"); */
///*   g_fn_prtlin( "      border-spacing: 0;"); */
//     g_fn_prtlin( "      border: none;");
//  g_fn_prtlin( "      border-spacing: 0;");
//
//
///*   g_fn_prtlin( "      padding-right:2%;"); */
///*   g_fn_prtlin( "      padding-left:2%;"); */
//  g_fn_prtlin( "      margin-left: auto;");
//  g_fn_prtlin( "      margin-right:auto;");
//  g_fn_prtlin( "    }");
//  g_fn_prtlin( "    td {");
///*   g_fn_prtlin( "      font-family: Andale Mono, Monospace, Courier New;"); */
//
//  g_fn_prtlin( "      white-space: pre;");
///*   g_fn_prtlin( "      font-size: 80%;"); */
//
//  g_fn_prtlin( "      font-size: 90%;");
//
//  g_fn_prtlin( "      text-align: left;");
//
///*   g_fn_prtlin( "      border: 1px solid black;"); */
///*   g_fn_prtlin( "      border-collapse: collapse;"); */
///*   g_fn_prtlin( "      border-spacing: 0;"); */
//     g_fn_prtlin( "      border: none;");
//  g_fn_prtlin( "      border-spacing: 0;");
//
///*   g_fn_prtlin( "      padding-left: 5px; "); */
///*   g_fn_prtlin( "      padding-right: 5px; "); */
//  g_fn_prtlin( "      padding-left: 5px; ");
//  g_fn_prtlin( "      padding-right: 5px; ");
//
//  g_fn_prtlin( "    }");
//  g_fn_prtlin( "    table.center {");
//  g_fn_prtlin( "      margin-left:auto;");
//  g_fn_prtlin( "      margin-right:auto;");
//  g_fn_prtlin( "    }");
//  g_fn_prtlin( "    th {");
//
//  g_fn_prtlin( "      padding: 5px; ");
//  g_fn_prtlin( "      vertical-align:bottom;");
//
///*   g_fn_prtlin( "      font-family: Trebuchet MS, Arial, Verdana, sans-serif;"); */
////  g_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New;");
//  g_fn_prtlin( "  font-family: Menlo, Monaco, Consolas, \"Lucida Console\", \"Andale Mono\", Monospace, \"Courier New\" "); 
//
///*   g_fn_prtlin( "      font-size: 85%;"); */
//  g_fn_prtlin( "      font-size: 90%;");
//
///*   g_fn_prtlin( "      padding-left: 10px; "); */
///*   g_fn_prtlin( "      padding-right: 10px; "); */
//
///*   g_fn_prtlin( "      background-color: #e1fdc3 ;"); */
//     g_fn_prtlin( "      background-color: #fcfce0 ;");
//
///*   g_fn_prtlin( "      border: 1px solid black;"); */
//  g_fn_prtlin( "      border: none;");
//  g_fn_prtlin( "      border-spacing: 0;");
//
//  g_fn_prtlin( "      text-align: center;");
//  g_fn_prtlin( "    }");
//
//  g_fn_prtlin( "    table td  { text-align: right; ");
///*   g_fn_prtlin( "      font-family: Andale Mono, Menlo, Monospace, Courier New;"); */
////  g_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New;");
//  g_fn_prtlin( "  font-family: Menlo, Monaco, Consolas, \"Lucida Console\", \"Andale Mono\", Monospace, \"Courier New\" "); 
//  g_fn_prtlin( "    }");
//
//  g_fn_prtlin( "    table td+td { text-align: left; ");
///*   g_fn_prtlin( "      font-family: Andale Mono, Menlo, Monospace, Courier New;"); */
////  g_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New;");
//  g_fn_prtlin( "  font-family: Menlo, Monaco, Consolas, \"Lucida Console\", \"Andale Mono\", Monospace, \"Courier New\" "); 
//  g_fn_prtlin( "    }");
//
//  g_fn_prtlin( "    table td+td+td { text-align: right; ");
///*   g_fn_prtlin( "      padding-right:3%;"); */
///*   g_fn_prtlin( "      font-family: Andale Mono, Menlo, Monospace, Courier New;"); */
////  g_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New;");
//  g_fn_prtlin( "  font-family: Menlo, Monaco, Consolas, \"Lucida Console\", \"Andale Mono\", Monospace, \"Courier New\" "); 
//  g_fn_prtlin( "    }");
//
//  g_fn_prtlin( "    table td+td+td+td { text-align: left; ");
///*   g_fn_prtlin( "      font-family: Andale Mono, Menlo, Monospace, Courier New;"); */
////  g_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New;");
//  g_fn_prtlin( "  font-family: Menlo, Monaco, Consolas, \"Lucida Console\", \"Andale Mono\", Monospace, \"Courier New\" "); 
//  g_fn_prtlin( "    }");
//
///*   g_fn_prtlin( "    .row4        { background-color:#fdfddc; }"); */
///*   g_fn_prtlin( "    .cLineGood   { background-color:#c3fdc3; }"); */
///*   g_fn_prtlin( "    .cLineStress { background-color:#ffbac7; }"); */
//  g_fn_prtlin( "    .row4        { background-color:#f8f0c0; }");
//
///*   p_fn_prtlin( "    .cGr2        { background-color:#d0fda0; }"); */
///*   g_fn_prtlin( "    .cGr2        { background-color:#8bfd87; }"); */
///*   g_fn_prtlin( "    .cGr2        { background-color:#66ff33; }"); */
//
///*   p_fn_prtlin( "    .cGre        { background-color:#e1fdc3; }"); */
///*   g_fn_prtlin( "    .cGre        { background-color:#ccffb9; }"); */
///*   p_fn_prtlin( "    .cRed        { background-color:#ffd9d9; }"); */
///*   g_fn_prtlin( "    .cRed        { background-color:#ffcccc; }"); */
///*   p_fn_prtlin( "    .cRe2        { background-color:#fcb9b9; }"); */
///*   g_fn_prtlin( "    .cRe2        { background-color:#fc8888; }"); */
///*   g_fn_prtlin( "    .cRe2        { background-color:#fc6094; }"); */
///*   g_fn_prtlin( "    .cRe2        { background-color:#ff3366; }"); */
//
//  // webview version
//
//  /* put GREEN highlight for trait, green+red for other
//  */
//  if (strcmp(gbl_format_as, "trait rank") == 0 
//    && strstr(gbl_trait_name, "Best Calendar Year") == NULL 
//    && strstr(gbl_trait_name, "Best Day on") == NULL )
//  {
//
//    /*     g_fn_prtlin( "    .cGr2        { background-color:#a3f275; }"); */
//    /*     g_fn_prtlin( "    .cGre        { background-color:#bbf699; }"); */
//    /*     g_fn_prtlin( "    .cNeu        { background-color:#d3f9bd; }"); */
//    /*     g_fn_prtlin( "    .cRed        { background-color:#bbf699; }"); */
//    /*     g_fn_prtlin( "    .cRe2        { background-color:#a3f275; }"); */
//
///*     g_fn_prtlin( "    .cGr2        { background-color:#a3f275; }");  */
///*     g_fn_prtlin( "    .cGre        { background-color:#a3f275; }"); */
///*     g_fn_prtlin( "    .cNeu        { background-color:#a3f275; }"); */
///*     g_fn_prtlin( "    .cRed        { background-color:#a3f275; }"); */
///*     g_fn_prtlin( "    .cRe2        { background-color:#a3f275; }"); */
//
//    /* all same green (all good) */
//
///*     g_fn_prtlin( "    .cGr2,.cGre,.cNeu,.cRed,.cRe2 {background-color: #a3f275;}"); */
////    g_fn_prtlin( "    .cGr2,.cGre,.cNeu,.cRed,.cRe2 {background-color: #d3ffa5;}");
//
//// abandon 20150604
////    // 20150603 introduce alternating green colors
////    //
////    g_fn_prtlin( "    .cPerGreen1 {background-color: #d3ffa5;}");
////    g_fn_prtlin( "    .cPerGreen2 {background-color: #e6ffcc;}");
//
////    g_fn_prtlin( "    .cPerGreen1 {background-color: #d3ffa5;}");  
////    g_fn_prtlin( "    .cPerGreen2 {background-color: #d3ffa5;}"); 
//
////    g_fn_prtlin( "    .cPerGreen1 {background-color: #ceffa0;}");  
////    g_fn_prtlin( "    .cPerGreen2 {background-color: #dfffbb;}"); 
//
////    g_fn_prtlin( "    .cPerGreen1 {background-color: #d3ffa5;}");  // same
//
//    g_fn_prtlin( "    .cPerGreen1 {background-color: #f0f8ff;}");  // alternating light blue and a little darker blue
////    g_fn_prtlin( "    .cPerGreen2 {background-color: #d3ffa5;}"); // same
//    g_fn_prtlin( "    .cPerGreen2 {background-color: #c0e0ff;}");  // alternating light blue and a little darker blue
//
//    g_fn_prtlin( "    .cPerGreen3 {background-color: #4c7cff; color: white}");  // darker blue for Most title and footer
//
//  } else {
//
////    g_fn_prtlin( "    .cGr2        { background-color:#66ff33; }");
//    g_fn_prtlin( "    .cGr2        { background-color:#80ff40; }");
//  /*   g_fn_prtlin( "    .cGre        { background-color:#84ff98; }"); */
////    g_fn_prtlin( "    .cGre        { background-color:#a8ff98; }");
//    g_fn_prtlin( "    .cGre        { background-color:#c0ffc0; }");
///*   g_fn_prtlin("    .cNeu        { background-color:#e1ddc3; }"); */
////    g_fn_prtlin("    .cNeu        { background-color:#e5e2c7; }");
//    g_fn_prtlin("    .cNeu        { background-color:#edebd8; }");
////    g_fn_prtlin( "    .cRed        { background-color:#ff98a8; }");
//    g_fn_prtlin( "    .cRed        { background-color:#ffb5c9; }");
////    g_fn_prtlin( "    .cRe2        { background-color:#ff4477; }");
////    g_fn_prtlin( "    .cRe2        { background-color:#ff678f; }");
//    g_fn_prtlin( "    .cRe2        { background-color:#ff7ba3; }");
//  }
//
//
//    g_fn_prtlin( "    .cHed        { background-color:#fcfce0; }");
//    g_fn_prtlin( "    .cNam        { color:#3f3ffa;");
//    g_fn_prtlin( "                   background-color: #F7ebd1;");
//    g_fn_prtlin( "                   font-size: 133%;");
//    g_fn_prtlin( "    }");
//    g_fn_prtlin( "    .cNam2       { color:#3f3ffa; }");
//
//    g_fn_prtlin( "  </style>");
//
//    /* put in favicon */
//    g_fn_prtlin("<link href=\"data:image/x-icon;base64,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\" rel=\"icon\" type=\"image/x-icon\" />");
//
//
////    g_fn_prtlin("\n<body>");
//
//
//}  /* end of  put_top_of_html_group_rpt() */  // webview version
//
//
// put_top_of_html_group_rpt() not used  20210402



/* output the css, headings etc.
*/
//void put_top_of_just2_group_rpt(void)  // just_2 rpt    NOTE  this is browser version
//{
//  int i;
//tn();trn("in put_top_of_just2_group_rpt()");
//
//  /* 1. read until [beg_topinfo1]  (name)  (skipping [beg_program])
//  */
//  for (i=0; ; i++) {
//    g_docin_get(doclin);
//    if (strstr(doclin, "[beg_topinfo1]") != NULL) break;
//  }
//  /* then save lines until graph until [end_topinfo1] 
//  * then put out html 
//  */
//  for (i=0; ; i++) {
//    g_docin_get(doclin);
//    if (strstr(doclin, "[end_topinfo1]") != NULL) break;
//    strcpy(g_arr(i), doclin);               //  HERE's where arr(0) and arr(1) get populated
//    
//    // see these
//    //  char gbl_just2PersonA[64];
//    //  char gbl_just2PersonB[64];
//  }
//
///*   at end, change to STRICT  */
//  g_fn_prtlin( "<!doctype html public \"-//w3c//dtd html 4.01 transitional//en\" ");
//  g_fn_prtlin( "  \"http://www.w3.org/TR/html4/loose.dtd\">");
//
////  g_fn_prtlin( "<html>");
////  g_fn_prtlin( "\n<head>");
//
//
//
//
//  /* HTML HEAD <TITLE>  this appears in browser tab and tooltip when hover
//  */
//
//
///*   sprintf(writebuf, "  <title>%s+%s Compatibility, produced by iPhone app %s.</title>",arr(0),arr(1), APP_NAME); */
///*   g_fn_prtlin(writebuf); */
//
//
//  /* if HTML filename, gbl_ffnameHTML, has any slashes, grab the basename
//  */
//  char myBaseName[256], *myptr;
//  if (sfind(gbl_gfnameHTML, '/')) {
//    myptr = strrchr(gbl_gfnameHTML, '/');
//    strcpy(myBaseName, myptr + 1);
//  } else {
//    strcpy(myBaseName, gbl_gfnameHTML);
//  }
//  sprintf(writebuf, "  <title>%s</title>", myBaseName);
//  g_fn_prtlin(writebuf);
//  
//
//
//  /* HEAD  META
//  */
//  sprintf(writebuf, "  <meta name=\"description\" content=\"Report of compatibility of 2 people produced by iPhone app %s\"> ", APP_NAME);
//  g_fn_prtlin(writebuf);
//
//
///*   g_fn_prtlin( "  <meta http-equiv=\"Content-Type\" content=\"text/html\"; charset=\"iso-8859-1\">");  */
//  g_fn_prtlin( "  <meta http-equiv=\"Content-Type\" content=\"text/html\"; charset=\"UTF-8\">"); 
///*   g_fn_prtlin( "  <meta name=\"Author\" content=\"Author goes here\">"); */
//
//
///*   g_fn_prtlin( "  <meta name=\"keywords\" content=\"group,group member,compatibility,year in the life,astrology,future,personality,GMCR\"> "); */
///*   g_fn_prtlin( "  <meta name=\"keywords\" content=\"BFF,astrology,compatibility,group,best,match,calendar,year,stress,personality\"> "); */
///*   g_fn_prtlin( "  <meta name=\"keywords\" content=\"measure,group,member,best,match,calendar,year,passionate,personality\"> "); */
///*   g_fn_prtlin( "  <meta name=\"keywords\" content=\"women,woman,female,BFF,compatibility,group,best,match,personality,stress,calendar,year\"> "); */ /* 86 chars */ 
//  g_fn_prtlin( "  <meta name=\"keywords\" content=\"women,woman,female,BFF,me,compatibility,group,best,match,personality,stress,calendar,year\"> ");  /* 89 chars */
//
//  /* get rid of CHROME translate "this page is in Galician" 
//  * do you want to translate?
//  */
//  g_fn_prtlin("  <meta name=\"google\" content=\"notranslate\">");
//  g_fn_prtlin("  <meta http-equiv=\"Content-Language\" content=\"en\" />");
//
//
//  /* Using the Viewport Meta Tag   this is browser version
//  * https://developer.apple.com/library/safari/documentation/AppleApplications/Reference/SafariWebContent/UsingtheViewport/UsingtheViewport.html#//apple_ref/doc/uid/TP40006509-SW25
//  *
//  * For example, TO SET THE VIEWPORT WIDTH TO THE WIDTH OF THE DEVICE, add this to your HTML file:
//  * <meta name="viewport" content="width=device-width"> 
//  * To set the initial scale to 1.0, add this to your HTML file:
//  * <meta name="viewport" content="initial-scale=1.0"> 
//  * To set the initial scale and to turn off user scaling, add this to your HTML file:
//  * <meta name="viewport" content="initial-scale=2.3, user-scalable=no">
//  */
//  g_fn_prtlin("  <meta name=\"viewport\" content=\"width=device-width\" />");
//
//
//  g_fn_prtlin("  <meta name = \"format-detection\" content = \"telephone=no\">");
//
//
//  /* HEAD   STYLE/CSS
//  */
//  g_fn_prtlin( "\n  <style type=\"text/css\">");
//  g_fn_prtlin( "    @media print { TABLE { font-size: 50%; } }");
//
//  g_fn_prtlin( "    BODY {");
///*  g_fn_prtlin( "      background-color: #F5EFCF;"); */
//  g_fn_prtlin( "      background-color: #f7ebd1;");
//
///*   g_fn_prtlin( "      font-family: Trebuchet MS, Arial, Verdana, sans-serif;"); */
//  g_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New;");
//
//  g_fn_prtlin( "      font-size:   medium;");
//  g_fn_prtlin( "      font-weight: normal;");
//  g_fn_prtlin( "      text-align:  center;");
///*   g_fn_prtlin( "    <!-- "); */
///*   g_fn_prtlin( "      background-image: url('mkgif1g.gif');"); */
///*   g_fn_prtlin( "    --> "); */
//  g_fn_prtlin( "    }");
//
///*   g_fn_prtlin( "    H1 { font-size: 137%; font-weight: bold;   line-height: 95%; text-align: center;}"); */
///*   g_fn_prtlin( "    H2 { font-size: 137%; font-weight: bold;   line-height: 25%; text-align: center;}"); */
///*   g_fn_prtlin( "    H3 { font-size: 110%; font-weight: normal; line-height: 30%; text-align: center;}"); */
///*   g_fn_prtlin( "    H1 { font-size: 137%; font-weight: bold;   line-height: 15%; text-align: center;}"); */
//  g_fn_prtlin( "    H1 { font-size: 137%; font-weight: bold;   line-height: 100%; text-align: center;}");
//  g_fn_prtlin( "    H2 { font-size: 120%; font-weight: bold;   line-height: 95%; text-align: center;}");
//  g_fn_prtlin( "    H3 { font-size: 110%; font-weight: normal; line-height: 95%; text-align: center;}");
//
//  g_fn_prtlin( "    H4 { font-size:  75%; font-weight: bold;   line-height: 30%; text-align: center;}");
//  g_fn_prtlin( "    H5 { font-size:  70%; font-weight: normal; line-height: 30%; text-align: center;}");
//
//
///*   g_fn_prtlin( "    H4 { font-size:  85%; font-weight: bold;   line-height: 30%; text-align: center;}"); */
///*   g_fn_prtlin( "    H5 { font-size:  55%; font-weight: normal; line-height: 90%; text-align: center;}"); */
///*   g_fn_prtlin( "    H5 { font-size:  70%; font-weight: normal; line-height: 30%; text-align: center;}"); */
//
//  g_fn_prtlin( "    PRE {");    // just 2
///*   g_fn_prtlin( "      padding: 1%;"); */
//  g_fn_prtlin( "      display: inline-block;");
///*   g_fn_prtlin( "      border-style: solid;"); */
//
///*   g_fn_prtlin( "      border-color: black;"); */
///*   g_fn_prtlin( "      border-width: 2px;"); */
///*   g_fn_prtlin( "      border-color: #e4dfae;"); */
///*   g_fn_prtlin( "      border-width: 5px;"); */
//
///*   g_fn_prtlin( "      display: inline-block;"); */
//  g_fn_prtlin( "      display: inline;");
//
//  g_fn_prtlin( "      background-color: #fcfce0;");
///*   g_fn_prtlin( "      border: none;"); */
///*   g_fn_prtlin( "      border-collapse: collapse;"); */
///*   g_fn_prtlin( "      border-spacing: 0;"); */
///*       border-collapse: collapse; */
///*   g_fn_prtlin( "      font-family: Andale Mono, Monospace, Courier New;"); */
///*   g_fn_prtlin( "      font-weight: normal;"); */
///*   g_fn_prtlin( "      font-size:   65%;"); */
///*   g_fn_prtlin( "      font-size:   75%;"); */
///*   g_fn_prtlin( "      line-height: 70%;"); */
///*   g_fn_prtlin( "      line-height: 100%;"); */
//  g_fn_prtlin( "      margin:0 auto;");
//  g_fn_prtlin( "    }");
//
///*   g_fn_prtlin( "      padding-left: 5%;"); */
///*   g_fn_prtlin( "      padding-right:5%;"); */
///*   g_fn_prtlin( "      text-align: center;"); */
///*   g_fn_prtlin( "    P { "); */
///*   g_fn_prtlin( "      font-family: Andale Mono, Menlo, Monospace, Courier New;"); */
///*   g_fn_prtlin( "      width: auto;"); */
///*   g_fn_prtlin( "      font-size:   80%;"); */
///*   g_fn_prtlin( "      margin-top: 0;"); */
///*   g_fn_prtlin( "      margin-bottom: 0;"); */
///*   g_fn_prtlin( "      margin-left: auto;"); */
///*   g_fn_prtlin( "      margin-right:auto;"); */
///*   g_fn_prtlin( "      text-align: left;"); */
///*   g_fn_prtlin( "    }"); */
//
//  g_fn_prtlin( "    P { ");
//  g_fn_prtlin( "      display: inline;");
//  g_fn_prtlin( "      margin:0 auto;");
//  g_fn_prtlin( "      background-color: #f7ebd1;");
//  g_fn_prtlin( "    }");
//
////  g_fn_prtlin( "    .expressed { ");
////  g_fn_prtlin( "      margin-left: 5em;");
////  g_fn_prtlin( "      width: 360%;");
////  g_fn_prtlin( "      color: red;");
////  g_fn_prtlin( "      font-size: 12em;");
//////  g_fn_prtlin( "      margin:0 auto;");
////  g_fn_prtlin( "    }");
////
//
///* for table: */
///*       border: 2px solid black; */
///*       cellspacing: 0; */
///*       border-top: 0; */
///*       border-bottom: 0; */
//
///* TABLE TABLE TABLE TABLE TABLE TABLE TABLE TABLE */
///*   g_fn_prtlin( "    table {");
//*   g_fn_prtlin( "      border-collapse: collapse;");
//*   g_fn_prtlin( "      border-spacing: 0;");
//*   g_fn_prtlin( "    }");
//*   g_fn_prtlin( "    table.center {");
//*   g_fn_prtlin( "      margin-left:auto;");
//*   g_fn_prtlin( "      margin-right:auto;");
//*   g_fn_prtlin( "    }");
//*   g_fn_prtlin( "    TD {");
//*   g_fn_prtlin( "      white-space: nowrap;");
//*   g_fn_prtlin( "      padding: 0;");
//*   g_fn_prtlin( "    }");
//*/
//
//  g_fn_prtlin( "    .browserRedGreenCenter {");
//  g_fn_prtlin( "      white-space: pre;");
//  g_fn_prtlin( "      margin-top: -3em;");
//  g_fn_prtlin( "      margin-left:auto;");
//  g_fn_prtlin( "      margin-right:auto;");
//  g_fn_prtlin( "    }");
////  g_fn_prtlin( "    table.redGreenCenter tr {");
////  g_fn_prtlin( "      white-space: pre;");
////  g_fn_prtlin( "      text-align: center;");
////  g_fn_prtlin( "      font-size: 1.5em;");
////  g_fn_prtlin( "    }");
//
//  g_fn_prtlin( "    .browserRedGreenCenter td {");
////  g_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New;");
//  g_fn_prtlin( "      white-space: pre;");
//  g_fn_prtlin( "      text-align: center;");
////  g_fn_prtlin( "      font-size: 1.5em;");
////  g_fn_prtlin( "      font-size: 1.2em;");
//  g_fn_prtlin( "      font-size: 0.8em;");
//// g_fn_prtlin( "      color: blue;"); 
//  g_fn_prtlin( "    }");
//
//                               /* new stuff for bottom TABLE */
//  g_fn_prtlin( "    table {");
///*   g_fn_prtlin( "      font-family: Andale Mono, Menlo, Monospace, Courier New;"); */
//  g_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New;");
//  g_fn_prtlin( "      text-align: left;");
//
///*   g_fn_prtlin( "      border: 1px solid black;"); */
//  g_fn_prtlin( "      border-collapse: collapse;");
//  g_fn_prtlin( "      border-spacing: 0;");
//
///*   g_fn_prtlin( "      padding-right:2%;"); */
///*   g_fn_prtlin( "      padding-left:2%;"); */
//  g_fn_prtlin( "      margin-left: auto;");
//  g_fn_prtlin( "      margin-right:auto;");
//  g_fn_prtlin( "    }");
//  g_fn_prtlin( "    td {");
///*   g_fn_prtlin( "      font-family: Andale Mono, Menlo, Monospace, Courier New;"); */
//  g_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New;");
//  g_fn_prtlin( "      white-space: pre;");
//  g_fn_prtlin( "      font-size: 90%;");
//  g_fn_prtlin( "      text-align: left;");
//
///*   g_fn_prtlin( "      border: 1px solid black;"); */
//  g_fn_prtlin( "      border-collapse: collapse;");
//  g_fn_prtlin( "      border-spacing: 0;");
//
///*   g_fn_prtlin( "      padding-left: 10px; "); */
///*   g_fn_prtlin( "      padding-right: 10px; "); */
//  g_fn_prtlin( "      padding-left: 5px; ");
//  g_fn_prtlin( "      padding-right: 5px; ");
//
//  g_fn_prtlin( "    }");
//  g_fn_prtlin( "    table.center {");
//  g_fn_prtlin( "      margin-left:auto;");
//  g_fn_prtlin( "      margin-right:auto;");
//  g_fn_prtlin( "    }");
//  g_fn_prtlin( "    th {");
//
//  g_fn_prtlin( "      padding: 5px; ");
//  g_fn_prtlin( "      vertical-align:bottom;");
//
///*   g_fn_prtlin( "      font-family: Trebuchet MS, Arial, Verdana, sans-serif;"); */
//  g_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New;");
//  g_fn_prtlin( "      font-size: 90%;");
///*   g_fn_prtlin( "      padding-left: 10px; "); */
///*   g_fn_prtlin( "      padding-right: 10px; "); */
//
///*   g_fn_prtlin( "      background-color: #e1fdc3 ;"); */
//     g_fn_prtlin( "      background-color: #fcfce0 ;");
//
///*   g_fn_prtlin( "      border: 1px solid black;"); */
//  g_fn_prtlin( "      border-spacing: 0;");
//
//  g_fn_prtlin( "      text-align: center;");
//  g_fn_prtlin( "    }");
//  g_fn_prtlin( "    table td  { text-align: right; }");
//  g_fn_prtlin( "    table td+td { text-align: left; }");
//
///*   g_fn_prtlin( "    table td+td+td { text-align: right; }"); */
//  g_fn_prtlin( "    table td+td+td { text-align: right; ");
///*   g_fn_prtlin( "      padding-right:3%;"); */
//  g_fn_prtlin( "    }");
//
//  g_fn_prtlin( "    table td+td+td+td { text-align: left; }");
//
//  g_fn_prtlin( "    .row4        { background-color:#f8f0c0; }");
//
///*   p_fn_prtlin( "    .cGr2        { background-color:#d0fda0; }"); */
///*   g_fn_prtlin( "    .cGr2        { background-color:#8bfd87; }"); */
///*   g_fn_prtlin( "    .cGr2        { background-color:#66ff33; }"); */
//
///*   p_fn_prtlin( "    .cGre        { background-color:#e1fdc3; }"); */
///*   g_fn_prtlin( "    .cGre        { background-color:#ccffb9; }"); */
///*   p_fn_prtlin( "    .cRed        { background-color:#ffd9d9; }"); */
///*   g_fn_prtlin( "    .cRed        { background-color:#ffcccc; }"); */
///*   p_fn_prtlin( "    .cRe2        { background-color:#fcb9b9; }"); */
///*   g_fn_prtlin( "    .cRe2        { background-color:#fc8888; }"); */
///*   g_fn_prtlin( "    .cRe2        { background-color:#fc6094; }"); */
///*   g_fn_prtlin( "    .cRe2        { background-color:#ff3366; }"); */
//
//
////  g_fn_prtlin( "    .cGr2        { background-color:#66ff33; }");
//  g_fn_prtlin( "    .cGr2        { background-color:#80ff40; }");
///*   g_fn_prtlin( "    .cGre        { background-color:#84ff98; }"); */
////  g_fn_prtlin( "    .cGre        { background-color:#a8ff98; }");
//  g_fn_prtlin( "    .cGre        { background-color:#c0ffc0; }");
////  g_fn_prtlin( "    .cRed        { background-color:#ff98a8; }");
//  g_fn_prtlin( "    .cRed        { background-color:#ffb5c9; }");
////  g_fn_prtlin( "    .cRe2        { background-color:#ff4477; }");
////  g_fn_prtlin( "    .cRe2        { background-color:#ff678f; }");
//  g_fn_prtlin( "    .cRe2        { background-color:#ff7ba3; }");
//
//
///*   g_fn_prtlin("    .cNeu        { background-color:#e1ddc3; }"); */
////  g_fn_prtlin("    .cNeu        { background-color:#e5e2c7; }");
//  g_fn_prtlin("    .cNeu        { background-color:#edebd8; }");
//
//  g_fn_prtlin( "    .cHed        { background-color:#fcfce0; }");
//  g_fn_prtlin( "    .cNam        { color:#3f3ffa;");
//  g_fn_prtlin( "                   background-color: #F7ebd1;");
//  g_fn_prtlin( "                   font-size: 133%;");
//  g_fn_prtlin( "    }");
//  g_fn_prtlin( "    .cNam2       { color:#3f3ffa; }");
//  g_fn_prtlin( "    .cCat        { background-color:#fdfbe1; }");
///* TABLE TABLE TABLE TABLE TABLE TABLE TABLE TABLE */
//
//  g_fn_prtlin( "  </style>");
//
///*   g_fn_prtlin( "    <!-- "); */
///*   g_fn_prtlin( "    PRE {line-height: 68%}; "); */
///*   g_p_fn_prtlin( "    P {margin-left:10%; margin-right:10%}"); */
///*   g_p_fn_prtlin( "    --> "); */
//
//    
//    /* put in favicon */
//    g_fn_prtlin("<link href=\"data:image/x-icon;base64,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\" rel=\"icon\" type=\"image/x-icon\" />");
//
//    
//    
//    
///* put in favicon */
//    // old favicon    g_fn_prtlin("<link href=\"data:image/x-icon;base64,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\" rel=\"icon\" type=\"image/x-icon\" />");
//
//  g_fn_prtlin( "</head>");
//  g_fn_prtlin( " ");
////  g_fn_prtlin("\n<body>");
//
//  // table title
//  g_fn_prtlin("<h1>Compatibility Potential of </h1>");  // these are ignored, i believe
//  sprintf(writebuf,
//    "<h1>%s and %s</h1>",
////    "<h1><span class=\"cNam\">%s</span> and <span class=\"cNam\">%s</span></h1>",
//    g_arr(0), g_arr(1)
//  );
//  g_fn_prtlin(writebuf);
// 
//  g_fn_prtlin(" ");
//
////  p_fn_prtlin( "<div style=\"height: 15vh\"></div>" ); // NOW IN JS  // add a div of height = height of divNAVB  +  2vh
//  g_fn_prtlin("<div id=\"smup_underNAVB\" style=\"position: relative; width: 100%; \"> </div>" ); // NOW IN JS, height is added (navbar * 1.25) 
//
//
//} /* end of put_top_of_just2_group_rpt() */
//


/* arg in_docin_last_idx  is pointing at the last line written.
* Therefore, the current docin_lines written
* run from index = 0 to index = arg in_docin_last_idx.
*/
void g_docin_get(char *in_line)
{
  
//tn();tr("in grphtm g_docin_GET");
tr("g_docin_get");ksn(in_line);
  if (is_first_g_docin_get == 1) g_global_read_idx = 0;
  else                           g_global_read_idx++;

  
  is_first_g_docin_get = 0;  /* set to false */

//tr("in g_docin_get");ki(g_global_read_idx);ki(g_global_max_docin_idx);

  if (   g_global_read_idx > g_global_max_docin_idx) {
    g_docin_free();
    rkabort("Error. grphtm.c walked off end of docin_lines array");
  }

  strcpy(in_line, g_global_docin_lines[g_global_read_idx] );

//tn();ksn(in_line);

  scharout(in_line,'\n');   /* remove newlines */

} /* end of g_docin_get */



void g_fn_prtlin(char *lin)
{
  char myEOL[8];
//tn();tr("in g_fn_prtlin");ksn(lin); 

//  if (strstr(gbl_g_in_html_filename, "webview") != NULL) {tn();tr("in g_fn_prtlin");ksn(lin); }

//if (gbl_db_code == 1) { tn();tr("gbl_db_code=1a");ksn(lin); }

  // if lin is like this,  _(gbl_db_code=1)___lin=[tabl|pair@16@tulsi gabbard@austin m]__
  // put underscores in lin   tulsi_gabbard   austin m
  //
//3132 _(gbl_db_code=1b)___lin=[tabl|pair@16@space_above@x]__
//3137 _(gbl_db_code=1b)___lin=[tabl|pair@16@tulsi_gabbard@austin_m]__
//3142 _(gbl_db_code=1b)___lin=[tabl|pair@16@space_below@x]__
//
  if (   strstr(lin, "tabl|pair")   != NULL // has to be there
      && strstr(lin, "space above") == NULL // cannot be there
      && strstr(lin, "space below") == NULL // cannot be there
  ) {
//ksn("put underscore 22222 bbb  ___________________________________");

    // 20170212 fixer put underscore in name with space
    //
    scharswitch(lin, ' ', '_');

    if (gbl_db_code == 1) { tn();tr("gbl_db_code=1b");ksn(lin); }
  }




  // EXCEPTION: for new tblrpts pco, actually output the lines
  //
  if (   strcmp(gbl_are_in_just2, "we are in make_html_file_just_2_people") == 0
      && strstr(gbl_g_in_html_filename, "webview") != NULL   
  ) {
    ; // for webview version of grpof2, go and print


  } else if (   strcmp(global_instructions, "return only html for table in string") == 0
             || strcmp(global_instructions, "return only compatibility score"     ) == 0
  ) {

    return;  /* do not write anything */
  }


// int dbsw;
// if (strstr(lin, "xx    ") != NULL) {dbsw = 1; tn();tn();}
 //if (dbsw == 1) {ksn(lin);}

    strcpy(myEOL, "\n");
    if (GBL_HTML_HAS_NEWLINES == 1)     strcpy(myEOL, "\n");
    if (GBL_HTML_HAS_NEWLINES == 0) {
      /* scharout(lin,'\n'); */  /* remove newlines */
      if (gbl_we_are_in_PRE_block == 1) strcpy(myEOL, "<br>");
      else                              strcpy(myEOL, "");
    }


    /* g_global_n = sprintf(g_global_p,"%s\n", lin); */
    g_global_n = sprintf(g_global_p,"%s%s", lin, myEOL);





// smup     fput(g_global_p, g_global_n, Fp_g_HTML_file);     NO FILES
//
// new write from here down

  if (gbl_is_first_g_fn_prtlin == 1) {
    gbl_put_html_here        = 0;  // beg of js malloc'd mem
    gbl_is_first_g_fn_prtlin = 0;  // not first any more
  }

// smup   fput(global_p, global_n, Fp_p_HTML_file);
//
  // char *gbl_space_for_HTML_per; // space malloc'ed in js,  passed into mamb_report_personality(), then here
  //
  // e.g.  memcpy(out_rank_lines[*out_rank_line_idx], &line, sizeof(struct rank_report_line));
  memcpy(gbl_space_for_HTML_ju2 + gbl_put_html_here, g_global_p, g_global_n);
//  char *tempptr;
//  int tempint;
//  void *tempptr = memcpy(gbl_space_for_HTML_per, g_global_p, global_n);
//    gbl_space_for_HTML_per = strncpy(gbl_space_for_HTML_per + gbl_put_html_here, g_global_p, global_n);
//    strncpy(gbl_space_for_HTML_per + gbl_put_html_here, g_global_p, global_n);

  gbl_put_html_here = gbl_put_html_here + g_global_n;
//tn();
//kin(gbl_put_html_here);
//ksn(gbl_space_for_HTML_ju2);

// smup 

} // end of  g_fn_prtlin()



/* show good      "stars" in graph as green line
*  show difficult "stars" in graph as red   line
*  Must change all "*" to " ";
*/
void g_fn_prtlin_stars(char *starline)
{
  char *pBegStar;
  char *pEndStar;
  char beforeStars[512], mycolor[8], allStars[512], afterStars[512];
  /* remember these incase the stars wrap to line 2,3, etc
  */
  static char current_star_type[16];  /* "good" or "difficult" */

//tn();trn("SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS");ksn(starline);

  if (sall(starline, " ") == 1) {
    return;
  }

  // set  gbl_countMinusLines = 0;  
  if (sfind(starline, '-')) {         // line has a '-' in it
    gbl_countMinusLines = gbl_countMinusLines + 1;
  }

  if (strstr(starline, "asy")      != NULL) {
    strcpy(current_star_type, "easy");
  }
  if (strstr(starline, "ifficult") != NULL) {
    strcpy(current_star_type, "difficult");
  }
  if (strcmp(current_star_type, "easy") == 0) {
/*     strcpy(mycolor, "cGr2");  */
    strcpy(mycolor, "cGre"); /* easy */
  }
  if (strcmp(current_star_type, "difficult") == 0) {
/*     strcpy(mycolor, "cRe2"); */
    strcpy(mycolor, "cRed");
  }
  /*    .cGre        { background-color:#e1fdc3; }
  *     .cRed        { background-color:#ffd9d9; }
  *     .cLineGood   { background-color:#c3fdc3; }
  *     .cLineStress { background-color:#ffbac7; }
  */

  /* write star line here
  */

  /*   pBegStar = strchr (starline, '*'); */
  /*   pEndStar = strrchr(starline, '*'); */

  /* NOTICE: "stars" are now '+'  or  '-' */

  /* find out if line has +  or  -  */
  /* returns 1 if it finds a char c in string s else, returns 0 */
  /* int sfind(char s[], char c)  */

  if (sfind(starline, '+')) {
    pBegStar = strchr (starline, '+');
    pEndStar = strrchr(starline, '+');
  } else if (sfind(starline, '-')) {
    pBegStar = strchr (starline, '-');
    pEndStar = strrchr(starline, '-');
  } else {
    return;  /* no "stars" */
  }
//ksn(starline);
  mkstr(beforeStars, starline, pBegStar - 1);
  mkstr(allStars,    pBegStar, pEndStar);
  mkstr(afterStars,  pEndStar + 1, starline + strlen(starline) - 1);
//ksn(beforeStars);
//ksn(allStars);
//ksn(afterStars);


  char side_left[128];
  char side_right[128];
  strcpy(side_left,  "<tr><td>");

  strcpy(side_right, "</td></tr>");


  // add one space at end of line for browser version
  //
  if (gbl_we_are_in_webview_version == 1)
  {  // 1/0 yes/no //  if (strstr(in_html_filename, "webview") != NULL)   // webview version
      sprintf(writebuf,
        "%s&nbsp%s<span class=\"%s\">%s</span>%s%s",   //  FFFFFFFFFF
        side_left,
        beforeStars + 12,
        mycolor,
        allStars,
        afterStars,
        side_right
      ); 
//ksn(writebuf);

      // weird fix   replace "qx" with one space
      //
      //      scharout(writebuf, 'q');  // removes all q (only one there)
      //      scharout(writebuf, 'x');  // removes all x (only one there)
      scharswitch(writebuf, 'q', ' '); // in s, replaces all old with new 
      scharswitch(writebuf, 'x', ' ');

//tn();tr("webview");ksn(writebuf);

//      g_fn_prtlin(writebuf);  
      prtStarsAs2lines(writebuf);

  } else {  
      // browser version
      sprintf(writebuf,
//      "%s %s<span class=\"%s\">%s</span>%s%s",
        "%s %s<span class=\"%s\">%s</span>%s %s",    // <=====  note  1 sp at eol
        side_left,
        beforeStars + 12,
        mycolor,
        allStars,
        afterStars,
        side_right
      ); 
//ksn(writebuf);

      // weird fix   replace "qx" with one space
      //
      //      scharout(writebuf, 'q');  // removes all q (only one there)
      //      scharout(writebuf, 'x');  // removes all x (only one there)
      scharswitch(writebuf, 'q', ' '); // in s, replaces all old with new 
      scharswitch(writebuf, 'x', ' ');

//tn();tr("browser");ksn(writebuf);

//      g_fn_prtlin(writebuf);  
      prtStarsAs2lines(writebuf);

  }

} /* end of g_fn_prtlin_stars() */

// we want "thicker line" so add blank line with color first and css has line-height at 50% so overlap
//
// example input line
//  [<tr><td>&nbsp         <span class="cGre">+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++</span>  </td></tr>]
//
void prtStarsAs2lines(char *linetoprt)
{
  char myworkline1[4096], myworkline2[4096];

//tn(); ki(gbl_countMinusLines);
//ksn(linetoprt);

  strcpy(myworkline1, linetoprt);               // print "blank" line            first
  strcpy(myworkline2, linetoprt);               // print print line with "stars" second

  // strsubg(char *s, char *replace_me, char *with_me) // on str s (max 2048) does  :s/replace_me/with_me/g
  strsubg(myworkline1, "+", "&nbsp");           // on str s (max 2048) does  :s/replace_me/with_me/g
  strsubg(myworkline1, "-", "&nbsp");           // on str s (max 2048) does  :s/replace_me/with_me/g

  if (gbl_countMinusLines == 0) {
    strsubg(myworkline1, "<tr>", "<tr class=\"linehite_0120\">");           // on str s (max 2048) does  :s/replace_me/with_me/g
//trn("blank  0 using linehite_0120");
  }
  if (gbl_countMinusLines == 1) {
    strsubg(myworkline1, "<tr>", "<tr class=\"linehite_0240\">");  
//trn("blank  1 using linehite_0240");
  }
  if (gbl_countMinusLines >= 2) {
    strsubg(myworkline1, "<tr>", "<tr class=\"linehite_0160\">"); 
//trn("blank  2 using linehite_0160");
  }

//ksn(myworkline1);
  g_fn_prtlin(myworkline1);  


  strcpy( myworkline2, linetoprt);               // now print line with "stars"  (++++  or ---)

  if (gbl_countMinusLines == 0) {
    strsubg(myworkline2, "<tr>", "<tr class=\"linehite_0120\">");
//trn("stars  0  using linehite_0120");
  }
  if (gbl_countMinusLines == 1) {
    strsubg(myworkline2, "<tr>", "<tr class=\"linehite_0000\">");
//trn("stars  1  using linehite_0000");
  }
  if (gbl_countMinusLines >= 2) {
    strsubg(myworkline2, "<tr>", "<tr class=\"linehite_0050\">"); 
//trn("stars  2  using linehite_0050");
  }


//ksn(myworkline2);
  g_fn_prtlin(myworkline2);  
  
} // end of prtStarsAs2lines



// iiiiiiiiiiiiiiiiiiiiiiiiiiiiiii   webview / ios  html code  iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii
// iiiiiiiiiiiiiiiiiiiiiiiiiiiiiii   webview / ios  html code  iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii
// iiiiiiiiiiiiiiiiiiiiiiiiiiiiiii   webview / ios  html code  iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii


/* output the css, headings etc.
*/
//void put_ios_top_of_just2_group_rpt(void)  /* just_2 rpt */
//{
////  int i;
////tn();trn("in put_ios_top_of_just2_group_rpt()");
//
//return;  // now rpt is tblrpt, not html
//
//
//// now rpt is tblrpt, not html
////
////  /* 1. read until [beg_topinfo1]  (name)  (skipping [beg_program])
////  */
////  for (i=0; ; i++) {
////    g_docin_get(doclin);
////    if (strstr(doclin, "[beg_topinfo1]") != NULL) break;
////  }
////  /* then save lines until graph until [end_topinfo1] 
////  * then put out html 
////  */
////  for (i=0; ; i++) {
////    g_docin_get(doclin);
////    if (strstr(doclin, "[end_topinfo1]") != NULL) break;
////    strcpy(arr(i), doclin);               //  HERE's where arr(0) and arr(1) get populated
////  }
////
/////*   at end, change to STRICT  */
////  g_fn_prtlin( "<!doctype html public \"-//w3c//dtd html 4.01 transitional//en\" ");
////  g_fn_prtlin( "  \"http://www.w3.org/TR/html4/loose.dtd\">");
////
////  g_fn_prtlin( "<html>");
////  g_fn_prtlin( "\n<head>");
////
////
////
////
////  /* HTML HEAD <TITLE>  this appears in browser tab and tooltip when hover
////  */
////
////
/////*   sprintf(writebuf, "  <title>%s+%s Compatibility, produced by iPhone app %s.</title>",arr(0),arr(1), APP_NAME); */
/////*   g_fn_prtlin(writebuf); */
////
////
////  /* if HTML filename, gbl_ffnameHTML, has any slashes, grab the basename
////  */
////  char myBaseName[256], *myptr;
////  if (sfind(gbl_gfnameHTML, '/')) {
////    myptr = strrchr(gbl_gfnameHTML, '/');
////    strcpy(myBaseName, myptr + 1);
////  } else {
////    strcpy(myBaseName, gbl_gfnameHTML);
////  }
////  sprintf(writebuf, "  <title>%s</title>", myBaseName);
////  g_fn_prtlin(writebuf);
////  
////
////
////  /* HEAD  META
////  */
////  sprintf(writebuf, "  <meta name=\"description\" content=\"Report of compatibility of 2 people produced by iPhone app %s\"> ", APP_NAME);
////  g_fn_prtlin(writebuf);
////
////
/////*   g_fn_prtlin( "  <meta http-equiv=\"Content-Type\" content=\"text/html\"; charset=\"iso-8859-1\">");  */
////  g_fn_prtlin( "  <meta http-equiv=\"Content-Type\" content=\"text/html\"; charset=\"UTF-8\">"); 
/////*   g_fn_prtlin( "  <meta name=\"Author\" content=\"Author goes here\">"); */
////
////
/////*   g_fn_prtlin( "  <meta name=\"keywords\" content=\"group,group member,compatibility,year in the life,astrology,future,personality,GMCR\"> "); */
/////*   g_fn_prtlin( "  <meta name=\"keywords\" content=\"BFF,astrology,compatibility,group,best,match,calendar,year,stress,personality\"> "); */
/////*   g_fn_prtlin( "  <meta name=\"keywords\" content=\"measure,group,member,best,match,calendar,year,passionate,personality\"> "); */
/////*   g_fn_prtlin( "  <meta name=\"keywords\" content=\"women,woman,female,BFF,compatibility,group,best,match,personality,stress,calendar,year\"> "); */ /* 86 chars */ 
////  g_fn_prtlin( "  <meta name=\"keywords\" content=\"women,woman,female,BFF,me,compatibility,group,best,match,personality,stress,calendar,year\"> ");  /* 89 chars */
////
////  /* get rid of CHROME translate "this page is in Galician" 
////  * do you want to translate?
////  */
////  g_fn_prtlin("  <meta name=\"google\" content=\"notranslate\">");
////  g_fn_prtlin("  <meta http-equiv=\"Content-Language\" content=\"en\" />");
////
////
////  /* Using the Viewport Meta Tag  (in iOS webView)
////  * https://developer.apple.com/library/safari/documentation/AppleApplications/Reference/SafariWebContent/UsingtheViewport/UsingtheViewport.html#//apple_ref/doc/uid/TP40006509-SW25
////  *
////  * For example, TO SET THE VIEWPORT WIDTH TO THE WIDTH OF THE DEVICE, add this to your HTML file:
////  * <meta name="viewport" content="width=device-width"> 
////  * To set the initial scale to 1.0, add this to your HTML file:
////  * <meta name="viewport" content="initial-scale=1.0"> 
////  * To set the initial scale and to turn off user scaling, add this to your HTML file:
////  * <meta name="viewport" content="initial-scale=2.3, user-scalable=no">
////  */
////
////  g_fn_prtlin("  <meta name=\"viewport\" content=\"width=device-width\" />");   //  ORIG   ORIG
////
////
////  // THIS IS WEBVIEW VERSION
////
////  
//////  g_fn_prtlin("  <meta name=\"viewport\" content=\"width=device-width, initial-scale=0.33, minimum-scale=0.33, maximum-scale=0.33 \" />");  // webview  OK <6=no
//////  g_fn_prtlin("  <meta name=\"viewport\" content=\"width=device-width initial-scale=0.56 minimum-scale=0.56; \" />");  // webview  OK <6=no
//////  g_fn_prtlin("  <meta name=\"viewport\" content=\"width=device-width, initial-scale=2.0, minimum-scale=2.0, maximum-scale=2.0\" />");  // webview  OK <6=no
////
////
////  g_fn_prtlin("  <meta name = \"format-detection\" content = \"telephone=no\">");
////
////
////  /* HEAD   STYLE/CSS
////  */
////  g_fn_prtlin( "\n  <style type=\"text/css\">");
////  g_fn_prtlin( "    @media print { TABLE { font-size: 50%; } }");
////
////
////  g_fn_prtlin( "    BODY {");   // WEBVIEW grpof2
////
/////*  g_fn_prtlin( "      background-color: #F5EFCF;"); */
////  g_fn_prtlin( "      background-color: #f7ebd1;");
////
/////*   g_fn_prtlin( "      font-family: Trebuchet MS, Arial, Verdana, sans-serif;"); */
////  g_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New;");
////
////  g_fn_prtlin( "      font-size:   medium;");
////  g_fn_prtlin( "      font-weight: normal;");
////  g_fn_prtlin( "      text-align:  center;");
/////*   g_fn_prtlin( "    <!-- "); */
/////*   g_fn_prtlin( "      background-image: url('mkgif1g.gif');"); */
/////*   g_fn_prtlin( "    --> "); */
////  g_fn_prtlin( "    }");
////
/////*   g_fn_prtlin( "    H1 { font-size: 137%; font-weight: bold;   line-height: 95%; text-align: center;}"); */
/////*   g_fn_prtlin( "    H2 { font-size: 137%; font-weight: bold;   line-height: 25%; text-align: center;}"); */
/////*   g_fn_prtlin( "    H3 { font-size: 110%; font-weight: normal; line-height: 30%; text-align: center;}"); */
/////*   g_fn_prtlin( "    H1 { font-size: 137%; font-weight: bold;   line-height: 15%; text-align: center;}"); */
////  g_fn_prtlin( "    H1 { font-size: 137%; font-weight: bold;   line-height: 100%; text-align: center;}");
////  g_fn_prtlin( "    H2 { font-size: 120%; font-weight: bold;   line-height: 95%; text-align: center;}");
////  g_fn_prtlin( "    H3 { font-size: 110%; font-weight: normal; line-height: 95%; text-align: center;}");
////
////  g_fn_prtlin( "    H4 { font-size:  75%; font-weight: bold;   line-height: 30%; text-align: center;}");
////  g_fn_prtlin( "    H5 { font-size:  70%; font-weight: normal; line-height: 30%; text-align: center;}");
////
////
/////*   g_fn_prtlin( "    H4 { font-size:  85%; font-weight: bold;   line-height: 30%; text-align: center;}"); */
/////*   g_fn_prtlin( "    H5 { font-size:  55%; font-weight: normal; line-height: 90%; text-align: center;}"); */
/////*   g_fn_prtlin( "    H5 { font-size:  70%; font-weight: normal; line-height: 30%; text-align: center;}"); */
////
////  // this is just 2
////
////  g_fn_prtlin( "    .expressed { ");
////  g_fn_prtlin( "      background-color: #f7ebd1;");
//////  g_fn_prtlin( "      margin-left: 8em;");
////  g_fn_prtlin( "      width: 360%;");
//////  g_fn_prtlin( "      color: red;");
////  g_fn_prtlin( "      font-size: 2.5em;");
////  g_fn_prtlin( "      margin:0 auto;");
////  g_fn_prtlin( "    }");
////
////  g_fn_prtlin( "    .linehite_0120 { ");        // blank line with countMinus == 0 (line with pluses +++)
////  g_fn_prtlin( "      line-height: 1.2;");    // stars line with countMinus == 0 (line with pluses +++)
////  g_fn_prtlin( "    }");
////
////  g_fn_prtlin( "    .linehite_0240 { ");        // blank line with countMinus == 1
////  g_fn_prtlin( "      line-height: 2.4;");
////  g_fn_prtlin( "    }");
////  g_fn_prtlin( "    .linehite_0160 { ");        // blank line with countMinus >= 2
////  g_fn_prtlin( "      line-height: 1.6;");
////  g_fn_prtlin( "    }");
////  g_fn_prtlin( "    .linehite_0000 { ");        // stars line with countMinus == 1
////  g_fn_prtlin( "      line-height: 0.0;");
////  g_fn_prtlin( "    }");
////  g_fn_prtlin( "    .linehite_0050 { ");          // stars line with countMinus >= 2 + lots of other lines
////  g_fn_prtlin( "      line-height: 0.5;");
////  g_fn_prtlin( "    }");
////
////
////  g_fn_prtlin( "    PRE {");
////  g_fn_prtlin( "      display: inline;");   // NEEDED ?
////  g_fn_prtlin( "      background-color: #fcfce0;");
//////  g_fn_prtlin( "      font-size: 0.6em;");         // GOLD order #3
////  g_fn_prtlin( "    }");
/////*   g_fn_prtlin( "      padding: 1%;"); */
//////  g_fn_prtlin( "      display: inline-block;");
/////*   g_fn_prtlin( "      border-style: solid;"); */
////
/////*   g_fn_prtlin( "      border-color: black;"); */
/////*   g_fn_prtlin( "      border-width: 2px;"); */
/////*   g_fn_prtlin( "      border-color: #e4dfae;"); */
/////*   g_fn_prtlin( "      border-width: 5px;"); */
////
/////*   g_fn_prtlin( "      display: inline-block;"); */
////
/////*   g_fn_prtlin( "      border: none;"); */
/////*   g_fn_prtlin( "      border-collapse: collapse;"); */
/////*   g_fn_prtlin( "      border-spacing: 0;"); */
/////*       border-collapse: collapse; */
/////*   g_fn_prtlin( "      font-family: Andale Mono, Monospace, Courier New;"); */
/////*   g_fn_prtlin( "      font-weight: normal;"); */
/////*   g_fn_prtlin( "      font-size:   65%;"); */
/////*   g_fn_prtlin( "      font-size:   75%;"); */
/////*   g_fn_prtlin( "      line-height: 70%;"); */
/////*   g_fn_prtlin( "      line-height: 100%;"); */
//////  g_fn_prtlin( "      margin:0 auto;");
////
/////*   g_fn_prtlin( "      padding-left: 5%;"); */
/////*   g_fn_prtlin( "      padding-right:5%;"); */
/////*   g_fn_prtlin( "      text-align: center;"); */
/////*   g_fn_prtlin( "    P { "); */
/////*   g_fn_prtlin( "      font-family: Andale Mono, Menlo, Monospace, Courier New;"); */
/////*   g_fn_prtlin( "      width: auto;"); */
/////*   g_fn_prtlin( "      font-size:   80%;"); */
/////*   g_fn_prtlin( "      margin-top: 0;"); */
/////*   g_fn_prtlin( "      margin-bottom: 0;"); */
/////*   g_fn_prtlin( "      margin-left: auto;"); */
/////*   g_fn_prtlin( "      margin-right:auto;"); */
/////*   g_fn_prtlin( "      text-align: left;"); */
/////*   g_fn_prtlin( "    }"); */
////
////  g_fn_prtlin( "    .myTitle {");
////  g_fn_prtlin( "      margin-top: 0.2em;");
//////  g_fn_prtlin( "      margin-bottom: 1.2em;");
////  g_fn_prtlin( "      margin-bottom: 0.2em;");
//////  g_fn_prtlin( "      margin-left: 2em;");
//////  f_fn_prtlin( "      text-align: center;");      // GOLD order #1
////  g_fn_prtlin( "      text-align: left;");      // GOLD order #1
////     // are putting spaces in code to center
//////  g_fn_prtlin( "      width: 300%m;");             // GOLD order #2
////  g_fn_prtlin( "      font-size: 3.0em;");         // GOLD order #3
////  g_fn_prtlin( "      font-weight: bold;"); 
////  g_fn_prtlin( "      background-color: #F7ebd1;");
////  g_fn_prtlin( "      white-space: pre ; display: block; unicode-bidi: embed");
////  g_fn_prtlin( "    }");
////
////  g_fn_prtlin( "    .checkoutbestmatch {");
////  //g_fn_prtlin( "      background-color: #fcfce0;");
////  g_fn_prtlin( "      margin-top: -0.8em;");
////  g_fn_prtlin( "      margin-left: 5.5em;");
////  g_fn_prtlin( "      text-align: left;");      // GOLD order #1
//////  g_fn_prtlin( "      width: 240%;");             // GOLD order #2  *BUT* width  AFFECTS OTHER BLOCKS
////  g_fn_prtlin( "      font-size: 1.0em;");  /* gold order #3 */
////  //g_fn_prtlin( "      line-height: 130%;");  
////  g_fn_prtlin( "      margin-bottom: 3em;");  // MUST BE ABOVE "white-space: pre;"
////  g_fn_prtlin( "      white-space: pre ; display: block; unicode-bidi: embed");
////  g_fn_prtlin( "    }");
////
////  g_fn_prtlin( "    .explproportion{");
//////  g_fn_prtlin( "      background-color: #fcfce0;");
////
////  g_fn_prtlin( "      padding-top: 0;");
////
////  g_fn_prtlin( "      padding-bottom: 0;");
//////  g_fn_prtlin( "      padding-bottom: -8.0em;");
////
//////  g_fn_prtlin( "      margin-top: 0.1em;");
////
//////  g_fn_prtlin( "      margin-top: -2.0em;");
////
////  g_fn_prtlin( "      margin-left: 1em;");
////  g_fn_prtlin( "      text-align: left;");      // GOLD order #1
//////  g_fn_prtlin( "      width: 240%;");             // GOLD order #2  *BUT* width  AFFECTS OTHER BLOCKS
////
////  g_fn_prtlin( "      font-size: 1.0em;");  /* gold order #3 */
////
//////  g_fn_prtlin( "      line-height: 150%;");  
//////  g_fn_prtlin( "      line-height: 115%;");  
//////  g_fn_prtlin( "      line-height: 1.2em;");  
//////  g_fn_prtlin( "      line-height: 1.5em;"); 
////  g_fn_prtlin( "      line-height: 1.2em;"); 
//////  g_fn_prtlin( "      margin-bottom: 0.1em;");  // MUST BE ABOVE "white-space: pre;"
////  g_fn_prtlin( "      margin-bottom: -2.0em;");  // MUST BE ABOVE "white-space: pre;"
//////  g_fn_prtlin( "      white-space: pre ; width: 100%; display: block; unicode-bidi: embed");
////  g_fn_prtlin( "      white-space: pre ;              display: block; unicode-bidi: embed");
////  g_fn_prtlin( "    }");
////
////
//////  g_fn_prtlin( "    .bgwide { background-color: #f00; width: 100%; height: 100%; display: block; } ");
//////  g_fn_prtlin( "    .bgwide { background-color: #f00; width: 100%;  display: inline-block; } ");
//////  g_fn_prtlin( "    .bgwide { background-color: #f00; overflow-x: hidden; width: 333%; } ");
////
////
//////  p_fn_prtlin( "     overflow-x: hidden; ");    // webview
//////  p_fn_prtlin( "      width: 300%;");             // GOLD order #2
////
////
//////  g_fn_prtlin( "    .aroundTop {");
////////table { table-layout:fixed }
//////  g_fn_prtlin( "      table-layout:fixed  ");
//////  g_fn_prtlin( "    }");
////
////  g_fn_prtlin( "    .categoryTable {");
//////  g_fn_prtlin( "      width: 70%;");
//////  g_fn_prtlin( "      font-size: 80%;");
////  g_fn_prtlin( "      font-size: 100%;");
////  g_fn_prtlin( "      background-color: #fcfce0;");
////  g_fn_prtlin( "    }");
////
////
////  g_fn_prtlin( "    .foreachcat {");
////  g_fn_prtlin( "     overflow-x: hidden; ");    // webview
////  g_fn_prtlin( "      text-align: left;");      // GOLD order #1
////
//////  g_fn_prtlin( "      width: 360%;");             // GOLD order #2
//////  g_fn_prtlin( "      width: 300%;");             // GOLD order #2
//////  g_fn_prtlin( "      width: 350%;");             // GOLD order #2
//////  g_fn_prtlin( "      width: 340%;");             // GOLD order #2  ok
//////  g_fn_prtlin( "      width: 345%;");             // GOLD order #2
////
//////  g_fn_prtlin( "      width: 360%;");             // GOLD order #2
//////  g_fn_prtlin( "      width: 400%;");             // GOLD order #2
////  g_fn_prtlin( "      width: 370%;");             // GOLD order #2
//////  g_fn_prtlin( "      width: 360%;");             // GOLD order #2
////
//////  g_fn_prtlin( "      font-size: 1.7em;"); 
//////  g_fn_prtlin( "      font-size: 1.5em;"); 
//////  g_fn_prtlin( "      font-size: 1.2em;"); 
////  g_fn_prtlin( "      font-size: 1.5em;"); 
////
////  g_fn_prtlin( "      background-color: #fcfce0;");
//////  g_fn_prtlin( "      text-align: left;");      // GOLD order #1
////
//////  g_fn_prtlin( "      line-height: 1.2em;");
//////  g_fn_prtlin( "      line-height: 1.33em;");
//////  g_fn_prtlin( "      line-height: 1.6;");
//////  g_fn_prtlin( "      line-height: 1.45;");
////  g_fn_prtlin( "      line-height: 1.45em;");
////
////  g_fn_prtlin( "      white-space: pre; display: block; unicode-bidi: embed; ");
////  g_fn_prtlin( "    }");
////
////
////  g_fn_prtlin( "    .foreachcat2 {");  // not used for now  20150513
//////  g_fn_prtlin( "      margin-top: -3.0em;");  // MUST BE ABOVE "white-space: pre;"
//////  g_fn_prtlin( "      margin-right: 7.0em;");
////  g_fn_prtlin( "     overflow-x: hidden; ");    // webview
////  g_fn_prtlin( "      text-align: left;");      // GOLD order #1
//////  g_fn_prtlin( "      width: 360%;");             // GOLD order #2
//////  g_fn_prtlin( "      width: 100%;");             // GOLD order #2
//////  g_fn_prtlin( "      width: 250%;");             // GOLD order #2
//////  g_fn_prtlin( "      width: 300%;");             // GOLD order #2
//////  g_fn_prtlin( "      width: 330%;");             // GOLD order #2
////  g_fn_prtlin( "      width: 360%;");             // GOLD order #2
//////  g_fn_prtlin( "      font-size: 1.2em;"); 
//////  g_fn_prtlin( "      font-size: 0.1em;"); 
//////  g_fn_prtlin( "      font-size: 0em;"); 
//////  g_fn_prtlin( "      font-size: 1.2em;"); 
//////  g_fn_prtlin( "      font-size: 0.4em;"); 
////  g_fn_prtlin( "      background-color: #fcfce0;");
////  g_fn_prtlin( "      color: #fcfce0;");
//////  g_fn_prtlin( "      line-height: 1.45em;");
////  g_fn_prtlin( "      line-height: 0.5em;");
////  g_fn_prtlin( "      white-space: pre; display: block; unicode-bidi: embed; ");
////  g_fn_prtlin( "    }");
////
////
////  // this is just 2
////
////
////  g_fn_prtlin( "    .aspectPara {");
////  g_fn_prtlin( "      background-color: #F7ebd1;");
//// // p_fn_prtlin( "      margin-left: 2.5em;");
////  g_fn_prtlin( "      margin-left: 0.5em;");
////  g_fn_prtlin( "      margin-right: 0.5em;"); 
////  g_fn_prtlin( "      margin-top: 2em;");
////  g_fn_prtlin( "      line-height: 130%;");  
////  g_fn_prtlin( "      text-align: left;");      // GOLD order #1
//////  p_fn_prtlin( "      width: 333%;");             // GOLD order #2
//////  g_fn_prtlin( "      width: 300%;");             // GOLD order #2
////  g_fn_prtlin( "      width: 360%;");             // GOLD order #2
////  
//////  g_fn_prtlin( "      font-size: 1.25em;");  /* gold order #3 */
//////  g_fn_prtlin( "      font-size: 2.5em;");  /* gold order #3 */
//////  g_fn_prtlin( "      font-size: 1.5em;");  /* gold order #3 */
////  g_fn_prtlin( "      font-size: 2.0em;");  /* gold order #3 */
////
//////  g_fn_prtlin( "      color:green;"); // 
////  g_fn_prtlin( "      white-space: pre ; display: block; unicode-bidi: embed");
////  g_fn_prtlin( "    }");
////
////
////
////  g_fn_prtlin( "    .categories{");
////
//////  g_fn_prtlin( "     width: 100%; ");
////
////
//////  g_fn_prtlin( "     background-color: #f00; width: 100%;  display: inline-block;  ");
////
//////  g_fn_prtlin( "     overflow-x: hidden; ");    // webview
////
//////  g_fn_prtlin( "      width: 300%;  display: inline-block;  ");
//////  g_fn_prtlin( "      width: 300%; ");
//////  g_fn_prtlin( "      width: 250%; ");
//////  g_fn_prtlin( "      width: 400%; ");
//////  g_fn_prtlin( "      width: 340%; ");
//////  g_fn_prtlin( "      width: 320%; ");
//////  g_fn_prtlin( "      width: 270%; ");
//////  g_fn_prtlin( "      width: 380%; ");
//////  g_fn_prtlin( "      width: 360%; ");
//////  g_fn_prtlin( "      width: 350%; ");
////  g_fn_prtlin( "      background-color: #fcfce0;");
////
////
////  g_fn_prtlin( "      padding-top: 0;");
//////  g_fn_prtlin( "      margin-top: -1.2em;");
////
//////  g_fn_prtlin( "      margin-left: 0.5em;");
////
//////  g_fn_prtlin( "      padding-bottom: -2.5em;");
//////  g_fn_prtlin( "      margin-bottom: -2.5em;");
////  g_fn_prtlin( "      text-align: left;");      // GOLD order #1
//////  g_fn_prtlin( "      width: 240%;");             // GOLD order #2  *BUT* width  AFFECTS OTHER BLOCKS
////
////  g_fn_prtlin( "      font-size: 0.8em;");  /* gold order #3 */
//////  g_fn_prtlin( "      font-size: 0.8em;");  /* gold order #3 */
////  //g_fn_prtlin( "      line-height: 130%;");  
////
////  g_fn_prtlin( "      margin-bottom: 3em;");  // MUST BE ABOVE "white-space: pre;"
//////  g_fn_prtlin( "      margin-bottom: -2.5em;"); 
////
////  g_fn_prtlin( "      white-space: pre ; display: block; unicode-bidi: embed");
////
//////  g_fn_prtlin( "     background-color: #f00; width: 300%; overflow-x: hidden;  display: block;  ");
//////  g_fn_prtlin( "     background-color: #f00; width: 200%; overflow-x: hidden;  display: block;  ");
//////  g_fn_prtlin( "     background-color: #f00; width: 160%; overflow-x: hidden;  display: inline-block;  ");
//////  g_fn_prtlin( "     background-color: #f00; width: 200%; overflow-x: hidden;                          ");
////
////  g_fn_prtlin( "    }");
////
////
////  g_fn_prtlin( "    P { ");
////  g_fn_prtlin( "      display: inline;");
////  g_fn_prtlin( "      margin:0 auto;");
////  g_fn_prtlin( "      background-color: #f7ebd1;");
////  g_fn_prtlin( "    }");
////
////
////  // this is just 2
////
////
////
////  g_fn_prtlin( "    .explpotential{");
//////  g_fn_prtlin( "      width: 250%;");
//////  g_fn_prtlin( "      background-color: #fcfce0;");
////  g_fn_prtlin( "      padding-top: 0;");
////  g_fn_prtlin( "      padding-bottom: 0;");
////
//////  g_fn_prtlin( "      margin-top: -4.3em;");
////
//////  g_fn_prtlin( "      margin-left: 0.3em;");
//////  g_fn_prtlin( "      margin-left: 1.5em;");
//////  g_fn_prtlin( "      margin-left: 3.0em;");
////  g_fn_prtlin( "      margin-left: 2.3em;");
////
////  g_fn_prtlin( "      text-align: left;");      // GOLD order #1
//////  g_fn_prtlin( "      width: 240%;");             // GOLD order #2  *BUT* width  AFFECTS OTHER BLOCKS
////
//////  g_fn_prtlin( "      font-size: 1.0em;");  /* gold order #3 */
//////  g_fn_prtlin( "      font-size: 3.0em;");  /* gold order #3 */
//////  g_fn_prtlin( "      font-size: 2.0em;");  /* gold order #3 */
//////  g_fn_prtlin( "      font-size: 1.5em;");  /* gold order #3 */
//////  g_fn_prtlin( "      font-size: 2.5em;");  /* gold order #3 */
////  g_fn_prtlin( "      font-size: 2.0em;");  /* gold order #3 */
////
////
////
//////  g_fn_prtlin( "      font-size: 1.0em;");  /* gold order #3 */
////  //g_fn_prtlin( "      line-height: 130%;");  
//////  g_fn_prtlin( "      margin-top: -2.0em;");  
//////  g_fn_prtlin( "      margin-top: -1.0em;");  
////  g_fn_prtlin( "      margin-top: -0.5em;");  
////  g_fn_prtlin( "      margin-bottom: 0.1em;");  // MUST BE ABOVE "white-space: pre;"
////  g_fn_prtlin( "      white-space: pre ; display: block; unicode-bidi: embed");
////  g_fn_prtlin( "    }");
////
////
////  g_fn_prtlin( "    .explrelationship{");
//////  g_fn_prtlin( "      background-color: #fcfce0;");
//////  g_fn_prtlin( "      width: 250%;");
////  g_fn_prtlin( "      padding-top: 0;");
////  g_fn_prtlin( "      padding-bottom: 0;");
//////  g_fn_prtlin( "      margin-top: 2em;");
////  g_fn_prtlin( "      margin-top: 1em;");
////
//////  g_fn_prtlin( "      margin-left: 3.8em;");
//////  g_fn_prtlin( "      margin-left: 1.5em;");
//////  g_fn_prtlin( "      margin-left: 2.1em;");
//////  g_fn_prtlin( "      margin-left: 2.7em;");
//////  g_fn_prtlin( "      margin-left: 5.7em;");
//////  g_fn_prtlin( "      margin-left: 4.1em;");
////  g_fn_prtlin( "      margin-left: 3.7em;");
////
////  g_fn_prtlin( "      text-align: left;");      // GOLD order #1
//////  g_fn_prtlin( "      width: 240%;");             // GOLD order #2  *BUT* width  AFFECTS OTHER BLOCKS
////
//////  g_fn_prtlin( "      font-size: 1.0em;");  /* gold order #3 */
//////  g_fn_prtlin( "      font-size: 1.4em;");  /* gold order #3 */
//////  g_fn_prtlin( "      font-size: 1.2em;");  /* gold order #3 */
//////  g_fn_prtlin( "      font-size: 1.1em;");  /* gold order #3 */
////
//////  g_fn_prtlin( "      font-size: 2.0em;");  /* gold order #3 */
//////  g_fn_prtlin( "      font-size: 1.6em;");  /* gold order #3 */
//////  g_fn_prtlin( "      font-size: 2.0em;");  /* gold order #3 */
////  g_fn_prtlin( "      font-size: 1.8em;");  /* gold order #3 */
////
////  //g_fn_prtlin( "      line-height: 130%;");  
////
////  g_fn_prtlin( "      margin-bottom: 0.1em;");  // MUST BE ABOVE "white-space: pre;"
//////  g_fn_prtlin( "      margin-bottom: -2.0em;");  // MUST BE ABOVE "white-space: pre;"
////
////  g_fn_prtlin( "      white-space: pre ; display: block; unicode-bidi: embed");
////  g_fn_prtlin( "    }");
////
////
////  g_fn_prtlin( "    .appby{");
//////  g_fn_prtlin( "      background-color: #fcfce0;");
////  g_fn_prtlin( "      padding-top: 0;");
////  g_fn_prtlin( "      padding-bottom: 0;");
//////  g_fn_prtlin( "      margin-top: 1.5em;");
////  g_fn_prtlin( "      margin-top: 1.0em;");
////
//////  g_fn_prtlin( "      margin-left: 12em;");
//////  g_fn_prtlin( "      margin-left: 6.5em;");
//////  g_fn_prtlin( "      margin-left: 3em;");
//////  g_fn_prtlin( "      margin-left: 4.5em;");
//////  g_fn_prtlin( "      margin-left: 8em;");
//////  g_fn_prtlin( "      margin-left: 11em;");
////  g_fn_prtlin( "      margin-left: 9.5em;");
////
////  g_fn_prtlin( "      text-align: left;");      // GOLD order #1
//////  g_fn_prtlin( "      width: 240%;");             // GOLD order #2  *BUT* width  AFFECTS OTHER BLOCKS
////
//////  g_fn_prtlin( "      font-size: 0.8em;");  /* gold order #3 */
//////  g_fn_prtlin( "      font-size: 1.5em;");  /* gold order #3 */
//////  g_fn_prtlin( "      font-size: 1.0em;");  /* gold order #3 */
////  g_fn_prtlin( "      font-size: 1.5em;");  /* gold order #3 */
////
////  //g_fn_prtlin( "      line-height: 130%;");  
////  g_fn_prtlin( "      margin-bottom: 0.1em;");  // MUST BE ABOVE "white-space: pre;"
////  g_fn_prtlin( "      white-space: pre ; display: block; unicode-bidi: embed");
////  g_fn_prtlin( "    }");
////
////
////  g_fn_prtlin( "    .entertainment {");
////  g_fn_prtlin( "      text-align: left;");
////  g_fn_prtlin( "      margin-top: -1.0em;");  // MUST BE ABOVE "white-space: pre;"
//////  g_fn_prtlin( "      margin-left: 9em;");
//////  g_fn_prtlin( "      margin-left: 4em;");
//////  g_fn_prtlin( "      margin-left: 8em;");
////  g_fn_prtlin( "      margin-left: 7em;");
//////  g_fn_prtlin( "      width: 150%;");             // GOLD order #2
//////  g_fn_prtlin( "      background-color: #F7ebd1;");
////
//////  g_fn_prtlin( "      font-size: 0.8em;");
//////  g_fn_prtlin( "      font-size: 1.6em;");
//////  g_fn_prtlin( "      font-size: 1.1em;");
////  g_fn_prtlin( "      font-size: 1.5em;");
////  g_fn_prtlin( "      font-weight: bold;");
////
////  g_fn_prtlin( "      color:#FF0000;");  // RED print
////  g_fn_prtlin( "      white-space: pre ; display: block; unicode-bidi: embed");
/////*   p_fn_prtlin( "      font-size: 130%;");  */
////  g_fn_prtlin( "    }");
////
////
////  // this is just 2
////
////
/////* for table: */
/////*       border: 2px solid black; */
/////*       cellspacing: 0; */
/////*       border-top: 0; */
/////*       border-bottom: 0; */
////
/////* TABLE TABLE TABLE TABLE TABLE TABLE TABLE TABLE */
/////*   g_fn_prtlin( "    table {");
////*   g_fn_prtlin( "      border-collapse: collapse;");
////*   g_fn_prtlin( "      border-spacing: 0;");
////*   g_fn_prtlin( "    }");
////*   g_fn_prtlin( "    table.center {");
////*   g_fn_prtlin( "      margin-left:auto;");
////*   g_fn_prtlin( "      margin-right:auto;");
////*   g_fn_prtlin( "    }");
////*   g_fn_prtlin( "    TD {");
////*   g_fn_prtlin( "      white-space: nowrap;");
////*   g_fn_prtlin( "      padding: 0;");
////*   g_fn_prtlin( "    }");
////*/
////                               /* new stuff for bottom TABLE */
//////   g_fn_prtlin( "    table {");
////// /*   g_fn_prtlin( "      font-family: Andale Mono, Menlo, Monospace, Courier New;"); */
//////   g_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New;");
//////   g_fn_prtlin( "      text-align: left;");
////// /*   g_fn_prtlin( "      border: 1px solid black;"); */
//////   g_fn_prtlin( "      border-collapse: collapse;");
//////   g_fn_prtlin( "      border-spacing: 0;");
////// /*   g_fn_prtlin( "      padding-right:2%;"); */
////// /*   g_fn_prtlin( "      padding-left:2%;"); */
//////   g_fn_prtlin( "      margin-left: auto;");
//////   g_fn_prtlin( "      margin-right:auto;");
//////   g_fn_prtlin( "    }");
////
////   g_fn_prtlin( "    table {");  // applies to all tables ?  YES, IT DOES !  yay
////   g_fn_prtlin( "      border-collapse: collapse;");
//////   g_fn_prtlin( "      width: 350%;");
////
//////   g_fn_prtlin( "      width: 360%;");
////   g_fn_prtlin( "      width: 340%;");
////
////  g_fn_prtlin( "    }");
////
////
////
////  g_fn_prtlin( "    table.category {");   // webview version
////
//////  g_fn_prtlin( "      margin-left: 2em;");
////
////  g_fn_prtlin( "      width: 360%;");  // magic (matches width of .foreachcat and one other)
////  g_fn_prtlin( "      margin-top: 0em;");
////  g_fn_prtlin( "      margin-bottom: 0em;");
////  g_fn_prtlin( "     border-collapse: collapse;   ");
////  g_fn_prtlin( "      border-spacing: 0;");
////  g_fn_prtlin( "      border: none;");
////  g_fn_prtlin( "      font-size: 1.0em;");
////  g_fn_prtlin( "      background-color: #fcfce0 ;");
//////  g_fn_prtlin( "      background-color: #fcace0 ;");  // 
////
//////  g_fn_prtlin( "      white-space: pre; display: block; unicode-bidi: embed; ");
//////  g_fn_prtlin( "      white-space: pre;  ");
//////  g_fn_prtlin( "      text-align: left;");
////
////  g_fn_prtlin( "    }");
////
////  g_fn_prtlin( "    table.category tr {");
//////  g_fn_prtlin( "      line-height: 0.5em;");
////  g_fn_prtlin( "      margin-top: 0em;");
////  g_fn_prtlin( "      margin-bottom: 0em;");
////  g_fn_prtlin( "      border-spacing: 0;");
////  g_fn_prtlin( "      border-collapse: collapse;");
////  g_fn_prtlin( "      border-spacing: 0;");
////  g_fn_prtlin( "      padding-top: 0px; ");
////  g_fn_prtlin( "      padding-bottom: 0px; ");
////  g_fn_prtlin( "    }");
////  g_fn_prtlin( "    table.category td {");
////  g_fn_prtlin( "      border: none;");
////  g_fn_prtlin( "      border-spacing: 0;");
////  g_fn_prtlin( "      border-collapse: collapse;");
////  g_fn_prtlin( "      padding-top: 0px; ");
////  g_fn_prtlin( "      padding-bottom: 0px; ");
////  g_fn_prtlin( "    }");
////
////
////
////
////  g_fn_prtlin( "    td {");
/////*   g_fn_prtlin( "      font-family: Andale Mono, Menlo, Monospace, Courier New;"); */
////  g_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New;");
////  g_fn_prtlin( "      white-space: pre;");
////
//////  g_fn_prtlin( "      font-size: 90%;");
////
////  g_fn_prtlin( "      text-align: left;");
////
/////*   g_fn_prtlin( "      border: 1px solid black;"); */
////  g_fn_prtlin( "      border-collapse: collapse;");
////  g_fn_prtlin( "      border-spacing: 0;");
////
/////*   g_fn_prtlin( "      padding-left: 10px; "); */
/////*   g_fn_prtlin( "      padding-right: 10px; "); */
////  g_fn_prtlin( "      padding-left: 5px; ");
////  g_fn_prtlin( "      padding-right: 5px; ");
////
////  g_fn_prtlin( "    }");
////  g_fn_prtlin( "    table.center {");
////  g_fn_prtlin( "      margin-left:auto;");
////  g_fn_prtlin( "      margin-right:auto;");
////  g_fn_prtlin( "    }");
////  g_fn_prtlin( "    table.center td{");
////  g_fn_prtlin( "      text-align: center;");
////  g_fn_prtlin( "      font-size: 1.5em;");
////  g_fn_prtlin( "    }");
////
////  // this is just 2
////
////  g_fn_prtlin( "    table.redGreenCenter {");
////  g_fn_prtlin( "      white-space: pre;");
////  g_fn_prtlin( "      margin-top: -3em;");
////  g_fn_prtlin( "      margin-left:auto;");
////  g_fn_prtlin( "      margin-right:auto;");
////  g_fn_prtlin( "    }");
//////  g_fn_prtlin( "    table.redGreenCenter tr {");
//////  g_fn_prtlin( "      white-space: pre;");
//////  g_fn_prtlin( "      text-align: center;");
//////  g_fn_prtlin( "      font-size: 1.5em;");
//////  g_fn_prtlin( "    }");
////
////  g_fn_prtlin( "    table.redGreenCenter td {");
//////  g_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New;");
////  g_fn_prtlin( "      white-space: pre;");
////  g_fn_prtlin( "      text-align: center;");
//////  g_fn_prtlin( "      font-size: 1.5em;");
////  g_fn_prtlin( "      font-size: 0.8em;");
//////  g_fn_prtlin( "      color: blue;");
////  g_fn_prtlin( "    }");
////  g_fn_prtlin( "    th {");
////
////  g_fn_prtlin( "      padding: 5px; ");
////  g_fn_prtlin( "      vertical-align:bottom;");
////
/////*   g_fn_prtlin( "      font-family: Trebuchet MS, Arial, Verdana, sans-serif;"); */
////  g_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New;");
////  g_fn_prtlin( "      font-size: 90%;");
/////*   g_fn_prtlin( "      padding-left: 10px; "); */
/////*   g_fn_prtlin( "      padding-right: 10px; "); */
////
/////*   g_fn_prtlin( "      background-color: #e1fdc3 ;"); */
////     g_fn_prtlin( "      background-color: #fcfce0 ;");
////
/////*   g_fn_prtlin( "      border: 1px solid black;"); */
////  g_fn_prtlin( "      border-spacing: 0;");
////
////  g_fn_prtlin( "      text-align: center;");
////  g_fn_prtlin( "    }");
////  g_fn_prtlin( "    table td  { text-align: right; }");
////  g_fn_prtlin( "    table td+td { text-align: left; }");
////
/////*   g_fn_prtlin( "    table td+td+td { text-align: right; }"); */
////  g_fn_prtlin( "    table td+td+td { text-align: right; ");
/////*   g_fn_prtlin( "      padding-right:3%;"); */
////  g_fn_prtlin( "    }");
////
////  g_fn_prtlin( "    table td+td+td+td { text-align: left; }");
////
////  g_fn_prtlin( "    .row4        { background-color:#f8f0c0; }");
////
/////*   p_fn_prtlin( "    .cGr2        { background-color:#d0fda0; }"); */
/////*   g_fn_prtlin( "    .cGr2        { background-color:#8bfd87; }"); */
/////*   g_fn_prtlin( "    .cGr2        { background-color:#66ff33; }"); */
////
/////*   p_fn_prtlin( "    .cGre        { background-color:#e1fdc3; }"); */
/////*   g_fn_prtlin( "    .cGre        { background-color:#ccffb9; }"); */
/////*   p_fn_prtlin( "    .cRed        { background-color:#ffd9d9; }"); */
/////*   g_fn_prtlin( "    .cRed        { background-color:#ffcccc; }"); */
/////*   p_fn_prtlin( "    .cRe2        { background-color:#fcb9b9; }"); */
/////*   g_fn_prtlin( "    .cRe2        { background-color:#fc8888; }"); */
/////*   g_fn_prtlin( "    .cRe2        { background-color:#fc6094; }"); */
/////*   g_fn_prtlin( "    .cRe2        { background-color:#ff3366; }"); */
////
////
////  g_fn_prtlin( "    .cGr2        { background-color:#66ff33; }");
////  g_fn_prtlin( "    .cGr2tabonly { background-color:#66ff33; line-height: 175% ; padding: 0;}");
////
/////*   g_fn_prtlin( "    .cGre        { background-color:#84ff98; }"); */
////  g_fn_prtlin( "    .cGre        { background-color:#a8ff98; }");
////  g_fn_prtlin( "    .cGretabonly { background-color:#a8ff98; line-height: 175% ; padding: 0;}");
//////  g_fn_prtlin( "    .cGLi        { background-color:#eaffe6; }");  // super light green 
////  g_fn_prtlin( "    .cGLi        { background-color:#daffe3; }");  // super light green   little darker
////
//////  g_fn_prtlin( "    .cRed        { background-color:#ff98a8; }");
//////  g_fn_prtlin( "    .cRedtabonly { background-color:#ff98a8; line-height: 175% ; padding: 0}");
////  g_fn_prtlin( "    .cRed        { background-color:#ffb5c9; }");
////  g_fn_prtlin( "    .cRedtabonly { background-color:#ffb5c9; line-height: 175% ; padding: 0}");
//////  g_fn_prtlin( "    .cRLi        { background-color:#ffe8ee; }");  // super light red 
////  g_fn_prtlin( "    .cRLi        { background-color:#fff0f4; }");  // super light red even lighter
////  g_fn_prtlin( "    .cBbg        { background-color:#f7ebd1; }");  // body background color
////
////  g_fn_prtlin( "    }");
//////  g_fn_prtlin( "    .cRe2        { background-color:#ff4477; }");
////  g_fn_prtlin( "    .cRe2        { background-color:#ff678f; }");
//////  g_fn_prtlin( "    .cRe2tabonly { background-color:#ff4477; line-height: 175% ; padding: 0; font-weight: bold; }");
//////  g_fn_prtlin( "    .cRe2tabonly { background-color:#ff4477; line-height: 175% ; padding: 0;                    }");
////  g_fn_prtlin( "    .cRe2tabonly { background-color:#ff678f; line-height: 175% ; padding: 0;                    }");
////  g_fn_prtlin( "    .cNeu        { background-color:#e5e2c7; }");
////  g_fn_prtlin( "    .cNeutabonly { background-color:#e5e2c7; line-height: 175% ; padding: 0;}");
////
////  g_fn_prtlin( "    .cHed        { background-color:#fcfce0; }");
////  g_fn_prtlin( "    .cNam        { color:#3f3ffa;");
////  g_fn_prtlin( "                   background-color: #F7ebd1;");
////  g_fn_prtlin( "                   font-size: 133%;");
////  g_fn_prtlin( "    }");
////  g_fn_prtlin( "    .cNam2       { color:#3f3ffa; }");
////  g_fn_prtlin( "    .cCat        { background-color:#fdfbe1; }");
/////* TABLE TABLE TABLE TABLE TABLE TABLE TABLE TABLE */
////
////  g_fn_prtlin( "  </style>");
////
/////*   g_fn_prtlin( "    <!-- "); */
/////*   g_fn_prtlin( "    PRE {line-height: 68%}; "); */
/////*   g_p_fn_prtlin( "    P {margin-left:10%; margin-right:10%}"); */
/////*   g_p_fn_prtlin( "    --> "); */
////
////    
////    /* put in favicon */
////    g_fn_prtlin("<link href=\"data:image/x-icon;base64,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\" rel=\"icon\" type=\"image/x-icon\" />");
////
////    
////    
////    
/////* put in favicon */
////    // old favicon    g_fn_prtlin("<link href=\"data:image/x-icon;base64,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\" rel=\"icon\" type=\"image/x-icon\" />");
////
////  g_fn_prtlin( "</head>");
////  g_fn_prtlin( " ");
////  g_fn_prtlin("\n<body>");
////
/////*   g_fn_prtlin( "<body background=\"file:///mkgif1g.gif\">"); */
/////*   g_fn_prtlin( "<body background=\"file:///C/USR/RK/html/mkgif1g.gif\">"); */
////
//// 
////  int sizeLongestFld;
////  char myleftmargin[32], name1_and[32];
////
////  sizeLongestFld = sprintf(name1_and, "%s  and", arr(0)); // name1 always has "  and"
////  if ((int)strlen(arr(1)) > sizeLongestFld) sizeLongestFld = (int)strlen(arr(1));
////
////  // then max 15 char name, then 4 char " and"     both centered in 19 char field
////  // extra sp on left
////
////  // centre "name1  and" in a fld of max 19 (15 + 4)
////  //
////       if (sizeLongestFld ==  5) { strcpy(myleftmargin, "5.3em;"); }
////  else if (sizeLongestFld ==  6) { strcpy(myleftmargin, "5.0em;"); }
////  else if (sizeLongestFld ==  7) { strcpy(myleftmargin, "4.8em;"); }
////  else if (sizeLongestFld ==  8) { strcpy(myleftmargin, "4.5em;"); }
////  else if (sizeLongestFld ==  9) { strcpy(myleftmargin, "4.3em;"); }
////  else if (sizeLongestFld == 10) { strcpy(myleftmargin, "4.0em;"); }
////  else if (sizeLongestFld == 11) { strcpy(myleftmargin, "3.8em;"); }
////  else if (sizeLongestFld == 12) { strcpy(myleftmargin, "3.5em;"); }
////  else if (sizeLongestFld == 13) { strcpy(myleftmargin, "3.3em;"); }
////  else if (sizeLongestFld == 14) { strcpy(myleftmargin, "3.0em;"); }
////  else if (sizeLongestFld == 15) { strcpy(myleftmargin, "2.8em;"); }
////  else if (sizeLongestFld == 16) { strcpy(myleftmargin, "2.5em;"); }
////  else if (sizeLongestFld == 17) { strcpy(myleftmargin, "2.3em;"); }
////  else if (sizeLongestFld == 18) { strcpy(myleftmargin, "2.0em;"); }
////  else if (sizeLongestFld == 19) { strcpy(myleftmargin, "1.8em;"); }
////  else                           { strcpy(myleftmargin, "1.5em;"); }
////
////
////
//////  sprintf(writebuf,  "<pre style=\"margin-left: %s;\" class=\"myTitle\" >", myleftmargin); 
//////  g_fn_prtlin(writebuf);
//////  gbl_we_are_in_PRE_block = 1;
//////
//////  g_fn_prtlin(name1_and);   // name1
//////  g_fn_prtlin(arr(1));      // name2
//////
//////  gbl_we_are_in_PRE_block = 0;
//////  g_fn_prtlin("</pre>");
//////
////  g_fn_prtlin("<div><br></div>");
////
////
//// now rpt is tblrpt
//
//
//}  // end of  put_ios_top_of_just2_group_rpt(void)  /* just_2 rpt */
//

// all commented out

// iiiiiiiiiiiiiiiiiiiiiiiiiiiiiii   webview / ios  html code  iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii
// iiiiiiiiiiiiiiiiiiiiiiiiiiiiiii   webview / ios  html code  iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii
// iiiiiiiiiiiiiiiiiiiiiiiiiiiiiii   webview / ios  html code  iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii


/* ************************************************************
*
* ************************************************************/
void g_fn_browser_aspect_text(char *in_aspect_code)
{
  int nn;
  char aspcodeToSearch[32], possessiveA[64], possessiveB[64], lastchar; 
  char oldAspCode[32];
  char numplusminus[32];

//trn("in g_fn_browser_aspect_text()"); 
//ksn(in_aspect_code);
  // get old gP_ITEM_TBL from PSV
  //
  strcpy(oldAspCode,   csv_get_field(in_aspect_code, "|", 1) );
  strcpy(numplusminus, csv_get_field(in_aspect_code, "|", 2) );


  // fix aspect code like this:  e.g.  _(in g_docin_GET)___in_line=[^(c03b02)]__
  //                   to this:  "c03b02"
  strcpy(aspcodeToSearch, oldAspCode);
  scharout(aspcodeToSearch, '^');  
  scharout(aspcodeToSearch, '(');  
  scharout(aspcodeToSearch, ')');  
//ksn(aspcodeToSearch);

  nn = binsearch_asp(aspcodeToSearch, g_asptab, G_NKEYS_ASP);
//kin(nn);

  if (nn < 0) return;  /* do not print any aspect text at all  */

  strcpy(g_my_aspect_text, g_asptab[nn].g_asp_text);


  // do posessive forms of names, if necessary
  //
  if (strstr(g_my_aspect_text, "^^(Ap)") != NULL ) { 
    lastchar = gbl_just2PersonA[strlen(gbl_just2PersonA) - 1];
    if (lastchar == 's' ||  lastchar == 'z') {
      sprintf(possessiveA, "%s\'", gbl_just2PersonA);
      strsubg(g_my_aspect_text, "^^(Ap)", possessiveA);
    } else {
      sprintf(possessiveA, "%s\'s", gbl_just2PersonA);
      strsubg(g_my_aspect_text, "^^(Ap)", possessiveA);
    }
  }
  if (strstr(g_my_aspect_text, "^^(Bp)") != NULL ) { 
    lastchar = gbl_just2PersonB[strlen(gbl_just2PersonB) - 1];
    if (lastchar == 's' ||  lastchar == 'z') {
      sprintf(possessiveB, "%s\'", gbl_just2PersonB);
      strsubg(g_my_aspect_text, "^^(Bp)", possessiveB);
    } else {
      sprintf(possessiveB, "%s\'s", gbl_just2PersonB);
      strsubg(g_my_aspect_text, "^^(Bp)", possessiveB);
    }
  }
  if (strstr(g_my_aspect_text, "^^(A)") != NULL ) { 
    strsubg(g_my_aspect_text, "^^(A)", gbl_just2PersonA);
  }
  if (strstr(g_my_aspect_text, "^^(B)") != NULL ) { 
    strsubg(g_my_aspect_text, "^^(B)",  gbl_just2PersonB);
  }



  /* wrap lines at 80 chars with <br> */
/*   put_br_every_n(my_aspect_text, 80);  */
//  put_br_every_n(g_my_aspect_text, 65);

  char redgre_beg[133];
  char redgre_end[133];

//  strcpy(redgre_beg, "<table class=\"center\"><tr><td><p>");
//  strcpy(redgre_end, "</p></td></tr></table>");
//  sprintf(writebuf, "%s%s%s\n", redgre_beg, g_my_aspect_text, redgre_end);
//  g_fn_prtlin(writebuf);

  strcpy(redgre_beg, "<table class=\"RPPE_table\"><tr><td class=\"RPPE_td\"><p class=\"RPPE_p\">");
  strcpy(redgre_end, "</p></td></tr></table>");  // no <br>
  sprintf(writebuf, "  %s%s%s\n", redgre_beg, g_my_aspect_text, redgre_end);
  g_fn_prtlin(writebuf);


// abandon prtRedGreenPlusMinus   2017 05   too complex
//   prtRedGreenPlusMinus(atoi(numplusminus), 0); // 0 = no, not webview

}  /* end of g_fn_browser_aspect_text(); */


void  prtRedGreenPlusMinus(int numPosNeg, int arg_is_webview)
{
    int  maxPosOrNegSigns;
    char grePosSigns[128], redNegSigns[128];  // 4 areas
    char grePosBlank[128], redNegBlank[128];  // 4 areas
    char linePosNeg[2024];

    char area1_beg[128], area1_end[128];
    char area2_beg[128], area2_end[128];
    char area3_beg[128], area3_end[128];
    char area4_beg[128], area4_end[128];

    char redgre_beg[128], redgre_end[128];

//tn();trn("in prtRedGreenPlusMinus()");
//kin(numPosNeg);
    maxPosOrNegSigns = 25;

    if (numPosNeg  < 0) {  // DO RED   minus signs  on left

//      sfill(redNegBlank ,(maxPosOrNegSigns + numPosNeg) ,' ');
      sfill(redNegBlank ,(maxPosOrNegSigns + numPosNeg) ,'~');  // ~ = sp  change all ~ to &nbsp below
      sfill(redNegSigns ,(numPosNeg * -1)               ,'-');
      strcpy(grePosSigns, "");

//      sfill(grePosBlank , maxPosOrNegSigns              ,' ');
      sfill(grePosBlank , maxPosOrNegSigns              ,'~');
//      sfill(grePosBlank , maxPosOrNegSigns - 2          ,' ');
//      sprintf(grePosBlank, "&nbsp%s&nbsp", grePosBlank);

//trn("DO RED");
//ksn(redNegBlank);
//ksn(redNegSigns);
//ksn(grePosSigns);
//ksn(grePosBlank);
    }
    if (numPosNeg  > 0) {  // DO GREEN plus  signs  on right
//      sfill(redNegBlank , maxPosOrNegSigns              ,' ');
      sfill(redNegBlank , maxPosOrNegSigns              ,'~');
     strcpy(redNegSigns, "");
      sfill(grePosSigns , numPosNeg                     ,'+');
//      sfill(grePosBlank , numPosNeg                     ,' ');
      sfill(grePosBlank ,(maxPosOrNegSigns - numPosNeg) ,'~');
//trn("DO GRE");
//ksn(redNegBlank);
//ksn(redNegSigns);
//ksn(grePosSigns);
//ksn(grePosBlank);
    }

    // color the four areas
//    strcpy(area1_beg, "<span style=\"background-color: #fcfce0;\">");
//    strcpy(area2_beg, "<span style=\"background-color: #ffb5c9;\">"); 
//    strcpy(area3_beg, "<span style=\"background-color: #a8ff98;\">");
//    strcpy(area4_beg, "<span style=\"background-color: #fcfce0\">");


    if (strlen(redNegSigns) == 0) strcpy(area1_beg, "<span class=\"cBbg\">");   // area 1 for redNegBlank
    else                          strcpy(area1_beg, "<span class=\"cRLi\">");                       

        //font-weight   has "bolder" and "lighter" and these numbers:
        //100
        //200
        //300
        //400    same as normal
        //500
        //600
        //700    same as bold
        //800
        //900	Defines from thin to thick characters. 400 is the same as normal, and 700 is the same as bold	
        //

//  g_fn_prtlin( "      font-family: Menlo, Andale Mono, Monospace, Courier New; ");
    strcpy(area2_beg, "<span class=\"cRed\" style=\"font-weight: bold;\">");    // area 2 for redNegSigns
    strcpy(area3_beg, "<span class=\"cGre\" style=\"font-weight: normal;\">");  // area 3 for grePosSigns

    if (strlen(grePosSigns) == 0) strcpy(area4_beg, "<span class=\"cBbg\">");   // area 4 for grePosBlank
    else                          strcpy(area4_beg, "<span class=\"cGLi\">");                       


    strcpy(area1_end, "</span>");
    strcpy(area2_end, "</span>");
    strcpy(area3_end, "</span>");
    strcpy(area4_end, "</span>");



    if (arg_is_webview == 1) {  // webview version
//tn();trn("SET BEg END redgree !!  WEBVIEW version");
    //  strcpy(redgre_beg, "<table class=\"center\"><tr><td><p>");
    //  strcpy(redgre_end, "</p></td></tr><br></table>");
        strcpy(redgre_beg, "<table class=\"redGreenCenter\"><tr><td>");
        strcpy(redgre_end, "</td></tr><br></table>");
   } else {
//tn();trn("SET BEg END redgree !!  BROWSER version");
     // browser version
        strcpy(redgre_beg, "<tr class=\"browserRedGreenCenter\"><td>");
        strcpy(redgre_end, "</td></tr></table>");
   }

//    strcpy(lineBlank, "<div class=\"linehite_0050\"> |<span class=\"cRed\">                         </span>|<span class=\"cGre\">                         </span>| ");  // spaces line
//    sprintf(writebuf, "  %s%s%s\n", redgre_beg, lineBlank, redgre_end);
//    g_fn_prtlin(writebuf);  // blank line
//

    sprintf(linePosNeg,  " |%s%s%s%s%s%s|%s%s%s%s%s%s| ",
//    sprintf(linePosNeg,  " |%s%s%s%s%s%s %s%s%s%s%s%s| ",
      area1_beg   ,
      redNegBlank ,
      area1_end   ,

      area2_beg   ,
      redNegSigns ,
      area2_end   ,

      area3_beg   ,
      grePosSigns ,
      area3_end   ,

      area4_beg   ,
      grePosBlank ,
      area4_end   
    );
//ksn(linePosNeg);

    strsubg(linePosNeg, "~", "&nbsp");  // replace all spaces with hard spaces

//kin(strlen(linePosNeg));

    sprintf(writebuf, "  %s%s%s\n", redgre_beg, linePosNeg, redgre_end);
    g_fn_prtlin(writebuf);  // minuses or pluses line
//ksn(writebuf);
//    g_fn_prtlin("<div class=\"linehite_0050\"> |<span class=\"cRed\">                         </span>|<span class=\"cGre\">                         </span>| ");
//    g_fn_prtlin(" |<span class=\"cRed\">100%                   0%</span>|<span class=\"cGre\">0%                   100%</span>| </div>");


} // end of prtRedGreenPlusMinus


//void g_fn_webview_aspect_text(char *in_aspect_code){
//  int nn;
//  char aspcodeToSearch[32], possessiveA[64], possessiveB[64], lastchar; 
//  char oldAspCode[32];
//  char numplusminus[32];
//
////trn("in g_fn_webview_aspect_text()"); 
////ksn(in_aspect_code);
//
//  // get old gP_ITEM_TBL from PSV
//  //
//  strcpy(oldAspCode,   csv_get_field(in_aspect_code, "|", 1) );
//  strcpy(numplusminus, csv_get_field(in_aspect_code, "|", 2) );
//
//  // fix aspect code like this:  e.g.  _(in g_docin_GET)___in_line=[^(c03b02)]__
//  //                   to this:  "c03b02"
//  strcpy(aspcodeToSearch, oldAspCode);
//  scharout(aspcodeToSearch, '^');  
//  scharout(aspcodeToSearch, '(');  
//  scharout(aspcodeToSearch, ')');  
//
//  nn = binsearch_asp(aspcodeToSearch, g_asptab, G_NKEYS_ASP);   // +++++++++++++++++++++++++++++++++++++
//
//  if (nn < 0) return;  /* do not print any aspect text at all  */
//
//  strcpy(g_my_aspect_text, g_asptab[nn].g_asp_text);
//
//  // do posessive forms of names, if necessary
//  //
//  if (strstr(g_my_aspect_text, "^^(Ap)") != NULL ) { 
//    lastchar = gbl_just2PersonA[strlen(gbl_just2PersonA) - 1];
//    if (lastchar == 's' ||  lastchar == 'z') {
//      sprintf(possessiveA, "%s\'", gbl_just2PersonA);
//      strsubg(g_my_aspect_text, "^^(Ap)", possessiveA);
//    } else {
//      sprintf(possessiveA, "%s\'s", gbl_just2PersonA);
//      strsubg(g_my_aspect_text, "^^(Ap)", possessiveA);
//    }
//  }
//  if (strstr(g_my_aspect_text, "^^(Bp)") != NULL ) { 
//    lastchar = gbl_just2PersonB[strlen(gbl_just2PersonB) - 1];
//    if (lastchar == 's' ||  lastchar == 'z') {
//      sprintf(possessiveB, "%s\'", gbl_just2PersonB);
//      strsubg(g_my_aspect_text, "^^(Bp)", possessiveB);
//    } else {
//      sprintf(possessiveB, "%s\'s", gbl_just2PersonB);
//      strsubg(g_my_aspect_text, "^^(Bp)", possessiveB);
//    }
//  }
//  if (strstr(g_my_aspect_text, "^^(A)") != NULL ) { 
//    strsubg(g_my_aspect_text, "^^(A)", gbl_just2PersonA);
//  }
//  if (strstr(g_my_aspect_text, "^^(B)") != NULL ) { 
//    strsubg(g_my_aspect_text, "^^(B)",  gbl_just2PersonB);
//  }
//
//
//  /* wrap lines at 80 chars with <br> */
//  /*   put_br_every_n(my_aspect_text, 80);  */
//  /*   put_br_every_n(my_aspect_text, 65);  */
//  put_br_every_n(g_my_aspect_text, 50);          // <=====----
//
//  sprintf(writebuf, "para|%s\n",  g_my_aspect_text );
//  g_fn_prtlin(writebuf);
//
//  //  do red/green line in cocoa now (in tblrpts)
//  sprintf(writebuf, "redgreenline|%s\n",  numplusminus);
//  g_fn_prtlin(writebuf);
//  //
//  //  // here we write the red/green
//  //  prtRedGreenPlusMinus(atoi(numplusminus), 1); // 1 = yes, this is  webview version
//
//} // end of  g_fn_webview_aspect_text()
//

// NEW VERSION   (tblrpt  in cocoa)
void g_fn_webview_aspect_text(char *in_aspect_code){
  int nn;
  char aspcodeToSearch[32], possessiveA[64], possessiveB[64], lastchar; 
  char oldAspCode[32];
  char numplusminus[32];

//trn("in g_fn_webview_aspect_text() NEW VERSION   (tblrpt  in cocoa) "); 
//ksn(in_aspect_code);

  // get old gP_ITEM_TBL from PSV
  //
  strcpy(oldAspCode,   csv_get_field(in_aspect_code, "|", 1) );
  strcpy(numplusminus, csv_get_field(in_aspect_code, "|", 2) );

  // fix aspect code like this:  e.g.  _(in g_docin_GET)___in_line=[^(c03b02)]__
  //                   to this:  "c03b02"
  strcpy(aspcodeToSearch, oldAspCode);
  scharout(aspcodeToSearch, '^');  
  scharout(aspcodeToSearch, '(');  
  scharout(aspcodeToSearch, ')');  

  nn = binsearch_asp(aspcodeToSearch, g_asptab, G_NKEYS_ASP);   // +++++++++++++++++++++++++++++++++++++

  if (nn < 0) return;  /* do not print any aspect text at all  */

  strcpy(g_my_aspect_text, g_asptab[nn].g_asp_text);

  // do posessive forms of names, if necessary
  //
  if (strstr(g_my_aspect_text, "^^(Ap)") != NULL ) { 
    lastchar = gbl_just2PersonA[strlen(gbl_just2PersonA) - 1];
    if (lastchar == 's' ||  lastchar == 'z') {
      sprintf(possessiveA, "%s\'", gbl_just2PersonA);
      strsubg(g_my_aspect_text, "^^(Ap)", possessiveA);
    } else {
      sprintf(possessiveA, "%s\'s", gbl_just2PersonA);
      strsubg(g_my_aspect_text, "^^(Ap)", possessiveA);
    }
  }
  if (strstr(g_my_aspect_text, "^^(Bp)") != NULL ) { 
    lastchar = gbl_just2PersonB[strlen(gbl_just2PersonB) - 1];
    if (lastchar == 's' ||  lastchar == 'z') {
      sprintf(possessiveB, "%s\'", gbl_just2PersonB);
      strsubg(g_my_aspect_text, "^^(Bp)", possessiveB);
    } else {
      sprintf(possessiveB, "%s\'s", gbl_just2PersonB);
      strsubg(g_my_aspect_text, "^^(Bp)", possessiveB);
    }
  }
  if (strstr(g_my_aspect_text, "^^(A)") != NULL ) { 
    strsubg(g_my_aspect_text, "^^(A)", gbl_just2PersonA);
  }
  if (strstr(g_my_aspect_text, "^^(B)") != NULL ) { 
    strsubg(g_my_aspect_text, "^^(B)",  gbl_just2PersonB);
  }


  /* wrap lines at 80 chars with <br> */
  /*   put_br_every_n(my_aspect_text, 80);  */
  /*   put_br_every_n(my_aspect_text, 65);  */
//  put_br_every_n(g_my_aspect_text, 50);          // <=====----


  // print lines in g_my_aspect_text wrapped to line_not_longer_than_this
  // 
  char *pNewWord;
  int len_new_word, lenbuf, line_not_longer_than_this;
  char mybuf[8192];

  line_not_longer_than_this = 40;
  strcpy(mybuf, "");

  sprintf(writebuf, "fill|before para");
  g_fn_prtlin(writebuf);

  // NOTE here that strtok overwrites g_my_aspect_text to get the words,
  pNewWord = strtok (g_my_aspect_text, " ");  /* get ptr to first word */

  while (pNewWord != NULL)  /* for all words */
  {
    lenbuf       = (int)strlen(mybuf);
    len_new_word = (int)strlen(pNewWord);

    if (lenbuf + len_new_word >= line_not_longer_than_this) {

      while (strlen(mybuf) < line_not_longer_than_this) { // add spaces at end to fill up to line_not_longer_than_this  chars
        sprintf(mybuf, "%s ", mybuf);  // add a space at the end
      }
      sprintf(writebuf, "para|  %s",  mybuf);
      g_fn_prtlin(writebuf);
      
      strcpy(mybuf, "");                    /* init  mybuf */
    } /* write out since line too long */

    sprintf(mybuf, "%s%s%s", mybuf, pNewWord, " "); /* add new word to mybuf */

    pNewWord = strtok (NULL, " ");                  /* get ptr to next word */

  }  /* for all words */

  /* here no more words in aspect desc (mybuf has last line to add) */
  if (strlen(mybuf) != 0) {

    mybuf[ strlen(mybuf) - 1] = '\0'; /* but remove sp at end */

    while (strlen(mybuf) < line_not_longer_than_this) { // add spaces at end to fill up to line_not_longer_than_this  chars
      sprintf(mybuf, "%s ", mybuf);  // add a space at the end
    }
    sprintf(writebuf, "para|  %s",  mybuf);
    g_fn_prtlin(writebuf);
  }
  //
  // end of print lines in g_my_aspect_text wrapped to line_not_longer_than_this


//  sprintf(writebuf, "para|%s\n",  g_my_aspect_text );  // see above
//  g_fn_prtlin(writebuf);


    //
    //// 20151201  DECIDE TO LEAVE OUT
    //// no no   OR put 0% -> 100%  in Info screen    20151201  decide to leave out
    //  //  do red/green line in cocoa now (in tblrpts)
    //  sprintf(writebuf, "redgreenline|%s\n",  numplusminus);
    //  g_fn_prtlin(writebuf);
    //  //
    //  //  // here we write the red/green
    //  //  prtRedGreenPlusMinus(atoi(numplusminus), 1); // 1 = yes, this is  webview version
    //

} // end of  g_fn_webview_aspect_text()




/* end of grphtm.c */


