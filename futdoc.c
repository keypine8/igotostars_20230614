// futdoc.c 

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


// LOOK OUT!  DUMP of various FYIs used in here to get them in one place   LOOK OUT!  DUMP of various FYIs used in here to get them in one place  
// LOOK OUT!  DUMP of various FYIs used in here to get them in one place   LOOK OUT!  DUMP of various FYIs used in here to get them in one place  
//           (about 200 lines in 202005 )


      
      // FYI   from futasp.c
      //    ++Asp_tbl_idx;  // init=-1 //
      //    sprintf(P_asp_tbl[Asp_tbl_idx],
      //      "%04d%02d%02d%02d%02d%02d%04d%02d%02d%02d%02d",
      //      fy,fm,fd,np,tp,asp,ty,tm,td,np_hse,tp_hse);
      //      fyyyfmfdnptpastyyyhtmtd  ,np_hse,tp_hse);
      //               1          2    ...               
      //      123456789012134567890123 ...               
      // FYI
      //
      // FYI   from futdoc.h
      //  char *N_planet[]     = {"   ","sun","moo","mer","ven","mar","jup","sat","ura","nep","plu", "nod","asc","mc_"}; 
      //  char *N_trn_planet[] = {"   ","jup","sat","ura","nep","plu","mar"};
      //  char *N_sign[] = { "sgn","ari","tau","gem","can","leo","vir","lib","scp","sag","cap","aqu","pis"};
      //  char *N_aspect[] = {"   ","cnj","sxt","squ","tri","opp","tri","squ","sxt","cnj"};  // ASP IDXS THE SAME are  1=9, 2=8, 3=7, 4=6 
      // FYI
      //


    //  per_emcc_my2.html:94729 _(in do_paras() )__
    //  per_emcc_my2.html:94729 _()__
    //  per_emcc_my2.html:94729 _(all of P_asp_tbl)__
    //  per_emcc_my2.html:94729 _ia=[0]___P_asp_tbl[ia]=[20200101050201202002061010]__
    //  per_emcc_my2.html:94729 _ia=[1]___P_asp_tbl[ia]=[20200101050501202012311012]__
    //  per_emcc_my2.html:94729 _ia=[2]___P_asp_tbl[ia]=[20200119030107202002100110]__
    //  per_emcc_my2.html:94729 _ia=[3]___P_asp_tbl[ia]=[20200125010107202002180110]__
    //  per_emcc_my2.html:94729 _ia=[4]___P_asp_tbl[ia]=[20200222020201202008061010]__
    //  per_emcc_my2.html:94729 _ia=[5]___P_asp_tbl[ia]=[20200301040206202007270210]__
    //  per_emcc_my2.html:94729 _ia=[6]___P_asp_tbl[ia]=[20200309050101202004121010]__
    //  per_emcc_my2.html:94729 _ia=[7]___P_asp_tbl[ia]=[20200510020101202005181010]__
    //  per_emcc_my2.html:94729 _ia=[8]___P_asp_tbl[ia]=[20200617050101202007231010]__
    //  per_emcc_my2.html:94729 _ia=[9]___P_asp_tbl[ia]=[20200905050201202010211010]__
    //  per_emcc_my2.html:94729 _ia=[10]___P_asp_tbl[ia]=[20200907010107202009190110]__
    //  per_emcc_my2.html:94729 _ia=[11]___P_asp_tbl[ia]=[20201102050101202011281010]__
    //  per_emcc_my2.html:94729 _ia=[12]___P_asp_tbl[ia]=[20201118020201202012311012]__
    //  per_emcc_my2.html:94729 _ia=[13]___P_asp_tbl[ia]=[20201128040206202012310212]__
    //  per_emcc_my2.html:94729 _ia=[14]___P_asp_tbl[ia]=[20201206020101202012281010]__
    //  per_emcc_my2.html:94729 _ia=[15]___P_asp_tbl[ia]=[20201210040106202012280210]__
    //  per_emcc_my2.html:94729 _(all of P_asp_tbl)__
    //  per_emcc_my2.html:94729 _()__
    //  per_emcc_my2.html:94729 _()__
    //  per_emcc_my2.html:94729 _(all2of P_asp_tbl  at TOP of do_paras())__
    //  per_emcc_my2.html:94729 _tst128=[mar_cnj_sat  20200101 to 20200206  asp=01]__
    //  per_emcc_my2.html:94729 _tst128=[mar_cnj_plu  20200101 to 20201231  asp=01]__
    //  per_emcc_my2.html:94729 _tst128=[mer_squ_jup  20200119 to 20200210  asp=07]__
    //  per_emcc_my2.html:94729 _tst128=[sun_squ_jup  20200125 to 20200218  asp=07]__
    //  per_emcc_my2.html:94729 _tst128=[moo_cnj_sat  20200222 to 20200806  asp=01]__
    //  per_emcc_my2.html:94729 _tst128=[ven_tri_sat  20200301 to 20200727  asp=06]__
    //  per_emcc_my2.html:94729 _tst128=[mar_cnj_jup  20200309 to 20200412  asp=01]__
    //  per_emcc_my2.html:94729 _tst128=[moo_cnj_jup  20200510 to 20200518  asp=01]__
    //  per_emcc_my2.html:94729 _tst128=[mar_cnj_jup  20200617 to 20200723  asp=01]__
    //  per_emcc_my2.html:94729 _tst128=[mar_cnj_sat  20200905 to 20201021  asp=01]__
    //  per_emcc_my2.html:94729 _tst128=[sun_squ_jup  20200907 to 20200919  asp=07]__
    //  per_emcc_my2.html:94729 _tst128=[mar_cnj_jup  20201102 to 20201128  asp=01]__
    //  per_emcc_my2.html:94729 _tst128=[moo_cnj_sat  20201118 to 20201231  asp=01]__
    //  per_emcc_my2.html:94729 _tst128=[ven_tri_sat  20201128 to 20201231  asp=06]__
    //  per_emcc_my2.html:94729 _tst128=[moo_cnj_jup  20201206 to 20201228  asp=01]__
    //  per_emcc_my2.html:94729 _tst128=[ven_tri_jup  20201210 to 20201228  asp=06]__
    //  per_emcc_my2.html:94729 _(all2of P_asp_tbl  at TOP of do_paras())__
    //  per_emcc_my2.html:94729 _()__
    //  per_emcc_my2.html:94729 _do_me=[20200101050201202002061010]___(find all sames for )___np_tp_to_look_for=[0502]___aspect_to_look_for=[01]__
    //

      //
      //  // for test
      //  trn("");
      //  trn("all of P_asp_tbl");
      //  for (int ia=0; ia <= Asp_tbl_idx; ++ia) { 
      //  ki(ia);ksn(P_asp_tbl[ia]);  
      //  }
      //  trn("all of P_asp_tbl");
      //  trn("");
      //
      //  trn("");
      //  trn("all2of P_asp_tbl  at TOP of do_paras()");
      //  char tstfrom[32];
      //  char tstto[32];
      //  char tstnp[32];
      //  char tstasp[32];
      //  char tsttp[32];
      //  char tst128[128];
      //  for (int ib=0; ib <= Asp_tbl_idx; ++ib) { 
      //  //extern char *sfromto(char *dest,char *src, int beg, int end);
      //  sfromto(tstfrom,P_asp_tbl[ib], 1, 8);
      //  sfromto(tstnp  ,P_asp_tbl[ib], 9,10);
      //  sfromto(tsttp  ,P_asp_tbl[ib],11,12);
      //  sfromto(tstasp ,P_asp_tbl[ib],13,14);
      //  sfromto(tstto,  P_asp_tbl[ib],15,22);
      //
      //  sprintf(tst128, "%s_%s_%s  %s to %s  asp=%s",
      //    N_planet[atoi(tstnp)], N_aspect[atoi(tstasp)], N_trn_planet[atoi(tsttp)], tstfrom, tstto, tstasp);
      //  ksn(tst128);
      //  }
      //  trn("all2of P_asp_tbl  at TOP of do_paras()");
      //  trn("");
      //  //  char *N_planet[]     = {"   ","sun","moo","mer","ven","mar","jup","sat","ura","nep","plu", "nod","asc","mc_"};
      //  //  char *N_trn_planet[] = {"   ","jup","sat","ura","nep","plu","mar"};
      //  //  char *N_aspect[]     = {"   ","cnj","sxt","squ","tri","opp","tri","squ","sxt","cnj"};
      //  // for test
      //

      //
      // FYI  (from futdoc.h)
      //
      //      /* the following is for K&R fns day_of_year() & month_day() */
      //      double Day_tab[2][13] = {
      //        {365.0,31.0,28.0,31.0,30.0,31.0,30.0,31.0,31.0,30.0,31.0,30.0,31.0},
      //        {366.0,31.0,29.0,31.0,30.0,31.0,30.0,31.0,31.0,30.0,31.0,30.0,31.0}
      //      };
      //


    //no
    //    // fyi
    //    // k&r  /* set month, day  for jd=yearday in year */
    //    // k&r  void month_day(double year, double yearday, double *pmonth, double *pday)
    //    double pmonth;
    //    double pdayOfMonth;
    //    month_day(atof(year_in_the_life_todo_yyyy), (double)day_num, &pmonth, &pdayOfMonth );
    //

// SW_uses_aspect_addval()
//
      //    FYI - like gbl_PSV_of_SW_CSVs
      //    sprintf(curr_SW_CSV,              // looks like   "sun_opp_jup,20200106,20200521,positive,00000,00655,00112"
      //      "%s_%s_%s,%03d,%03d,%s,%03d,%03d,%03d",
      //      N_planet[np], N_aspect[asp], N_trn_planet[tp],
      //      (int) dbl_SW_BEG_DayOfYear,
      //      (int) dbl_SW_END_DayOfYear,
      //      SW_amplitude_sign,            // "positive" or "negative" for sinewave amplitude
      //      SW_amplitude_at_BEG,
      //      SW_amplitude_at_MAX,
      //      SW_amplitude_at_END
      //    );                              // curr_SW_CSV about 32 chars
      //

      // FYI  gbl_PSV_of_SW_CSVs
      //
      // ksn(gbl_PSV_of_SW_CSVs); tn();
            //    FYI  looks like this:  last csv is ""
            //
            //    _doclin=[from Jan  1 to Feb  8 ^(mogur)]__
            //    _(fn_BIGaspect_from_to() in futhtm.c  --  this is updated after the end of each aspect is reached )__
            //    _gbl_PSV_of_SW_CSVs=[sun_opp_jup,001,005,positive,015,045,000|ven_opp_jup,081,193,positive,015,045,000|ven_opp_jup,317,341,positive,015,045,000|mar_opp_jup,361,366,positive,015,045,000|ven_opp_sat,013,055,positive,015,045,000|mar_opp_sat,107,157,positive,015,045,000|ven_opp_sat,217,325,positive,015,045,000|mar_opp_sat,365,366,positive,015,045,000|moo_sxt_ura,001,039,positive,015,045,000|mar_squ_ura,001,107,positive,015,045,000|sun_sxt_ura,033,145,positive,015,045,000|sun_sxt_ura,319,366,positive,015,045,000|ven_opp_plu,015,237,positive,015,045,000|ven_opp_plu,317,366,positive,015,045,000|]__
            //

          // fyi
          //  char *N_planet[]     = {"   ","sun","moo","mer","ven","mar","jup","sat","ura","nep","plu", "nod","asc","mc_"};
          //  char *N_trn_planet[] = {"   ","jup","sat","ura","nep","plu","mar"};
          //  char *N_aspect[]     = {"   ","cnj","sxt","squ","tri","opp","tri","squ","sxt","cnj"};
//
// FYI in futhtm.c  -  aspects whose text GO ON THE SCREEN
//
//   doing make_fut_htm_file() in futdoc.c 4422)__
//   _(in make_fut_htm_file())__
//   _(futhtm.c BEG -->  now read and print aspects until we hit [end_aspects])
//   _doclin=[from Jan  1 to Jan  5 ^(subju)]__
//   _doclin=[from Jan  1 to Feb  8 ^(mogur)]__
//   _doclin=[from Jan  1 to Apr 16 ^(mabur)]__
//   _doclin=[from Jan 13 to Feb 24  and also from Aug  4 to Nov 20 ^(vebsa)]__
//   _doclin=[from Jan 15 to Aug 24  and also from Nov 12 to Dec 31 ^(vebpl)]__
//   _doclin=[from Feb  2 to May 24  and also from Nov 14 to Dec 31 ^(sugur)]__
//   _doclin=[from Mar 21 to Jul 11  and also from Nov 12 to Dec  6 ^(vebju)]__
//   _doclin=[from Apr 16 to Jun  5 ^(mabsa)]__
//   _doclin=[from Dec 26 to Dec 31 ^(mabju)]__
//   _doclin=[[end_aspects]]__                                                 
//   _(futhtm.c END -->  now read and print aspects until we hit [end_aspects])
//

//_(pass 01)___sinewave_60char=[sun_opp_jup,20200101,20200105,positive,00000,00655,00112]__
//_(pass 01)___sinewave_60char=[ven_opp_jup,20200321,20200711,positive,00000,00655,00112]__
//_(pass 01)___sinewave_60char=[ven_opp_jup,20201112,20201206,positive,00000,00655,00112]__
//_(pass 01)___sinewave_60char=[mar_opp_jup,20201226,20210101,positive,00000,00655,00112]__
//_(pass 01)___sinewave_60char=[ven_opp_sat,20200113,20200224,positive,00000,00655,00112]__
//_(pass 01)___sinewave_60char=[mar_opp_sat,20200416,20200605,positive,00000,00655,00112]__
//_(pass 01)___sinewave_60char=[ven_opp_sat,20200804,20201120,positive,00000,00655,00112]__
//_(pass 01)___sinewave_60char=[mar_opp_sat,20201230,20210101,positive,00000,00655,00112]__
//_(pass 01)___sinewave_60char=[moo_sxt_ura,20200101,20200208,positive,00000,00655,00112]__
//_(pass 01)___sinewave_60char=[mar_squ_ura,20200101,20200416,positive,00000,00655,00112]__
//_(pass 01)___sinewave_60char=[sun_sxt_ura,20200202,20200524,positive,00000,00655,00112]__
//_(pass 01)___sinewave_60char=[sun_sxt_ura,20201114,20210101,positive,00000,00655,00112]__
//_(pass 01)___sinewave_60char=[ven_opp_plu,20200115,20200824,positive,00000,00655,00112]__
//_(pass 01)___sinewave_60char=[ven_opp_plu,20201112,20210101,positive,00000,00655,00112]__
//


      // FYI -> mambutil.c  void strsubg(char *s, char *replace_me, char *with_me) // on str s (max 2048) does  :s/replace_me/with_me/g
      //                       * strsubg    on str s (max 2048) does  :s/replace_me/with_me/g
      //

    // FYI
    // char *N_aspect[] = {"   ","cnj","sxt","squ","tri","opp","tri","squ","sxt","cnj"};  // ASP IDXS THE SAME are  1=9, 2=8, 3=7, 4=6 
    //
    // NOTE that some aspect indexes are for the same aspect  ==---- >  ASP IDXS THE SAME are  1=9, 2=8, 3=7, 4=6 
    // NOTE that some aspect indexes are for the same aspect  ==---- >  ASP IDXS THE SAME are  1=9, 2=8, 3=7, 4=6 
    //

      //
      // FYI  (from futdoc.h)
      //
      //      /* the following is for K&R fns day_of_year() & month_day() */
      //      double Day_tab[2][13] = {
      //        {365.0,31.0,28.0,31.0,30.0,31.0,30.0,31.0,31.0,30.0,31.0,30.0,31.0},
      //        {366.0,31.0,29.0,31.0,30.0,31.0,30.0,31.0,31.0,30.0,31.0,30.0,31.0}
      //      };
      //
//  double day_of_year(double year, double month, double day)  /* return jd in year from year, month & day */

//
// LOOK OUT!  DUMP of various FYIs used in here to get them in one place   LOOK OUT!  DUMP of various FYIs used in here to get them in one place  
// LOOK OUT!  DUMP of various FYIs used in here to get them in one place   LOOK OUT!  DUMP of various FYIs used in here to get them in one place  




/* #import "tgmath.h"    in xcode required */

/* #include "rkdebug.h"  */
/*  #include "rkdebug_externs.h"  */

/*  NEW *   gets input specs from args  osdif*/

/* combines the old futursm2.c +futursmb.c */
/*******  OLD
   gets input specs from keyboard 
   calculates natal planetary positions 
   compares those against 6-month files of 
     future planetary positions 
   puts to stdout the aspect information 
  this is input to doc (awk   fmt_fut.awk )
*******/
/* #include "futuresm.h" */
/* #include "futtblsm.h" */


         // #include "futdefs.h"    // this is included in futdoc.h above
#include "futdoc.h"
#include <ctype.h>
#include <stdlib.h>

// from futasp.c 
#include <stdio.h>
#include <math.h>
#include <string.h>
// #include <stdlib.h>



int gbl_year_todo_yyyy_INT;

// data for drawing aspect impact sinewaves in JS canvas    data for drawing aspect impact sinewaves in JS canvas   
// data for drawing aspect impact sinewaves in JS canvas    data for drawing aspect impact sinewaves in JS canvas   
//
// SW   = SineWave
// AMPL = amplitude
//

char gbl_this_CNJ_is[32];  // for CONJUNCTIONS maintain  gbl_this_CNJ_is  "positive" or "negative"

// gbl_PSV_of_SW_CSVs  moved to futdoc.c
// 202004  for passing sinwave data from futdoc.c to futhtm.c, who puts
char gbl_PSV_of_SW_CSVs[8192];   // this is updated after each aspect in this current calendar year is "finished"

                 // ?            // this is updated continuously as add_aspect_to_grhdata() is called for every single day_num 1 -> 184

//char gbl_PSV_of_AMPL_CSVs[8192];  // this is updated continuously as add_aspect_to_grhdata() is called for every single day_num 1 -> 184

      //    FYI - like gbl_PSV_of_SW_CSVs
      //    sprintf(curr_SW_CSV,              // looks like   "sun_opp_jup,20200106,20200521,positive,00000,00655,00112"
      //      "%s_%s_%s,%03d,%03d,%s,%03d,%03d,%03d",
      //      N_planet[np], N_aspect[asp], N_trn_planet[tp],
      //      (int) dbl_SW_BEG_DayOfYear,
      //      (int) dbl_SW_END_DayOfYear,
      //      SW_amplitude_sign,            // "positive" or "negative" for sinewave amplitude
      //      SW_amplitude_at_BEG,
      //      SW_amplitude_at_MAX,
      //      SW_amplitude_at_END
      //    );                              // curr_SW_CSV about 32 chars
      //

      //      N_planet[np], N_aspect[asp], N_trn_planet[tp],
      //      (int) dbl_SW_BEG_DayOfYear,

     /* complete_this_SW_CSV() is called at the end of dspl_aspect() */
//void complete_this_SW_CSV(     // SW = SineWave
//  int dn,                      // Day Number
//  int fy, int fm,  int fd,  
//  int np, int asp, int tp,  
//  int ty, int tm,  int td
//);


//-------------------------------------------------------------------------------------------------
void SW_uses_aspect_addval(int addval, int nat_plt, int aspect_num, int trn_plt, int day_num); /* is called at the end of add_aspect_to_grhdata() */
void complete_this_SW_CSV (int np, int asp, int tp);
//-------------------------
void create_a_new_SW_CSV  (int addval, int nat_plt, int aspect_num, int trn_plt, int day_num);
void update_this_SW_CSV(
  char *SW_CSV_current,
  int   addval, int nat_plt, int aspect_num, int trn_plt, int day_num,
  char *arg_SW_open_or_done
);
//-------------------------------------------------------------------------------------------------

//
// data for drawing aspect impact sinewaves in JS canvas    data for drawing aspect impact sinewaves in JS canvas   
// data for drawing aspect impact sinewaves in JS canvas    data for drawing aspect impact sinewaves in JS canvas   




int  gbl_yearStressScoreIsDone;
int  gbl_topStarVal;              // for putting all-new benchmark labels to existing lines 
int  gbl_numBodyLinesToProcess;   // num_lines changes on the fly in here, so use this constant number
//char  gbl_first_star_is_in[32];        // value is one of "omg", "stress", "neutral" "good" OR "great")  USED TO SET graph COLOR
int  gbl_topStarBelowGood;        // for   newPlanBenchmarkLabels()
char gbl_lastBenchmarkLabel[32];  // (this will be "STRESS-", "GOOD-" or "GREAT-")
char gbls_addLines[256]; // 2 possible values are 1. "we added no lines"   2. "we added lines to ensure benchmark labels STRESS, GOOD and GREAT are all present"
extern void  remove_spans(char *line);  // in futhtm.c
int gbl_doLineCheck;
int gbl_numLinesFillToGREAT;  // want GREAT greenLine always on graph

//char gbl_thumbnailInfo[8192];
char gbl_thumbnailInfo[16384];
int  gbl_putThumbnailInfoHERE;  // where to write in above
int  gbl_topToGreatLine;        // count of lines from top of thumbnail tn to green great line
int  gbl_botToStressLine;       // count of lines from bot of thumbnail tn to red stress  line
int  gbl_hitGreatLine;          // 0=no  1=yes
int  gbl_hitStressLine;         // 0=no  1=yes
int  gbl_fromGreatToStress;     // linecnt
int  gbl_topStarBELOW_GREAT;    // 0=no  1=yes


//extern void f_docin_put(char *line, int length);
void f_docin_put(char *line, int length);



/* in mambutil.o */
/* e.g. int calculated_percentile_rank(in_score, 41, 18, 25, 10)
*  e.g. maps in_score between 41 and 18 to percentile ranks between 25 and 10
*/
extern int calc_percentile_rank(int in_score, int sc_hi, int sc_lo, int pr_hi, int pr_lo);
extern void  strsort(char *v[], int n);
extern char *sfromto(char *dest,char *src, int beg, int end);
extern void  sfill(char *s, int num, int c);
extern int   sall(char *s,char *set);
/* in mambutil.o */




// futasp.c 
// aspect part of fut.o 


/* externs follow */
extern struct Runrec Rt[];  /* rt=running_table     aaa   */
extern int Aspect_type[];

extern int get_house(int minutes, int mc);  /* defined in another .o */
extern int get_minutes(double d);


/* aspect_type  0=cnj, 1=good, 2=bad (subscripts into aspect_multipier[]) */

/* start date for this grh */
/* int Grh_beg_mn, Grh_beg_dy, Grh_beg_yr;  */
extern int Grh_beg_mn;
extern int Grh_beg_dy;
extern int Grh_beg_yr; 
extern int Eph_rec_every_x_days;  /* [2] from eph file ctrl rec */
extern FILE *Fp_docin_file;
extern char *N_long_mth[];
extern char *N_short_nat_plt[];
extern char *N_short_trn_plt[];
extern char *N_short_doc_aspect[];
extern int Num_eph_grh_pts;
extern char *N_trn_planet[];
extern char *N_planet[];
extern char *N_sign[];
extern char *N_aspect[];
extern char *N_mth[];
extern struct Futureposrec *Eph_buf; /* ptr to current buffer for /eph file */
extern int Ar_minutes_natal[];  /* +1 for [0], +3 for nod asc mc */
extern double Arco[];  /* one of 2 tables returned from calc_chart */
extern char Swk[];
/* end of externs */

/* following is local to this source file */

/* #define MAX_IN_ASP_TBL 50 */
#define MAX_IN_ASP_TBL 1024

#define SIZE_ASP_REC 26

char Asp_tbl[MAX_IN_ASP_TBL*(SIZE_ASP_REC+1)];
char *P_asp_tbl[MAX_IN_ASP_TBL];  /* ptrs to above tbl */
int Asp_tbl_idx;  /* idx to the last element in the table (not a count) */

char wk1[512];  /* for do_a_para() fix for f_docin_put */
char wk2[512];  /* for do_a_para() fix for f_docin_put */
char wk3[512];  /* for do_a_para() fix for f_docin_put */
char wk4[512];  /* for do_a_para() fix for f_docin_put */

// end of futasp.c  top stuff





//
// what is all this BIG stuff ?
// it is code to produce a big graph with jan -> dec on the bottom
// instead of 2 graphs with jan-> jun and jul -> dec
// ABANDONED in favour of 2 graphs -  too squished on iPhone (but great on iPad, Mac screens)
//



// stuff from futasp.c ===  in here now  ========================================
void do_paras(void);
void do_a_para(char *first, char *other1, char *other2);
void mk_new_date(double *pm, double *pd, double *py, double dstep);
int isinnewyear(double y, double m, double d, double step);
double day_of_year(double year, double month, double day);
void month_day(double year, double yearday, double *pmonth, double *pday);
// end of stuff from futasp.c ==========================================================



#define NUM_PTS_WHOLE_YEAR 184
#define SIZE_BIG_EPH_GRH_LINE 256 // 107  (about 184 + 7 + 1)
//char Grh_body[(SIZE_GRH_LEFT_MARGIN+SIZE_EPH_GRH_LINE+1)*MAX_GRH_BODY_LINES];
char Grh_body_BIG[(SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE +1) * MAX_GRH_BODY_LINES]; // max=333

char Grh_bottom_line1BIG[256];
char Grh_bottom_line2BIG[256];
char Grh_bottom_line3BIG[256];

void newPlanBenchmarkLabels(void);
void missingSTRESSline(void);     // edge case (like Kim jong Un -2106) where entire graph is below the stress line
void prt_BIGgrh_line(char *p_line, int cols_with_pt[],int pt_ctr, int *p_ln_ctr, int top) ;
void reverse_BIGgrh_body_and_prt(void); /* grh used to have high stress at top */
void prt_BIGgrh_bot(char *p_line, int cols_with_pt[], int pt_ctr, int *p_ln_ctr);
void mk_BIGgrh_bottom(double mn,double dy,double yr);
void prt_BIGgrh_hdr(int grh_num); /* grh title and 2nd line */
void put_BIGgrh_blnk_lines_at_top(void);   /* top is now the bottom */
void put_BIGscale_mth(int col,int mn);
void put_BIGscale_dy(int col,int dy);
void put_BIGscale_yr(int col,int yr);
void put_BIGgrh_scale_dates(int col,int mn,int dy,int yr);
void put_BIGscale_mark_char(int col,int line); /* line is 1 or 2 */
void do_BIGfuture(void);

void get_BIGeph_data(int m,int d,int y); /* args unused ? */
void do_aBIG_graph(int p_grh[], int grh_num);   /* qqq */



/* below also in mambutil.c and futhtm.c and futdoc.c */
#define IDX_FOR_MAGICAL 19
#define IDX_FOR_BEST_YEAR 90
#define IDX_FOR_MYSTERIOUS 91
#define IDX_FOR_BEST_DAY 92
#define IDX_FOR_UPS_AND_DOWNS_2 93 /* fix 201311 */
#define IDX_FOR_SCORE_B 95   /* best day 2nd iteration */


#define MAX_SIZE_PERSON_NAME  15


// make_calendar_day_html_file() not used  20210402
//extern int make_calendar_day_html_file(  /* this is in futhtm.c */
//  char *html_f_file_name,
//  char *csv_person_string,
//  int  itarget_mm,
//  int  itarget_dd,
//  int  itarget_yyyy,
//  int targetDayScore
//);
//
// make_calendar_day_html_file() not used  20210402

/* these are in rkdebug.o */
//extern void fopen_fpdb_for_debug(void);
//extern void fclose_fpdb_for_debug(void);

/* in mambutil.o */
int mapBenchmarkNumToPctlRank(int benchmark_num);    /* in mambutil.o */

void scharswitch(char *s, char ch_old, char ch_new);
void bracket_string_of(
  char *any_of_these,
  char *in_string,   
  char *left_bracket,
  char *right_bracket  );
extern int scharcnt(char *s, int c);
extern int mapNumStarsToBenchmarkNum(int category, int num_stars);
void get_event_details(  
  char   *csv_person_string,
  char   *event_name, 
  double *mn,
  double *dy,
  double *yr,
  double *hr,
  double *mu,
  int    *ap,
  double *tz,
  double *ln
);
extern void calc_chart(double mnarg, double dyarg, double yrarg,
  double hrarg, double muarg, int aparg,
  double tzarg, double lnarg, double ltarg);
extern char *sfromto(char *dest,char *src, int beg, int end);
extern void sfill(char *s, int num, int c);
extern int  sall(char *s,char *set);
extern void scharswitch(char *s, char ch_old, char ch_new);
extern char *csv_get_field(char *csv_string, char *delim, int want_fieldnum);
extern char *mkstr(char *s,char *begarg,char *end);
extern char *swholenum(char *t, char *s);
extern char *sdecnum(char *t, char *s);
extern int sfind(char s[], char c);
extern char *scapwords(char *s);
extern void strsubg(char *s, char *replace_me, char *with_me);
/* in mambutil.o */


//int mamb_report_year_in_the_life(  /* called from cocoa */
char *mamb_report_year_in_the_life(  /* called from cocoa */
  char *html_f_file_name,
  char *arg_space_for_returnSTR,   // space malloc'ed in js
  char *csv_person_string,
  char *year_todo_yyyy,
  char *instructions,  /* like  "return only year stress score" */
  char *stringBuffForStressScore
);


//  EXAMPLE of per
//
//from html:
//  var gbls_HTML_code_for_per = Module.ccall( 'mamb_report_personality' ,
//    'string',                                                 // return type
//    [ 'string', 'string', 'string', 'string', 'string' ],     // array of argument types
//    [ 'notused',
//      gbls_work_space_for_HTML_per,
//      csv_person_string2,
//      'notused',
//      myStringBuffForTraitCSV
//    ] // array of arguments
//  );
//
//from perdoc.c
//   char *mamb_report_personality ( /* in perdoc.o, called from incocoa */
//     char *html_output_filename_webview,
//   // smup   char *html_output_filename_browser,
//     char *arg_space_for_HTML_per,  // space malloc'ed in js
//     char *csv_person_string,
//     char *instructions,  /* like "return only csv with all trait scores",  */
//     char *string_buffer_for_trait_csv
//   );
//
//    // smup int mamb_report_personality (   /* in perdoc.o */
//    //
//    char *mamb_report_personality ( /* in perdoc.o, called from incocoa */
//      char *html_output_filename_webview,
//      // smup   char *html_output_filename_browser,
//      char *arg_space_for_HTML_per,  // space malloc'ed in js
//      char *csv_person_string,
//      char *instructions,  /* like "return only csv with all trait scores",  */
//      char *string_buffer_for_trait_csv
//    )
//    {
//

//int mamb_BIGreport_year_in_the_life(  /* called from cocoa */ 
char *mamb_report_big_year(  /* in futdoc,   called from cocoa */ 
  char *html_f_file_name,
  char *arg_space_for_HTML_fut,   // space malloc'ed in js
  char *csv_person_string,
  char *year_todo_yyyy,
  char *instructions,             // like  "return only year stress score" or  "return only thumbnail data" or "do Sine Wave data collection"
  char *stringBuffForStressScore  // 
);


void process_input(char *csv_person_string);  /* prep for calc_chart() */

void do_day_stress_score_B(void);
void fill_eph_buf_score_B(void);


#define NUM_ARGS 2
int Just_did_good_line;
char Good_save[32];    /* chars to put back, '-' */

int in_stress, out_of_stress;  /* new in jan1993 */
char gbl_instructions[128];
int gbl_in_stress, gbl_out_of_stress;  /* new in sep2013 (best cal yr rpt) */

/* int is_target_day_completed(int iday_num); */  /* return 1=yes,0=no  iday_num is one-based */

void checkFortargetDayScore(int d_daynum, int current_score);
int gblTargetDayScore; /* for best day on ... rpt */
int gblWeHaveTargetDayScore; /* 1=yes,0=no */

char  gbl_yyyy_todo[128];
char  gbl_yyyymmdd_todo[128];
double gbl_bd_mth;  /* bd = best day */
double gbl_bd_day;
double gbl_bd_year;
char gbl_csv_person_string[256];
char gbl_save_last_line[2024]; /* */
char gbl_BuffYearStressScore[32];
char gbl_BuffDAYstressScore[32];
                             /* manage month name overwrites for babies */
int  gbl_beg_last_mth_write; /* beg col of mth name last written */
int  gbl_end_last_mth_write; /* end col of mth name last written */
int  gbl_is_first_year_of_life;  /* year todo = birthyear */

/* ptr to end of str s (last char- not \0) */
#define PENDSTR(s) (&(s)[strlen((s))-1])
/* char *strim(); */


int is_first_f_docin_put;         /* 1=yes, 0=no */
int is_first_calloc_eph_space;    /* 1=yes, 0=no */
int is_first_set_grh_top_and_bot; /* 1=yes, 0=no */
int is_first_put_grh_scale_dates; /* 1=yes, 0=no */

int allow_docin_puts;  /* 1= yes, 0=no like for  "return only year stress score" */

char *gbl_space_for_returnSTR;  // space malloc'ed in js


/* old main()
* ===========================================================================
*/
//int mamb_report_year_in_the_life(  /* called from cocoa */
char *mamb_report_year_in_the_life(  /* called from cocoa */
  char *html_f_file_name,          // 20200321  COULD BE 'doing MOSM - MOSt Magical'    // DANGER - reusing unsed arg    char *html_f_file_name,
  char *arg_space_for_returnSTR,   // space malloc'ed in js
  char *csv_person_string,
  char *year_todo_yyyy,
  char *instructions,  /* like  "return only year stress score"  or  "return only thumbnail data" */
  char *stringBuffForStressScore
  )
{


  gbl_space_for_returnSTR = arg_space_for_returnSTR ; // space malloc'ed in js

//tn();
//trn("in mamb_report_year_in_the_life");
  int n, retval;      /* n used everywhere for "f_docin_put(p, n);" */
  char *p = &Swk[0];  /* p used everywhere for "f_docin_put(p, n);" */
  char s[128];
  int tempnum_x;
  int tempnum_y;
  int tempnum_z;
  int tempnum_MOSM;  // for MOSt Magical trait score
  int worknum2;  /* calibrate stress score for return value */
  int percentileRank_MOSM;
/*  int worknum3; */ /* calibrate stress score for return value */
  ;

  is_first_f_docin_put         = 1;  /* 1=yes, 0=no */
  is_first_calloc_eph_space    = 1;  /* 1=yes, 0=no */
  is_first_set_grh_top_and_bot = 1;  /* 1=yes, 0=no */
  is_first_put_grh_scale_dates = 1;  /* 1=yes, 0=no */

  strcpy(gbl_csv_person_string, csv_person_string);

  char mybirthyear[8];
  strcpy(mybirthyear, csv_get_field(csv_person_string, ",", 4));
  if (strcmp(mybirthyear, year_todo_yyyy) == 0) {
    gbl_is_first_year_of_life = 1;  /* year todo = birthyear */
  } else {
    gbl_is_first_year_of_life = 0;
  }

//  fopen_fpdb_for_debug();

//int testt; testt = strcmp(gbl_instructions,  "return only year stress score");
//kin(testt);
//  if(testt != 0)   // log only if not best year


//tn();
trn("in mamb_report_year_in_the_life() 2"); 
//ksn(html_f_file_name);
//ksn(csv_person_string);
//ksn(year_todo_yyyy);
//ksn(instructions);
//ksn(stringBuffForStressScore);




  if (strstr(instructions, "return only") == NULL) {
/*     trn("in mamb_report_year_in_the_life()"); */
  }  /* avoid dbmsg on non-rpt call */


  strcpy(gbl_instructions, instructions);

    /* note below:   NEW VERSION of DAY STRESS SCORE =  "B"
    *  gbl_instructions,  "return only day stress score_B")
    */
  if(strcmp(gbl_instructions,  "return only year stress score") == 0) {
//trn("year score only  - no docin_puts ");
    allow_docin_puts = 0;

    strcpy(gbl_yyyymmdd_todo, ""); 

    strcpy(year_in_the_life_todo_yyyy, year_todo_yyyy);

  }
//  else if(strcmp(gbl_instructions,  "return only day stress score") == 0) {
//b(61);
//    allow_docin_puts = 0;
//
//    strcpy(gbl_yyyymmdd_todo, year_todo_yyyy); /* DANGER - RE-USE ARG FIELD HERE */
//    /* (danger re-used arg has dd added to date) */
//
//    strcpy(year_in_the_life_todo_yyyy, sfromto(s,&year_todo_yyyy[0],1,4));
//
//    gbl_bd_mth  = atof(sfromto(s,&gbl_yyyymmdd_todo[0],5,6));
//    gbl_bd_day  = atof(sfromto(s,&gbl_yyyymmdd_todo[0],7,8));
//    gbl_bd_year = atof(sfromto(s,&gbl_yyyymmdd_todo[0],1,4));
//
//  }
//
  else if(strcmp(gbl_instructions,  "return only day stress score_B") == 0) {
//tn(); b(36);
//ksn(gbl_instructions);
//ks(stringBuffForStressScore); ki(gblTargetDayScore); ksn(gbl_csv_person_string);

    allow_docin_puts = 0;

    strcpy(gbl_yyyymmdd_todo, year_todo_yyyy); /* danger - re-use arg field here */
    /* (danger re-used arg has dd added to date) */

    strcpy(year_in_the_life_todo_yyyy, sfromto(s,&year_todo_yyyy[0],1,4));

    gbl_bd_mth  = atof(sfromto(s,&gbl_yyyymmdd_todo[0],5,6));
    gbl_bd_day  = atof(sfromto(s,&gbl_yyyymmdd_todo[0],7,8));
    gbl_bd_year = atof(sfromto(s,&gbl_yyyymmdd_todo[0],1,4));
//kd(gbl_bd_year); kd(gbl_bd_mth); kdn(gbl_bd_day);
  }

  else {                 /* "normal" fut run */
    allow_docin_puts = 1;

    strcpy(gbl_yyyymmdd_todo, ""); 

    strcpy(year_in_the_life_todo_yyyy, year_todo_yyyy);
  }


  gbl_in_stress     = 0;  /* init */
  gbl_out_of_stress = 0;  /* new in sep2013 */


  /* left-overs from input changes
  */
  fPI_OVER_2 = 3.1415926535897932384 / 2.0;
  sfill(&fEvent_name[0],SIZE_INBUF,' ');

  Num_fut_units_ordered = 2;   /* for a-year-in-the-life */

  /* get event details here
  */
  process_input(csv_person_string);  /* prep for calc_chart() */
  /*  input args to calc_chrt() 
  *  mth  date of birth 
  *  day 
  *  year 
  *  hour 
  *  minute 
  *  am,0 or pm,1 
  *  dob_city_diff_hrs_from_greenwich 
  *  dob_city_longitude 
  *  "0.0"  for latitude, take equator, equal house from mc 
  */
  calc_chart(fInmn,fIndy,fInyr,fInhr,fInmu,fInap,fIntz,fInln,fInlt);

  /*   f_display_positions(); for test  */

  GRH_BACKGROUND_CHAR = 88;  /* used to be arg */
  TITLE_LINE_CHAR     = 42;  /* used to be arg */

  /* do not worry about time of day confidence - say its 100% 
  */
  House_confidence = 1;
  Moon_confidence = 1;
  Moon_confidence_factor = 1.0; 

  /* fill natal position tbl, Ar_minutes_natal, incl mc
  */
  /* double Arco[14];        positions  are in following order:
  *     xxx,sun,mer,ven,mar,jup,sat,ura,nep,plu,moo,nod,asc,mc_
  * index 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13
  *
  *    BUT
  * Ar_minutes_natal[1]   sun
  * Ar_minutes_natal[2]   moo
  * Ar_minutes_natal[3]   mer
  * Ar_minutes_natal[4]   ven
  * Ar_minutes_natal[5]   mar
  * Ar_minutes_natal[6]   sat
  * Ar_minutes_natal[7]   jup
  * Ar_minutes_natal[8]   ura
  * Ar_minutes_natal[9]   nep
  * Ar_minutes_natal[10]  plu
  * Ar_minutes_natal[11]  nod
  * Ar_minutes_natal[12]  asc
  * Ar_minutes_natal[13]  mc_
  */
  put_minutes(&Ar_minutes_natal[0]); 

    // fyi
    //    --------------- "/Users/rk/_PC/usr/apple/_c/_wrk/free/xfils/futdoc.h" --------------
    //    221:int Orb_trn_adj_for_nat[NUM_PLANETS+1] = {0,40,30,27,24,21,-20,0,-20,-25,-30};
    //

  /*  set aspect ranges */
  put_aspect_ranges(&Orbs_trn[0],&Orb_trn_adj_for_nat[0]);

  /* this is 1st output to docin file 
  */
  f_set_doc_hdr();  /* -- this is 1st output to docin file -- */

  Is_past = 0;    /* 0= doing future, not past */



    /* note below:   NEW VERSION of DAY STRESS SCORE =  "B"
    *  gbl_instructions,  "return only day stress score_B")
    */
  /* ########################################################### */
  if(strcmp(gbl_instructions,  "return only day stress score_B") == 0) {
//tn();b(43);
//trn(" do_day_stress_score_B();  - calcs  gblTargetDayScore;  ");

    do_day_stress_score_B();  /* calcs  gblTargetDayScore; */

/* 
* tn();b(44);ki(worknum);
*     worknum = mapNumStarsToBenchmarkNum(IDX_FOR_SCORE_B, worknum);
* tn();b(45);ki(worknum);
*     worknum = mapBenchmarkNumToPctlRank(worknum);
* b(46);ki(worknum);
*       gblTargetDayScore= *(Grhdata_bestday + iday_num-1);
* 
*/

  }
  else {
trn("calling do_future() in mamb_report_year_in_the_life() ");
    do_future();    /* deep in here, eph_space ALLOCed */
trn("back from do_future() in mamb_report_year_in_the_life() ");

  }

  /* ########################################################### */

//trn("calling f_display_positions() in mamb_report_year_in_the_life() "); 


  f_display_positions();  /* put on bottom of docin_lines */

  n = sprintf(p,"\n[end_program]\n");
  f_docin_put(p, n);

  free_eph_space();  /* free Grhdata, Grh_colnum, Eph_buf */

  /* for test  put all docin_lines to stderr
  */
  /* int ii;
  * for (ii = 0; ii <= docin_idx; ii++) {
  *   strcpy(Swk, docin_lines[ii] );
  *   fprintf(stderr,"%s", Swk);
  * } 
  */

/* fprintf(stderr,"%s|%s|%d|%d|%d|\n",  fEvent_name, year_in_the_life_todo_yyyy, */
/*     gbl_out_of_stress , gbl_in_stress, gbl_out_of_stress - gbl_in_stress); */
/*  for test, no html */


    /* prepare stress score for ranking purposes.
    * 1.  + 8000 is to make all positive
    * 2.  / 87 is  to normalize to 100=median
    * 3.  map to standard benchmark numbers
    */

    tempnum_y = gbl_out_of_stress - gbl_in_stress;
    tempnum_y = (tempnum_y + 8000);
    if (tempnum_y < 0) tempnum_y = 0;
    tempnum_y = (tempnum_y / 123);

    /* 3. extern int mapNumStarsToBenchmarkNum(int category, int num_stars); */

    /* this is not num_stars, but rather,  gbl_out_of_stress - gbl_in_stress;
    */
//kin( gbl_out_of_stress);
//kin( gbl_in_stress);
//kin( tempnum_y);
trn("do i get here");
    tempnum_y = mapNumStarsToBenchmarkNum(IDX_FOR_BEST_YEAR, tempnum_y);
//kin( tempnum_y);
    tempnum_y = mapBenchmarkNumToPctlRank(tempnum_y);
//kin( tempnum_y);


    /* intercept information for data request invocation
    */
//trn("intercept information for data request invocation");

    sprintf(stringBuffForStressScore, "%02d", ((tempnum_y)));


    strcpy(gbl_BuffYearStressScore, stringBuffForStressScore);
////tn();b(66);
//ksn(stringBuffForStressScore);
//ksn( gbl_BuffYearStressScore);
/* 
*     worknum = mapNumStarsToBenchmarkNum(IDX_FOR_SCORE_B, worknum);
* 
*     sprintf(stringBuffForStressScore, "%d", worknum);
* 
* 
*/



  /* we might be finished  #1  (no HTML file)
  */
  if(strcmp(gbl_instructions,  "return only year stress score") == 0) {

//b(44);
//trn("no HTML file  - return from futdoc.c 0521");
//trn("return only year stress score  01!");
//ksn(stringBuffForStressScore);

    strcpy(gbl_instructions,  "");  /* init gbl */
    allow_docin_puts = 1;           /* init gbl */
//    fclose_fpdb_for_debug();



//    return(0);
//    return("hey2");

    return( stringBuffForStressScore);  // gbl_instructions,  "return only year stress score"
  }  // gbl_instructions,  "return only year stress score"

//b(70);
/*   if (strcmp(gbl_instructions,  "return only day stress score_B") == 0)  */

/* tn();trn("score_b end"); */
    /* prepare stress score for ranking purposes.
    * 1.  * -1  because used to be stress graph (high nums were stressful)
    *    * 10 for bigger numbers
    * 2.  +100 to make all positive
    * 3.  map to standard benchmark numbers
    */

    tempnum_z = gblTargetDayScore;
//kin(tempnum_z);
    tempnum_z = tempnum_z * -1; 
//kin(tempnum_z);

/* ki(tempnum_z); */
    tempnum_z = tempnum_z + 900;
//kin(tempnum_z);
    if (tempnum_z <= 0) tempnum_z = 1;
tr("bday fut"); trn("doing mapNumStarsToBenchmarkNum()");
tr("bday fut arg is IDX_FOR_SCORE_B ="); kin(IDX_FOR_SCORE_B);
tr("bday fut arg is "); kin(tempnum_z);

    tempnum_z = mapNumStarsToBenchmarkNum(IDX_FOR_SCORE_B, tempnum_z);  // fyi  IDX_FOR_SCORE_B = 95
                                                                        // fyi  #define IDX_FOR_BEST_YEAR 90

tr("bday fut return is"); kin(tempnum_z);


/* ki(tempnum_z); */

/*     tempnum_z = (tempnum_z + 8000); */
/*     tempnum_z = (tempnum_z / 123); */

    /* 3. extern int mapNumStarsToBenchmarkNum(int category, int num_stars); */


    /* intercept information for data request invocation
    */
    sprintf(stringBuffForStressScore, "%d", ((tempnum_z)));
//b(68);ksn(stringBuffForStressScore);


/*     sprintf(gbl_BuffYearStressScore,  "%d", ((tempnum_z))); */
/* tn();b(151);ksn(gbl_BuffYearStressScore); */
//b(79);



  if (strcmp(gbl_instructions,  "return only day stress score_B") == 0) {
//tn(); b(38);
//ksn(gbl_csv_person_string);
//ki(gblTargetDayScore);
//ks(stringBuffForStressScore);
//


/*     worknum2 = gblTargetDayScore; */
    worknum2 = atoi(stringBuffForStressScore);
//kin(worknum2);




  //  NOTE:  MOSM report returns here using tempnum_MOSM  (worknum2 above)
  // 
  // we have to know this call is for MOSM
  if (strcmp(html_f_file_name, "doing MOSM - MOSt Magical") == 0)   // DANGER - reusing unsed arg    char *html_f_file_name,
  {
    tempnum_MOSM = worknum2;  // raw score for MOSt Magical trait score
//kin(tempnum_MOSM);

//    // FYI   #define IDX_FOR_MAGICAL 19    (number is arbitrary and unique among IDX_FOR_*)
//    //
//        //    tempnum_MOSM = mapNumStarsToBenchmarkNum(IDX_FOR_MAGICAL, tempnum_MOSM);
//        //kin(tempnum_MOSM);
//        //    tempnum_MOSM = mapBenchmarkNumToPctlRank(tempnum_MOSM);
//        //kin(tempnum_MOSM);


    //  manually calculate CONVERSION   of MOSM raw scores to percentile rank score
    //
    //    MOSM  raw scores =     431,389,267,133, 50    // magical trait   
    //    BENCHMARK scores =      90, 75, 50, 25, 10    // these are percentile ranks
    //

    // from mambutil.c
    //
    // ===  key  ===================================================================  key  ===
    // ===  key  ===================================================================  key  ===
    //    int ts_magic[] = {-1,431,389,267,133, 50,  1};   // magical trait   // todo
    //    /* BENCHMARKs  =  -1, 90, 75, 50, 25, 10,  1    */
    // ===  key  ===================================================================  key  ===
    // ===  key  ===================================================================  key  ===
    //
    //    /* e.g. int calc_percentile_rank(in_score, 41, 18, 25, 10)
    //    *  e.g. maps in_score between 41 and 18 to percentile ranks between 25 and 10
    //    */
    //    int calc_percentile_rank(int in_score, int sc_hi, int sc_lo, int pr_hi, int pr_lo)
    //
    //  EXAMPLE from  mambutil.c  in fn  mapBenchmarkNumToPctlRank(int in_score)
            //  /* e.g. map score in range 41 -> 18  to  score in range 25 -> 10 */
            //  if (in_score <  18 && in_score >   1) return calc_percentile_rank(in_score,  18,   1, 10,  1);
            //  if (in_score <  42 && in_score >  18) return calc_percentile_rank(in_score,  42,  18, 25, 10);
            //  if (in_score < 100 && in_score >  42) return calc_percentile_rank(in_score, 100,  42, 50, 25);
            //  if (in_score < 213 && in_score > 100) return calc_percentile_rank(in_score, 213, 100, 75, 50);
            //  if (in_score < 373 && in_score > 213) return calc_percentile_rank(in_score, 373, 213, 90, 75);
            //  if (in_score < 777 && in_score > 373) return calc_percentile_rank(in_score, 777, 373, 99, 90);
            //
    //
    // from mambutil.c

    if      (tempnum_MOSM <=   1)                      percentileRank_MOSM =  1; 
    else if (tempnum_MOSM >  550)                      percentileRank_MOSM = 99;

    /* return exact hits */
    else if (tempnum_MOSM == 431)                      percentileRank_MOSM = 90;
    else if (tempnum_MOSM == 389)                      percentileRank_MOSM = 75;
    else if (tempnum_MOSM == 267)                      percentileRank_MOSM = 50;
    else if (tempnum_MOSM == 133)                      percentileRank_MOSM = 24;
    else if (tempnum_MOSM ==  50)                      percentileRank_MOSM = 10;

    else if (tempnum_MOSM <  50 && tempnum_MOSM >   1) percentileRank_MOSM = calc_percentile_rank(tempnum_MOSM,  50,   1, 10,  1);
    else if (tempnum_MOSM < 133 && tempnum_MOSM >  50) percentileRank_MOSM = calc_percentile_rank(tempnum_MOSM, 133,  25, 25, 10);
    else if (tempnum_MOSM < 267 && tempnum_MOSM > 133) percentileRank_MOSM = calc_percentile_rank(tempnum_MOSM, 267, 133, 50, 25);
    else if (tempnum_MOSM < 389 && tempnum_MOSM > 267) percentileRank_MOSM = calc_percentile_rank(tempnum_MOSM, 389, 267, 75, 50);
    else if (tempnum_MOSM < 431 && tempnum_MOSM > 389) percentileRank_MOSM = calc_percentile_rank(tempnum_MOSM, 431, 389, 90, 75);
    else if (tempnum_MOSM < 550 && tempnum_MOSM > 431) percentileRank_MOSM = calc_percentile_rank(tempnum_MOSM, 550, 431, 99, 90);
    //
    //  manually calculate CONVERSION   of MOSM raw scores to percentile rank score


    sprintf(stringBuffForStressScore, "%02d", percentileRank_MOSM );
//ksn(stringBuffForStressScore);


trn("\nin mamb_report_year_in_the_life()");
trn("in [return only day stress score_B]");
trn("returning score for MOSt Magical");

    return(stringBuffForStressScore); //  NOTE: in mamb_report_year_in_the_life() ,  MOSM report returns here using rawnum_mosm 
  }
  // 
  //  NOTE:  MOSM report returns here using rawnum_mosm 




/*     worknum2 = mapNumStarsToBenchmarkNum(IDX_FOR_SCORE_B, worknum2); */
//trn("after set worknum2 = atoi(stringBuffForStressScore);");

//trn("do map to 99 b");
tr("doing mapBenchmarkNumToPctlRank()");
tr("bday fut  arg is "); kin(worknum2);
    worknum2 = mapBenchmarkNumToPctlRank(worknum2);
tr("bday fut return is "); kin(worknum2);

    sprintf(stringBuffForStressScore, "%d", worknum2);
tr("bday fut"); trn("after set sprintf(stringBuffForStressScore, ... worknum2);  "); 
tr("bday fut"); ksn(stringBuffForStressScore);




    /* re-init stuff before leaving
    */
    gblTargetDayScore= 0; /* for best day on ... rpt */
    gblWeHaveTargetDayScore= 0; /* 1=yes,0=no */
    strcpy(gbl_instructions,  "");  /* init gbl */
    allow_docin_puts = 1;           /* init gbl */
//    fclose_fpdb_for_debug();

//    return(0);
//trn("20190428  no return(0);");
//ksn(stringBuffForStressScore);
//ks(stringBuffForStressScore);
//ki(gblTargetDayScore);
//ksn(gbl_csv_person_string);
//trn("return stringBuffForStressScore in mamb_report_year_in_the_life()");
//



//// not needed
////  f_docin_free();      /* free all allocated array elements */
//
//  free_eph_space();  /* free Grhdata, Grh_colnum, Eph_buf */
//        // FYI
//        //
//        //  void free_eph_space(void)
//        //  {
//        //    free(Eph_buf);    Eph_buf    = NULL;
//        //    free(Grhdata);    Grhdata    = NULL;
//        //    free(Grh_colnum); Grh_colnum = NULL;
//        //
//        //    if(strcmp(gbl_instructions,  "return only day stress score") == 0) {
//        //  b(65);
//        //      free(Eph_buf_bestday);  Eph_buf_bestday = NULL;
//        //      free(Grhdata_bestday);  Grhdata_bestday = NULL;
//        //    }
//        //  }
//        //
//


//trn("do FREE here??");





trn("\nin mamb_report_year_in_the_life()");
trn("in [return only day stress score_B]");
trn("returning stringBuffForStressScore");
ksn( stringBuffForStressScore);
    return( stringBuffForStressScore); // end of mamb_report_year_in_the_life()  - end of old main() 

  } //   if (strcmp(gbl_instructions,  "return only day stress score_B") == 0) 



trn("todo remove this?");

  // todo remove this?

  /* tn();  ksn(" HTML HTML HTML HTML HTML HTML HTML HTML HTML HTML "); */

  /* HTML HTML HTML HTML HTML HTML HTML HTML HTML HTML 
  */
  scharswitch(fEvent_name, ' ', '_');


  /* html_f_file_name is arg to mamb_report_year_in_the_life()
  */
/* tn();b(17);
* ks(stringBuffForStressScore);
* ks(gbl_BuffYearStressScore);
*/

/*   worknum3 = atoi(stringBuffForStressScore);
* kin(worknum3);
*   worknum3 = mapBenchmarkNumToPctlRank(worknum3);
* kin(worknum3);b(172);
* 
*   sprintf(stringBuffForStressScore, "%d", worknum3);
* ksn(stringBuffForStressScore);
*   sprintf(gbl_BuffYearStressScore, "%d", worknum3);
* ksn(gbl_BuffYearStressScore);
*/

//trn(" doing make_fut_htm_file() in futdoc.c 665");

  // this is in mamb_report_year_in_the_life
trn("calling  make_fut_htm_file   in mamb_report_year_in_the_life");
  retval = make_fut_htm_file(  // + new arg at bottom.  gbl_instructions,  "return only day stress score_B" // this is in mamb_report_year_in_the_life
//    html_f_file_name,
    gbl_thumbnailInfo,
    "unused",           // fix later
    docin_lines,
    docin_idx,
    gbl_BuffYearStressScore,
    gbl_is_first_year_of_life,

      //    "this arg is used for PSV_of_SW_CSVs"        // gbl_PSV_of_SW_CSVs
      //    char gbl_PSV_of_SW_CSVs[8192] = "";   // this is updated after each aspect in this current calendar year is "finished"
    gbl_PSV_of_SW_CSVs   // ?? hurts or not
  );



  if (retval != 0) {
    f_docin_free();      /* free all allocated array elements */
    rkabort("Error: html file (fut) was not produced");
  }


/* for test */
#ifdef PUT_BACK_COMMENTED_OUT_STUFF /****************************************/
#endif /* ifdef PUT_BACK_COMMENTED_OUT_STUFF ********************************/





/* for test, show all docin lines */
/* tn();trn(" #################  ALL DOCIN LINES ##############");
* trn(" #################  ALL DOCIN LINES ##############");
* int jj; for (jj = 0; jj <= docin_idx; jj++) { 
*   kin(jj);
*   strcpy(Swk, docin_lines[jj] );
*   ks(Swk);
* }
*/
/*   close_fut_output_file(); */





  f_docin_free();      /* free all allocated array elements */


  if (strstr(instructions, "return only") == NULL) {
/*     trn("end of mamb_report_year_in_the_life()!"); */
  }  /* avoid dbmsg on non-rpt call */

//  fclose_fpdb_for_debug();

  return(0);
// <.>  ?  returns string now


trn("end of mamb_report_year_in_the_life()  - end of old main() ");

} /* end of mamb_report_year_in_the_life()  - end of old main() */




void process_input(char *csv_person_string)   /* prep for calc_chart() */
{
/* trn(" in process_input()"); */
/* ksn(csv_person_string); */

  get_event_details(csv_person_string, fEvent_name, 
    &fInmn, &fIndy, &fInyr, &fInhr, &fInmu, &fInap, &fIntz, &fInln);
  if (fInhr == 12.0) fInhr = 0.0;  /* hour 12 must be 0 for calcchrt.c */

  /* get month and day to start the first graph
  * e.g.  "Delia,12,13,1971,12,15,0,-1,-19.05" 
  */

  /* get character versions of these
  */
  strcpy(mth_of_birth,  csv_get_field(csv_person_string, ",", 2));
  strcpy(day_of_birth,  csv_get_field(csv_person_string, ",", 3));
  strcpy(year_of_birth, csv_get_field(csv_person_string, ",", 4));

/* ksn(mth_of_birth); */
/* ksn(day_of_birth); */
/* ksn(year_of_birth); */

// NO privacy (determine yr of birth) , always start at jan 1
//  /* for year of birth, start at birthday
//  */
//  if (strcmp(year_in_the_life_todo_yyyy, year_of_birth) == 0) {
//    Fut_start_mn = atoi(mth_of_birth);
//    Fut_start_dy = atoi(day_of_birth); 
//  } else {
//    Fut_start_mn = 1;
//    Fut_start_dy = 1; /*  old was 2 */
//  }
//

    Fut_start_mn = 1;
    Fut_start_dy = 1; /*  old was 2 */

/* kin(Fut_start_mn); */
/* kin(Fut_start_dy); */
/* kin(Fut_start_yr); */

  Fut_start_yr = atoi(year_in_the_life_todo_yyyy);

}  /* end of process_input */


#ifdef PUT_BACK_COMMENTED_OUT_STUFF /****************************************/
/* for test */ f_docin_free(); b(99);
return(0); /* for test */
#endif /* ifdef PUT_BACK_COMMENTED_OUT_STUFF ********************************/


/* add a line to the array of docin_lines
*  replaces this:  fput(p,n,Fp_docin_file); 
*  
*  eg 1
*  * fput(p,n,Fp_docin_file); * 
* f_docin_put(p,n);
*    
*  eg 2
*  *fprintf(fFP_DOCIN_FILE,"\n[end_program]\n"); *
*  n = sprintf(p,"\n[end_program]\n");
*  f_docin_put(p, n);
*/
void f_docin_put(char *line, int length)
{
//tr("put_");ki(docin_idx);
//ksn(line);

  if (allow_docin_puts == 0) return; /* (like pt of view) */
 


//  char chkLine[512];
////kin(is_first_f_docin_put );
//  if (is_first_f_docin_put == 1)  gbl_doLineCheck = 1;
//
//  if (strstr(line, "GREAT-") != NULL) gbl_doLineCheck = 0;
////kin(gbl_doLineCheck);
//
//  if (    gbl_doLineCheck == 1
//      &&  strlen(line)    >= 184  ) {
////ksn(" HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH");
//    //
//    // check for line all sky (' ')  or star ('^')
//    //
//    strcpy(chkLine, line);
////trn(" check for line all sky ( )  or star (^)");
////ksn(chkLine);
//
//    remove_spans(chkLine);
////ksn(chkLine);
////int mywk143; mywk143 = sall(chkLine, " ^\n");
////kin(mywk143);
//
//    //  strcpy(gbls_addLines, "we added no lines");  // INIT add lines FLAG
//    //  strcpy(gbls_addLines, "we added lines to ensure benchmark labels STRESS, GOOD and GREAT are all present");
//    //
////    if lp    strcmp(gbls_addLines, "we added lines to ensure benchmark labels STRESS, GOOD and GREAT are all present") == 0
//    if (  
//            sall(chkLine, " ^\n") == 1             // line has only hats or spaces or both in it  OR NEWLINE
//        &&  strstr(chkLine, "^") != NULL           // line must have at least one hat '^'  (cannot be all spaces)
//    )
//    {  
//ksn(" hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh");
//trn("IS all hat and space");
//trn(" change stars to sky in line");
//
//ksn(line);
//      scharswitch(line, '^', ' ');    // change stars to sky 
//ksn(line);
//
//      gbl_doLineCheck = 0;            // do this one time only
//ksn(" hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh");
//    }
//ksn(" HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH");
//  }
//





//ksn("doing docin_put"); 
  if (is_first_f_docin_put == 1) docin_idx = 0;
  else                           docin_idx++;

  docin_lines[docin_idx] = malloc(length + 1);

  if (docin_lines[docin_idx] == NULL) {
    sprintf(errbuf, "malloc failed, arridx=%d, linelen=%d, line=[%s]\n",
      docin_idx, length, line);
    rkabort(errbuf);
  }



//    /* turn star (*) into caret (^) with star color */
//    bracket_string_of("*", linebuf, "<span class=\"star\">", "</span>");
//    scharswitch(linebuf, '*', '^');
//    n = sprintf(p,"%s\n", linebuf);
//    f_docin_put(p,n);
if (    strstr(line, "span class") != NULL
    &&  strstr(line, "star") != NULL       )
{
//tr("star");
//    scharswitch(line, '^', '*');
//  scharswitch(line, '^', ' ');
}

if (    strstr(line, "GREAT") != NULL
    ||  strstr(line, "GOOD") != NULL
    ||  strstr(line, "STRESS") != NULL
    ||  strstr(line, "OMG") != NULL    
    ||  strstr(line, "___") != NULL    
    ||  strstr(line, "---") != NULL    )
{
//tr("lbl");ksn(line);
}




  strcpy(docin_lines[docin_idx], line);   //  "write" is HERE



  strcpy(gbl_save_last_line, line);


  is_first_f_docin_put = 0;  /* set to no */
  
  /* When this function finishes,
  * the index docin_idx points at the last line written.
  * Therefore, the current docin_lines written
  * run from index = 0 to index = docin_idx. (see f_docin_free() below)
  */
}

/* Free the memory allocated for every member of docin_lines array.
*/
void f_docin_free(void)
{
  int i;

  for (i = 0; i <= docin_idx; i++) {
    free(docin_lines[i]);    docin_lines[i] = NULL;
  }
  docin_idx = 0;
}

      //#define NUM_PLANETS 10 
      //#define NUM_ASPECTS 9
      //
      // fyi
        //      int Aspect_id[NUM_ASPECTS+1] =
        //                   {0,  1,   2,   3,   4,    5,    6,    7,    8  ,9};
        //              /* name x cnj  sxt  squ  tri   opp   tri   squ   sxt  cnj */
        //            /* degrees x  0  60   90   120   180   240   270   300  360 */
        //      int Aspects[NUM_ASPECTS+1]=
        //                    {-1,  0,3600,5400,7200,10800,14400,16200,18000,21600};
        //            /* degrees x  0  60   90   120   180   240   270   300  360 */
        //              /* name x cnj  sxt  squ  tri   opp   tri   squ   sxt  cnj */
        //
        //      int Aspect_type[NUM_ASPECTS+1] = {-1,  0,   1,   2,   1,    2,    1,    2,    1,    0};
        //       /* Aspect_type  0=cnj, 1=good, 2=bad (subscripts into aspect_multipier[]) */
        //
        //      /* size of angle between 2 plts for all aspects
        //      */
        //
        //      int Beg_aspect_ranges[(NUM_PLANETS)*(NUM_ASPECTS+1)];
        //      int End_aspect_ranges[(NUM_PLANETS)*(NUM_ASPECTS+1)];
        //
    // fyi
    //  char *N_planet[]     = {"   ","sun","moo","mer","ven","mar","jup","sat","ura","nep","plu", "nod","asc","mc_"};
    //  char *N_trn_planet[] = {"   ","jup","sat","ura","nep","plu","mar"};
    //  char *N_aspect[]     = {"   ","cnj","sxt","squ","tri","opp","tri","squ","sxt","cnj"};
    // fyi
    //    --------------- "/Users/rk/_PC/usr/apple/_c/_wrk/free/xfils/futdoc.h" --------------
    //    221:int Orb_trn_adj_for_nat[NUM_PLANETS+1] = {0,40,30,27,24,21,-20,0,-20,-25,-30};
    //


/* calcs beg and end pts of all aspects */
/* ptrs to ints (table of orbs and adj to orbs) */
void put_aspect_ranges(int *porbs, int *porb_adj)
{
//trn("\n\nput_aspect_ranges\n");
  int i,k;
  ;
  for (k=1; k <= NUM_PLANETS; ++k) {
    for (i=1; i <= NUM_ASPECTS; ++i) {
      *(Beg_aspect_ranges+(k-1)*(NUM_ASPECTS+1)+i) = *(Aspects+i) - (*(porbs+i)+*(porb_adj+k));
      *(End_aspect_ranges+(k-1)*(NUM_ASPECTS+1)+i) = *(Aspects+i) + (*(porbs+i)+*(porb_adj+k));

// for test
//int Basp = *(Beg_aspect_ranges+(k-1)*(NUM_ASPECTS+1)+i);
//int Easp = *(End_aspect_ranges+(k-1)*(NUM_ASPECTS+1)+i);
//ki(k);ks(N_planet[k]);ki(i);ks(N_aspect[i]);ki(Basp);kin(Easp);


    }
  }
//trn("put_aspect_ranges\n\n");
}



#ifdef PUT_BACK_COMMENTED_OUT_STUFF /****************************************/
* void open_fut_output_file(void)
* {
*   sfill(&Docin_pathname[0],SIZE_INBUF,' ');
*   strcpy(&Docin_pathname[0],&Arg_docin_dir[0]);
*   strcat(&Docin_pathname[0],DIR_CHAR);
*   strcat(&Docin_pathname[0],&Futin_filename[0]);
* 
*   if ((Fp_docin_file = fopen( &Docin_pathname[0] ,WRITE_MODE)) == NULL) {
*     rkabort("future.c. open_fut_output_file(). fopen(). ");
*   }
* }
* 
* void close_fut_output_file(void)
* {
*   fclose(Fp_docin_file);
* }
#endif /* ifdef PUT_BACK_COMMENTED_OUT_STUFF ********************************/



void do_future(void)
{
  char s[8+1];
  double dmn,ddy,dyr,dstep;
  int ido;
  ;
  sfill(s,8,' ');
  if (Fut_start_mn == 0) {    /* special signal from mk_fut_input.c */
    dmn = atof(sfromto(s,&Date_of_order_entry[0],5,6)); /* "yyyymmdd" */
    ddy = atof(sfromto(s,&Date_of_order_entry[0],7,8));
    dyr = atof(sfromto(s,&Date_of_order_entry[0],1,4));
  } else {
    dmn = (double) Fut_start_mn;
    ddy = (double) Fut_start_dy;
    dyr = (double) Fut_start_yr;
  }
trn("do_future() #1");
/* kd(dmn); kd(ddy); kd(dyr);  */

  init_rt();

  /* for each 6-month future ordered
  */
  for (ido=1; ido <= Num_fut_units_ordered; ido++) {
    global_flag_which_graph = ido;   /* 1 or 2 */

    if (ido == 1)  dstep = 0.0;   /* WARNING v undefined 1st time thru */
    else  dstep = (double)(NUM_PTS_FOR_FUT*Eph_rec_every_x_days);

    mk_new_date(&dmn,&ddy,&dyr,dstep);

/*   if (ido == 1) trn("==========   FIRST GRAPH  =============="); */
/*   if (ido == 2) trn("==========  SECOND GRAPH  =============="); */

    Grh_beg_mn = (int)dmn; /* to be adjusted- set_grh_top_and bot()  */ 
    Grh_beg_dy = (int)ddy; /* so that arg date jogs with eph file   */  
    Grh_beg_yr = (int)dyr; /* dates, e.g. past is on Wed       */  

    get_eph_data((int)dmn,(int)ddy,(int)dyr);  /* args unused ? */




    // ***************************************************************************************************
    // ***************************************************************************************************
trn("calling do_grh_calcs_and_prt();    /* central pgm  qqq   in do_future()  */");

    do_grh_calcs_and_prt();    /* central pgm  qqq   in do_future()  */

trn("back from do_grh_calcs_and_prt();    /* central pgm  qqq   in do_future()  */");
    // ***************************************************************************************************
    // ***************************************************************************************************




    if (gbl_yearStressScoreIsDone == 1) {
trn("ss 01  gbl_yearStressScoreIsDone == 1  RETURN from do_future()  after do_grh_calcs_and_prt(); ");
      return;   // can return  if(strcmp(gbl_instructions,  "return only year stress score") == 0) 
    }



trn("1st do_paras()");
    do_paras();

    init_rt();

  } /*  for (ido=1; ido <= Num_fut_units_ordered; ido++) */

}  /* end of do_future() */


/* for 1 6-month future
*/
void get_eph_data(int m,int d,int y)  /* args unused ? */
{
  /* Only free eph_space stuff if calloc_eph_space has run already
  *  during this call to mamb_report_year_in_the_life()
  */
  if (is_first_calloc_eph_space == 1) {
    is_first_calloc_eph_space = 0;
  } else {
    free_eph_space();
  }

  Num_eph_grh_pts = (Is_past)? NUM_PTS_FOR_PAST: NUM_PTS_FOR_FUT;

  calloc_eph_space();

  Eph_rec_every_x_days = STEP_SIZE_FOR_FUT;

  fill_eph_buf();

}  /* end of get_eph_data() */


void calloc_eph_space(void)    /* for Grhdata[], fut_col_num[], all Futurepos recs */
{
  if ((Grhdata = (int *) calloc((NUM_EPH_GRAPHS-1)*Num_eph_grh_pts,sizeof(int))) == NULL)
      rkabort("future.c  not enough memory for calloc Grhdata");

//  if(strcmp(gbl_instructions,  "return only day stress score") == 0) {
//b(63);
//    if ((Grhdata_bestday = (int *)  calloc((NUM_EPH_GRAPHS-1)*Num_eph_grh_pts,sizeof(int))) == NULL) {
//        rkabort("future.c  not enough memory for calloc Grhdata_bestday");
//    }
//  }

  if ((Grh_colnum = (int *) calloc(Num_eph_grh_pts,sizeof(int))) == NULL)
      rkabort("future.c  not enough memory for calloc Grh_colnum");

  if ((Eph_buf =        /* v (add one for zeroth (ctrl) rec) */
    (struct Futureposrec*) calloc(Num_eph_grh_pts+1,sizeof(struct Futureposrec)))  == NULL)
      rkabort("future.c  not enough memory for calloc Eph_buf");


//  if(strcmp(gbl_instructions,  "return only day stress score") == 0) {
//b(64);
//    if ((Eph_buf_bestday =        /* v (add one for zeroth (ctrl) rec) */
//      (struct Futureposrec_bestday*) calloc(Num_eph_grh_pts+1,sizeof(struct Futureposrec_bestday)))  == NULL) {
//        rkabort("future.c  not enough memory for calloc Eph_buf_bestday");
//      }
//  }

}  

void free_eph_space(void)
{
  free(Eph_buf);    Eph_buf    = NULL;
  free(Grhdata);    Grhdata    = NULL;
  free(Grh_colnum); Grh_colnum = NULL;

//  if(strcmp(gbl_instructions,  "return only day stress score") == 0)
  if(strcmp(gbl_instructions,  "return only day stress score_B") == 0)
  {
    free(Eph_buf_bestday);  Eph_buf_bestday = NULL;
    free(Grhdata_bestday);  Grhdata_bestday = NULL;
  }
}


#ifdef PUT_BACK_COMMENTED_OUT_STUFF /****************************************/
/*   void open_eph_file(int year)
* {
*     char eph_pathname[SIZE_INBUF+1];
*     ;
*     sfill(&eph_pathname[0],SIZE_INBUF,' ');
*     sprintf(&eph_pathname[0],"%s%s%d",
*       DIR_FOR_EPH_FILES,
*       (Is_past)? "p": "f",
*       year);
* 
*     if ((Fp_an_eph_file = fopen( &eph_pathname[0] ,READ_MODE_BINARY)) == NULL) {
*       rkabort("future.c. open_eph_file().");
*     }
* } 
*/
#endif /* ifdef PUT_BACK_COMMENTED_OUT_STUFF ********************************/


#ifdef PUT_BACK_COMMENTED_OUT_STUFF /****************************************/
/*   void close_eph_file(void)
*   {
*     *     fclose(Fp_an_eph_file); *
*   }
* 
*   void get_ctrl_rec_stuff(void)
*   {
*     * read_eph(&mar_to_plu,0);  * ctrl rec * *
*     * OLD Eph_rec_every_x_days = mar_to_plu.positions[2]; *
*     Eph_rec_every_x_days = STEP_SIZE_FOR_FUT;
* 
* *     Eph_file_beg_mn = mar_to_plu.positions[3];
* *     Eph_file_beg_dy = mar_to_plu.positions[4];
* *     Eph_file_beg_yr = mar_to_plu.positions[5];
* *
* 
*   }
*/
#endif /* ifdef PUT_BACK_COMMENTED_OUT_STUFF ********************************/


/* puts into str s "from m,d,y to m,d,y +step" */
/* e.g. "from 03sep84 to 15dec85" */
void sput_date_range(char *s, int m, int d, int y, int step)
{
//trn("in sput_date_range");
//kin(m);
//kin(d);
//kin(y);
//kin(step);
  char sdate1[NUM_CHAR_DATE_RANGE+1],sdate2[NUM_CHAR_DATE_RANGE+1];
  double mn,dy,yr;
  ;
  sfill(sdate1,NUM_CHAR_DATE_RANGE,' ');
  sfill(sdate2,NUM_CHAR_DATE_RANGE,' ');
  sprintf(sdate1,"from %3s %02d, %04d", N_mth_cap[m], d, y);

  mn = (double)m;  dy = (double)d;  yr = (double)y;
  mk_new_date(&mn,&dy,&yr,(double)step);

  sprintf(sdate2," to %3s %02d, %04d",
           N_mth_cap[(int)mn], (int)dy, (int)y);

  strcpy(s,strcat(sdate1,sdate2));
}

/* populate 3 strings  Grh_bottom_array at graph bottom. Look like this:
*   (size 99 chars  with 7 chars in lf_mar[] )
*       |   |    |     |    |    |   |    |    |     |   |    |     |   |    |     |    |    |    |    |    
*       |   10   20    |    11   21  |    11   21    |   10   20    |   10   20    |    11   21   |    11   
*  2013 jan            feb           mar             apr            may            jun            jul       
*    #define SIZE_GRH_LEFT_MARGIN 7
*    #define SIZE_EPH_GRH_LINE 107
*    #define NUM_PTS_FOR_FUT 92
*    #define NUM_GRH_BOTTOM_LINES 3
*  char Grh_bottom_line1[SIZE_EPH_GRH_LINE+1];  *  +1 for \0*
*/
void mk_grh_bottom(double mn,double dy,double yr)
{
  double dstep;
  int ibot;
  char mywk[SIZE_EPH_GRH_LINE + 1];
  ;
/* trn("in mk_grh_bottom(double mn,double dy,double yr"); */

  /* populate lines with blanks into Grh_bottom_line s
  */
  if (Num_eph_grh_pts == NUM_PTS_WHOLE_YEAR) {  // do big graph
    sfill(mywk, NUM_PTS_WHOLE_YEAR, ' ');  /* line size without left margin */
    strcpy(Grh_bottom_line1BIG, mywk); 
    strcpy(Grh_bottom_line2BIG, mywk); 
    strcpy(Grh_bottom_line3BIG, mywk); 

  } else {
    sfill(mywk, NUM_PTS_FOR_FUT, ' ');  /* line size without left margin */
    strcpy(Grh_bottom_line1, mywk); 
    strcpy(Grh_bottom_line2, mywk); 
    strcpy(Grh_bottom_line3, mywk); 
  }

/* trn("------- after init bottom lines:");
* ksn(Grh_bottom_line1);
* ksn(Grh_bottom_line2);
* ksn(Grh_bottom_line3);
*/

  put_grh_scale_dates(0,(int)mn,(int)dy,(int)yr);  /* 1st column */

  for (ibot=1; ibot <= Num_eph_grh_pts-1; ibot++) {  /* 1= start with 2nd col */

    dstep = (double)(Eph_rec_every_x_days);
    mk_new_date(&mn,&dy,&yr,dstep);

    put_grh_scale_dates(ibot,(int)mn,(int)dy,(int)yr);
  }
} /* end of mk_grh_bottom(double mn,double dy,double yr) */


/* put_grh_scale_dates()
* 
*       |   |    |     |    |    |   |    |    |     |   |    line 1
*       |   10   20    |    11   21  |    11   21    |   10   line 2
*  2013 jan            feb           mar             apr      line 3
*---------------------------------
*         1         2         3   
*123456789 123456789 123456789 123
*---------------------------------
*/
void put_grh_scale_dates(int col,int mn,int dy,int yr)
{ 

  /* on "J" in january, put 2 scale mark chars
  * also, no "sideline out" on these
  *       if (global_flag_which_graph != 1) {  * leave pipes on "J" in Jan *
  */
  if (global_flag_which_graph == 1 && col == 0) {
    put_scale_mark_char(col,1);
    put_scale_mark_char(col,2);
  }


/*   if (global_flag_which_graph == 2  &&  times_thru3 == 0) { */
/*     times_thru3++; */

  /* add scale_mth (jul) on first star of second graph
  */
  if (global_flag_which_graph == 2 && is_first_put_grh_scale_dates == 1) {
    is_first_put_grh_scale_dates = 0;
    put_scale_mth(col,mn);
    return;
  }

  if (dy >= 1  &&  dy <= Eph_rec_every_x_days) { /* beg of new mth */
    if(mn == 1) {      /* beg of january */
      if(col == 0) {  /* 1st column */
        /* jan wrt only when beg of line */
/*         put_scale_mth(col,mn); */
        put_scale_mth(col,mn);  /* jan wrt only when beg of line */
        return;
      }
      put_scale_yr(col,yr);  /* wrt yr instead of jan */
      return;
    }
    put_scale_mth(col,mn);    /* wrt mth */
    return;
  }
  if (Is_past) return;  /* don't put 10, 20 */
  if (dy >= 10  &&  dy <= 10 + (Eph_rec_every_x_days-1)) {
    put_scale_dy(col,dy);
    return;
  }
  if (dy >= 20  &&  dy <= 20 + (Eph_rec_every_x_days-1)) {
    put_scale_dy(col,dy);
    return;
  }
}  /* put_grh_scale_dates() */


void put_scale_mth(int col,int mn)
{
  int line, len;
  ;
  line = 2;  /* fut */
  if (Is_past) line = 1;

  put_scale_mark_char(col,1);

  if (Is_past == 0) put_scale_mark_char(col,2);


  if (col >= Num_eph_grh_pts-1-1) return; { /* no room on line */

/*   for (i=1; i <= 3; ++i) {  * eg  3= jan feb * */
/*     *(Date_array+line*SIZE_EPH_GRH_LINE+col+(i-1)) = *(N_mth[mn]+(i-1)); */
/*   }    * ^on 3rd bottom line (line = 2) */

  /* put month names */
  /* Jan, Feb etc */

/*  memcpy(Grh_bottom_line3 + col, N_mth[mn], 3);*/  /* jan, feb etc */
/*   memcpy(Grh_bottom_line3 + col, N_mth_cap[mn], 3);   */
  /* Thu 29 May 2014 12:09:27 EDT */
  /* Jan, Feb etc */
/*   memcpy(Grh_bottom_line3 + col, N_mth_allcaps[mn], 3);  */



 len = (int)strlen(N_allcaps_long_mth[mn]); 
/*  tn();kin(len);ksn(N_allcaps_long_mth[mn]);  */

  /* if it's going to be an overwrite put spaces
  *  (only happens for first mth name on line)
  */
  int current_beg_mth_write;
  current_beg_mth_write = col;
/* kin(current_beg_mth_write ); */
  if (current_beg_mth_write <= gbl_end_last_mth_write) {
/* trn("WRITE SPACES!"); */
    memcpy(Grh_bottom_line3 + gbl_beg_last_mth_write, "                             ", 25);  
  }

/*   memcpy(Grh_bottom_line3 + col, N_allcaps_long_mth[mn], len);   */
  memcpy(Grh_bottom_line3 + col+1, N_allcaps_long_mth[mn], len);  

  gbl_beg_last_mth_write = col;       /* beg col of mth name last written */
  gbl_end_last_mth_write = col + len - 1 ;/* end col of mth name last written */

/* ki(gbl_beg_last_mth_write); ki(gbl_end_last_mth_write); */


/* ksn("line3 after mth:");
* ki(strlen(Grh_bottom_line3));
* ksn(Grh_bottom_line3);
*/
  }  /* put month names */


} /* end of put_scale_mth() */


void put_scale_dy(int col,int dy)
{
  char s[3];
  ;
  put_scale_mark_char(col,1);
  sprintf(s,"%02d",dy);

/*   for (i=1; i <= 2; i++) { */
/*     *(Date_array+SIZE_EPH_GRH_LINE+col+(i-1)) = *(s+(i-1)); */
/*   } */

  memcpy(Grh_bottom_line2 + col, s, 2);   /* 10,11,20,21 */
/* ksn("line2 after day:");
* ki(strlen(Grh_bottom_line2));
* ksn(Grh_bottom_line2);
*/

} /* end of put_scale_dy() */


void put_scale_yr(int col,int yr)
{
  char s[5];
  ;
  put_scale_mark_char(col,1);
  put_scale_mark_char(col,2);

  
  /* with new 92 star graph, no room for next year
  */
  /*   return; */

  /* UNLESS col (max 92) is  <=89 (4 chars)
  */
  if (col > Num_eph_grh_pts - 3) return;

/*   sprintf(s,"%02d",(yr-(yr/100*100))); */
/*   for (i=1; i <= 4; i++) { */
/*     *(Date_array+2*SIZE_EPH_GRH_LINE+col+(i-1)) = *(s+(i-1)); */
/*   } */

  sprintf(s,"%04d",yr);

  memcpy(Grh_bottom_line3 + col, s, 4);   /* 2013 */
/* ksn("line3 after day:");
* ki(strlen(Grh_bottom_line3));
* ksn(Grh_bottom_line3);
*/
} /* end of put_scale_yr() */


void put_scale_mark_char(int col,int line) /* line is 1 or 2 */
{
/*   *(Date_array+(line-1)*SIZE_EPH_GRH_LINE+col) = SCALE_MARK_CHAR; */

  if(line == 1)  memcpy(Grh_bottom_line1 + col, "|", 1);  
  if(line == 2)  memcpy(Grh_bottom_line2 + col, "|", 1);  
/*   if(line == 1)  memcpy(Grh_bottom_line1 + col, "@", 1);   */
/*   if(line == 2)  memcpy(Grh_bottom_line2 + col, "@", 1);   */
}


/* for 1 6-month future
*/
void fill_eph_buf(void) 
{
/* trn(" in fill_eph_buf "); */
  /* init */
  gbl_beg_last_mth_write = 0; /* beg col of mth name last written */
  gbl_end_last_mth_write = 0; /* end col of mth name last written */
  set_grh_top_and_bot();

  fill_eph_buf_by_calc();   /* NEW NEW NEW NEW NEW NEW NEW NEW NEW */

}  /* end of fill_eph_buf() */


#ifdef PUT_BACK_COMMENTED_OUT_STUFF /****************************************/
/*   int j,eph_jd,grh_jd,eph_year_open;
*      top of  fill_eph_buf() 
*   long recnum,size;
*   ;
* 
*   eph_year_open = Grh_beg_yr;
*   eph_jd = (int)day_of_year((double)Eph_file_beg_yr,
*                 (double)Eph_file_beg_mn,
*                 (double)Eph_file_beg_dy);
*   grh_jd = (int)day_of_year((double)Grh_beg_yr,
*                 (double)Grh_beg_mn,
*                 (double)Grh_beg_dy);
*   for (recnum=1, j=eph_jd; j < grh_jd; ++recnum) {
*     j += Eph_rec_every_x_days;
*   }
*   recnum = recnum-1;    * the for goes one past the target *
*   if (grh_jd <= eph_jd) recnum=1;  * don't open eph file yr before *
*/
#endif /* ifdef PUT_BACK_COMMENTED_OUT_STUFF ********************************/

#ifdef PUT_BACK_COMMENTED_OUT_STUFF /****************************************/
/*  ***
*      bot of  fill_eph_buf() 
*   fiseek(Fp_an_eph_file,(recnum-1)*size); * skip to right eph file record *
*   ***
*   size = sizeof(struct Futureposrec);  * num char in an eph file record *
*   fseek(Fp_an_eph_file,(recnum-1)*size,SEEK_CUR);
*     * skip to the right eph file record *
* 
*   for (k=1; k <= Num_eph_grh_pts; k++) {
*     if (read_eph(Eph_buf,k) == 0) {  * 0 = eof *
*       close_eph_file();
*       open_eph_file(++eph_year_open);
*       get_ctrl_rec_stuff();  * skip ctrl rec *
*       if (read_eph(Eph_buf,k) == 0)
*         rkabort("future.c. fill_eph_buf().");
*     }
*   }
*/
#endif /* ifdef PUT_BACK_COMMENTED_OUT_STUFF ********************************/


/* Instead of the commented out stuff below with pre-calc eph files,
*  call calc_chart() Num_eph_grh_pts times and fill in 
*  Eph_buf, which is defined as ptr to struct Futureposrec:
*
*    struct Futureposrec *Eph_buf;   * ptr to current buffer for /eph file *
*
*  and which was calloc'd like this: 
*
*    Eph_buf = (struct Futureposrec*)calloc(Num_eph_grh_pts+1, sizeof(struct Futureposrec))
*
*        (add one for zeroth (ctrl) rec) 
*        
*  Futureposrec (for mar -> plu) is this:      
*
*    struct Futureposrec {int positions[NUM_PLANETS_IN_EPH_FILES];};
*
*
*  Eph_buf ACCESS -   Eph_buf[k].positions[m] 
*                 or
*                    (Eph_buf+k)->positions[m]
*
* 2 other tables calloc'd in get_future_data(),
* both for size= Num_eph_grh_pts  ints
*   int *Grhdata; 
*   int *Grh_colnum;
*/
void fill_eph_buf_by_calc(void)
{
  double m,d,y,step;
  int grh_pt, idx , minits;
  /*   int testmoon, testsun, testidx; */

  /* init */
  gbl_beg_last_mth_write = 0; /* beg col of mth name last written */
  gbl_end_last_mth_write = 0; /* end col of mth name last written */

  step = (double) Eph_rec_every_x_days;

  /* init first day to calc */
  m = (double) Grh_beg_mn;
  d = (double) Grh_beg_dy;
  y = (double) Grh_beg_yr;


  /* for all pts in one graph  -------------------------------------
  */
  for (grh_pt=1; grh_pt <= Num_eph_grh_pts; grh_pt++) {

    /* if ( grh_pt % 10 == 0) {
    *   trn("every 10"); ki(grh_pt); kd(y);kd(m);kd(d); ki(testsun);
    * }
    */

    /* calculate planetary positions for 12:01 pm on given day
    * 
    * for 12:01 pm - have to put 0.0 for arg 4 (hr)
    * 
    * calc_chart(m,d,y,12.0,1.0,1.0,0.0,0.0,0.0);
    */
    calc_chart(m,d,y,0.0,1.0,1.0,0.0,0.0,0.0);/* calcchrt.c wants 0 for hr=12*/

    /* put mar (0) to plu (5)  positions into   ------------
    *  Eph_buf Futureposrec struct member positions
    */
    for (idx=0; idx <= NUM_PLANETS_FOR_FUTURE-1; ++idx) { 
      /* testsun = get_minutes(Arco[1]);
      * testmoon = get_minutes(Arco[10]);
      * testidx = grh_pt;
      */
      /* double Arco[14];        positions  are in following order:
      *     xxx,sun,mer,ven,mar,jup,sat,ura,nep,plu,moo,nod,asc,mc_
      * index 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13
      *                       x                          
      */

      minits = get_minutes(Arco[idx + 4]);
      (Eph_buf + grh_pt)->positions[idx] = minits;   /* <=== */
    }



/* put every day, not every 2 ! */


    /* if necessary, put positions of _bestday transiting planets sun,mer,ven,moo
    *  into Eph_buf_bestday
    */
//    if(strcmp(gbl_instructions,  "return only day stress score") == 0) {
//b(66);
//
//      for (idx=1; idx <= 3; ++idx) {   /*  sun,mer,ven  (in Arco) */
//        /* double Arco[14];        positions  are in following order:
//        *     xxx,sun,mer,ven,mar,jup,sat,ura,nep,plu,moo,nod,asc,mc_
//        * index 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13
//        *                       x                          
//        */
//        minits = get_minutes(Arco[idx]);
//        (Eph_buf_bestday + grh_pt)->positions[idx-1] = minits;   /* <=== */
//
///*  */
///* if (idx == 1) { */
///* int mydeg; mydeg = (Eph_buf_bestday + grh_pt)->positions[idx-1] / 60; */
///* int mysgn; mysgn = (mydeg / 30) + 1; */
///*            mydeg = mydeg - ((mysgn - 1) * 30); */
///*  kin(grh_pt);ki(mysgn);ki(mydeg);  */
///* } */
//
//
//      }
//      minits = get_minutes(Arco[10]);   /* Arco [10] = moon, positions [3] = moon */
//      (Eph_buf_bestday + grh_pt)->positions[3] = minits;   /* <=== */
//
//
//    }
//

    mk_new_date(&m,&d,&y,step);

  }  /* for all pts in one graph */

  /* kin(testidx); ki(testsun); ki(testmoon); */

} /* end of fill_eph_buf_by_calc() */



void set_grh_top_and_bot(void)
{
#ifdef PUT_BACK_COMMENTED_OUT_STUFF /****************************************/
/*   double dmn,ddy,dyr,dstep;
*   ;
*   dmn = (double)Eph_file_beg_mn;
*   ddy = (double)Eph_file_beg_dy;
*   dyr = (double)Eph_file_beg_yr;
*   dstep = (double)(recnum*Eph_rec_every_x_days);
* 
*   mk_new_date(&dmn,&ddy,&dyr,dstep);
* 
*   Grh_beg_mn = (int)dmn;  * prev grh_beg date was arg date *
*   Grh_beg_dy = (int)ddy;  * now it jogs with eph date *
*   Grh_beg_yr = (int)dyr;  * e.g. fut dates are on Wed *
*/
#endif /* ifdef PUT_BACK_COMMENTED_OUT_STUFF ********************************/

  if (is_first_set_grh_top_and_bot == 1) {
    is_first_set_grh_top_and_bot = 0;

    /*     Grh_beg_mn = 1; */
    /*     Grh_beg_dy = 1;  */

// NO  privacy  20150211  can infer birth info
//    /* get month and day to start the first graph
//    */
//    if (strcmp(year_in_the_life_todo_yyyy, year_of_birth) == 0) {
//      Grh_beg_mn = atoi(mth_of_birth);
//      Grh_beg_dy = atoi(day_of_birth); 
//    } else {
//      Grh_beg_mn = 1;
//      Grh_beg_dy = 1; /*  old was 2 */
//    }
//
      Grh_beg_mn = 1;
      Grh_beg_dy = 1; /*  old was 2 */

    Grh_beg_yr =  atoi(year_in_the_life_todo_yyyy);

  }  else {
    ;  /* start date for 2nd graph was set at the top of do_future() */
  }

  sput_date_range(
    &Grh_title_dates[0],
    Grh_beg_mn,
    Grh_beg_dy,
    Grh_beg_yr,
    (Num_eph_grh_pts-1) * Eph_rec_every_x_days
  );

  if (Num_eph_grh_pts == NUM_PTS_WHOLE_YEAR) {  // do big graph
    mk_BIGgrh_bottom((double)Grh_beg_mn,(double)Grh_beg_dy,(double)Grh_beg_yr);
  } else {
    mk_grh_bottom((double)Grh_beg_mn,(double)Grh_beg_dy,(double)Grh_beg_yr);
  }

} /* end of  set_grh_top_and_bot() */


#ifdef PUT_BACK_COMMENTED_OUT_STUFF /****************************************/
* /* offset= which rec to read e.g. &mar_to_plu+3 is the 4th */
* /* mar_to_plu record */
* int read_eph(struct Futureposrec *pbuf,int offset)
* {
*   int size;
*   struct Futureposrec *p = pbuf;
*   ;
*   size = sizeof(struct Futureposrec);
*   if (fget(p+offset,size,Fp_an_eph_file) < size)
*     return(0);
*   else 
*     return(1);
* }
#endif /* ifdef PUT_BACK_COMMENTED_OUT_STUFF ********************************/


/* ****************  more on do_grh_calcs_and_prt()
*             &&  (k % FUT_GRH_PT_EVERY_X_RECS) == 0) { 
* above line taken out of the if since it's true in all foreseeable circumstances
*   do_future(ptr to beg of fut pos structs)
*   for (each trn plt - mar thru plu)
*     for (each fut day - 1 thru 6 months worth of days) right now, 
*       for (each natal plt - sun thru plu)    1 rec = 1 day
*         is_aspect(1 between this trn plt
*               2 on this fut day
*               3 and this natal plt
*               4 using these orbs )
*         keep_track() of aspects as we go along in the running_table
*         if (there is an aspect  and  day is even)
*           do fut graph calculations
*/
void do_grh_calcs_and_prt(void)
{
trn("in do_grh_calcs_and_prt()");

// did not work
//kin( Num_eph_grh_pts);
//  Num_eph_grh_pts = 183;  // try fix
//kin( Num_eph_grh_pts);

  int itrn_plt, inatal_plt, iday_num, aspect_num ;
  int starting_natal_plt;
/*   int do_world_affairs_nat_plts; */
/*   int minutes_difference; */

  starting_natal_plt = 1;  /* set default */

//trn("printing P_asp_tbl[]  a");
//prt_asp_tbl();

    // fyi
    //  char *N_planet[]     = {"   ","sun","moo","mer","ven","mar","jup","sat","ura","nep","plu", "nod","asc","mc_"};
    //  char *N_trn_planet[] = {"   ","jup","sat","ura","nep","plu","mar"};
    //  char *N_aspect[]     = {"   ","cnj","sxt","squ","tri","opp","tri","squ","sxt","cnj"};

  /* do REGULAR TRANSITING PLANETS  mar,jup,sat,ura,nep,plu
  */
  for (itrn_plt=1; itrn_plt <= NUM_PLANETS_IN_EPH_FILES; ++itrn_plt)       /* trn_plt */  // NUM_PLANETS_IN_EPH_FILES = 6
  {
    for (iday_num=1; iday_num <= Num_eph_grh_pts; ++iday_num)              /* day_num (every 2 days)  jan 1, jan 3, ...  1->183/4 */
    {

/*  for test ! */
/* if (itrn_plt == 1) {  */
/* int mydeg; mydeg = (Eph_buf+ iday_num)->positions[itrn_plt-1] / 60; */
/* int mysgn; mysgn = (mydeg / 30) + 1; */
/*            mydeg = mydeg - ((mysgn - 1) * 30); */
/*  kin(iday_num);ki(mysgn);ki(mydeg);  */
/* } */



          /* in double Arco[14];  natal positions  are in following order:
          *     xxx,sun,mer,ven,mar,jup,sat,ura,nep,plu,moo,nod,asc,mc_
          * index 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13
          *
          *    BUT in Ar_minutes_natal[] ,
          * Ar_minutes_natal[1]   sun
          * Ar_minutes_natal[2]   moo
          * Ar_minutes_natal[3]   mer
          * Ar_minutes_natal[4]   ven
          * Ar_minutes_natal[5]   mar
          * Ar_minutes_natal[6]   sat
          * Ar_minutes_natal[7]   jup
          * Ar_minutes_natal[8]   ura
          * Ar_minutes_natal[9]   nep
          * Ar_minutes_natal[10]  plu
          * Ar_minutes_natal[11]  nod
          * Ar_minutes_natal[12]  asc
          * Ar_minutes_natal[13]  mc_
          */
      /* ordinary run  does natal plts 1-10  sun,moo,mer,ven,mar,jup,sat,ura,nep,plu
      *  world affairs does natal plts 5-10                  mar,jup,sat,ura,nep,plu
      */
/*       do_world_affairs_nat_plts = 1;
*       if (do_world_affairs_nat_plts == 1) starting_natal_plt = 5;
*/

      /* for (inatal_plt=1; inatal_plt <= NUM_PLANETS; ++inatal_plt) lb  */
      /*  (NUM_PLANETS is 10) */
      for (inatal_plt=starting_natal_plt; inatal_plt <= NUM_PLANETS; ++inatal_plt)      // NUM_PLANETS = 10
      {
        
/*         if (do_world_affairs_nat_plts == 1) {
*           Ar_minutes_natal[ 5] = (Eph_buf+iday_num)->positions[ 0];
*           Ar_minutes_natal[ 6] = (Eph_buf+iday_num)->positions[ 1];
*           Ar_minutes_natal[ 7] = (Eph_buf+iday_num)->positions[ 2];
*           Ar_minutes_natal[ 7] = (Eph_buf+iday_num)->positions[ 3];
*           Ar_minutes_natal[ 9] = (Eph_buf+iday_num)->positions[ 4];
*           Ar_minutes_natal[10] = (Eph_buf+iday_num)->positions[ 5];
*         }
*/


/* trn_plt  why = 1 and not zero  test result -> leave it */
/*           abs((Eph_buf+iday_num)->positions[itrn_plt-1] - Ar_minutes_natal[inatal_plt]), */

        aspect_num = isaspect(
          abs((Eph_buf+iday_num)->positions[itrn_plt] - Ar_minutes_natal[inatal_plt]),
          (inatal_plt-1)*(NUM_ASPECTS+1)
        );

        do_rt(inatal_plt, aspect_num, itrn_plt, iday_num); /* keep_track() of aspects as we go along in the running_table */
        // also populate dbASP
        // also populate aspect_IMPACT_data

        if(aspect_num != 0) {   /* add_aspect_to_grhdata() */ 
          add_aspect_to_grhdata(inatal_plt, aspect_num, itrn_plt, iday_num);
        }
      } /* natal_plt */
    } /* day_num in 6 months of graph */
  } /* trn_plt */


//qxqx

trn("END of populating P_asp_tbl");


//
//// for test  show all of P_asp_tbl
//trn("");
//trn("for test show all of P_asp_tbl");
//for (int ia=0; ia <= Asp_tbl_idx; ++ia) { 
//ki(ia);ksn(P_asp_tbl[ia]);  
//}
//trn("all of P_asp_tbl");
//trn("");
//
//trn("");
//trn("all33of P_asp_tbl  at END of populating P_asp_tbl");
//char tstfrom[32];
//char tstto[32];
//char tstnp[32];
//char tstasp[32];
//char tsttp[32];
//char tst128c[128];
//for (int ib=0; ib <= Asp_tbl_idx; ++ib) { 
////extern char *sfromto(char *dest,char *src, int beg, int end);
//sfromto(tstfrom,P_asp_tbl[ib], 1, 8);
//sfromto(tstnp  ,P_asp_tbl[ib], 9,10);
//sfromto(tsttp  ,P_asp_tbl[ib],11,12);
//sfromto(tstasp ,P_asp_tbl[ib],13,14);
//sfromto(tstto,  P_asp_tbl[ib],15,22);
//
//sprintf(tst128c, "%s_%s_%s  %s to %s  asp=%s",
//  N_planet[atoi(tstnp)], N_aspect[atoi(tstasp)], N_trn_planet[atoi(tsttp)], tstfrom, tstto, tstasp);
//ksn(tst128c);
//}
//trn("all33of P_asp_tbl  at END of populating P_asp_tbl");
//trn("");
////  char *N_planet[]     = {"   ","sun","moo","mer","ven","mar","jup","sat","ura","nep","plu", "nod","asc","mc_"};
////  char *N_trn_planet[] = {"   ","jup","sat","ura","nep","plu","mar"};
////  char *N_aspect[]     = {"   ","cnj","sxt","squ","tri","opp","tri","squ","sxt","cnj"};
//// for test
//
//




//trn("printing P_asp_tbl[]  z");
//prt_asp_tbl();


//  if(strcmp(gbl_instructions,  "return only day stress score") == 0) {
//b(67);
//
///* tn();ksn(gbl_csv_person_string); tn(); */
//    /* do BESTDAY TRANSITING PLANETS  sun,mer,ven,moo
//    */
//    /* #define NUM_PLANETS_TRN_BESTDAY 4      4 sun,mer,ven,mo10,mo01,mo04,mo07 */
//    for (itrn_plt=0; itrn_plt <= NUM_PLANETS_TRN_BESTDAY-1; ++itrn_plt) {  /* 0->3 */
//
//      for (iday_num=1; iday_num <= Num_eph_grh_pts; ++iday_num)      {   /* day_num */
//
//            /* in double Arco[14];  natal positions  are in following order:
//            *     xxx,sun,mer,ven,mar,jup,sat,ura,nep,plu,moo,nod,asc,mc_
//            * index 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13
//            *
//            *    BUT in Ar_minutes_natal[] ,
//            * Ar_minutes_natal[1]   sun
//            * Ar_minutes_natal[2]   moo
//            * Ar_minutes_natal[3]   mer
//            * Ar_minutes_natal[4]   ven
//            * Ar_minutes_natal[5]   mar
//            * Ar_minutes_natal[6]   sat
//            * Ar_minutes_natal[7]   jup
//            * Ar_minutes_natal[8]   ura
//            * Ar_minutes_natal[9]   nep
//            * Ar_minutes_natal[10]  plu
//            * Ar_minutes_natal[11]  nod
//            * Ar_minutes_natal[12]  asc
//            * Ar_minutes_natal[13]  mc_
//            */
//
//            /* TRANSITING PLT POSITIONS  in Eph_buf_bestday
//            *  struct Futureposrec_bestday{   * NEW *
//            *  int positions[NUM_PLANETS_TRN_BESTDAY];   * 4 sun,mer,ven,mo10,mo01,mo04,mo07 
//            *                                          index   0   1   2   3    4    5    6
//            *  };
//            */
//
//        /*  (NUM_PLANETS is 10) */
//        for (inatal_plt=1; inatal_plt <= NUM_PLANETS; ++inatal_plt) {
//
//          aspect_num = isaspect(
//            abs((Eph_buf_bestday+iday_num)->positions[itrn_plt] - Ar_minutes_natal[inatal_plt]),
//            (inatal_plt-1)*(NUM_ASPECTS+1)
//          );
//
//
//          /* show aspects for a trn_plt
//          */
//          /*  test if isaspect works */
//          /*  for test ! */
//          /* if (itrn_plt == 3 && aspect_num != 0) {  */
//          /* int mydeg; int mysgn; char myasp[8]; */
//          /* mydeg = (Eph_buf_bestday+iday_num)->positions[itrn_plt] / 60; */
//          /* mysgn = (mydeg / 30) + 1; */
//          /* mydeg = mydeg - ((mysgn - 1) * 30); */
//          /* strcpy(myasp, N_aspect[aspect_num]); */
//          /* ksn(myasp);tr("  trn");ki(iday_num); ki(itrn_plt);ki(mysgn);ki(mydeg);  */
//          /* mydeg = Ar_minutes_natal[inatal_plt] / 60; */
//          /* mysgn = (mydeg / 30) + 1; */
//          /* mydeg = mydeg - ((mysgn - 1) * 30); */
//          /* tr("   nat");ki(inatal_plt);ki(iday_num);ki(mysgn);ki(mydeg);  */
//          /* } */
//
//
//          if(aspect_num != 0) {   /* add_aspect_to_grhdata() */ 
//            add_aspect_to_grhdata_bestday(inatal_plt, aspect_num, itrn_plt, iday_num);
//          }
//
//        } /* natal_plt */
//      } /* day_num in 6 months of graph */
//    } /* trn_plt */
//
///* here grab return value for new calendar day rpt */
//
//
//  } /*   if(strcmp(gbl_instructions,  "return only day stress score") == 0)  */
//


trn("calling do_grhs()");
  do_grhs();   /*  qqq   print graph  */

trn("back from do_grhs()");
kin(gbl_yearStressScoreIsDone);


  if (gbl_yearStressScoreIsDone == 1) {
trn("ss 02  gbl_yearStressScoreIsDone == 1  RETURN from    do_grh_calcs_and_prt()    after do_grhs(); ");
    return;   // can return  if(strcmp(gbl_instructions,  "return only year stress score") == 0) 
  }





//   show all grhdata_bestday
//       *(Grhdata+igrh*Num_eph_grh_pts+n) /= SIZE_EPH_GRH_INCREMENT;
//       this_num = *(Grhdata+igrh*Num_eph_grh_pts+n);
//#ifdef PUT_BACK_COMMENTED_OUT_STUFF /****************************************/
// static int mytimes; mytimes++;
//   double dmn,ddy,dyr,dstep;
//     dstep = (double)(Eph_rec_every_x_days);
//     dmn = (double) Fut_start_mn;
//     ddy = (double) Fut_start_dy;
//     dyr = (double) Fut_start_yr;
// if (mytimes == 2 ) mk_new_date(&dmn,&ddy,&dyr,dstep+92*2-2);
// 
// for (iday_num=1; iday_num <= Num_eph_grh_pts; ++iday_num) {
// 
// fprintf(stderr,"%s|%d|%04d|%02d|%02d|%d|\n",  fEvent_name, iday_num,
//     (int)dyr,
//     (int)dmn,
//     (int)ddy,
//     *(Grhdata_bestday + (iday_num-1) )
// );
// 
//     mk_new_date(&dmn,&ddy,&dyr,dstep);
// }
//#endif /* ifdef PUT_BACK_COMMENTED_OUT_STUFF ********************************/
//
//   show all grhdata_bestday 
 trn("at end of do_grh_calcs_and_prt()");
} /* void do_grh_calcs_and_prt(void) */



/* more on is_aspect() 
* 
*   double Current_aspect_force  (0.0 THRU 1.0) *
*         ( pi     orb_in_minutes - diff_from_exact  )
*     sin ( --   x --------------------------------  )
*         ( 2        orb_in_minutes                  )
* 
*   note: sin(pi/2) = 1
*   defined in isaspect(), used in add_aspect_to_grhdata()
* 
*
* mdiff= diff in minutes of planets 1 and 2 
* subscript for right row in beg_aspect_ranges[]
*                     and in end_aspect_ranges[]
*/
int isaspect(int mdiff,int right_row)
{
  int iasp;
  int *p = Beg_aspect_ranges;
  int *q = End_aspect_ranges;
  double dorb;
  ;
  for (iasp=1; iasp <= NUM_ASPECTS; ++iasp) {

    if (mdiff > *(q+right_row+iasp)) continue;   /*keeplooking*/
    if (mdiff < *(p+right_row+iasp)) return(0);  /*noaspect*/

    dorb = (double) ( (*(q+right_row+iasp) - *(p+right_row+iasp)) / 2 );     /* (a-b)/2 */


/* int mydiff; mydiff = (*(Aspects+iasp)-mdiff); */
/* int mya,myb; */
/* mya = *(Aspects+iasp); */
/* myb = mdiff; */
/* kdn(dorb); */
/* ki(mya);ki(myb); ki(mydiff); */


    Current_aspect_force = sin(fPI_OVER_2 * (dorb - fabs((double)(*(Aspects+iasp) - mdiff)) ) / dorb);

    return(Aspect_id[iasp]);  /* found aspect */
  }
  return(0);    /* return of zero means no aspect found */

}  /* end of isaspect() */



/* Arco array is from calc_chart().
*     Arco `coordinates' are in following order: 
*     xxx,sun,mer,ven,mar,jup,sat,ura,nep,plu,moo,nod,asc,mc_
*     positions are in radians
*
* void put_minutes(int *pi) 
*   puts positions in minutes 0 thru 360*60-1
*   into a planet position table
*   
*   pi arg  is ptr to ints (position table #1 or #2) 
*/
      /* double Arco[14];        positions  are in following order:
      *     xxx,sun,mer,ven,mar,jup,sat,ura,nep,plu,moo,nod,asc,mc_
      * index 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13
      */
void put_minutes(int *pi) 
{
  int imin;
  ;
  *(pi+1) = get_minutes(Arco[1]);    /* sun */
  *(pi+2) = get_minutes(Arco[10]);  /* moon */
  for (imin=3; imin <= NUM_PLANETS; ++imin) {  /* 3->10 (mer->plu) */
    *(pi+imin) = get_minutes(Arco[imin-1]);
  }
  *(pi+11) = get_minutes(Arco[11]);  /* nod */
  *(pi+12) = get_minutes(Arco[12]);  /* asc */
  *(pi+13) = get_minutes(Arco[13]);  /* mc_ */

#ifdef PUT_BACK_COMMENTED_OUT_STUFF /****************************************/
*   Prt_retro[1] = Retro[1];  /* these array elements are strings */
*   Prt_retro[2] = Retro[10];  /* moon */
*   for (i=3; i <= NUM_PLANETS; ++i) {  /* 3->10 */
*     Prt_retro[i] = Retro[i-1];
*   }
*   Prt_retro[11] = Retro[11];
*   Prt_retro[12] = Retro[12];
*   Prt_retro[13] = Retro[13];
#endif /* ifdef PUT_BACK_COMMENTED_OUT_STUFF ********************************/
}  /* end of put_minutes() */

int get_minutes(double d)
{
  /***
  return((int)round(60.0 * fnu(fnd(d) + 360.0)));  * converted to int *
  ***/
  return((int)ceil(60.0 * fnu(fnd(d) + 360.0)));  /* converted to int */
} 

/* add_aspect_to_grhdata()  fills in Grhdata[][] 
*
*  this function is called for each day in the year
*
*
* Integral to following fn are defines in as_defines.h
*       for f_get_plt_in_12() and get_aspect_multiplier
*    #define f_get_plt_in_12(i,k,m) (*(f_Plt_in_12+\
*/
void add_aspect_to_grhdata(int nat_plt,int aspect_num,int trn_plt,int day_num) 
{
  int ical;
  int addval;
  double a,b,c,d,e;
  double my_sav_maxAspForce;
  char myDBstrPREV[2048];
  char myDBstrCURR[2048];
  strcpy(myDBstrPREV, "init myDBstrPREV");
  ;
/* trn("add_aspect_to_grhdata(int nat_plt,int aspect_num,int trn_plt,int day_num) "); */

  // NOTE: add_aspect_to_grhdata() fn is called ONLY IF there is an aspect

  if (Moon_confidence == 0
    &&  nat_plt == NAT_PLT_NUM_FOR_MOON)  return;

  for (ical=0; ical <= NUM_HOUSES_CONSIDERED - 1; ++ical) {  /* NUM_HOUSES_CONSIDERED = 1 */

    a = (double)(f_get_plt_in_12(
      nat_plt-1,
      get_sign(Ar_minutes_natal[nat_plt])-1,
      ical)
    );

    if (House_confidence == 0)  b = a;
    else  b = (double)(f_get_plt_in_12(nat_plt-1,
            get_house(Ar_minutes_natal[nat_plt],
              Ar_minutes_natal[13]) -1, /*13=mc*/
            ical));

    c = (double)(
      f_get_plt_in_12(
        ((trn_plt == 6)? 5:trn_plt+5)-1,
        get_sign((Eph_buf+day_num)->positions[trn_plt]) -1,
        ical)
      );

    if (House_confidence == 0)  d = c;
    else  d = (double)(f_get_plt_in_12(((trn_plt == 6)? 5:trn_plt+5)-1,
            get_house((Eph_buf+day_num)->positions[trn_plt],
                  Ar_minutes_natal[13]) - 1, /*13=mc*/
            ical));

    e = (double)(get_aspect_multiplier(Aspect_type[aspect_num],
            trn_plt-1,
            nat_plt-1,
            ical));
         // FYI
         //
            //#define NUM_PLANETS 10 
            //#define NUM_ASPECTS 9
            //
            // fyi
              //      int Aspect_id[NUM_ASPECTS+1] =
              //                   {0,  1,   2,   3,   4,    5,    6,    7,    8  ,9};
              //              /* name x cnj  sxt  squ  tri   opp   tri   squ   sxt  cnj */
              //            /* degrees x  0  60   90   120   180   240   270   300  360 */
              //      int Aspects[NUM_ASPECTS+1]=
              //                    {-1,  0,3600,5400,7200,10800,14400,16200,18000,21600};
              //           /* degrees x   0  60   90   120   180   240   270   300  360 */
              //              /* name x cnj  sxt  squ  tri   opp   tri   squ   sxt  cnj */
              //
              //      int Aspect_type[NUM_ASPECTS+1] = {-1,  0,   1,   2,   1,    2,    1,    2,    1,    0};
              //       /* Aspect_type  0=cnj, 1=good, 2=bad (subscripts into aspect_multipier[]) */
              //
              //      /* size of angle between 2 plts for all aspects
              //      */
              //
              //      int Beg_aspect_ranges[(NUM_PLANETS)*(NUM_ASPECTS+1)];
              //      int End_aspect_ranges[(NUM_PLANETS)*(NUM_ASPECTS+1)];
              //
          // fyi
          //  char *N_planet[]     = {"   ","sun","moo","mer","ven","mar","jup","sat","ura","nep","plu", "nod","asc","mc_"};
          //  char *N_trn_planet[] = {"   ","jup","sat","ura","nep","plu","mar"};
          //  char *N_aspect[]     = {"   ","cnj","sxt","squ","tri","opp","tri","squ","sxt","cnj"};
          // fyi
          //    --------------- "/Users/rk/_PC/usr/apple/_c/_wrk/free/xfils/futdoc.h" --------------
          //    221:int Orb_trn_adj_for_nat[NUM_PLANETS+1] = {0,40,30,27,24,21,-20,0,-20,-25,-30};
          //
         //
         // FYI



//if (nat_plt == 2 && aspect_num == 1 && trn_plt == 1) 
//{
//trn("addval dbl");kd(myTstDbl);kdn(Current_aspect_force);
//if (myTstDbl == 0) trn("is zero");
//if (myTstDbl != 0) trn("is  not zero");
//if (myTstDbl  < 0) trn("is  < zero");
//if (myTstDbl  > 0) trn("is  > zero");
//}

    // for CONJUNCTIONS (1)  maintain  gbl_this_CNJ_is
    //
    double my_addvalDBL;
    if (aspect_num == 1) {

//      my_addvalDBL=  Current_aspect_force * Moon_confidence_factor * e * (sqrt(a*a+b*b)+sqrt(c*c+d*d));
//      if (my_addvalDBL < 0) strcpy(gbl_this_CNJ_is, "positive");
//      if (my_addvalDBL > 0) strcpy(gbl_this_CNJ_is, "negative");
//        // odd convention

      // new: 20210102  get "pos" and "neg" by consulting  Aspect_multiplier array
        //  char Aspect_multiplier  [
        //              NUM_ASPECT_TYPES*
        //              NUM_PLANETS_IN_EPH_FILES*       /* transiting plts jup,sat,ura,nep,plu,mar */
        //              NUM_PLANETS*
        //              NUM_HOUSES_CONSIDERED
        //  ]  = { ... }
        // this func  =  void add_aspect_to_grhdata(int nat_plt,int aspect_num,int trn_plt,int day_num) 
        //
        double myAspectMultiplier_val;
        myAspectMultiplier_val = (double)(get_aspect_multiplier(Aspect_type[aspect_num],
            trn_plt-1,
            nat_plt-1,
            0));
//tr("see am");kdn(myAspectMultiplier_val);
        if (myAspectMultiplier_val < 0) strcpy(gbl_this_CNJ_is, "positive");
        if (myAspectMultiplier_val > 0) strcpy(gbl_this_CNJ_is, "negative");
    }
    //
    // for CONJUNCTIONS (1)  maintain  gbl_this_CNJ_is




    addval = (int)(Current_aspect_force * Moon_confidence_factor * e * (sqrt(a*a+b*b)+sqrt(c*c+d*d)));





// for test    for test    for test    for test    for test    for test    for test    for test   
// for test    for test    for test    for test    for test    for test    for test    for test   
//
    // want to save FIRST           addval for each aspect period in P_asp_tbl
    // want to save biggest ABSVAL  addval for + or -
    // want to save LAST            addval for each aspect period in P_asp_tbl
    //
char  dbASP2[1024];
char *N_planet[] =
    {"   ","sun","moo","mer","ven","mar","jup","sat","ura","nep","plu",
     "nod","asc","mc_"};
char *N_trn_planet[] =  /* i think this should be xmjsunp (mars 1st) */
    {"   ","jup","sat","ura","nep","plu","mar"};
char *N_aspect[] =
    {"   ","cnj","sxt","squ","tri","opp","tri","squ","sxt","cnj"};
char *N_mth_cap[] =
    {"Mth","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
double d_mn;
double d_dy;
double d_yr;
double d_step;

    //no
    //    // fyi
    //    // k&r  /* set month, day  for jd=yearday in year */
    //    // k&r  void month_day(double year, double yearday, double *pmonth, double *pday)
    //    double pmonth;
    //    double pdayOfMonth;
    //    month_day(atof(year_in_the_life_todo_yyyy), (double)day_num, &pmonth, &pdayOfMonth );
    //

    // day_num = 1 is this date - Jan 01
      //
      //    Fut_start_mn = 1;
      //    Fut_start_dy = 1; /*  old was 2 */
      //

    // get current date  into d_mn, d_dy, d_yr
    //
    d_mn = (double) 1;
    d_dy = (double) 1;
    d_yr = (double) atoi(year_in_the_life_todo_yyyy) ;

    // day_num = 1 is this date - Jan 01
    // day_num = 2 is this date - Jan 03
    // day_num = 3 is this date - Jan 05
    // 
    d_step = (double)((day_num-1) * Eph_rec_every_x_days);  // every 2 days

    //  mk_new_date(double *pm, double *pd, double *py, double dstep)  
    mk_new_date(&d_mn, &d_dy, &d_yr, d_step);    /* add dstep days to previous date  mn/dy/yr */

//
//////rkt
//sprintf(dbASP2, "%s_%s_%s day_num %03d [%s%02d%02d] %s_%02d val=%05d ",
//  N_planet[nat_plt], N_aspect[aspect_num], N_trn_planet[trn_plt],
//  day_num,
//  year_in_the_life_todo_yyyy, (int)d_mn, (int)d_dy,
//  N_mth_cap[(int)d_mn], (int)d_dy,
//  addval 
//);
//
//if (aspect_num == 1) // 1=CNJ
//{ tr("addval time");ks(dbASP2); ksn(gbl_this_CNJ_is); }
//

//
//
// for test    for test    for test    for test    for test    for test    for test    for test   
// for test    for test    for test    for test    for test    for test    for test    for test   





    // use  addval to update amplitude data  gbl_PSV_of_AMPL_CSVs
    // unique key into gbl_PSV_of_SW_CSVs  is like  "sun_opp_jup!045"  (45 = beg day_num)
    //
    // do update ONLY IF planets are RPT planets --  those that are used for aspects on the screen
    // 
    char *RPT_PLTs_desc_nat[] = {"   ","sun","moo","mer","ven","mar"};
    char *RPT_PLTs_desc_trn[] = {"   ","jup","sat","ura","nep","plu"};
    int   ok_plt_nat = 0;
    int   ok_plt_trn = 0;
    for (int i=1; i <=5; i++) {
      if ( strcmp(N_planet[nat_plt]    , RPT_PLTs_desc_nat[i]) == 0)  ok_plt_nat = 1;
      if ( strcmp(N_trn_planet[trn_plt], RPT_PLTs_desc_trn[i]) == 0)  ok_plt_trn = 1;
    }
    if (    ok_plt_nat == 1
        &&  ok_plt_trn == 1 )
    {
//      update_this_SW_CSV(addval, nat_plt, aspect_num, trn_plt, day_num);   // <<<---------===

//      process_this_addval(addval, nat_plt, aspect_num, trn_plt, day_num);   // <<<---------===
//      add_aspect_addval_to_SW(addval, nat_plt, aspect_num, trn_plt, day_num);   // <<<---------===
//      add aspect_day_num_to_SW
//      add asp_day_num_to_SW
//      add addval_to_SW
//      SW_incorporate_addval 
//      SW_incorporate_this_addval 
//      incorporate_aspect_addval_to_SW
//      SW_incorporate_aspect_addval
//      SW_uses_aspect_addval
//      SW_affected_by_aspect_addval
//      aspect_addval_affects_SW
//      weave_aspect_addval_into_SW
//      merge_apect_addval_to_SW
//      add_an_aspect_addval_to_SW
//      add_aspect_addval_to_SW
//      update_SW_with_aspect_addval
//      change_SW_with_aspect_addval
//      change_SW_with_aspect
//      change_SW_data_with_aspect
//      change_SW_data_with_aspect_addval
//      mix_aspect_addval_into_SW
//      SW_uses_aspect_addval
//      change_SW_with_aspect_addval
//

      if (strcmp(gbl_instructions, "do Sine Wave data collection") == 0)
      {
        SW_uses_aspect_addval(addval, nat_plt, aspect_num, trn_plt, day_num);   // <<<---------===
      }
    }
    //
    //  in  gbl_PSV_of_SW_CSVs, this function could create   a brand new SW_CSV 
    //  in  gbl_PSV_of_SW_CSVs, this function could update   SW_amplitude_at_MAX  in an existing SW_CSV



    *(Grhdata + ical * Num_eph_grh_pts + (day_num-1) ) += addval;
  }

}  /* end of add_aspect_to_grhdata() */


// SW_uses_aspect_addval()
//
      //    FYI - like gbl_PSV_of_SW_CSVs
      //    sprintf(curr_SW_CSV,              // looks like   "sun_opp_jup,20200106,20200521,positive,00000,00655,00112"
      //      "%s_%s_%s,%03d,%03d,%s,%03d,%03d,%03d",
      //      N_planet[np], N_aspect[asp], N_trn_planet[tp],
      //      (int) dbl_SW_BEG_DayOfYear,
      //      (int) dbl_SW_END_DayOfYear,
      //      SW_amplitude_sign,            // "positive" or "negative" for sinewave amplitude
      //      SW_amplitude_at_BEG,
      //      SW_amplitude_at_MAX,
      //      SW_amplitude_at_END
      //    );                              // curr_SW_CSV about 32 chars
      //

      // FYI  gbl_PSV_of_SW_CSVs
      //
      // ksn(gbl_PSV_of_SW_CSVs); tn();
            //    FYI  looks like this:  last csv is ""
            //
            //    _doclin=[from Jan  1 to Feb  8 ^(mogur)]__
            //    _(fn_BIGaspect_from_to() in futhtm.c  --  this is updated after the end of each aspect is reached )__
            //    _gbl_PSV_of_SW_CSVs=[sun_opp_jup,001,005,positive,015,045,000|ven_opp_jup,081,193,positive,015,045,000|ven_opp_jup,317,341,positive,015,045,000|mar_opp_jup,361,366,positive,015,045,000|ven_opp_sat,013,055,positive,015,045,000|mar_opp_sat,107,157,positive,015,045,000|ven_opp_sat,217,325,positive,015,045,000|mar_opp_sat,365,366,positive,015,045,000|moo_sxt_ura,001,039,positive,015,045,000|mar_squ_ura,001,107,positive,015,045,000|sun_sxt_ura,033,145,positive,015,045,000|sun_sxt_ura,319,366,positive,015,045,000|ven_opp_plu,015,237,positive,015,045,000|ven_opp_plu,317,366,positive,015,045,000|]__
            //
            //    _doclin=[from Jan  1 to Apr 16 ^(mabur)]__
            //    _(fn_BIGaspect_from_to() in futhtm.c  --  this is updated after the end of each aspect is reached )__
            //    _gbl_PSV_of_SW_CSVs=[sun_opp_jup,001,005,positive,015,045,000|ven_opp_jup,081,193,positive,015,045,000|ven_opp_jup,317,341,positive,015,045,000|mar_opp_jup,361,366,positive,015,045,000|ven_opp_sat,013,055,positive,015,045,000|mar_opp_sat,107,157,positive,015,045,000|ven_opp_sat,217,325,positive,015,045,000|mar_opp_sat,365,366,positive,015,045,000|moo_sxt_ura,001,039,positive,015,045,000|mar_squ_ura,001,107,positive,015,045,000|sun_sxt_ura,033,145,positive,015,045,000|sun_sxt_ura,319,366,positive,015,045,000|ven_opp_plu,015,237,positive,015,045,000|ven_opp_plu,317,366,positive,015,045,000|]__
            //
            //    FYI  looks like this:
      // for test of gbl_PSV_of_SW_CSVs
      //
      // FYI  gbl_PSV_of_SW_CSVs
      //
      //

// ===============================================================================================================
// ===============================================================================================================
// ===============================================================================================================
//
//
//  in  gbl_PSV_of_SW_CSVs, this function could create   a brand new SW_CSV 
//  in  gbl_PSV_of_SW_CSVs, this function could create   a SECOND (or 3rd) new SW_CSV for this same  SW_CSV_ASP_string (like "sun_opp_jup")
//  in  gbl_PSV_of_SW_CSVs, this function could update   SW_amplitude_at_MAX  in an existing SW_CSV
//
void SW_uses_aspect_addval(int addval, int nat_plt, int aspect_num, int trn_plt, int day_num) 
{


// for test
//if ( nat_plt == 3 && trn_plt == 1) {
//ki(nat_plt);kin(trn_plt);
//tr("SW_uses_aspect_addval()");
//ks(N_planet[nat_plt]);ks(N_aspect[aspect_num]);ksn(N_trn_planet[trn_plt]);
//}
// for test

//  // for test
//if (day_num >=6) return;  // for test
//if (day_num >= 110) return;  // for test
//tn();

//  char SW_CSV_unique_KEY[32];   // like "sun_opp_jup,045"  where 045 is the day_num (every 2 days, 1 ->184)
//  sprintf(SW_CSV_unique_KEY, "%s_%s_%s,%03d", N_planet[nat_plt], N_aspect[aspect_num], N_trn_planet[trn_plt], day_num );
  // the UNIQUE KEY into gbl_PSV_of_SW_CSVs is first 2 flds like "sun_opp_jup,045"   45 is dayOfYear (1-366) (not day_num 1->183)

  char SW_CSV_ASP_string[32];   // like "sun_opp_jup"
  char SW_CSV_current[128];
  char str_SW_open_or_done[32]  ;     

//  char SW_CSV_updated[128];
//  char SW_CSV_forLoop[128];
//  strcpy(SW_CSV_forLoop, "token for first SW_CSV");  // so strlen()  is not zero
//  char SW_CSV_toPutIn[128];

//  int  FOUND_open_SW_CSV;
//
//  int  SW_CSV_FOUND_OPEN;
//
//  int  FOUND_OPEN_SW_CSV;
//
//  int  SW_CSV_FOUND_DONE;
//  int  SW_CSV_ASP_string_OPEN;
//
//

//  char NEW_PSV_of_SW_CSVs[8192] = "";   // this is updated after each aspect in this current calendar year is "finished"

//  SW_CSV_FOUND = 0;
//  FOUND_open_SW_CSV = 0;

  strcpy(SW_CSV_current, "token for first SW_CSV");  // so strlen()  is not zero


//  int  int_SW_BEG_DayOfYear     ;
//  int  int_SW_END_DayOfYear     ;
//  char str_SW_amplitude_sign[32];     // "positive" or "negative" for sinewave amplitude
//  int  int_SW_amplitude_at_BEG  ;
//  int  int_SW_amplitude_at_MAX  ;
//  int  int_SW_amplitude_at_END  ;
//  int  int_SW_day_num_updated   ;     // the day_num this SW_CSV  was last updated
//  char str_SW_open_or_done[32]  ;     // "open" or "done" for sinewave status
//


  char *N_planet[]     = {"   ","sun","moo","mer","ven","mar","jup","sat","ura","nep","plu", "nod","asc","mc_"};
  char *N_trn_planet[] = {"   ","jup","sat","ura","nep","plu","mar"};
  char *N_aspect[]     = {"   ","cnj","sxt","squ","tri","opp","tri","squ","sxt","cnj"};

  sprintf(SW_CSV_ASP_string, "%s_%s_%s",      N_planet[nat_plt], N_aspect[aspect_num], N_trn_planet[trn_plt]              );
//tr("newl");ks(SW_CSV_current);ksn(SW_CSV_ASP_string);

//char showaspnum[128];
//strcpy(showaspnum, N_aspect[aspect_num] );
//tr("newl2");ksn(showaspnum);

  // for this aspect, find an SW_CSV which can be updated because it is OPEN


  // NOTE: gbl_PSV_of_SW_CSVs ends in a zero-legth CSV = " csv...|csv...|csv...||"
  for (int ifld = 1; strlen(SW_CSV_current) != 0; ifld++)   // FOR EACH   SW_CSV in gbl_PSV_of_SW_CSVs
  {
    strcpy(SW_CSV_current, csv_get_field(gbl_PSV_of_SW_CSVs, "|", ifld));  // one-based fldnum
//tn();ki(ifld);ks(SW_CSV_current);ksn(SW_CSV_ASP_string);

    // check if this SW_CSV is for this aspect
    if (strncmp(SW_CSV_current, SW_CSV_ASP_string, strlen(SW_CSV_ASP_string)) == 0)  // if SW_CSV_current starts with SW_CSV_ASP_string
    {
      // get its open/done state
      strcpy(str_SW_open_or_done, csv_get_field(SW_CSV_current, ",", 9));  // one-based fldnum

      if (strcmp(str_SW_open_or_done, "open") == 0) {
// rkt
//tr("FOUND OPEN SW_CSV to UPDATE!");ks(SW_CSV_current);

        // here, this SW_CSV_current  is "open" and can be updated

        update_this_SW_CSV(SW_CSV_current, addval, nat_plt, aspect_num, trn_plt, day_num, "open");  // "open" or "done" for SW_CSV status
        return;
      }
    } // check if this SW_CSV is for this aspect
  } // for each SW_CSV in gbl_PSV_of_SW_CSVs

  // for this aspect, the loop above could not find an OPEN SW_CSV to update
  // so, create a new SW_CSV for it
  //
  create_a_new_SW_CSV(addval, nat_plt, aspect_num, trn_plt, day_num);

} // end of SW_uses_aspect_addval()

//
// ===============================================================================================================
// ===============================================================================================================
// ===============================================================================================================


// CREATE a NEW SW_CSV in gbl_PSV_of_SW_CSVs   CREATE a NEW SW_CSV in gbl_PSV_of_SW_CSVs   CREATE a NEW SW_CSV in gbl_PSV_of_SW_CSVs   
// CREATE a NEW SW_CSV in gbl_PSV_of_SW_CSVs   CREATE a NEW SW_CSV in gbl_PSV_of_SW_CSVs   CREATE a NEW SW_CSV in gbl_PSV_of_SW_CSVs   
// CREATE a NEW SW_CSV in gbl_PSV_of_SW_CSVs   CREATE a NEW SW_CSV in gbl_PSV_of_SW_CSVs   CREATE a NEW SW_CSV in gbl_PSV_of_SW_CSVs   
//
void create_a_new_SW_CSV(int addval, int nat_plt, int aspect_num, int trn_plt, int day_num) 
{
//tr("\nin create_a_new_SW_CSV()"); kin(addval);


//  if (day_num >= 183) {
//trn("_NO in create_a_new_SW_CSV() -> walked plank");
//    return; // fix bug with band-aid
//  }
  //
  // no, if walked the plank, put date back to dec 31
  //
//  if (day_num > 183) {
//trn("walked the plank - put back to dec 31");
//    day_num = 183;
//  }
  //

  char SW_CSV_current[128];
  strcpy(SW_CSV_current, "token for first SW_CSV");  // so strlen()  is not zero

  int  int_SW_BEG_DayOfYear     ;
  int  int_SW_END_DayOfYear     ;
  char str_SW_amplitude_sign[32];     // "positive" or "negative" for sinewave amplitude
  int  int_SW_amplitude_at_BEG  ;
  int  int_SW_amplitude_at_MAX  ;
  int  int_SW_amplitude_at_END  ;
  int  int_SW_day_num_updated   ;     // the day_num this SW_CSV  was last updated
  char str_SW_open_or_done[32]  ;     


    // use day_num arg to calc SW_BEG_DayOfYear in SW_CSV_current
    // use day_num arg to calc corresponding dayOfYear
    int_SW_BEG_DayOfYear     =  Eph_rec_every_x_days * day_num - 1 ;    //    Eph_rec_every_x_days is every 2 days
    int_SW_END_DayOfYear     = -1;


    // ----------------------------------------------------------------------------------
    // check SW_BEG_DayOfYear  for not being > number of days in  gbl_year_todo_yyyy_INT
//tr("in create_a_new_SW_CSV()  CHECK this");ki(int_SW_BEG_DayOfYear);

      //   the following is for K&R fns day_of_year() & month_day() 
      //  double Day_tab[2][13] = {
      //    {365.0,31.0,28.0,31.0,30.0,31.0,30.0,31.0,31.0,30.0,31.0,30.0,31.0},
      //    {366.0,31.0,29.0,31.0,30.0,31.0,30.0,31.0,31.0,30.0,31.0,30.0,31.0}
      //  };
      //
      // leap = (i%4 == 0 && i%100) != 0 || i%400 == 0;   // is the year i leap? 

    int is_leap_year;
    is_leap_year =  (gbl_year_todo_yyyy_INT % 4 == 0 && gbl_year_todo_yyyy_INT % 100) != 0 || gbl_year_todo_yyyy_INT % 400 == 0;
//kin(is_leap_year);
    
    if (is_leap_year == 1  &&  int_SW_BEG_DayOfYear > 366) {
//trn("> 366");
      return;
    } 
    if (is_leap_year == 0  &&  int_SW_BEG_DayOfYear > 365) {
//trn("> 365");
      return;
    }
//trn("= OK");
    // check SW_BEG_DayOfYear  for not being > number of days in  gbl_year_todo_yyyy_INT
    // ----------------------------------------------------------------------------------



    if ( strcmp(N_aspect[aspect_num], "sxt") == 0 ) strcpy(str_SW_amplitude_sign, "positive");
    if ( strcmp(N_aspect[aspect_num], "tri") == 0 ) strcpy(str_SW_amplitude_sign, "positive");
    if ( strcmp(N_aspect[aspect_num], "opp") == 0 ) strcpy(str_SW_amplitude_sign, "negative");
    if ( strcmp(N_aspect[aspect_num], "squ") == 0 ) strcpy(str_SW_amplitude_sign, "negative");
    if ( strcmp(N_aspect[aspect_num], "cnj") == 0 ) {
//tr("addval CHECK");kin(addval);
     // note switch  -ancient history-  higher stress used to be on top of graph
        //     strcpy(str_SW_amplitude_sign, (addval >= 0)? "negative": "positive"  ); 
      if (strcmp(gbl_this_CNJ_is, "positive") == 0)  strcpy(str_SW_amplitude_sign, "positive"  ); 
      if (strcmp(gbl_this_CNJ_is, "negative") == 0)  strcpy(str_SW_amplitude_sign, "negative"  ); 
    }

    // This is a NEW SW_CSV
    int_SW_amplitude_at_BEG  =  abs(addval);
    int_SW_amplitude_at_MAX  =  abs(addval);               // This is NEW SW_CSV
    int_SW_amplitude_at_END  = -1;
    int_SW_day_num_updated   =  day_num;
    strcpy(str_SW_open_or_done, "open");

    sprintf(SW_CSV_current,                   // create a NEW SW_CSV
      "%3s_%3s_%3s,%03d,%03d,%8s,%03d,%03d,%03d,%03d,%4s",
      N_planet[nat_plt], N_aspect[aspect_num], N_trn_planet[trn_plt],   // fld #1   // looks like "sun_opp_jup"
      int_SW_BEG_DayOfYear     ,
      int_SW_END_DayOfYear     ,
      str_SW_amplitude_sign    ,                                        // fld #4   // "positive" or "negative"
      int_SW_amplitude_at_BEG  ,
      int_SW_amplitude_at_MAX  ,
      int_SW_amplitude_at_END  ,                                        // fld #7
      int_SW_day_num_updated   ,
      str_SW_open_or_done                                               // fld #9   // "open" or "done"
    ); // SW_CSV_current has 49 chars

//<.>

//tr(" This is a NEW SW_CSV - append to gbl_PSV_of_SW_CSVs ");ki(aspect_num);
//ksn(SW_CSV_current);
//trn("in create NEW  SW_CSV  ->  append SW_CSV_current 

    // append SW_CSV_current to gbl_PSV_of_SW_CSVs 

    if (strlen(gbl_PSV_of_SW_CSVs) == 0 ) {
      sprintf(gbl_PSV_of_SW_CSVs, "%s|",                        SW_CSV_current); // this gbl used in futhtm.c
    } else {
      sprintf(gbl_PSV_of_SW_CSVs, "%s%s%s", gbl_PSV_of_SW_CSVs, SW_CSV_current, "|" ); // this gbl used in futhtm.c
// no   strcpy(gbl_PSV_of_SW_CSVs, strcat(SW_CSV_current, "|" ) ); // this gbl used in futhtm.c
    } 

//        strcat(linebuf, "##");  /* weird bug fix */
//*   strcat(&Docin_pathname[0],DIR_CHAR);
//*   strcat(&Docin_pathname[0],&Futin_filename[0]);
//  strcpy(s,strcat(sdate1,sdate2));


//ksn(SW_CSV_current);
ksn(gbl_PSV_of_SW_CSVs);
// for test
int  how_many_csvs = scharcnt(gbl_PSV_of_SW_CSVs, '|'); 
tr("num  create SW_CSVs in gbl_PSV_of_SW_CSVs"); kin(how_many_csvs);
trn("");

    return;
} // end of create_a_new_SW_CSV()
//
// CREATE a NEW SW_CSV in gbl_PSV_of_SW_CSVs   CREATE a NEW SW_CSV in gbl_PSV_of_SW_CSVs   CREATE a NEW SW_CSV in gbl_PSV_of_SW_CSVs   
// CREATE a NEW SW_CSV in gbl_PSV_of_SW_CSVs   CREATE a NEW SW_CSV in gbl_PSV_of_SW_CSVs   CREATE a NEW SW_CSV in gbl_PSV_of_SW_CSVs   
// CREATE a NEW SW_CSV in gbl_PSV_of_SW_CSVs   CREATE a NEW SW_CSV in gbl_PSV_of_SW_CSVs   CREATE a NEW SW_CSV in gbl_PSV_of_SW_CSVs   



// update this SW_CSV    update this SW_CSV    update this SW_CSV    update this SW_CSV    update this SW_CSV   
// update this SW_CSV    update this SW_CSV    update this SW_CSV    update this SW_CSV    update this SW_CSV   
// update this SW_CSV    update this SW_CSV    update this SW_CSV    update this SW_CSV    update this SW_CSV   
//
void update_this_SW_CSV(
  char *SW_CSV_current,
  int addval, int nat_plt, int aspect_num, int trn_plt, int day_num,
  char *arg_SW_open_or_done
)
{
//trn("\nin update_this_SW_CSV()"); 
//rkt
//tr("upd");ksn(SW_CSV_current);

  char SW_CSV_updated[128];
  char SW_CSV_forLoop[128];
  char SW_CSV_toPutIn[128];
  strcpy(SW_CSV_forLoop, "token for first SW_CSV");  // so strlen()  is not zero
  char NEW_PSV_of_SW_CSVs[8192] = "";   // this is updated after each aspect in this current calendar year is "finished"

        // create a SECOND (or 3rd) SW_CSV for this SW_CSV_ASP_string starting with day_num 
        //
        // create an updated version of  SW_CSV_current  in  SW_CSV_updated
        //
        // these 3 flds will be updated
        //    update int_SW_amplitude_at_MAX    f6   possibly update
        //    update int_SW_amplitude_at_END    f7   always   update so when the end comes, it is there
        //    update int_SW_day_num_updated     f8   always   update
        //
        int old_max_ampl;
        old_max_ampl = atoi( csv_get_field(SW_CSV_current, ",", 6) );

        char f1[64]; char f4[64]; char f9[64];
        int  f2,f3,f5,f6,f7,f8;

        strcpy(f1, csv_get_field(SW_CSV_current, ",", 1));                 // 1 SW_CSV_ASP_string 
        f2 = atoi( csv_get_field(SW_CSV_current, ",", 2));                 // 2 int_SW_BEG_DayOfYear     
        f3 = Eph_rec_every_x_days * day_num - 1 ;                          // 3 int_SW_END_DayOfYear   - Eph_rec_every_x_days is every 2 days
        strcpy(f4, csv_get_field(SW_CSV_current, ",", 4));                 // 4 str_SW_amplitude_sign    
        f5 = atoi( csv_get_field(SW_CSV_current, ",", 5));                 // 5 int_SW_amplitude_at_BEG  
        f6 = ( abs(addval) > old_max_ampl )? abs(addval) : old_max_ampl ;  // 6 int_SW_amplitude_at_MAX
        f7 = abs(addval)                                 ;                 // 7 int_SW_amplitude_at_END  
        f8 = day_num                                     ;                 // 8 day_num last updated (for reckoning new SW for same aspect desc)
        strcpy(f9, arg_SW_open_or_done)                  ;                 // 9 "open" or "done"

        sprintf(SW_CSV_updated,                   // create an UPDATED SW_CSV to replace the current one in gbl_PSV_of_SW_CSVs 
          "%11s,%03d,%03d,%8s,%03d,%03d,%03d,%03d,%4s", f1,f2,f3,f4,f5,f6,f7,f8,f9 ); // 41 chars

          // fyi
          //  char *N_planet[]     = {"   ","sun","moo","mer","ven","mar","jup","sat","ura","nep","plu", "nod","asc","mc_"};
          //  char *N_trn_planet[] = {"   ","jup","sat","ura","nep","plu","mar"};
          //  char *N_aspect[]     = {"   ","cnj","sxt","squ","tri","opp","tri","squ","sxt","cnj"};
//rkt
// for test
//if (nat_plt == 3 && trn_plt ==  1) {  // mer jup
//tr("upd 1 1");ksn(SW_CSV_updated);
//ki(f2); ki(day_num); kin(f3);
//}
// for test


        // in gbl_PSV_of_SW_CSVs, replace SW_CSV_current with SW_CSV_updated
        //
        for (int jfld = 1; strlen(SW_CSV_forLoop) != 0; jfld++) {
          strcpy(SW_CSV_forLoop, csv_get_field(gbl_PSV_of_SW_CSVs, "|", jfld));  // one-based fldnum

          if ( strcmp(SW_CSV_forLoop, SW_CSV_current) == 0 )  strcpy(SW_CSV_toPutIn, SW_CSV_updated);
          else                                                strcpy(SW_CSV_toPutIn, SW_CSV_forLoop);

          if (strlen(NEW_PSV_of_SW_CSVs) == 0 )  sprintf(NEW_PSV_of_SW_CSVs, "%s|",                       SW_CSV_toPutIn); 
          else                                   sprintf(NEW_PSV_of_SW_CSVs, "%s%s|", NEW_PSV_of_SW_CSVs, SW_CSV_toPutIn);
        }
//ksn(gbl_PSV_of_SW_CSVs);
//
      strcpy( gbl_PSV_of_SW_CSVs, NEW_PSV_of_SW_CSVs );
//ksn(NEW_PSV_of_SW_CSVs);
//ksn(gbl_PSV_of_SW_CSVs);
}  // tr("END of   update_this_SW_CSV"); 

//
// update this SW_CSV    update this SW_CSV    update this SW_CSV    update this SW_CSV    update this SW_CSV   
// update this SW_CSV    update this SW_CSV    update this SW_CSV    update this SW_CSV    update this SW_CSV   
// update this SW_CSV    update this SW_CSV    update this SW_CSV    update this SW_CSV    update this SW_CSV   






/* arg  trn_plt is 0-> 3 coming in  sun,mer,ven,moo
*  arg  nat_plt is 1->10 coming in
*                  sun,moo,mer,ven,mar,jup,sat,ura,nep,plu, 
*/
void add_aspect_to_grhdata_bestday(int nat_plt,int aspect_num,int trn_plt,int day_num) 
{
  ;
  int ical;
  int addval;
  double a,b,c,d,e;
  ;
  /* trn("add_aspect_to_grhdata(int nat_plt,int aspect_num,int trn_plt,int day_num) "); */

  if (Moon_confidence == 0
    &&  nat_plt == NAT_PLT_NUM_FOR_MOON)  return;



  for (ical=0; ical <= NUM_HOUSES_CONSIDERED - 1; ++ical) {  /* NUM_HOUSES_CONSIDERED = 1 */

    a = (double)(f_get_plt_in_12(
      nat_plt-1,
      get_sign(Ar_minutes_natal[nat_plt])-1,
      ical)
    );
/* kdn(a); */

    if (House_confidence == 0)  b = a;
    else  b = (double)(f_get_plt_in_12(nat_plt-1,
            get_house(Ar_minutes_natal[nat_plt],
              Ar_minutes_natal[13]) -1, /*13=mc*/
            ical));
/* kd(b); */
/* kin(trn_plt);ki(ical);ki(day_num); */
/* int eph; eph = (Eph_buf_bestday+day_num)->positions[trn_plt] -1; ki(eph); */

    c = (double)(
      get_plt_in_12_bestday(
        trn_plt, /* trn_plt is 0->3 coming in */
        get_sign((Eph_buf_bestday+day_num)->positions[trn_plt]) -1,
        ical)
      );
/* kd(c); */

    if (House_confidence == 0)  d = c;
    else  d = (double)(get_plt_in_12_bestday(
            trn_plt,
            get_house((Eph_buf_bestday+day_num)->positions[trn_plt],
                  Ar_minutes_natal[13]) - 1, /*13=mc*/
            ical));
/* kd(d); */

    e = (double)(get_aspect_multiplier_bestday(
            Aspect_type[aspect_num],   /* aspect_type  0=cnj, 1=good, 2=bad */
            trn_plt,
            nat_plt-1,
            ical));
/* kd(e); */
/* int mytyp;mytyp= Aspect_type[aspect_num]; */
/* ki(aspect_num);ki(mytyp); */

    addval = (int)(Current_aspect_force * Moon_confidence_factor *
            e * (sqrt(a*a+b*b)+sqrt(c*c+d*d)));
/* ki(addval); */
/* kd(Current_aspect_force); */

    *(Grhdata_bestday +ical * Num_eph_grh_pts+(day_num-1)) += addval;
  }


/* static int mytimes2; mytimes2++;
* if (mytimes == 1 ) mk_new_date(&dmn,&ddy,&dyr,dstep);
* if (mytimes == 2 ) mk_new_date(&dmn,&ddy,&dyr,dstep+92*2);
*/

/*  for test ! */
/* test asp details */
/* show all aspects */
/* char myasp[8], mynat[8], mytrn[8];
* char sday[4]; sprintf(sday,"%02d", day_num);
* strcpy(myasp, N_aspect[aspect_num]);
* strcpy(mytrn, N_planet_bestday[trn_plt]);
* strcpy(mynat, N_planet[nat_plt]);
* ksn(sday); ks(myasp); ks(mytrn); ks(mynat); ki(addval);
*/
/*  for test ! */



#ifdef PUT_BACK_COMMENTED_OUT_STUFF /****************************************/
#endif /* ifdef PUT_BACK_COMMENTED_OUT_STUFF ********************************/

} /* end of add_aspect_to_grhdata_bestday() */



int get_sign(int minutes)
{
  return((int)floor((minutes/60.0)/30.0)+1);
} 


int get_house(int minutes,int mc)
{
  int asc;
  ;
  asc = mc + 90*60;
  if (asc >= NUM_MINUTES_IN_CIRCLE) asc = asc - NUM_MINUTES_IN_CIRCLE;
  if (minutes >= asc)  return(get_sign(minutes-asc));
  else  return(get_sign((NUM_MINUTES_IN_CIRCLE-asc)+minutes));
}  /* end of get_house() */



/*  **************  more on do_grhs()  **************** 
*  
* args-  p_grh is a ptr to array extern ints of y values for grh 
*       grh_incr is increment.  e.g. =5 means if yvalue is 20 
*         then that pt goes on 4th line of grh from zero y value 
*  
*   initialize prt line to blanks 
*  for each graph to be done()     
*     change the grh values to 12lpi line numbers 
*     init the col_num array 
*     sort the grh values 
*     set up .ne for doc 
*     do_a_graph() 
*/
void do_grhs(void)
{
  int igrh, stress_num, this_num;  /* igrh = grhs 2,4,5,7,10, or whatever */
  int n;
  ;
trn("in do_grhs()  "); 


//
  /* --------------- "/Users/xxx/_PC/usr/apple/_c/_wrk/futdefs.h" -------------- */
  /* 128:#define SUBSCRIPT_FOR_VLO_STRESS_LEVEL 6    * Stress_val[6] = vlo- "great"*/
  /* 129:#define SUBSCRIPT_FOR_LO_STRESS_LEVEL 5     * Stress_val[5] = lo- "good" */
  /* 130:#define SUBSCRIPT_FOR_HIGH_STRESS_LEVEL 3   * Stress_val[3] = hi-"stress" */
  /* 131:#define SUBSCRIPT_FOR_VHIGH_STRESS_LEVEL 2  * Stress_val[2] = hi-"OMG" */
    //
    //    futdoc.h
    //    char *Stress_name[NUM_STRESS_LEVELS] = {
    //      "       ",
    //      "   OMG-",
    //      "       ",
    //      "STRESS-",
    //      "       ",
    //      "  GOOD-",
    //      "       ",
    //      " GREAT-",
    //    };
    //
  //    #define SIZE_EPH_GRH_INCREMENT 6  /* 1 '*' for every 6 Grhdata score nums */
  //
  // gbl_numLinesFillToGREAT = (Stress_val[SUBSCRIPT_FOR_VLO_STRESS_LEVEL]  -  Grh_bot ) / SIZE_EPH_GRH_INCREMENT; 
  //
  /* --------------- "/Users/xxx/_PC/usr/apple/_c/_wrk/futdoc.h" -------------- */
  /* 223:int Stress_val[NUM_STRESS_LEVELS] = {304,250,196,142,88,34,-20,-74};   */
  /*                                                   32  23,    5,            */
  /*                                                  omg str, good, -20=great  */
  //


  for (igrh=0; igrh <= NUM_EPH_GRAPHS-1 -1; igrh++)    /* -1, total grh later */
  {

    in_stress = 0;
    out_of_stress = 0;

    stress_num = Stress_val[SUBSCRIPT_FOR_HIGH_STRESS_LEVEL] / SIZE_EPH_GRH_INCREMENT;  /* "stress-" label */

    /*  Stress_val[SUBSCRIPT_FOR_LO_STRESS_LEVEL] "good-" label */

    /* init TABLES
    */
    for (n=0; n <= Num_eph_grh_pts-1; n++)   /* init tbls */
    {  /* init tbls */
      *(Grhdata+igrh*Num_eph_grh_pts+n) /= SIZE_EPH_GRH_INCREMENT;

      *(Grh_colnum+n) = n; /* init col num array [0]=0, [1]=1 etc. */


      this_num = *(Grhdata+igrh*Num_eph_grh_pts+n);

/*  */
      /* here, do possible intercept of data for rpt "Best Day on"
      *  and put it into return val var= targetDayScore
      */
/*       if(   strcmp(gbl_instructions,  "return only day stress score") == 0  */
      if(   strcmp(gbl_instructions,  "return only day stress score_B") == 0 
         && gblWeHaveTargetDayScore== 0)
      {
        checkFortargetDayScore(n, this_num);

      }

      /* OLD (  stress_num is 23  (201312)
      */
           //       223:int Stress_val[NUM_STRESS_LEVELS] = {304,250,196,142,88,34,-20,-74};   
      if (this_num >= stress_num) {
        in_stress = in_stress         + (this_num - stress_num);
        gbl_in_stress = gbl_in_stress + (this_num - stress_num);
      } else {
        out_of_stress = out_of_stress         + (stress_num - this_num);
        gbl_out_of_stress = gbl_out_of_stress + (stress_num - this_num);
      }

    } /* init tbls */


//tr("before set gbl_yearStressScoreIsDone ");
//ksn(gbl_instructions);


          // re: stringBuffForStressScore
          // here, in    init TABLES    gbl_in_stress and gbl_out_of_stress  are calculated
          // so can return  if(strcmp(gbl_instructions,  "return only year stress score") == 0) 
          //
    if(strcmp(gbl_instructions,  "return only year stress score") == 0) {

      gbl_yearStressScoreIsDone = 1;   // can return  if(strcmp(gbl_instructions,  "return only year stress score") == 0) 
//ksn("SET gbl_yearStressScoreIsDone  = 1");

trn("ss 03  so,   RETURN from do_grhs()  after  init tbls   block ");

      return;  // from call do_grhs
    };
   









/*  show y values */
/* int y; for (n=0; n <= Num_eph_grh_pts-1; n++) { */
/*   y = *(Grhdata+igrh*Num_eph_grh_pts+n);  */
  /*  arg1 = p_grh y values */
/* kin(n);ki(y); */
/* } */


// log grhdata
//trn(" log grhdata  BEFORE * int Stress_val[NUM_STRESS_LEVELS] = {304,250,196,142,88,34,-20,-74}");
//int rkn;
//for (rkn=0; rkn <= Num_eph_grh_pts-1; rkn++) { ki(rkn);kin(*(Grhdata+igrh*Num_eph_grh_pts+rkn)); }



    /* #define SUBSCRIPT_FOR_HIGH_STRESS_LEVEL 3  * Stress_val[3] = hi-"stress" *
    * int Stress_val[NUM_STRESS_LEVELS] = {304,250,196,142,88,34,-20,-74};
    */
    sort_grh(Grhdata+igrh*Num_eph_grh_pts,Num_eph_grh_pts,Grh_colnum);


    gbl_topStarVal =  *(Grhdata + igrh * Num_eph_grh_pts + 0); // for putting all-new benchmark labels to existing lines 
//ki(gbl_topStarVal);
    gbl_topStarVal =  gbl_topStarVal  *  SIZE_EPH_GRH_INCREMENT ;  // this is needed
//kin(gbl_topStarVal);


// log grhdata
//trn(" log grhdata  AFTER  * int Stress_val[NUM_STRESS_LEVELS] = {304,250,196,142,88,34,-20,-74}");
////int rkn;
//for (rkn=0; rkn <= Num_eph_grh_pts-1; rkn++) { ki(rkn);kin(*(Grhdata+igrh*Num_eph_grh_pts+rkn)); }





//
//    // ----------------------------------------------------------------------------------------------------------
//    // POPULATE gbl_topStarBelowGood;        // for   newPlanBenchmarkLabels()
//    // ----------------------------------------------------------------------------------------------------------
//    // compare the top star data (+ 0 index) to GOOD benchmark label stress_val
//    //
//    int topStarData;
////    topStarData =  *(Grhdata + igrh * Num_eph_grh_pts + 0) *  SIZE_EPH_GRH_INCREMENT ;
//    topStarData =  *(Grhdata + igrh * Num_eph_grh_pts + 0);
//    if (topStarData >= Stress_val[SUBSCRIPT_FOR_LO_STRESS_LEVEL] )  // LO = GOOD benchmark label ( = 34 )
////    if (topStarData >= Stress_val[SUBSCRIPT_FOR_VLO_STRESS_LEVEL] )  // LO = GREAT benchmark label ( = -20 )
//    {
//      gbl_topStarBelowGood = 1;
//    } else {
//      gbl_topStarBelowGood = 0;
//    }
//trn(" POPULATE gbl_topStarBelowGood;   for   newPlanBenchmarkLabels()");
//kin(*(Grhdata + igrh * Num_eph_grh_pts + 0) );
//kin(topStarData);
//tr(" GREAT");kin(Stress_val[SUBSCRIPT_FOR_VLO_STRESS_LEVEL] );
//tr("  GOOD");kin(Stress_val[SUBSCRIPT_FOR_LO_STRESS_LEVEL] );   // = 34
//tr("STRESS");kin(Stress_val[SUBSCRIPT_FOR_HIGH_STRESS_LEVEL] );
//tr("   OMG");kin(Stress_val[SUBSCRIPT_FOR_VHIGH_STRESS_LEVEL] );
//kin( gbl_topStarBelowGood);
//
//        /* --------------- "/Users/xxx/_PC/usr/apple/_c/_wrk/futdefs.h" -------------- */
//        /* 128:#define SUBSCRIPT_FOR_VLO_STRESS_LEVEL 6    * Stress_val[6] = vlo- "great"*/
//        /* 129:#define SUBSCRIPT_FOR_LO_STRESS_LEVEL 5     * Stress_val[5] = lo- "good" */
//        /* 130:#define SUBSCRIPT_FOR_HIGH_STRESS_LEVEL 3   * Stress_val[3] = hi-"stress" */
//        /* 131:#define SUBSCRIPT_FOR_VHIGH_STRESS_LEVEL 2  * Stress_val[2] = hi-"OMG" */
//          //
//          //    futdoc.h
//          //    char *Stress_name[NUM_STRESS_LEVELS] = {
//          //      "       ",
//          //      "   OMG-",
//          //      "       ",
//          //      "STRESS-",
//          //      "       ",
//          //      "  GOOD-",
//          //      "       ",
//          //      " GREAT-",
//          //    };
//          //
//        //    #define SIZE_EPH_GRH_INCREMENT 6  /* 1 '*' for every 6 Grhdata score nums */
//        //
//        // gbl_numLinesFillToGREAT = (Stress_val[SUBSCRIPT_FOR_VLO_STRESS_LEVEL]  -  Grh_bot ) / SIZE_EPH_GRH_INCREMENT; 
//        //
//        /* --------------- "/Users/xxx/_PC/usr/apple/_c/_wrk/futdoc.h" -------------- */
//        /* 223:int Stress_val[NUM_STRESS_LEVELS] = {304,250,196,142,88,34,-20,-74};   */
//        /*                                                   32  23,    5,            */
//        /*                                                  omg str, good, -20=great  */
//        //
//
//    //
//    // POPULATE gbl_topStarBelowGood;        // for   newPlanBenchmarkLabels()
//    // ----------------------------------------------------------------------------------------------------------
//
//







    set_tops_and_bots(igrh);

    /* for test */
    /* tn();
    * int mytop, mybot;
    * mytop = Grh_top/SIZE_EPH_GRH_INCREMENT;
    * mybot = Grh_bot/SIZE_EPH_GRH_INCREMENT;
    * trn("!!!!!!!!!!!!!!");ki(Grh_top);
    * trn("!!!!!!!!!!!!!!");ki(Grh_bot);
    * trn("!!!!!!!!!!!!!!");ki(mytop);
    * trn("!!!!!!!!!!!!!!");ki(mybot); tn();
    */

    do_size_grh();

    if (Num_eph_grh_pts == NUM_PTS_WHOLE_YEAR) {  // do big graph
      do_aBIG_graph(Grhdata+igrh*Num_eph_grh_pts,igrh);  /*  arg1 = p_grh y values */
//trn(" do_aBIG_graph(Grhdata+igrh*Num_eph_grh_pts,igrh);");
    } else {
      do_a_graph(Grhdata+igrh*Num_eph_grh_pts,igrh);  /*  arg1 = p_grh y values */
//trn(" do_a_graph(Grhdata+igrh*Num_eph_grh_pts,igrh);");
    }
  }  /* for each NUM_EPH_GRAPH */
trn("end of do_grhs() ");
}  /* end of do_grhs() */



void checkFortargetDayScore(int daynum, int current_score)
{
  double d_dy,d_mn,d_yr,d_step;
  double d_jd_current, d_jd_target;   /* jd=julian date */
  int    i_jd_current, i_jd_target;   /* jd=julian date */
  static int save_last_score;

/* tn(); trn("in checkFortargetDayScore()"); */
/* kin(daynum);ki(current_score); */
/* kin(Grh_beg_mn); ki(Grh_beg_dy); ki(Grh_beg_yr); */

  daynum = daynum + 1;  /* make it one-based */

  /* get current date  into d_mn, d_dy, d_yr
  */
  d_mn = (double)Grh_beg_mn;
  d_dy = (double)Grh_beg_dy;
  d_yr = (double)Grh_beg_yr;

  d_step = (double)((daynum-1) * Eph_rec_every_x_days);

  mk_new_date(&d_mn, &d_dy, &d_yr, d_step);


  /* compare current date to target date for "Best Day" rpt
  *  by converting to julian dates
  */
  if ((int)d_yr !=  gbl_bd_year) return;

  d_jd_current = day_of_year(d_yr, d_mn, d_dy);
  d_jd_target  = day_of_year(
    gbl_bd_year,
    gbl_bd_mth,
    gbl_bd_day
  );
  i_jd_current = (int)d_jd_current;
  i_jd_target  = (int)d_jd_target ;

/* kin(i_jd_current); ki(i_jd_target); */


  if (i_jd_current == i_jd_target) {
    gblTargetDayScore = current_score;  /* DONE! */
    gblWeHaveTargetDayScore= 1;  /* 1=yes,0=no */
    return;
  }
  /* there is 1 star every 2 days, so
  * check for case that current date is 1 more than target
  */
  if (i_jd_current > i_jd_target) {
    if (save_last_score == 0) {
      gblTargetDayScore = current_score;  /* DONE! */
      gblWeHaveTargetDayScore = 1;  /* 1=yes,0=no */
    return;

    } else {
      gblTargetDayScore = (save_last_score + current_score) / 2;  /* DONE! */
      gblWeHaveTargetDayScore = 1;  /* 1=yes,0=no */
      return;
    }
  }

  save_last_score = current_score;

} /* end of  checkFortargetDayScore() */



void set_tops_and_bots(int grh_num)
{
//trn("set_tops_and_bots()");
//kin(Grh_bot);
  Grh_top = *(Grhdata+grh_num*Num_eph_grh_pts+Num_eph_grh_pts-1) 
      * SIZE_EPH_GRH_INCREMENT;
  Grh_bot = *(Grhdata+grh_num*Num_eph_grh_pts+0) 
      * SIZE_EPH_GRH_INCREMENT;
//kin(Grh_bot);

  if (Grh_top < Stress_val[SUBSCRIPT_FOR_HIGH_STRESS_LEVEL]) {
    False_top =  Stress_val[SUBSCRIPT_FOR_HIGH_STRESS_LEVEL];
  } else {             /* ^top < hi stress level */
    False_top = Grh_top;     /* top >= hi stress level  ("STRESS_") */
  }

//
//274:int Stress_val[NUM_STRESS_LEVELS] = {304,250,196,142,88,34,-20,-74};
//2420:  if (Grh_bot > Stress_val[SUBSCRIPT_FOR_VLO_STRESS_LEVEL]) {
//2421:    False_bot =  Stress_val[SUBSCRIPT_FOR_VLO_STRESS_LEVEL];
//--------------- "/Users/rk/_PC/usr/apple/_c/_wrk/free/xfils/futdefs.h" --------------
//222:#define SUBSCRIPT_FOR_VLO_STRESS_LEVEL 6   /* Stress_val[6] = vlo- "great"*/
//223:#define SUBSCRIPT_FOR_LO_STRESS_LEVEL 5    /* Stress_val[5] = lo- "good" */
//224:#define SUBSCRIPT_FOR_HIGH_STRESS_LEVEL 3  /* Stress_val[3] = hi-"stress" */
//225:#define SUBSCRIPT_FOR_VHIGH_STRESS_LEVEL 2  /* Stress_val[3] = hi-"OMG" */
//
//    #define SIZE_EPH_GRH_INCREMENT 6  /* 1 '*' for every 6 Grhdata score nums */
//

//kin(False_bot);
//int test123;
//test123 = Stress_val[SUBSCRIPT_FOR_VLO_STRESS_LEVEL]; 
//kin(test123);
  if (Grh_bot > Stress_val[SUBSCRIPT_FOR_VLO_STRESS_LEVEL]) {
    False_bot =  Stress_val[SUBSCRIPT_FOR_VLO_STRESS_LEVEL];
  } else {             /* ^bot > vlo stress level   ("GOOD") */
    False_bot = Grh_bot;     /* bot <= vlo stress level */
  }
//kin(False_bot);

  if (False_top <= Grh_top) Num_file_lines_top = 0;
  else                      Num_file_lines_top = ((False_top-Grh_top-1)/SIZE_EPH_GRH_INCREMENT)+1;
//kin(Num_file_lines_top);

  if (False_bot >= Grh_bot) {
    Num_file_lines_bot = 0;
  } else {
    Num_file_lines_bot = ((Grh_bot-False_bot-1)/SIZE_EPH_GRH_INCREMENT)+1;
  }
//kin(Num_file_lines_bot);

  // calc gbl_numLinesFillToGREAT 
//  gbl_numLinesFillToGREAT = (Stress_val[SUBSCRIPT_FOR_VLO_STRESS_LEVEL]  -  Grh_bot ) / SIZE_EPH_GRH_INCREMENT; 
//kin(gbl_numLinesFillToGREAT);

/* tn();ki(Num_file_lines_top); */
/* tn();ki(Num_file_lines_bot); */

}  /* end of set_tops_and_bots() */



void do_a_graph(int p_grh[], int grh_num)    /* qqq */
{
  int n;
  char *p = &Swk[0];
  static int fut_line_ctr;
/*   char grh_line[SIZE_EPH_GRH_LINE+1]; */
  char grh_line[1024];
  int cols_with_pt[SIZE_EPH_GRH_LINE+1];/*for this line, col#s holding a pt*/
    /* cols_with_pt starts at [1] */
  int k,m,current_grh_y_val,last_grh_y_val_printed,nl,pt_ctr;
  ;                      /* nl = newest line in grh */
/* trn("in do_a_graph()"); */

  n = sprintf(p,"\n\n[beg_graph]\n");  /* signal to fmt_f.awk */
  /* fput(p,n,Fp_docin_file); */
  f_docin_put(p,n);

  Num_lines_in_grh_body = 0;
  last_grh_y_val_printed = 0;
  pt_ctr = 0;
  fut_line_ctr = 0;
  current_grh_y_val = *(p_grh+Num_eph_grh_pts-1);/* for 1st time thru below */
  last_grh_y_val_printed = current_grh_y_val;  /* for 1st time thru below */
  prt_grh_hdr(grh_num);

  sfill(&grh_line[0],Num_eph_grh_pts,GRH_BACKGROUND_CHAR);

  for (k=Num_eph_grh_pts-1; k > -1; k--) {

    if ( (nl=*(p_grh+k)) != current_grh_y_val  &&
          Num_lines_in_grh_body < MAX_GRH_BODY_LINES  ) {

      prt_grh_line(&grh_line[0],&cols_with_pt[0],pt_ctr,
        &fut_line_ctr,Grh_top);

      for (m=1; m <= last_grh_y_val_printed-nl-1; m++) {
        prt_grh_line(&grh_line[0],&cols_with_pt[0],0,
          &fut_line_ctr,Grh_top);
      }
                /* ^ put in 'blank' lines */
      last_grh_y_val_printed = nl;
      pt_ctr = 0;
    }

    pt_ctr++;
    cols_with_pt[pt_ctr] = Grh_colnum[k];
    current_grh_y_val = nl;

/*  */
/* kin(current_grh_y_val); */

  }


  prt_grh_bot(&grh_line[0],&cols_with_pt[0],pt_ctr,&fut_line_ctr);

   n = sprintf(p,"\n[end_graph]\n\n");  /* signal to fmt_f.awk */
   f_docin_put(p,n);
trn("end of do_a_graph()");
}  /* end of do_a_graph() */


void prt_grh_hdr(int grh_num)  /* grh title and 2nd line */
{
  char lf_mar[SIZE_GRH_LEFT_MARGIN+1];
  char star_desc[64], star_wk[64], num1[16], num2[16];
  char wk_line[SIZE_EPH_GRH_LINE+1];
  int n;
  char *p = &Swk[0];
  long int tmp_long;
  ;
  sfill(&lf_mar[0],SIZE_GRH_LEFT_MARGIN,' ');
/*
* if (Is_past) strcpy(&star_desc[0],".(one star every Wednesday)");
* else sprintf(&star_desc[0],"(one star for every %d days)",
*   Eph_rec_every_x_days);
*/
  sfill(star_desc,26,'.');
  tmp_long =  (long int) out_of_stress;
  commafy_int(num1, tmp_long, 6);
  tmp_long =  (long int)     in_stress;
  commafy_int(num2, tmp_long, 6);
  sprintf(star_wk, "ok=%s+, stress=%s-",   /* area score  good/bad */
    strim(num1," "), strim(num2," ") );
  memcpy(star_desc, star_wk, strlen(star_wk));

  /* put name in field of dots
  */
  char dotfield[MAX_SIZE_PERSON_NAME+2];  /* 15 in 201309 */
  sfill(dotfield, MAX_SIZE_PERSON_NAME+1, '.');
  memcpy(dotfield, fEvent_name, strlen(fEvent_name));
  dotfield[MAX_SIZE_PERSON_NAME+1] = '\0';


/*    "\n\n%s .....%s..........................................%s.....%s..... \n", */
/*     Grh_name[grh_num],   */
/*    "\n\n%s .....%s.............................................%s.....%s..... \n", */
/*     "\n\n%s .....%s.............................................%s.....%s..... \n",  */

/* tn(); */
/* ksn(&lf_mar[0]); */
/* ksn(dotfield); */

/*     "\n\n%s ..<span class=\"bgy\">...%s.....................T.......................%s.....%s..... </span>\n",  */
/*     "\n\n%s ..<span class=\"bgy\">...%s..................T.....................%s.....%s..... </span>\n",  */
/*     "\n\n%s<span class=\"k\"> .....%s........................................%s.....%s..... </span>\n",  */
/*     (global_flag_which_graph == 1)? "First Half.": "Second Half"  */


/*    "%s .....%s.......... STRESS LEVELS................%s.....%s..... ", */
/*    "%s .....%s........................................%s.....%s..... ", */
/*    "%s .....%s........................................%s.....%s..... ", */

  n = sprintf(p,
    "%s .....%s...........STRESS.LEVELS................%s.....%s..... ",   /* "stress levels" added 20150325 */
    &lf_mar[0],
    dotfield,
    year_in_the_life_todo_yyyy,
    (global_flag_which_graph == 1)? "First 6 months.": "Second 6 months"
              
  );
/* kin(strlen(p)); */
/* ksn(p); */

  scharswitch(p, '.', ' ');  /* dots out */

  f_docin_put(p,n);

  strcpy(p,"\n");  /* blank line before grh lines */
  n = (int)strlen(p);
  f_docin_put(p,n);
/* kin(strlen(p)); */


  sfill(&wk_line[0],Num_eph_grh_pts,GRH_CONNECT_CHAR);
  wk_line[0] = GRH_SIDELINE_CHAR;  
  wk_line[Num_eph_grh_pts-1] = GRH_SIDELINE_CHAR;


  n = sprintf(p,"%s%s\n",&lf_mar[0],&wk_line[0]);  /* 2nd line */

/*  scharswitch(p, '|', ' '); */ /* sideline out */
  scharswitch(p, '|', '#');  /* sideline out */

/* tn();b(88);ks(p); */
      bracket_string_of("#", p, "<span class=\"cSky\">", "</span>");
/* tn();b(89);ks(p); */
      scharswitch(p, '#', ' ');
/* tn();b(89);ks(p); */

  n = (int)strlen(p);
/* kin(n); */
  f_docin_put(p,n);
  put_grh_blnk_lines_at_top();

}  /* end of prt_grh_hdr() */


#ifdef PUT_BACK_COMMENTED_OUT_STUFF /****************************************/
* /*
*     takes integer "intnum", formats it right-justified
*     starting at ptr "dest" in a field of "sizeofs"
* */
* void commafy_int(char *dest, long intnum, int sizeofs)
* {
*     char wkstr[64];                 /* hold digits int "intnum" */
*     char *digits;                   /* pointer to current digit */
*     char fmt[64];
*     int n;              /* digit pointer (goes backwards) */
*     int ctr;            /* digit counter (forwards) */
*     int place;          /* current char num in dest */
*     ;
*     sprintf(wkstr,"%ld",intnum);
*     digits = &wkstr[strlen(wkstr)-1];
* 
*     sprintf(fmt,"%%%ds",sizeofs);
*     sprintf(dest,fmt," ");
*     for (ctr=1, n=strlen(wkstr), place=sizeofs-1;   n >= 1;   n--, digits--, ctr++,place--) {
*         dest[place] = *digits;
*         if (ctr % 3 == 0  &&  n != 1) {
*             place--;
*             dest[place] = ',';
*         }
*     }
*     if (dest[place+1] == ',') dest[place+1] = ' ';
*     if (dest[place+1] == '-'  &&  dest[place+2] == ',') {
*         dest[place+1] = ' ';
*         dest[place+2] = '-';
*     }
* }    /* end of commafy_int() */
#endif /* ifdef PUT_BACK_COMMENTED_OUT_STUFF ********************************/

#ifdef PUT_BACK_COMMENTED_OUT_STUFF /****************************************/
* /*
*   char *strim(s,set)
*   in string s, trim from both the left end and right end
*   all the characters in string set.
*   returns ptr to 1st non-set char in s.  
*   (\0 is written into s if right trimming occured)
* */
* char *strim(char *s, char *set)
* {
*   char *p,*q;
*   ;
*   for (p=s; *p != '\0'; p++) {
*     if (strchr(set,*p) == NULL) break;  /* out on 1st non-set char */
*   }
*   if (*p == '\0') return("");  /* s is all set chars */
*   q = PENDSTR(s);            /* | null stmt */
*   for ( ; strchr(set,*q) != NULL; q--) ;  /* out on 1st non-set char */
*   *(q+1) = '\0';
*   return(p);
* }
#endif /* ifdef PUT_BACK_COMMENTED_OUT_STUFF ********************************/


void put_grh_blnk_lines_at_top(void)    /* top is now the bottom */
{      /* after reversal. (high stress used to be at the top) */
  static int top_ln_ctr;
  int itop;
  int dummy[1];
  char prt_line[SIZE_EPH_GRH_LINE+1];
  ;
  dummy[0] = 0; /* init */
  if (False_top <= Grh_top) return;
  top_ln_ctr = 0;
  sfill(&prt_line[0],Num_eph_grh_pts,GRH_BACKGROUND_CHAR);

  /* sideline out */
/*   prt_line[0] = GRH_SIDELINE_CHAR; */
/*   prt_line[Num_eph_grh_pts-1] = GRH_SIDELINE_CHAR; */


  for (itop=1; itop <= Num_file_lines_top; ++itop) {
/* tn();b(200);ki(Num_file_lines_top); */
    prt_grh_line(&prt_line[0],dummy,0,&top_ln_ctr,False_top);
  }
/* ksn(gbl_save_last_line); */
}


void prt_grh_bot(char *p_line, int cols_with_pt[], int pt_ctr, int *p_ln_ctr)
{
  char lf_mar[SIZE_GRH_LEFT_MARGIN+1];
  int n,k;
  char *p = &Swk[0];
  char mywk[SIZE_GRH_LEFT_MARGIN+1];
  ;
/* trn("in prt_grh_bot"); */
  sfill(&lf_mar[0],SIZE_GRH_LEFT_MARGIN,' ');

  *p_ln_ctr = -1;      /* last line marker */
  prt_grh_line(&p_line[0],&cols_with_pt[0],pt_ctr,   
    p_ln_ctr,Grh_top); /* last line */

  sfill(&p_line[0],Num_eph_grh_pts,GRH_CONNECT_CHAR);

  /* sideline out */
/*   p_line[0] = GRH_SIDELINE_CHAR; */
/*   p_line[Num_eph_grh_pts-1] = GRH_SIDELINE_CHAR; */

  put_fill_lines_at_bot(&p_line[0]);  /* now top after reversal */

  reverse_grh_body_and_prt();

  sfill(&p_line[0],Num_eph_grh_pts,GRH_BACKGROUND_CHAR);

  /* sideline out */
/*   p_line[0] = GRH_SIDELINE_CHAR; */
/*   p_line[Num_eph_grh_pts-1] = GRH_SIDELINE_CHAR;  */ /* one buffer line */

  n = sprintf(p,"%s%s\n",&lf_mar[0],&p_line[0]);

  //scharswitch(p, GRH_BACKGROUND_CHAR, '|');   // change tick from apostrophe to pipe
  scharswitch(p, GRH_BACKGROUND_CHAR, '\'');

  f_docin_put(p,n);
      /* ^bot line of dots */


  /* sideline out */
  if (global_flag_which_graph != 1) {  /* leave pipes on "J" in Jan */
    Grh_bottom_line1[0] = ' ';  /* 1st col, (sideline char) */
  }
  Grh_bottom_line1[Num_eph_grh_pts-1] = ' '; /* right side of grh*/

  n = sprintf(p,"%s%s\n", &lf_mar[0], Grh_bottom_line1);
  f_docin_put(p,n);

  /* sideline out */
  if (global_flag_which_graph != 1) {  /* leave pipes on "J" in Jan */
    Grh_bottom_line2[0] = ' ';  /* 1st col, (sideline char) */
  }

  /* right side of grh*/
/*   Grh_bottom_line2[Num_eph_grh_pts] = ' ';  */
/*   Grh_bottom_line2[Num_eph_grh_pts-1] = 'Q';  */

  n = sprintf(p,"%s%s\n", &lf_mar[0], Grh_bottom_line2);
  f_docin_put(p,n);

  /* put year into line3 lf_mar 
  */
  sfill(mywk, SIZE_GRH_LEFT_MARGIN, ' ');
  sprintf(mywk,"%4d  ", Grh_beg_yr);    /* =magic */
  k = (int)strlen(lf_mar) -1 - 4;           /* 4= numchar in yr e.g. 1988 */
  strncpy(lf_mar+k, mywk, 4);

/*   n = sprintf(p,"%s%s\n", &lf_mar[0], Grh_bottom_line3); */

  strcpy(p,"\n");  /* blank line before line with month names   may 2014 */
  n = (int)strlen(p);
  f_docin_put(p,n);

  n = sprintf(p,"%s%s\n", &lf_mar[0], Grh_bottom_line3);
  f_docin_put(p,n);

}  /* end of prt_grh_bot() */


void put_fill_lines_at_bot(char p_line[0])  /* now top */
{
//trn("put_fill_lines_at_bot");
//ksn(p_line);
  int ibot;
  int dummy[1];
  static int bot_ln_ctr;
  ;
  dummy[0] = 0; /* init */
  if (False_bot >= Grh_bot) return;
  bot_ln_ctr = 0;
//tn();b(633);ki(ibot);ks(p_line); 
//kin(Num_file_lines_bot);
  for (ibot=1; ibot <= Num_file_lines_bot; ++ibot) {
    prt_grh_line(&p_line[0],dummy,0,&bot_ln_ctr,Grh_bot);
//tr("put_fill_lines_at_bot()"); ki(ibot); ksn(p_line); 
  }
} 


void reverse_grh_body_and_prt(void)  /* grh used to have high stress at top */
{
  int iprt, n, running_stress_level_on_line;
  char linebuf[2048];
  char *p = &Swk[0];
  char *q = &Grh_body[0];
  int we_have_hit_great_line;   /* 1=y,0=n */
  int we_have_hit_good_line;    /* 1=y,0=n */
  int we_have_hit_stress_line;  /* 1=y,0=n */
  int we_have_hit_omg_line;     /* 1=y,0=n */
  char myLastLine[2024];
  int  first_star_is_in_great, myidx;
  int  first_star_is_in_good;
  int  first_star_is_in_neutral;
  int  first_star_is_in_stress;
  int  first_star_is_in_omg;
  ;

  /* 20130911 ONLY use these flags to determine star coloring
  *  for good (green) and stress (red)
  */
  we_have_hit_great_line   = 0;  /* init to no */
  we_have_hit_good_line   = 0;  /* init to no */
  we_have_hit_stress_line = 0;  /* init to no */
  we_have_hit_omg_line = 0;  /* init to no */

/* tn();trn("in reverse_grh_body_and_prt()"); */

  if (Num_lines_in_grh_body-1 <  MAX_GRH_BODY_LINES-1) {
    iprt = Num_lines_in_grh_body-1;
  } else {
//tn();trn("HIT MAX_GRH_BODY_LINES = 333 ! a  holy cow");tn();
    iprt = MAX_GRH_BODY_LINES-1;
  }

  /* read thru Grh_body to see if "GREAT-" or "GOOD-" is first.
  *  (this is for coloring the first star lines.  we do not
  *   know if Great * or Good * level is first)
  */
  myidx = iprt;
  first_star_is_in_great    = 0;
  first_star_is_in_good     = 0;
  first_star_is_in_neutral  = 0;
  first_star_is_in_stress   = 0;
  first_star_is_in_omg      = 1;  // default
  for ( ;  myidx > -1  ; --myidx) {    /* iprt is num lines in grh body */
    strcpy(linebuf, q+myidx*(SIZE_GRH_LEFT_MARGIN+SIZE_EPH_GRH_LINE+1));
    if (strstr(linebuf, "GREAT")  != NULL) {
      first_star_is_in_great = 1;
      first_star_is_in_omg   = 0;
      break;
    }
    if (strstr(linebuf, "GOOD")   != NULL) {
      first_star_is_in_good = 1;
      first_star_is_in_omg  = 0;
      break;
    }
    if (strstr(linebuf, "STRESS")   != NULL) {
      first_star_is_in_neutral = 1;
      first_star_is_in_omg     = 0;
      break;
    }
    if (strstr(linebuf, "OMG")   != NULL) {
      first_star_is_in_stress = 1;
      first_star_is_in_omg    = 0;
      break;
    }
  }


  /* graph top (used to be on bot)
  *  this stress level num increases as graph moves down.
  */
  running_stress_level_on_line = Grh_bot; /* graph top (used to be on bot) */

int  have_printed_blank_top_line;  /*  take out */
  have_printed_blank_top_line = 0;

  for ( ;  iprt > -1  ; --iprt) {    /* iprt is num lines in grh body */


    strcpy(linebuf, q+iprt*(SIZE_GRH_LEFT_MARGIN+SIZE_EPH_GRH_LINE+1));


/*  show iprt and how many stars in linebuf  */
/* int starcnt; starcnt = scharcnt(linebuf, '*'); */
/* kin(iprt);ki(starcnt); */
/*  show iprt and how many stars in linebuf  */


    if (strstr(linebuf, "GREAT")  != NULL)   we_have_hit_great_line  = 1;
    if (strstr(linebuf, "GOOD")   != NULL)   we_have_hit_good_line   = 1;
    if (strstr(linebuf, "STRESS") != NULL)   we_have_hit_stress_line = 1;
    if (strstr(linebuf, "OMG")    != NULL)   we_have_hit_omg_line    = 1;



    /* we want no blank lines above the GOOD green line level (or GREAT
    *  They must contain a * or X.
    *  TOP LINE OF GRAPH CANNOT BE "EMPTY" of * or X  UNLESS it is GOOD line
    */

/* OLD */
/*         && we_have_hit_great_line == 0  */
/* trn("  !!!   no blank lines above GREAT line !!!"); */

    /* line contains no  * or X  */  
    /* this is bot/ now top line of all connect_CHARS (#)
    */
    if (   sall(linebuf, " |#") 
        && have_printed_blank_top_line == 0
        && we_have_hit_good_line == 0 ) {

        strcat(linebuf, "##");  /* weird bug fix */

      bracket_string_of("#", linebuf, "<span class=\"cSky\">", "</span>");
      scharswitch(linebuf, '#', ' ');

      scharswitch(linebuf, '|', ' ');  /* sideline out */

      n = sprintf(p,"%s\n", linebuf);
      f_docin_put(p,n);
      have_printed_blank_top_line = 1;

      continue;

    }

#ifdef PUT_BACK_COMMENTED_OUT_STUFF /****************************************/
#endif /* ifdef PUT_BACK_COMMENTED_OUT_STUFF ********************************/


/* if(i==41){strcpy(linebuf, "X  *X  *XX XX  XX   * X* X  *X  *XX XX  XX   * X* X  *X  *XX XX  XX   * X* X  *X  *XX XX  XX   * X*");} */
/* if(i==40){tn();tr("-----------ordinary(40) ----------line---");ksn(linebuf);tn();} */
/* if(i==41){strcpy(linebuf, "X  *X  *XX XX  XX   * X* X  *X  *XX XX  XX X * X* X  *X  *XX XX  XX   * X* X  *X  *XX XX *");} */
/* if(i==41){strcpy(linebuf, "       |X  *X  *XX XX  XX   * X* X  *X  *XX XX  XX X * X* X  *X  *XX XX  XX   * X* X  *X  *XX XX *|");} */
/* if(i==41){strcpy(linebuf, "       |                            *X  *XX XX  XX X * X* X  *X  *XX X                            |");}  */
/* if(i==41){strcpy(linebuf, "       |                            *X  *XX XX  XX X *                                            |");}  */


/* kin(running_stress_level_on_line); ki(Stress_val[SUBSCRIPT_FOR_LO_STRESS_LEVEL]); */
/*    if (running_stress_level_on_line < Stress_val[SUBSCRIPT_FOR_LO_STRESS_LEVEL] *//* is GOOD */

    /* here we have not hit the GREAT line OR the GOOD LINE 
    *  we are either  in Great color or GOOD color
    */
    if (   we_have_hit_great_line == 0
        && we_have_hit_good_line  == 0
        && strstr(linebuf, "GOOD") == NULL    /* not on GOOD line */
        && strstr(linebuf, "GREAT") == NULL ) /* not on GREAT line */
    {
      /* here we are in GREAT territory- color cGr2
      */
/*       strsubg(linebuf, "X ", "<span class=\"cGr2\">X</span> ");
*       strsubg(linebuf, " X", " <span class=\"cGr2\">X</span>"); 
*       strsubg(linebuf, "*" , "<span class=\"cGr2\">*</span>");
* 
*       strsubg(linebuf, 
*         "<span class=\"cGr2\">*</span><span class=\"cGr2\">*</span>",
*         "<span class=\"cGr2\">**</span>"
*       );
*       strsubg(linebuf, 
*         "<span class=\"cGr2\">**</span><span class=\"cGr2\">**</span>",
*         "<span class=\"cGr2\">****</span>"
*       );
*/
/*       bracket_string_of("X*", linebuf, "<span class=\"cGr2\">", "</span> "); */

      /* great or good
      */
      if (first_star_is_in_great == 1) {
        bracket_string_of("X", linebuf, "<span class=\"cGr2\">", "</span>");
      }
      if (first_star_is_in_good  == 1) {
        bracket_string_of("X", linebuf, "<span class=\"cGre\">", "</span>");
      }
      if (first_star_is_in_neutral  == 1) {
        bracket_string_of("X", linebuf, "<span class=\"cNeu\">", "</span>");
      }
      if (first_star_is_in_stress  == 1) {
        bracket_string_of("X", linebuf, "<span class=\"cRed\">", "</span>");
      }
      if (first_star_is_in_omg  == 1) {
        bracket_string_of("X", linebuf, "<span class=\"cRe2\">", "</span>");
      }

      scharswitch(linebuf, 'X', ' ');
      bracket_string_of("#", linebuf, "<span class=\"cSky\">", "</span>");
      scharswitch(linebuf, '#', ' ');
      scharswitch(linebuf, '|', ' ');  /* sideline out */

      /* turn star (*) into caret (^) with star color */
      bracket_string_of("*", linebuf, "<span class=\"star\">", "</span>");
      scharswitch(linebuf, '*', '^');

      n = sprintf(p,"%s\n", linebuf);
      f_docin_put(p,n);
      running_stress_level_on_line += SIZE_EPH_GRH_INCREMENT;
      continue;
    }

    /* here we have hit the GREAT line, but not the GOOD line
    *  we are in GOOD color
    **/
    if (   we_have_hit_good_line == 0 
        && strstr(linebuf, "GOOD") == NULL    /* not on GOOD line */
        && strstr(linebuf, "GREAT") == NULL ) /* not on GREAT line */
    {
      /* here we are in GOOD territory- color cGre
      */
/*       strsubg(linebuf, "X ", "<span class=\"cGre\">X</span> ");
*       strsubg(linebuf, " X", " <span class=\"cGre\">X</span>"); 
*       strsubg(linebuf, "*" , "<span class=\"cGre\">*</span>");
* 
*       strsubg(linebuf, 
*         "<span class=\"cGre\">*</span><span class=\"cGre\">*</span>",
*         "<span class=\"cGre\">**</span>"
*       );
*       strsubg(linebuf, 
*         "<span class=\"cGre\">**</span><span class=\"cGre\">**</span>",
*         "<span class=\"cGre\">****</span>"
*       );
*/
      bracket_string_of("X", linebuf, "<span class=\"cGre\">", "</span>");
      scharswitch(linebuf, 'X', ' ');
      bracket_string_of("#", linebuf, "<span class=\"cSky\">", "</span>");
      scharswitch(linebuf, '#', ' ');
      scharswitch(linebuf, '|', ' ');  /* sideline out */

      /* turn star (*) into caret (^) with star color */
      bracket_string_of("*", linebuf, "<span class=\"star\">", "</span>");
      scharswitch(linebuf, '*', '^');

      n = sprintf(p,"%s\n", linebuf);
      f_docin_put(p,n);
      running_stress_level_on_line += SIZE_EPH_GRH_INCREMENT;
      continue;
    }


    /*  we are in Neutral color  (no stress line yet) */
    if (   we_have_hit_stress_line == 0
        && strstr(linebuf, "GOOD") == NULL    /* not on GOOD line */
        && strstr(linebuf, "GREAT") == NULL) {/* not on GREAT line */
      bracket_string_of("X", linebuf, "<span class=\"cNeu\">", "</span>");
      scharswitch(linebuf, 'X', ' ');
      bracket_string_of("#", linebuf, "<span class=\"cSky\">", "</span>");
      scharswitch(linebuf, '#', ' ');
      scharswitch(linebuf, '|', ' ');  /* sideline out */
    }


    if (   we_have_hit_stress_line == 1
        && we_have_hit_omg_line != 1
        && strstr(linebuf, "STRESS") == NULL  /* not on STRESS line */
        && strstr(linebuf, "OMG")    == NULL) /* not on    OMG line */
    {
      /* here we are in STRESS territory- color Red
      */
/*       strsubg(linebuf, "X ", "<span class=\"cRed\">X</span> ");
*       strsubg(linebuf, " X", " <span class=\"cRed\">X</span>"); 
*       strsubg(linebuf, "*" , "<span class=\"cRed\">*</span>");
*/

      bracket_string_of("X", linebuf, "<span class=\"cRed\">", "</span>");
      scharswitch(linebuf, 'X', ' ');
      bracket_string_of("#", linebuf, "<span class=\"cSky\">", "</span>");
      scharswitch(linebuf, '#', ' ');
      scharswitch(linebuf, '|', ' ');  /* sideline out */

      /* turn star (*) into caret (^) with star color */
      bracket_string_of("*", linebuf, "<span class=\"star\">", "</span>");
      scharswitch(linebuf, '*', '^');

      n = sprintf(p,"%s\n", linebuf);
      f_docin_put(p,n);
      running_stress_level_on_line += SIZE_EPH_GRH_INCREMENT;
      continue;
    }


    if (   we_have_hit_omg_line == 1
        && strstr(linebuf, "OMG")    == NULL) /* not on    OMG line */
    {
      /* here we are in OMG territory- color Re2
      */
/*       strsubg(linebuf, "X ", "<span class=\"cRe2\">X</span> ");
*       strsubg(linebuf, " X", " <span class=\"cRe2\">X</span>"); 
*       strsubg(linebuf, "*" , "<span class=\"cRe2\">*</span>");
*/

      bracket_string_of("X", linebuf, "<span class=\"cRe2\">", "</span>");
      scharswitch(linebuf, 'X', ' ');
      bracket_string_of("#", linebuf, "<span class=\"cSky\">", "</span>");
      scharswitch(linebuf, '#', ' ');
      scharswitch(linebuf, '|', ' ');  /* sideline out */

      /* turn star (*) into caret (^) with star color */
      bracket_string_of("*", linebuf, "<span class=\"star\">", "</span>");
      scharswitch(linebuf, '*', '^');

      n = sprintf(p,"%s\n", linebuf);
      f_docin_put(p,n);
      running_stress_level_on_line += SIZE_EPH_GRH_INCREMENT;
      continue;
    }


    /* NOTE it looks like GREAT falls thru to here  (maybe the others) */

    /* turn star (*) into caret (^) with star color */
    bracket_string_of("*", linebuf, "<span class=\"star\">", "</span>");
    scharswitch(linebuf, '*', '^');



    n = sprintf(p,"%s\n", linebuf);
    f_docin_put(p,n);
    running_stress_level_on_line += SIZE_EPH_GRH_INCREMENT;

  }  /* for each line in grh body */

  /* put extra line at bottom for esthetics
  *  (saving last line preserves its color)
  */
  /* get color of last line and print an empty grh line with it */
/* tn();b(420);ksn(gbl_save_last_line); */
  if (strstr(gbl_save_last_line, "STRESS") == NULL) {  /* only if not on stress line */
//ksn("futdoc.c PPUTTING blank line 1");
    if (strstr(gbl_save_last_line, "cRed") != NULL) {
      sfill(myLastLine, Num_eph_grh_pts, ' '); 
      bracket_string_of(" ", myLastLine, "<span class=\"cRed\">", "</span>");
      n = sprintf(p,"       %s\n", myLastLine );  /* left margin = 7 spaces */
      f_docin_put(p,n);
//ksn("futdoc.c PPUTTING blank line 2");
    }
    if (strstr(gbl_save_last_line, "cRe2") != NULL) {
      sfill(myLastLine, Num_eph_grh_pts, ' '); 
      bracket_string_of(" ", myLastLine, "<span class=\"cRe2\">", "</span>");
      n = sprintf(p,"       %s\n", myLastLine );  /* left margin = 7 spaces */
      f_docin_put(p,n);
//ksn("futdoc.c PPUTTING blank line 3");
    }
  }


  scharswitch(gbl_save_last_line, 'X', ' ');
  scharswitch(gbl_save_last_line, '#', ' ');
  scharswitch(gbl_save_last_line, '*', ' ');
  scharswitch(gbl_save_last_line, '|', ' ');  /* sideline out */
/* b(300); */
  n = sprintf(p,"%s\n", gbl_save_last_line);
  f_docin_put(p,n);

}  /* end of reverse_grh_body_and_prt() */






/* with \n at end */
void prt_grh_line(char *p_line, int cols_with_pt[], int pt_ctr, int *p_ln_ctr, int top) 
{
  int ilin;
  ;

  ++Num_lines_in_grh_body;   // ----------------------------------------------------

  /* do not walk the plank */
  if (Num_lines_in_grh_body >= MAX_GRH_BODY_LINES)
  {
//tn();trn("HIT MAX_GRH_BODY_LINES = 333 ! b  holy cow");tn();
  return;
  }
 
  /* sideline out */
/*  p_line[0] = GRH_SIDELINE_CHAR; */ /* 1st col, (sideline char) */
/*  p_line[Num_eph_grh_pts-1] = GRH_SIDELINE_CHAR; */ /* right side of grh*/

  /* pts in graph  (these are the stars (*)  )
  */
  for (ilin=1; ilin <= pt_ctr; ilin++) {
    *(p_line+cols_with_pt[ilin]) = EPH_GRH_CHAR;
  } 


  /* try to avoid stars on the sideline  (jun 2013)
  * 1st col, (sideline char) 
  * right side of grh
  */
/*  weird */
  /* sideline out */
/*   p_line[0] = GRH_SIDELINE_CHAR;  */
/*   p_line[Num_eph_grh_pts-1] = GRH_SIDELINE_CHAR;  */

/*   p_line[0] = 'q';  */
/*   p_line[Num_eph_grh_pts-1] = 'q';  */
/* tn();kc(p_line[0]); kc(p_line[Num_eph_grh_pts-1]); */
  /*     *(SIZE_GRH_LEFT_MARGIN+SIZE_EPH_GRH_LINE+1),"%s%s\0", (warn on 0) */

  /* PUT LINE IN TBL
   */
  sprintf(  
    Grh_body + (Num_lines_in_grh_body-1) * 
               (SIZE_GRH_LEFT_MARGIN+SIZE_EPH_GRH_LINE+1),
    "%s%s",
    get_grh_left_margin(p_ln_ctr,top,p_line),
    p_line
  );

  strcpy(gbl_save_last_line, p_line);

  for (ilin=1; ilin <= pt_ctr; ilin++)
    *(p_line+cols_with_pt[ilin]) = GRH_CONNECT_CHAR;  /*ch pt to connect*/

  if (Just_did_good_line == 1) {
    Just_did_good_line = 0;
    undo_good_line(p_line);

    for (ilin=1; ilin <= pt_ctr; ilin++)
      *(p_line+cols_with_pt[ilin]) = GRH_CONNECT_CHAR;  /*ch pt to connect*/
  }
}  /* end of prt_grh_line() */

// from futdefs.h  -------------------------------------------------------------
//    #define SIZE_EPH_GRH_INCREMENT 6  /* 1 '*' for every 6 Grhdata score nums */
//    #define NUM_STRESS_LEVELS 8
//    #define SUBSCRIPT_FOR_VLO_STRESS_LEVEL 6   /* Stress_val[6] = vlo- "great"*/
//    #define SUBSCRIPT_FOR_LO_STRESS_LEVEL 5    /* Stress_val[5] = lo- "good" */
//    #define SUBSCRIPT_FOR_HIGH_STRESS_LEVEL 3  /* Stress_val[3] = hi-"stress" */
//    #define SUBSCRIPT_FOR_VHIGH_STRESS_LEVEL 2  /* Stress_val[3] = hi-"OMG" */
// from futdefs.h  -------------------------------------------------------------
//
// from futdoc.h  -------------------------------------------------------------
//    char *Stress_name[NUM_STRESS_LEVELS] = {
//      "       ",
//      "   OMG-",
//      "       ",
//      "STRESS-",
//      "       ",
//      "  GOOD-",
//      "       ",
//      " GREAT-",
//    };
//
// from futdoc.h  -------------------------------------------------------------

char *get_grh_left_margin(int *p_ln_ctr, int top, char *p_line)
{
  int this_line,ilef;
  static char l_mar[SIZE_GRH_LEFT_MARGIN+1];  /* must be static for */
  ;      /* return value to point to stable chars, not automatic */
  sfill(&l_mar[0],SIZE_GRH_LEFT_MARGIN,' ');  /* mk margin = blanks */
  if (*p_ln_ctr == -1)  return(&l_mar[0]);  /* bot line of dots */
  (*p_ln_ctr)++;  /* e.g. =3, this line about to be printed is 3rd line */
  this_line = top - (*p_ln_ctr-1) * SIZE_EPH_GRH_INCREMENT;
  for (ilef=0; ilef <= NUM_STRESS_LEVELS-1; ilef++) {
    if (this_line >= Stress_val[ilef]) {
      if (this_line < Stress_val[ilef] + SIZE_EPH_GRH_INCREMENT) {
        sprintf(&l_mar[0],"%s",Stress_name[ilef]);

/***
         if (ilef == SUBSCRIPT_FOR_LO_STRESS_LEVEL)  * "good line" *
***/
        if (ilef == SUBSCRIPT_FOR_LO_STRESS_LEVEL  ||
            ilef == SUBSCRIPT_FOR_HIGH_STRESS_LEVEL
        )  /* "good line or stress line" */
          put_good_line(p_line);
        return(&l_mar[0]);
      } else { 
      return(&l_mar[0]); 
      }
    }
  }
  return(&l_mar[0]);
}  /* end of get_grh_left_margin() */


void put_good_line(char *p_line)    /* put line marking "good" level */
{
  ;
#ifdef PUT_BACK_COMMENTED_OUT_STUFF /****************************************/
*   int i,k,leftmarg;
*   ;
*   leftmarg = SIZE_GRH_LEFT_MARGIN;
*   for (i=0,k=6; k <= Num_eph_grh_pts+leftmarg-5; k=k+6,++i) {
*     Good_save[i] = *(p_line+k);    /* chars to put back */
*     if (*(p_line+k) != EPH_GRH_CHAR)
*       *(p_line+k) = '-';      /* good line marker char */
*   }
*   Just_did_good_line = 1;
#endif /* ifdef PUT_BACK_COMMENTED_OUT_STUFF ********************************/
}

        
void undo_good_line(char *p_line)    /* take away line marking "good" level */
{
  ;
#ifdef PUT_BACK_COMMENTED_OUT_STUFF /****************************************/
*   int i,k,leftmarg;
*   ;
*   leftmarg = SIZE_GRH_LEFT_MARGIN;
*   for (i=0,k=6; k <= Num_eph_grh_pts+leftmarg-5; k=k+6,++i) {
*     *(p_line+k) = Good_save[i];    /* put back old non-goodline chars */
*   }
#endif /* ifdef PUT_BACK_COMMENTED_OUT_STUFF ********************************/
}

        
/* alt = 2nd parallel ar to be sorted along with v */
/* sorts y-axis value and moves x-axis around to keep them together */
/* v = Grhdata (2,4,5,7,or10), alt = Grh_colnum */
void sort_grh(int varg[], int n, int altarg[])
{
  int gap,jj,ii;
  int temp;
  int *v = varg;
  int *alt = altarg;
  ;
  for (gap=n/2; gap>0; gap /= 2) {
    for (ii=gap; ii<n; ii++) {
      for (jj=ii-gap; jj>=0 && *(v+jj) > *(v+jj+gap); jj -= gap) {
        temp = *(v+jj);
        *(v+jj) = *(v+jj+gap);
        *(v+jj+gap) = temp;
        temp = *(alt+jj);
        *(alt+jj) = *(alt+jj+gap);
        *(alt+jj+gap) = temp;
      }
    }
  }
}  /* end of sort_grh() */


void do_size_grh(void)
{
  int size_grh,topval,botval;  /* in print lines (at 12 lpi) */
  ;
  topval = Grh_top/SIZE_EPH_GRH_INCREMENT;
  botval = Grh_bot/SIZE_EPH_GRH_INCREMENT;
//
  size_grh = NUM_GRH_HDR_LINES 
      + Num_file_lines_top
      + topval - botval + 1
      + Num_file_lines_bot
      + NUM_GRH_BOT_LINES_ALL_DOTS
      + NUM_DATE_SCALE_LINES
      + NUM_LINES_DOC_FOOTER;  /* m3+m4 in doc */

  /* (at 12lpi) +2= grh title, +1= bot line all dots, */
  /* +2= date scale line */

}  /* end of do_size_grh() */


/* #include "futursmb.c" */

/* futursmb.c */

#ifdef PUT_BACK_COMMENTED_OUT_STUFF /****************************************/
* /* read futin, assign birth info to fields
* *
* */
* int get_fut_input(char *futin_pathname)
* {
*   int irk;
*   ;
* 
*   if (( Fp_futin_file = fopen( &futin_pathname[0] ,READ_MODE) )
*     == NULL) {
*     rkabort("future.c.  get_fut_input(). fopen().");
*   }
* 
*   init_bufs();
* 
*   for (irk=1; irk <= NUM_INPUT_ITEMS; ++irk) {  /* get input items */
*     rd_futin(&Inbuf[0],irk);
*     assign_fld(irk);              /* 0= normal end */
*   }  
*   fclose(Fp_futin_file);
*   if (equal(Is_ok,"n") || equal(Is_ok,"N")) return(0);
*   if (Num_past_units_ordered == 0  &&
*     Num_fut_units_ordered == 0) return(0);
*   return(1);    /* not eof */
* }  /* end of get_fut_input() */
#endif /* ifdef PUT_BACK_COMMENTED_OUT_STUFF ********************************/


#ifdef PUT_BACK_COMMENTED_OUT_STUFF /****************************************/
* void init_bufs(void)
* {
*   sfill(&fEvent_name[0],SIZE_INBUF,' ');
*   sfill(&Madd_last_name[0],SIZE_INBUF,' ');
*   sfill(&Madd_first_names[0],SIZE_INBUF,' ');
*   sfill(&Madd1[0],SIZE_INBUF,' ');
*   sfill(&Madd2[0],SIZE_INBUF,' ');
*   sfill(&City_town[0],SIZE_INBUF,' ');
*   sfill(&Prov_state[0],SIZE_INBUF,' ');
*   sfill(&Country[0],SIZE_INBUF,' ');
*   sfill(&Postal_code[0],SIZE_INBUF,' ');
*   sfill(&Letter_comment_1[0],SIZE_INBUF,' ');
*   sfill(&Letter_comment_2[0],SIZE_INBUF,' ');
*   sfill(&Is_ok[0],SIZE_INBUF,' ');
*   sfill(&Futin_filename[0],SIZE_INBUF,' ');
* }
* 
* 
* /* more on rd_futin() */
* /*                                     */
* /*   fgets return 0  -->  last_line  -->  last_line=""  -->  abort  */
* /*     |n          |n          |n          */
* /*     |          |          |            */
* /*     ok          abort          ok            */
* 
* void rd_futin(char *buf, int num_being_read)
* {
*   ;
*   sfill(&buf[0],SIZE_INBUF,' ');
*   if (rkfgets(&buf[0],SIZE_INBUF,Fp_futin_file) == NULL) {
*     if (num_being_read == NUM_INPUT_ITEMS 
* /*       && (i=equal(buf,NULL)) != NULL */
*       ) {
*       ;    /* ^no \n on last line is ok, except if last line = "" */
*     } else {
*       rkabort("future.c.  rd_futin(). fgets().");
*     }
*   }
* }  /* end of rd_futin() */
#endif /* ifdef PUT_BACK_COMMENTED_OUT_STUFF ********************************/


#ifdef PUT_BACK_COMMENTED_OUT_STUFF /****************************************/
* void assign_fld(int jrk)    /* put latest input into right field */
* {
*   #define SIZE_ORDNUM 5
*   int int_Inmn, int_Indy;
*   ;
*   switch (jrk) {    /* below "inbuf" should really be coded "&inbuf[0]" */
*     case  1: strcpy(fEvent_name,Inbuf);
*         if(sall(fEvent_name," ")) {
*           /* assume zero length input file */
*           unlink(Arg_futin_pathname);
*           exit(0);
*         }
*         break;
*     case  2: Inmn = atof(Inbuf); int_Inmn = atoi(Inbuf); break;
*     case  3: Indy = atof(Inbuf); int_Indy = atoi(Inbuf); break;
*     case  4: Inyr = atof(Inbuf); break;
*     case  5: Inhr = atof(Inbuf); break;
*     case  6: Inmu = atof(Inbuf); break;
*     case  7: Inap = atoi(Inbuf); break;
*     case  8: Incf = atoi(Inbuf); break;
*     case  9: break;  /* sex not used by future.c */
*     case 10: Intz = atof(Inbuf); break;
*     case 11: Inln = atof(Inbuf); strcpy(Ln_prt,Inbuf); break;
*     case 12: strcpy(Madd_last_name,Inbuf); break;
*     case 13: strcpy(Madd_first_names,Inbuf); break;
*     case 14: strcpy(Madd1,Inbuf); break;
*     case 15: strcpy(Madd2,Inbuf); break;
*     case 16: strcpy(City_town,Inbuf); break;
*     case 17: strcpy(Prov_state,Inbuf); break;
*     case 18: strcpy(Country,Inbuf); break;
*     case 19: strcpy(Postal_code,Inbuf); break;
*     case 20: Num_past_units_ordered = atoi(Inbuf); break;
*     case 21: Past_start_mn = atoi(Inbuf); break;
*         /*if =0, means future.c uses order_entry date minus 2 yrs */
*     case 22: Past_start_dy = atoi(Inbuf); break;
*     case 23: Past_start_yr = atoi(Inbuf); break;
*     case 24: Num_fut_units_ordered = atoi(Inbuf); break;
*     case 25: Fut_start_mn = atoi(Inbuf); break;  
*         /*if =0, means future.c uses order_entry date */
*     case 26: Fut_start_dy = atoi(Inbuf); break;
*     case 27: Fut_start_yr = atoi(Inbuf); break;
*     case 28: strcpy(Letter_comment_1,Inbuf); break;
*     case 29: strcpy(Letter_comment_2,Inbuf); break;
*     case 30: break; /* cents paid not used by future.c */
*     case 31: break; /* payment code not used by future.c */
*     case 32: break; /* ad code not used by future.c */
*     case 33: break; /* do a pp? not used by future.c */
*     case 34: break; /* comparison line not used by future.c */
*     case 35: break; /* units ordered daily not used by future.c */
*     case 36: break; /* daily start date mmddyy not used by future.c */
*     case 37: break; /* extra field#5 not used by future.c */
*     case 38: break; /* extra field#6 not used by future.c */
*     case 39: strcpy(Is_ok,Inbuf); break;
*     case 40: strcpy(Ordnum,Inbuf); break;
*     case 41: strcpy(Date_of_order_entry,Inbuf); break;
* /***
* old qnx name 16 chars
*     case 42: strcpy(&Futin_filename[0],Inbuf); break;  
*             * ^from mk_fut_input.c *
* ***/
*     case 42:
*       strcpy(Futin_filename,Inbuf);
* 
*       break;  
* 
*   }  /* end of switch */
* 
* }  /* end of assign_fld() */
#endif /* ifdef PUT_BACK_COMMENTED_OUT_STUFF ********************************/


#ifdef PUT_BACK_COMMENTED_OUT_STUFF /****************************************/
* /* this is to get around gets(), fgets()
* *  difference QNX v1.1 and v1.20
* *  \n here is NOT included as part of return string
* * this rkfgets() acts like old fgets() 
* */
* char *rkfgets(char *buf, int size_buf,FILE *fp_inputfile)  
* {
*   int n = size_buf;
*   char *p;
*   char *q = &buf[0];
*   ;
*   /*  fgets(buf,size_buf,fp_inputfile); */
*   fgetline(fp_inputfile,q,n);
*   p = strchr(q,'\n');  /* new qnx fn 02jan85 */
*   if (p == NULL) return(q);  /* no \n in buf */
*   *p = '\0';    /* replace \n with \0 (2 \0's in buf) */
*   return(q);
* }
#endif /* ifdef PUT_BACK_COMMENTED_OUT_STUFF ********************************/


void f_set_doc_hdr(void)
{
   int n;
   char *p = &Swk[0];

  /* html moved to fmt_f.awk, which looks for "[beg_topinfo1]
  */

  n = sprintf(p,"%s\n", "\n[beg_topinfo1]");
    f_docin_put(p,n);

  n = sprintf(p,"%s\n", "A Year in the Life");
  f_docin_put(p,n);   
  n = sprintf(p,"%s\n", &fEvent_name[0]); 
    f_docin_put(p,n);
 n = sprintf(p,"%s\n", year_in_the_life_todo_yyyy);
 f_docin_put(p,n);   

/*   n = sprintf(p,"<h1>&nbsp&nbsp&nbsp&nbsp A Year in the2Life &nbsp&nbsp<span style=\"font-size: 80%%;\">of %s</span> &nbsp&nbsp <span style=\"font-size:115%%;\"> %s </span><br></h1>",  */
/*   n = sprintf(p,"<h1>A Year in the2Life<span style=\"font-size: 80%%;\">of %s</span><span style=\"font-size:115%%;\"> %s </span><br></h1>",  */

/*   n = sprintf(p, */
/*       "<h1>A Year in the2Life<span style=\"font-size: 80%%;\">of %s</span> %s <br></h1>",  */
/*     &fEvent_name[0],  year_in_the_life_todo_yyyy); */
/*   f_docin_put(p,n);    */


  /*   n = sprintf(p,"%02d%3s%02d\n",
  *     (int)Fut_start_dy,
  *     N_mth[(int)Fut_start_mn],
  *     (int)Fut_start_yr - (int)Fut_start_yr/100 * 100 
  *   );
  */
 
  n = sprintf(p,"%s\n", "[end_topinfo1]");
  f_docin_put(p,n);

}  /* end of f_set_doc_hdr() */




/* void display_event_specs(char *prt_ordnum) */

#ifdef PUT_BACK_COMMENTED_OUT_STUFF /****************************************/
* /* 2013  no more of this */
* #define size_f1 18    /* for display_event_specs only */
* #define size_f2 5
* #define size_f3 5
* #define size_f4 20
* #define size_f5 17
* #define size_f6 31
* #define size_f7 35
* void display_event_specs(void)
* {
*   int i,idy,iyr,ihr,imu,od,oy,om;
*   char f2[size_f2+1], f3[size_f3+1];  /* blank fills */
*   char s1[6],s2[6];
*   int minit, deg;
*   int n;
*   char *p = &Swk[0];
*   ;
* 
*   n = sprintf(p,"%s\n", "\n[beg_topinfo2]");
*     f_docin_put(p,n);
* 
*   /* 1. of 5  first name
*   */
*   /* n = sprintf(p,"%s\n", scapwords(&fEvent_name[0])); */
*   n = sprintf(p,"%s\n", &fEvent_name[0]);
*     f_docin_put(p,n);
* 
* 
*   i = Inmn; idy=Indy; iyr=Inyr; ihr=Inhr; imu=Inmu;
*   od = atoi(sfromto(f2,Date_of_order_entry,7,8));  /* order day */
*   oy = atoi(sfromto(f2,Date_of_order_entry,3,4));
*   om = atoi(sfromto(f2,Date_of_order_entry,5,6));
* 
*   /* 2. of 5  birth time 03mar84 12:33pm (standard time)
*   */
*   n = sprintf(p,"%02d%s%d %02d:%02d%s%s\n",
*     idy,
*     N_mth[i],
*     iyr,
*     (ihr == 0)?12:ihr,
*     imu,
*     (Inap == 1)?"pm":"am",
*     " (standard time)"
*   );
*   f_docin_put(p,n);  
* 
*   /* 3. of 5  longitude
*   */
*   minit = atoi(sdecnum(s2,&Ln_prt[0]));
*   deg = abs(atoi(swholenum(s1,&Ln_prt[0])));
*   n = sprintf(p,"longitude %03d%s%02d\n",
*     deg,
*     (sfind(&Ln_prt[0],'-')? "e":"w"),
*     minit
*   );
*   f_docin_put(p,n);
* 
*   /* 4. of 5  order number
*   */
*   sfromto(f2,Ordnum,1,2);
*   sfromto(f3,Ordnum,3,5);
*   n = sprintf(p,"order number %s-%s\n",
*     f2,
*     f3);
*   f_docin_put(p,n);
* 
*   /* 5. of 5  run date
*   */
*   n = sprintf(p,"run date %02d%s%02d\n",
*     od,
*     N_mth[om],
*     oy
*   );
*   f_docin_put(p,n);   /* run date: */
* 
* 
*   n = sprintf(p,"%s", "[end_topinfo2]\n");
*     f_docin_put(p,n);
* 
* }  /* end of display_event_specs */
#endif /* ifdef PUT_BACK_COMMENTED_OUT_STUFF ********************************/


 

/* capitalizes all chars in s */
/* returns ptr to str s */
char *sallcaps(char *s)
{
  char *saveptr;
   ;
  saveptr = &s[0];
  for (; *s; ++s) *s = toupper( (int) *s);
   return(saveptr); 
} 


void f_display_positions(void)  /* now prints report title in title[] */
{
  int idsp,sign,min_in_sign,deg_in_sign,min_in_deg;
  char pos_str[(11+1)*(13+1)],lf_fill[5+1];  /* 11=numchar one str */
  char mid_fill[11+1];
        /* e.g. sun_10vir44  13=numelement (sun->plu + nod,asc,mc) */
  int n;
  char *p = &Swk[0];
  ;

//trn("in f_display_positions()");
  /* sprintf(pos_str+idsp*(11+1),"%s%s%02d%s%02d\0", warn on 0 */
  for (idsp=1; idsp <= NUM_PLANETS +3; ++idsp) {
    sign = get_sign(Ar_minutes_natal[idsp]);
    min_in_sign = Ar_minutes_natal[idsp] - (sign-1)*30*60;
    deg_in_sign = min_in_sign/60;
    min_in_deg  = min_in_sign - 60*deg_in_sign;
    sprintf(pos_str+idsp*(11+1),"%s%s%02d%s%02d",
      N_planet[idsp],   "_"      ,deg_in_sign,N_sign[sign],min_in_deg);
/*    N_planet[idsp],Prt_retro[idsp],deg_in_sign,N_sign[sign],min_in_deg); */
  }
  sfill(lf_fill,5,' ');  sfill(&mid_fill[0],11,' ');


  n = sprintf(p,"%s\n", "\n[beg_astrobuffs]");
    f_docin_put(p,n);

  n = sprintf(p,"%s\n", "--------for astrology buffs---------");
  f_docin_put(p,n);

  n = sprintf(p,"%s  %s  %s\n",
    pos_str+1*(11+1), pos_str+5*(11+1), pos_str+9*(11+1));
  f_docin_put(p,n);

  n = sprintf(p,"%s  %s  %s\n",
    pos_str+2*(11+1), pos_str+6*(11+1), pos_str+10*(11+1));
  f_docin_put(p,n);

  n = sprintf(p,"%s  %s  %s\n",
    pos_str+3*(11+1), pos_str+7*(11+1), pos_str+11*(11+1));
  f_docin_put(p,n);

  n = sprintf(p,"%s  %s  %s\n",
    pos_str+4*(11+1), pos_str+8*(11+1), pos_str+13*(11+1));
  f_docin_put(p,n);

  n = sprintf(p,"%s\n", "------------------------------------");
  f_docin_put(p,n);

  n = sprintf(p,"%s", "[end_astrobuffs]\n");
    f_docin_put(p,n);

}  /* end of f_display_positions() */


void do_day_stress_score_B(void)
{
//tn(); b(37);
//trn("in do_day_stress_score_B()");
////ks(stringBuffForStressScore);   stringBuffForStressScore NOT DEFINED HERE
//kin(gblTargetDayScore);
//ksn(gbl_csv_person_string);
  char s[8+1];
  double dmn,ddy,dyr,dstep;
  ;

  /* here start lines from  do_future() */

  sfill(s,8,' ');
  if (Fut_start_mn == 0) {    /* special signal from mk_fut_input.c */
    dmn = atof(sfromto(s,&Date_of_order_entry[0],5,6)); /* "yyyymmdd" */
    ddy = atof(sfromto(s,&Date_of_order_entry[0],7,8));
    dyr = atof(sfromto(s,&Date_of_order_entry[0],1,4));
  } else {
    dmn = (double) Fut_start_mn;
    ddy = (double) Fut_start_dy;
    dyr = (double) Fut_start_yr;
//    ddy = (double) 1 ;
  }

  init_rt();  /* now has more max aspects (1024) */

  dstep = 1.0;  /* do eph every day instead of every 2 */

  mk_new_date(&dmn,&ddy,&dyr,dstep);  /* init */

  /* these are needed for put_start_of_aspect();
  */
  Grh_beg_mn = (int)dmn; /* to be adjusted- set_grh_top_and bot()  */ 
  Grh_beg_dy = (int)ddy; /* so that arg date jogs with eph file   */  
  Grh_beg_yr = (int)dyr; /* dates, e.g. past is on Wed       */  
//tn();ki(Grh_beg_mn); ki(Grh_beg_dy); kin(Grh_beg_yr);
  /* here get_eph_data() is called
  */



  /* lines from  get_eph_data() */    /* lines from  get_eph_data() */    /* lines from  get_eph_data() */  /* lines from  get_eph_data() */
  /* lines from  get_eph_data() */    /* lines from  get_eph_data() */    /* lines from  get_eph_data() */  /* lines from  get_eph_data() */

//
//  /* Only free eph_space stuff if calloc_eph_space has run already
//  *  during this call to mamb_report_year_in_the_life()
//  */
//  if (is_first_calloc_eph_space == 1) {
//b(371);
//    is_first_calloc_eph_space = 0;
//  } else {
//b(372);
//    free(Grhdata_bestday);  Grhdata_bestday = NULL;
//    free(Eph_buf_bestday);  Eph_buf_bestday = NULL;
//  }
//

  Num_eph_grh_pts = 366;  /* hard code for score_B */


//trn("no more part a");

  // PART A  CALLOC *_bestday   (PART B BELOW)           // BESTDAY ALLOC_FREE
  /* calloc eph space for score_B  (use _bestday vars)   // BESTDAY ALLOC_FREE   // allocated guys are defined in futdoc.h
  */
//trn("calloc eph space for score_B  (use _bestday vars) - BESTDAY ALLOC_FREE");
  if ((Grhdata_bestday = (int *)  calloc((NUM_EPH_GRAPHS-1)*Num_eph_grh_pts,sizeof(int))) == NULL)                                 // BESTDAY ALLOC_FREE
  {
    rkabort("future.c  not enough memory for calloc Grhdata_bestday");
  }
  if ((Eph_buf_bestday =  (struct Futureposrec_bestday*) calloc(Num_eph_grh_pts+1,sizeof(struct Futureposrec_bestday)))  == NULL)  // BESTDAY ALLOC_FREE
                                                                             /* ^ (add one for zeroth (ctrl) rec) */
  {
    rkabort("future.c  not enough memory for calloc Eph_buf_bestday");
  }



/*  */

  Eph_rec_every_x_days = 1;   /* NOT this ->  STEP_SIZE_FOR_FUT */

    /* here start lines from  fill_eph_buf() */

// NO privacy 20150211  can guess birth info
//    /* get month and day to start the first graph
//    */
//    if (strcmp(year_in_the_life_todo_yyyy, year_of_birth) == 0) {
//      Grh_beg_mn = atoi(mth_of_birth);
//      Grh_beg_dy = atoi(day_of_birth); 
//    } else {
//      Grh_beg_mn = 1;
//      Grh_beg_dy = 1; /*  old was 2 */
//    }
//
      Grh_beg_mn = 1;
      Grh_beg_dy = 1; /*  old was 2 */


    Grh_beg_yr =  atoi(year_in_the_life_todo_yyyy);
//tn();b(373);
//ksn(year_in_the_life_todo_yyyy);
//ki(Grh_beg_mn); ki(Grh_beg_dy); kin(Grh_beg_yr);
//trn("calling fill_eph_buf_score_B()");

    fill_eph_buf_score_B(); /* see fill_eph_buf_by_calc();   */

    /* end of  lines from  fill_eph_buf() */

  /* lines from  get_eph_data() */    /* lines from  get_eph_data() */    /* lines from  get_eph_data() */  /* lines from  get_eph_data() */
  /* lines from  get_eph_data() */    /* lines from  get_eph_data() */    /* lines from  get_eph_data() */  /* lines from  get_eph_data() */




  /* here we have all the Eph_data_score_B populated */

  /* start of lines from do_grh_calcs_and_prt() */


  int itrn_plt, inatal_plt, iday_num, aspect_num ;
  int starting_natal_plt;

  starting_natal_plt = 1;  /* set default */



  //  get rid of this "error" :  Loop will run at most once (loop increment never executed) 
  //    by commenting out line below
  //  for (iday_num=1; iday_num <= Num_eph_grh_pts; ++iday_num)      {   /* day_num */
    iday_num = 1;

//trn("");
    for (itrn_plt=0; itrn_plt <= NUM_PLANETS_TRN_BESTDAY-1; ++itrn_plt) {  /* 0->7 */

      for (inatal_plt=starting_natal_plt; inatal_plt <= NUM_PLANETS; ++inatal_plt) {

//trn("doing...");ki(itrn_plt);ki(inatal_plt);

        aspect_num = isaspect(
          abs((Eph_buf_bestday+iday_num)->positions[itrn_plt] - Ar_minutes_natal[inatal_plt]),
          (inatal_plt-1)*(NUM_ASPECTS+1)
        );

        if(aspect_num != 0) {   /* add_aspect_to_grhdata() */ 
          add_aspect_to_grhdata_bestday(inatal_plt, aspect_num, itrn_plt, iday_num);
        }

      } /* nat plt */

    } /* trn plt */
//trn("");



      /* are we finished ?
      */
/*     if (is_target_day_completed(iday_num) == 1) { */



      gblTargetDayScore= *(Grhdata_bestday + iday_num-1);
//trn("SETTING gblTargetDayScore in do_day_stress_score_B()");
//kin(gblTargetDayScore);
////ks(stringBuffForStressScore);   stringBuffForStressScore NOT DEFINED HERE

/*   show all grhdata_bestday */
    /* calibrate */
/*   double ddmn,dddy,ddyr,ddstep; int myii;
*     ddstep = (double)(Eph_rec_every_x_days);
*     ddmn = (double) Fut_start_mn;
*     dddy = (double) Fut_start_dy;
*     ddyr = (double) Fut_start_yr;
* fprintf(stderr, "\n\nshow all grhdata_bestday\n");
* for (myii=1; myii <= iday_num; ++myii) {
* 
* 
*  int mytempn;
*     mytempn = (*(Grhdata_bestday + (myii-1)) * -1 ) ;
*     if (mytempn <= 0) mytempn = 1;
*     fprintf(stderr,"%d\n", mytempn); 
* 
*     fprintf(stderr,"%s|%d|%04d|%02d|%02d|%d|\n",  fEvent_name, myii,
*         (int)ddyr,
*         (int)ddmn,
*         (int)dddy,
*         *(Grhdata_bestday + (myii-1) )
*     );
* }
*/
/*   show all grhdata_bestday */



/*     mk_new_date(&ddmn,&dddy,&ddyr,ddstep); */

//trn("no more part b");

  // PART B  FREE  *_bestday   (PART A ABOVE)            // BESTDAY ALLOC_FREE
  /* FREE eph space for score_B  (use _bestday vars)     // BESTDAY ALLOC_FREE
  */
//trn("FREE eph space for score_B  (use _bestday vars) - BESTDAY ALLOC_FREE");
    free(Grhdata_bestday);  Grhdata_bestday = NULL;     // BESTDAY ALLOC_FREE   // defined in futdoc.h
    free(Eph_buf_bestday);  Eph_buf_bestday = NULL;     // BESTDAY ALLOC_FREE   // defined in futdoc.h






//trn(" return;    * to call of do_day_stress_score_B(void) * ");
      return;    /* to call of do_day_stress_score_B(void) */

/*     } */

  //  get rid of this "error" :  Loop will run at most once (loop increment never executed)
  //    by commenting out line below
  //  } /* daynum */


} /* end of do_day_stress_score_B(void) */




#ifdef PUT_BACK_COMMENTED_OUT_STUFF /****************************************/
* int is_target_day_completed(int iday_num)  /* return 1=yes,0=no  iday_num is one-based */
* {
*   double d_dy,d_mn,d_yr,d_step, d_jd_current, d_jd_target;   /* jd=julian date */
*   int    i_jd_current, i_jd_target;   /* jd=julian date */
* 
* /* tn(); trn("in is_target_day_completed()"); */
* /* kin(daynum);ki(current_score); */
* /* kin(Grh_beg_mn); ki(Grh_beg_dy); ki(Grh_beg_yr); */
* 
*   /* get current date  into d_mn, d_dy, d_yr
*   */
*   d_mn = (double)Grh_beg_mn;
*   d_dy = (double)Grh_beg_dy;
*   d_yr = (double)Grh_beg_yr;
* 
*   d_step = (double)((iday_num-1) * Eph_rec_every_x_days);
* 
*   mk_new_date(&d_mn, &d_dy, &d_yr, d_step);
* 
* 
*   /* compare current date to target date for "Best Day" rpt
*   *  by converting to julian dates
*   */
*   if ((int)d_yr !=  gbl_bd_year) return(0);
* 
*   d_jd_current = day_of_year(d_yr, d_mn, d_dy);
*   d_jd_target  = day_of_year(
*     gbl_bd_year,         /* doubles */
*     gbl_bd_mth,
*     gbl_bd_day
*   );
*   i_jd_current = (int)d_jd_current;
*   i_jd_target  = (int)d_jd_target ;
* 
* /* kin(i_jd_current); ki(i_jd_target); */
* 
* 
*   if (i_jd_current == i_jd_target) return(1);
*   else                             return(0);
* 
* } /* end of  is_target_day_completed(int iday_num) */
#endif /* ifdef PUT_BACK_COMMENTED_OUT_STUFF ********************************/


/* modified from fill_eph_buf_by_calc(); 
*/
void fill_eph_buf_score_B(void)
{
  double m,d,y,step;
  int grh_pt, idx , minits;


  // =====================================
  // horrible bug here when these were length [8]
  //
  // char  s_hours[8] , s_long[8]  ;    // BAD BUG
  //
  //  FYI   __gbl_csv_person_string=[joris,4,13,1964,12,01,1,5,79.25]__
  //  length 8 should have been  long enough for "5" and "79.25"
  //  BUT log showed
        //  _s_hours=[5]__                      LENGTH = 1
        //  _s_long=[79.25                 ]__  LENGTH = 22  ?  <<<<<<<<<<---==
        //
  // =====================================
  //
  //       char   s_hours[8], s_long[8];
  //
  //  FYI   __gbl_csv_person_string=[joris,4,13,1964,12,01,1,5,79.25]__
  // here is the bad log
        //
        //  _(fill_eph_buf_score_B)__
        //  _step=[1        ]___d_long=[79.25    ]__
        //  _d_hours=[0        ]___gbl_bd_year=[2020     ]___gbl_bd_mth=[3        ]__
        //  _gbl_bd_day=[11       ]___Num_eph_grh_pts=[1]__
        //  _( here get_eph_data() ends )__
        //  _( end of fill_eph_buf_score_B() )__
        //
        //
  // somehow d_hours was = 0 ?
  //
  // char  s_hours[8] , s_long[8]  ;    // BAD BUG
  //
//  char    s_hours[128], s_longitude[128];    // GOOD  CORRECTION
  char    s_hours[1024], s_longitude[1024];    // GOOD  CORRECTION
  //
  // =====================================
  // horrible bug here when these were [8]
  // =====================================



  double d_hours;
  double d_longitude;
//tn();trn("fill_eph_buf_score_B");

  /* init */
  gbl_beg_last_mth_write = 0; /* beg col of mth name last written */
  gbl_end_last_mth_write = 0; /* end col of mth name last written */

  step = (double) Eph_rec_every_x_days;
  /* init first day to calc */
/*   m = (double) Grh_beg_mn; */
/*   d = (double) Grh_beg_dy; */
/*   y = (double) Grh_beg_y; */
  /* new   do only target day */



  /* get hours diff from greenwich and longitude
  * e.g.  "Delia,12,13,1971,12,15,0,-1,-19.05" 
  */
  strcpy(s_hours, csv_get_field(gbl_csv_person_string, ",", 8));
  strcpy(s_longitude,  csv_get_field(gbl_csv_person_string, ",", 9));
  strim(s_hours," ");
  strim(s_longitude," ");

  d_hours      = atof(s_hours);
  d_longitude  = atof(s_longitude);

  d_hours      = (double) d_hours;
  d_longitude  = (double) d_longitude;


// for all 366 days
// only from target date - 10 ?
// only to target date
//

  Num_eph_grh_pts = 1;  /* new   do only target day */

  m = (double) gbl_bd_mth;
  d = (double) gbl_bd_day;
  y = (double) gbl_bd_year;         /* doubles */

// hangs here on second bestday report

  for (grh_pt=1; grh_pt <= Num_eph_grh_pts; grh_pt++) {  /* now only 1 day (target) */
//trn("loop top");
//kdn(m);
//kdn(d);
//kdn(y);
//kdn(d_longitude);
//kdn(d_hours);


    /* time = 12 noon */
    calc_chart(m,d,y,0.0,1.0,1.0,d_hours,d_longitude,0.0);  /* calcchrt.c wants 0 for hr=12*/

    /* do sun,mer,ven,mar first   then MOON
    */
    for (idx=1; idx <= 4; ++idx) {   /*  sun,mer,ven,mar (in Arco) */
      /* double Arco[14];        positions  are in following order:
      *     xxx,sun,mer,ven,mar,jup,sat,ura,nep,plu,moo,nod,asc,mc_
      * index 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13
      *                       x                          
      */
      minits = get_minutes(Arco[idx]);
      (Eph_buf_bestday + grh_pt)->positions[idx-1] = minits;   /* <=== */

    }
    /* do sun,mer,ven,mar first,  then MOON at 10am,1pm,4pm,7pm
    */
    calc_chart(m,d,y,10.0,1.0,0.0,d_hours,d_longitude,0.0);  /* calcchrt.c wants 0 for hr=12*/
    minits = get_minutes(Arco[10]);   /* Arco [10] = MOON, positions [4->7] = MOON */
    (Eph_buf_bestday + grh_pt)->positions[4] = minits;  /* MOON  10 am  */

    calc_chart(m,d,y, 1.0,1.0,1.0,d_hours,d_longitude,0.0);
    minits = get_minutes(Arco[10]); 
    (Eph_buf_bestday + grh_pt)->positions[5] = minits;  /* MOON   1 pm  */

    calc_chart(m,d,y, 4.0,1.0,1.0,d_hours,d_longitude,0.0);
    minits = get_minutes(Arco[10]);  
    (Eph_buf_bestday + grh_pt)->positions[6] = minits;  /* MOON   4 pm  */

    calc_chart(m,d,y, 7.0,1.0,1.0,d_hours,d_longitude,0.0);
    minits = get_minutes(Arco[10]);   
    (Eph_buf_bestday + grh_pt)->positions[7] = minits;  /* MOON   7 pm  */


    mk_new_date(&m,&d,&y,step);
//trn("loop bot");
  }
//trn("finished loop");

/* show all Eph_buf_bestday positions trnplt=sun,mer,ven,m10,m01,m04,m07   for test
*/
/* fprintf(stderr,"\n\nshow all Eph_buf_bestday\n");
* int mydeg, mymin, mysgn;  char mytrn[8],smysgn[8];
* for (grh_pt=1; grh_pt <= Num_eph_grh_pts; grh_pt++) {
*   fprintf(stderr,"\n%03d|",grh_pt);
*   for (idx=0; idx <= 7; ++idx) {  
* 
*     mydeg = (Eph_buf_bestday + grh_pt)->positions[idx] / 60;
*     mysgn = (mydeg / 30) + 1;
*     mydeg = mydeg - ((mysgn - 1) * 30);
*     mymin = (Eph_buf_bestday + grh_pt)->positions[idx] % (60*30);
*     mymin = mymin % 60;
*     strcpy(mytrn,N_planet_bestday[idx]);
*     strcpy(smysgn,N_sign[mysgn]);
*     fprintf(stderr,"%s|%02d|%02d|",  smysgn,mydeg,mymin);
* 
*   }
* }
*/
/* show all Eph_buf_bestday */


//trn(" here get_eph_data() ends ");
//trn(" end of fill_eph_buf_score_B() ");
//tn();

} /* end of fill_eph_buf_score_B() */




char *gbl_space_for_HTML_fut;  // space malloc'ed in js

// ==============================  BIG report renamed functions  ===============================
// ==============================  BIG report renamed functions  ===============================
// ==============================  BIG report renamed functions  ===============================
//int mamb_BIGreport_year_in_the_life(  /* called from cocoa */
//  char *instructions,  is  like  "return only year stress score" 
/* called from cocoa */
//char *mamb_report_big_year(
//  char *html_f_file_name,
//  char *csv_person_string,
//  char *year_todo_yyyy,
//  char *instructions,
//  char *stringBuffForStressScore
//  )
char *mamb_report_big_year(  /* in futdoc,   called from cocoa */ 
  char *html_f_file_name,         // not used
  char *arg_space_for_HTML_fut,   // space malloc'ed in js
  char *csv_person_string,
  char *year_todo_yyyy,
  char *instructions,             // like  "return only year stress score" or  "return only thumbnail data" or "do Sine Wave data collection"
  char *stringBuffForStressScore  // 
)
{
  gbl_year_todo_yyyy_INT = atoi(year_todo_yyyy);

  gbl_space_for_HTML_fut = arg_space_for_HTML_fut; // space malloc'ed in js

//tn();trn("in mamb_report_big_year"); 
tr("\nin mamb_report_big_year"); ksn(year_todo_yyyy);
//ksn(html_f_file_name);
//trn("2nd arg is arg_space_for_HTML_fut");
ksn(csv_person_string);
ksn(year_todo_yyyy);
ksn(instructions);
//ksn(stringBuffForStressScore);
//int rkitst;
//rkitst = 123;
//kin(rkitst);

  int n, retval;      /* n used everywhere for "f_docin_put(p, n);" */
  char *p = &Swk[0];  /* p used everywhere for "f_docin_put(p, n);" */
  char s[128];
  int tempnum_x;
  int tempnum_y;
  int tempnum_z;
  int worknum2;  /* calibrate stress score for return value */
/*  int worknum3; */ /* calibrate stress score for return value */
  ;


//trn("");
//trn("all0of P_asp_tbl  TOP of mamb_report_big_year()");
//
//char tstfrom[32];
//char tstto[32];
//char tstnp[32];
//char tstasp[32];
//char tsttp[32];
//char tst128a[128];
//for (int ib=0; ib <= Asp_tbl_idx; ++ib) { 
////extern char *sfromto(char *dest,char *src, int beg, int end);
//sfromto(tstfrom,P_asp_tbl[ib], 1, 8);
//sfromto(tstnp  ,P_asp_tbl[ib], 9,10);
//sfromto(tsttp  ,P_asp_tbl[ib],11,12);
//sfromto(tstasp ,P_asp_tbl[ib],13,14);
//sfromto(tstto,  P_asp_tbl[ib],15,22);
//
//sprintf(tst128a, "%s_%s_%s  %s to %s  asp=%s",
//  N_planet[atoi(tstnp)], N_aspect[atoi(tstasp)], N_trn_planet[atoi(tsttp)], tstfrom, tstto, tstasp);
//ksn(tst128a);
//}
//trn("all0of P_asp_tbl  TOP of mamb_report_big_year()");
//trn("");
//

  is_first_f_docin_put         = 1;  /* 1=yes, 0=no */
  is_first_calloc_eph_space    = 1;  /* 1=yes, 0=no */
  is_first_set_grh_top_and_bot = 1;  /* 1=yes, 0=no */
  is_first_put_grh_scale_dates = 1;  /* 1=yes, 0=no */

  strcpy(gbl_csv_person_string, csv_person_string);

  char mybirthyear[8];
  strcpy(mybirthyear, csv_get_field(csv_person_string, ",", 4));
  if (strcmp(mybirthyear, year_todo_yyyy) == 0) {
    gbl_is_first_year_of_life = 1;  /* year todo = birthyear */
  } else {
    gbl_is_first_year_of_life = 0;
  }


  memcpy(gbl_thumbnailInfo, "\0", 4096); /* init */

  gbl_topToGreatLine  = 0;        // count of lines from top of thumbnail tn to green great line
  gbl_botToStressLine = 0;       // count of lines from bot of thumbnail tn to red stress  line
  gbl_hitGreatLine    = 0;          // 0=no  1=yes
  gbl_hitStressLine   = 0;         // 0=no  1=yes
//  fopen_fpdb_for_debug();


  // =============================================
  // =============================================
  //
  strcpy(gbl_instructions, instructions);
  //
  // =============================================
  // =============================================


  if (strcmp(gbl_instructions, "do Sine Wave data collection") == 0)
  {
    strcpy(gbl_PSV_of_SW_CSVs, "");   // this is updated after each aspect in this current calendar year is "finished"

//trn("SET gbl_PSV_of_SW_CSVs");
//ksn(gbl_PSV_of_SW_CSVs);
// for test
//int  how_many_csvs = scharcnt(gbl_PSV_of_SW_CSVs, '|'); 
//tr("num SW_CSVs in gbl_PSV_of_SW_CSVs"); kin(how_many_csvs);

  }

    /* note below:   NEW VERSION of DAY STRESS SCORE =  "B"
    *  gbl_instructions,  "return only day stress score_B")
    */
  if(strcmp(gbl_instructions,  "return only year stress score") == 0) {
//trn("BIGreport_y   year score only  - no docin_puts  3865");
    allow_docin_puts = 0;

    strcpy(gbl_yyyymmdd_todo, ""); 

    strcpy(year_in_the_life_todo_yyyy, year_todo_yyyy);

  }

//  else if(strcmp(gbl_instructions,  "return only day stress score") == 0) {
//b(68);
//    allow_docin_puts = 0;
//
//    strcpy(gbl_yyyymmdd_todo, year_todo_yyyy); /* danger - re-use arg field here */
//    /* (danger re-used arg has dd added to date) */
//
//    strcpy(year_in_the_life_todo_yyyy, sfromto(s,&year_todo_yyyy[0],1,4));
//
//    gbl_bd_mth  = atof(sfromto(s,&gbl_yyyymmdd_todo[0],5,6));
//    gbl_bd_day  = atof(sfromto(s,&gbl_yyyymmdd_todo[0],7,8));
//    gbl_bd_year = atof(sfromto(s,&gbl_yyyymmdd_todo[0],1,4));
//
//  }
//


  else if(strcmp(gbl_instructions,  "return only day stress score_B") == 0) {
/* ksn(gbl_instructions);
* tn(); b(36); ks(stringBuffForStressScore);
* b(37);
* ki(gblTargetDayScore);
* b(4);
* b(38);
* ksn(gbl_csv_person_string);
* b(39);
*/
    allow_docin_puts = 0;

    strcpy(gbl_yyyymmdd_todo, year_todo_yyyy); /* danger - re-use arg field here */
    /* (danger re-used arg has dd added to date) */

    strcpy(year_in_the_life_todo_yyyy, sfromto(s,&year_todo_yyyy[0],1,4));

    gbl_bd_mth  = atof(sfromto(s,&gbl_yyyymmdd_todo[0],5,6));
    gbl_bd_day  = atof(sfromto(s,&gbl_yyyymmdd_todo[0],7,8));
    gbl_bd_year = atof(sfromto(s,&gbl_yyyymmdd_todo[0],1,4));

/*  */
  }

//  else if(strcmp(gbl_instructions,  "do day stress report and return stress score") == 0) {
//// b(5);tn();
//// trn("BIG");ksn( gbl_csv_person_string); 
//
//    allow_docin_puts = 0;   /* so short we can hard code html with no docin_puts */
//
//    strcpy(gbl_yyyymmdd_todo, year_todo_yyyy); /* danger - re-use arg field here */
//    /* (danger re-used arg has dd added to date) */
//
//    strcpy(year_in_the_life_todo_yyyy, sfromto(s,&year_todo_yyyy[0],1,4));
//
//    gbl_bd_mth  = atof(sfromto(s,&gbl_yyyymmdd_todo[0],5,6));
//    gbl_bd_day  = atof(sfromto(s,&gbl_yyyymmdd_todo[0],7,8));
//    gbl_bd_year = atof(sfromto(s,&gbl_yyyymmdd_todo[0],1,4));
///*  */
//
//  }
//

  else {                 /* "normal" fut run */
    allow_docin_puts = 1;

    strcpy(gbl_yyyymmdd_todo, ""); 

    strcpy(year_in_the_life_todo_yyyy, year_todo_yyyy);
  }

  gbl_in_stress     = 0;  /* init */
  gbl_out_of_stress = 0;  /* new in sep2013 */


  /* left-overs from input changes
  */
  fPI_OVER_2 = 3.1415926535897932384 / 2.0;
  sfill(&fEvent_name[0],SIZE_INBUF,' ');

  Num_fut_units_ordered = 2;   /* for a-year-in-the-life */

  /* get event details here
  */
  process_input(csv_person_string);  /* prep for calc_chart() */
  /*  input args to calc_chrt() 
  *  mth  date of birth 
  *  day 
  *  year 
  *  hour 
  *  minute 
  *  am,0 or pm,1 
  *  dob_city_diff_hrs_from_greenwich 
  *  dob_city_longitude 
  *  "0.0"  for latitude, take equator, equal house from mc 
  */
  calc_chart(fInmn,fIndy,fInyr,fInhr,fInmu,fInap,fIntz,fInln,fInlt);

  /*   f_display_positions(); for test  */

  GRH_BACKGROUND_CHAR = 88;  /* used to be arg */
  TITLE_LINE_CHAR     = 42;  /* used to be arg */

  /* do not worry about time of day confidence - say its 100% 
  */
  House_confidence = 1;
  Moon_confidence = 1;
  Moon_confidence_factor = 1.0; 

  /* fill natal position tbl, Ar_minutes_natal, incl mc
  */
  /* double Arco[14];        positions  are in following order:
  *     xxx,sun,mer,ven,mar,jup,sat,ura,nep,plu,moo,nod,asc,mc_
  * index 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13
  *
  *    BUT
  * Ar_minutes_natal[1]   sun
  * Ar_minutes_natal[2]   moo
  * Ar_minutes_natal[3]   mer
  * Ar_minutes_natal[4]   ven
  * Ar_minutes_natal[5]   mar
  * Ar_minutes_natal[6]   sat
  * Ar_minutes_natal[7]   jup
  * Ar_minutes_natal[8]   ura
  * Ar_minutes_natal[9]   nep
  * Ar_minutes_natal[10]  plu
  * Ar_minutes_natal[11]  nod
  * Ar_minutes_natal[12]  asc
  * Ar_minutes_natal[13]  mc_
  */
  put_minutes(&Ar_minutes_natal[0]); 

  /*  set aspect ranges */
  put_aspect_ranges(&Orbs_trn[0],&Orb_trn_adj_for_nat[0]);


  /* this is 1st output to docin file 
  */
  f_set_doc_hdr();  /* -- this is 1st output to docin file -- */

  Is_past = 0;    /* 0= doing future, not past */



    /* note below:   NEW VERSION of DAY STRESS SCORE =  "B"
    *  gbl_instructions,  "return only day stress score_B")
    */
  /* ########################################################### */
  if(strcmp(gbl_instructions,  "return only day stress score_B") == 0) {

    do_day_stress_score_B();  /* calcs  gblTargetDayScore; */

/* 
* tn();b(44);ki(worknum);
*     worknum = mapNumStarsToBenchmarkNum(IDX_FOR_SCORE_B, worknum);
* tn();b(45);ki(worknum);
*     worknum = mapBenchmarkNumToPctlRank(worknum);
* b(46);ki(worknum);
*       gblTargetDayScore= *(Grhdata_bestday + iday_num-1);
* 
*/

  }

//  else if(strcmp(gbl_instructions,  "do day stress report and return stress score") == 0) {
//// b(6);tn();
//// trn("BIG");ksn( gbl_csv_person_string); 
//    int itarget_mm;
//    int itarget_dd;
//    int itarget_yyyy;
//
//    do_day_stress_score_B();  /* calcs  gblTargetDayScore; */
//
//    itarget_mm   = atof(sfromto(s,&gbl_yyyymmdd_todo[0],5,6));
//    itarget_dd   = atof(sfromto(s,&gbl_yyyymmdd_todo[0],7,8));
//    itarget_yyyy = atof(sfromto(s,&gbl_yyyymmdd_todo[0],1,4));
//
///*  */
//    retval = make_calendar_day_html_file(  /* in futhtm.c */
//      html_f_file_name,
//      csv_person_string,
//      itarget_mm,
//      itarget_dd,
//      itarget_yyyy,
//      gblTargetDayScore
//    );
//
//
//    /* set up return value to mamb_report_year_in_the_life()
//    */
//    int worknum;  /* calibrate stress score for return value */
//
///*     worknum = gbl_stress_score_for_target_day; */
//    worknum = gblTargetDayScore;
//    worknum = worknum * -1; 
//    worknum = worknum + 900;
//    if (worknum <= 0) worknum = 1;
///* tn();b(44);ki(worknum); */
//    worknum = mapNumStarsToBenchmarkNum(IDX_FOR_SCORE_B, worknum);
///* tn();b(45);ki(worknum); */
//    worknum = mapBenchmarkNumToPctlRank(worknum);
///* b(46);ki(worknum); */
//
///*  */
//    sprintf(stringBuffForStressScore, "%d", worknum);
//
//
//    if (retval != 0) {
//      f_docin_free();      /* free all allocated array elements */
//      rkabort("Error: html file (fut) was not produced");
//    }
//
//    /* put back settings
//    */
//    gblTargetDayScore= 0; /* for best day on ... rpt */
//    gblWeHaveTargetDayScore= 0; /* 1=yes,0=no */
//    strcpy(gbl_instructions,  "");  /* init gbl */
//    allow_docin_puts = 1;           /* init gbl */
////    fclose_fpdb_for_debug();
//// b(7);tn();
//// trn("BIG end 1");
//    return(0);
//
//  }
//

  else {
trn("beginning do_BIGfuture()");
    do_BIGfuture();    /* deep in here, eph_space ALLOCed */ // ----------------------

  }
  /* ########################################################### */



  f_display_positions();  /* put on bottom of docin_lines */

  n = sprintf(p,"\n[end_program]\n");
  f_docin_put(p, n);

  free_eph_space();  /* free Grhdata, Grh_colnum, Eph_buf */

  /* for test  put all docin_lines to stderr
  */
  /* int ii;
  * for (ii = 0; ii <= docin_idx; ii++) {
  *   strcpy(Swk, docin_lines[ii] );
  *   fprintf(stderr,"%s", Swk);
  * } 
  */

/* fprintf(stderr,"%s|%s|%d|%d|%d|\n",  fEvent_name, year_in_the_life_todo_yyyy, */
/*     gbl_out_of_stress , gbl_in_stress, gbl_out_of_stress - gbl_in_stress); */
/*  for test, no html */


/*  */
    /* prepare stress score for ranking purposes.
    * 1.  + 8000 is to make all positive
    * 2.  / 87 is  to normalize to 100=median
    * 3.  map to standard benchmark numbers
    */

    tempnum_y = gbl_out_of_stress - gbl_in_stress;
    tempnum_y = (tempnum_y + 8000);
    if (tempnum_y < 0) tempnum_y = 0;
    tempnum_y = (tempnum_y / 123);

    /* 3. extern int mapNumStarsToBenchmarkNum(int category, int num_stars); */

    /* this is not num_stars, but rather,  gbl_out_of_stress - gbl_in_stress;
    */
    tempnum_y = mapNumStarsToBenchmarkNum(IDX_FOR_BEST_YEAR, tempnum_y);
    tempnum_y = mapBenchmarkNumToPctlRank(tempnum_y);


    /* intercept information for data request invocation
    */
//trn(" intercept information for data request invocation");
    sprintf(stringBuffForStressScore, "%02d", ((tempnum_y)));
//ksn(stringBuffForStressScore);

/*  */
    strcpy(gbl_BuffYearStressScore, stringBuffForStressScore);
//ksn(gbl_BuffYearStressScore);
/* 
*     worknum = mapNumStarsToBenchmarkNum(IDX_FOR_SCORE_B, worknum);
* 
*     sprintf(stringBuffForStressScore, "%d", worknum);
* 
* 
*/

  // NOTE:  this is in   mamb_report_big_year()

  /* we might be finished  #0  (no HTML file)
  */
  if(strcmp(gbl_instructions,  "return only thumbnail data") == 0) 
  {
    strcpy(gbl_instructions,  "");  /* init gbl */
    allow_docin_puts = 1;           /* init gbl */
    
//trn("these 5 get appended - tot = 13 chars");
//tr("1");kin(gbl_topStarBELOW_GREAT);
//tr("2");ksn(gbl_BuffYearStressScore);
//tr("4");ksn(year_in_the_life_todo_yyyy);
//tr("3");kin(gbl_topToGreatLine);
//tr("3");kin(gbl_botToStressLine);

//
//    char zeroes5[8];
//    sprintf(zeroes5, "%s", "\0\0\0\0\0");
//
//
//    // NOTE:  this is in   mamb_report_big_year()
//
//
//char *last50chars; // get last 50 characters of the string 
//last50chars = gbl_thumbnailInfo + (strlen(gbl_thumbnailInfo) - 50);
//trn("before flag ");
//ksn(last50chars);
//
//    // append 1 char flag   gbl_topStarBELOW_GREAT;  0=no  1=yes to fix weird rubbish above great line when gbl_topStarBELOW_GREAT=1
//    //
//    // note "-1"   is to overwrite the last '\0'
//    //
//    char str_topStarBELOW_GREAT[8];
//    sprintf(str_topStarBELOW_GREAT, "%01d", gbl_topStarBELOW_GREAT);
//    memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE - 1, str_topStarBELOW_GREAT, 1);
//    gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 1;
//
//
//
//    // append 2 char stress score at end of thumbnail data
//    //
//    // note "-1"   is to overwrite the last '\0'
//    //
//last50chars = gbl_thumbnailInfo + (strlen(gbl_thumbnailInfo) - 50);
//trn("before stress score   ");
//ksn(last50chars);
//
////ksn(gbl_BuffYearStressScore);
//    memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE - 1, gbl_BuffYearStressScore, 2); /* write 2char score */
//    gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 2;
////ksn(gbl_BuffYearStressScore);
////trn("after stress score    ");ksn(gbl_thumbnailInfo);
//
//
//last50chars = gbl_thumbnailInfo + (strlen(gbl_thumbnailInfo) - 50);
//trn("before year ");
//ksn(last50chars);
//
//    // append 4 char year at end of thumbnail data
//    //
//    // note "-1"   is to overwrite the last '\0'
//    //
////trn("before year           ");ksn(gbl_thumbnailInfo);
//    memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE - 1, year_in_the_life_todo_yyyy, 4); 
//    gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 4;
//
//
//last50chars = gbl_thumbnailInfo + (strlen(gbl_thumbnailInfo) - 50);
//trn("before topToGreatLine ");
//ksn(last50chars);
//
//    // append 3 char topToGreatLine count at end of thumbnail data
//    //
//    // note "-1"   is to overwrite the last '\0'
//    //
////trn("before topToGreat     ");ksn(gbl_thumbnailInfo);
//    char str_topToGreatLine[16];
////    sprintf(str_topToGreatLine, "%02d", gbl_topToGreatLine );
////    sprintf(str_topToGreatLine, "%02d%s", gbl_topToGreatLine, zeroes5);
//
//
//
////    sprintf(str_topToGreatLine, "%03d%s", gbl_topToGreatLine, zeroes5);
//    sprintf(str_topToGreatLine, "%03d", gbl_topToGreatLine         );
//
//
//
//ksn(str_topToGreatLine);
//    memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE - 1, str_topToGreatLine, 3);
//    gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 3;
//
//
////if(strcmp(year_in_the_life_todo_yyyy,  "1974") == 0) {
////kin(gbl_topToGreatLine);
////ksn(str_topToGreatLine);
////}
//
//last50chars = gbl_thumbnailInfo + (strlen(gbl_thumbnailInfo) - 50);
//trn("before botToStressLine ");
//ksn(last50chars);
//
//    // append 3 char botToStressLine count at end of thumbnail data
//    //
//    // note "-1"   is to overwrite the last '\0'
//    //
//    // NOTE  NOTE    FIX  for some reason, (emscripten bug?)   had to write 5 \0 at the end 
//    // NOTE  NOTE    FIX  for some reason, (emscripten bug?)   had to write 5 \0 at the end 
//    // to overwrite 1 char garbage ('Z' here)  at end   Ob8ZZZOb8ZZZOb8ZZZ0619950745Z]
//    //
////trn("before botToStress    ");ksn(gbl_thumbnailInfo);
//    char str_botToStressLine[16];
////    sprintf(str_botToStressLine, "%02d", gbl_botToStressLine);
////    sprintf(str_botToStressLine, "%02d%s", gbl_botToStressLine, zeroes5);
//    sprintf(str_botToStressLine, "%03d%s", gbl_botToStressLine, zeroes5);
//
////if(strcmp(year_in_the_life_todo_yyyy,  "1974") == 0) {
////kin(gbl_botToStressLine);
//////ksn(zeroes5);
////ksn(str_botToStressLine);
////} 
//
////    memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE - 1, str_botToStressLine, 2);
//    memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE - 1, str_botToStressLine, 3); 
//    gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 3;
//
//last50chars = gbl_thumbnailInfo + (strlen(gbl_thumbnailInfo) - 50);
//trn("before write END OF STRING char");
//ksn(last50chars);
//
////trn("before write EOS      ");ksn(gbl_thumbnailInfo);
//    // write END OF STRING char
//    memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE, "\0", 1); /* write the string */
//    gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 1;
////trn("after  write EOS      ");ksn(gbl_thumbnailInfo);
//
//last50chars = gbl_thumbnailInfo + (strlen(gbl_thumbnailInfo) - 50);
//trn("after write END OF STRING char");
//ksn(last50chars);
//
//


    char str_my13chars[32];

    sprintf(str_my13chars, "%01d%2s%4s%03d%03d",
      gbl_topStarBELOW_GREAT,
      gbl_BuffYearStressScore,
      year_in_the_life_todo_yyyy,
      gbl_topToGreatLine,
      gbl_botToStressLine
    );

//  NOTE: did not  understand this bug below (where did "</div>" come from ? )
//
//char *last99chars; // get last 50 characters of the string 
//ksn(str_my13chars);
//last99chars = gbl_thumbnailInfo + (strlen(gbl_thumbnailInfo) - 99);
//trn("new BEFORE write str_my13chars chars");
//kin(strlen(gbl_thumbnailInfo));
//kin(gbl_putThumbnailInfoHERE);
//ksn(last99chars);
//

    memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE - 1, str_my13chars, 13); 
    gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 13;

//last99chars = gbl_thumbnailInfo + (strlen(gbl_thumbnailInfo) - 99);
//trn("new AFTER2 write str_my13chars chars");
//kin(strlen(gbl_thumbnailInfo));
//kin(gbl_putThumbnailInfoHERE);
//ksn(last99chars);

// old  memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE, "\0", 1); /* write the EOS char */
    memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE - 1, "\0", 1); /* write the EOS char */
    gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 1;

//last99chars = gbl_thumbnailInfo + (strlen(gbl_thumbnailInfo) - 99);
//trn("new AFTER  write END OF STRING char");
//kin(strlen(gbl_thumbnailInfo));
//kin(gbl_putThumbnailInfoHERE);
//ksn(last99chars);


//  NOTE: did not  understand this bug below (where did "</div>" come from ? )
//  NOTE: did not  understand this bug  - was FIXED by /* write the EOS char lines above */
//
//per_emcc_my2.html:84546 WW here we get the thumbnail data by  2. running the C program to calculate it         (about 1/2 second)
//per_emcc_my2.html:84546 gbls_tg_returnSTRING_work_space.length =[4095]
//per_emcc_my2.html:84546 gbls_ccall_csv1   =[Millie Bobby Br,2,19,2004,12,1,1,-1,4.53]
//per_emcc_my2.html:84546 yyyy_argAsString2 =[2020]
//per_emcc_my2.html:84546 _(in mamb_report_big_year)___year_todo_yyyy=[2020]__
//per_emcc_my2.html:84546 _csv_person_string=[Millie Bobby Br,2,19,2004,12,1,1,-1,4.53]__
//per_emcc_my2.html:84546 _year_todo_yyyy=[2020]__
//per_emcc_my2.html:84546 _instructions=[return only thumbnail data]__
//per_emcc_my2.html:84546 _(these 5 get appended - tot = 13 chars)__
//per_emcc_my2.html:84546 _(1)___gbl_topStarBELOW_GREAT=[0]__
//per_emcc_my2.html:84546 _(2)___gbl_BuffYearStressScore=[29]__
//per_emcc_my2.html:84546 _(4)___year_in_the_life_todo_yyyy=[2020]__
//per_emcc_my2.html:84546 _(3)___gbl_topToGreatLine=[12]__
//per_emcc_my2.html:84546 _(3)___gbl_botToStressLine=[12]__
//per_emcc_my2.html:84546 _str_my13chars=[0292020012012]__
//
//
//per_emcc_my2.html:84546 _(new BEFORE write str_my13chars chars)__
//per_emcc_my2.html:84546 _strlen(gbl_thumbnailInfo)=[1692]__
//per_emcc_my2.html:84546 _gbl_putThumbnailInfoHERE=[1693]__
//per_emcc_my2.html:84546 _last99chars=[B01S03B03S53ZZZS5eB01S03B03S53ZZZS62B03S53ZZZS63B01S54ZZZS63B01S54ZZZS63B01S54ZZZS63B01S54ZZZSb8ZZZ]__
//
//
//per_emcc_my2.html:84546 _(new AFTER2 write str_my13chars chars)__
//per_emcc_my2.html:84546 _strlen(gbl_thumbnailInfo)=[1740]__
//per_emcc_my2.html:84546 _gbl_putThumbnailInfoHERE=[1706]__
//per_emcc_my2.html:84546 _last99chars=[B01S54ZZZS63B01S54ZZZS63B01S54ZZZS63B01S54ZZZSb8ZZZ02920200120123B01S54ZZZS63B01S54ZZZSb8ZZZ</div>
//per_emcc_my2.html:84546 ]__
//
//
//per_emcc_my2.html:84546 _(new AFTER  write END OF STRING char)__
//per_emcc_my2.html:84546 _strlen(gbl_thumbnailInfo)=[1705]__
//per_emcc_my2.html:84546 _gbl_putThumbnailInfoHERE=[1707]__
//per_emcc_my2.html:84546 _last99chars=[ZZS5eB01S03B03S53ZZZS62B03S53ZZZS63B01S54ZZZS63B01S54ZZZS63B01S54ZZZS63B01S54ZZZSb8ZZZ0292020012012]__
//
//
//  NOTE: did not  understand this bug above (where did "</div>" come from ? )





//if (strcmp(year_in_the_life_todo_yyyy, "2020") == 0 )    exit (1);



    return gbl_thumbnailInfo;
  }

  /* we might be finished  #1  (no HTML file)
  */
  if(strcmp(gbl_instructions,  "return only year stress score") == 0) {
//
trn("in mamb_report_big_year -- we might be finished ->   return only year stress score   ()");
trn("in mamb_report_big_year -- now return string for year stress score   if gbl_instructions =  return only year stress score");


    strcpy(gbl_instructions,  "");  /* init gbl */
    allow_docin_puts = 1;           /* init gbl */

//    fclose_fpdb_for_debug();
//    return(0);

ksn(stringBuffForStressScore);
ksn(gbl_BuffYearStressScore);

    return( stringBuffForStressScore);

  }







//
//  /* we might be finished  #2  (no HTML file)
//  */
//  if(strcmp(gbl_instructions,  "return only day stress score") == 0) {
//b(69);
//
//    /* prepare stress score for ranking purposes.
//    * 1.  * -1  because used to be stress graph (high nums were stressful)
//    *    * 10 for bigger numbers
//    * 2.  +100 to make all positive
//    * 3.  map to standard benchmark numbers
//    */
//
//    tempnum_x = gblTargetDayScore;
//    tempnum_x = tempnum_x * -1; 
///*     tempnum_x = tempnum_x * 10; */
//    tempnum_x = tempnum_x + 100;
//    if (tempnum_x <= 0) tempnum_x = 1;
//
//    /* this is not num_stars, but rather,  gbl_out_of_stress - gbl_in_stress;
//    */
//    tempnum_x = mapNumStarsToBenchmarkNum(IDX_FOR_BEST_DAY, tempnum_x);
//
//
///*     tempnum_x = (tempnum_x + 8000); */
///*     tempnum_x = (tempnum_x / 123); */
//
//    /* 3. extern int mapNumStarsToBenchmarkNum(int category, int num_stars); */
///*     tempnum_x = mapNumStarsToBenchmarkNum(IDX_FOR_BEST_YEAR, tempnum_x); */
//
//
//    /* intercept information for data request invocation
//    */
//    sprintf(stringBuffForStressScore, "%d", ((tempnum_x)));
//
//
//    /* re-init stuff before leaving
//    */
//    gblTargetDayScore= 0; /* for best day on ... rpt */
//    gblWeHaveTargetDayScore= 0; /* 1=yes,0=no */
//    strcpy(gbl_instructions,  "");  /* init gbl */
//    allow_docin_puts = 1;           /* init gbl */
////    fclose_fpdb_for_debug();
//    return(0);
//  }
//

/*   if (strcmp(gbl_instructions,  "return only day stress score_B") == 0) x */

/* !*/
/* tn();trn("score_b end"); */
    /* prepare stress score for ranking purposes.
    * 1.  * -1  because used to be stress graph (high nums were stressful)
    *    * 10 for bigger numbers
    * 2.  +100 to make all positive
    * 3.  map to standard benchmark numbers
    */


    tempnum_z = gblTargetDayScore;
    tempnum_z = tempnum_z * -1; 

/* ki(tempnum_z); */
    tempnum_z = tempnum_z + 900;
    if (tempnum_z <= 0) tempnum_z = 1;
trn("do i go here");
    tempnum_z = mapNumStarsToBenchmarkNum(IDX_FOR_SCORE_B, tempnum_z);


/* ki(tempnum_z); */

/*     tempnum_z = (tempnum_z + 8000); */
/*     tempnum_z = (tempnum_z / 123); */

    /* 3. extern int mapNumStarsToBenchmarkNum(int category, int num_stars); */


    /* intercept information for data request invocation
    */
    sprintf(stringBuffForStressScore, "%d", ((tempnum_z)));
//b(212);

/*  */
/*     sprintf(gbl_BuffYearStressScore,  "%d", ((tempnum_z))); */
/* tn();b(151);ksn(gbl_BuffYearStressScore); */



  if (strcmp(gbl_instructions,  "return only day stress score_B") == 0) {

// this is weird - check later (ever run?)


/*     worknum2 = gblTargetDayScore; */
    worknum2 = atoi(stringBuffForStressScore);

/*     worknum2 = mapNumStarsToBenchmarkNum(IDX_FOR_SCORE_B, worknum2); */

/* b(75);ki(worknum2); */
    worknum2 = mapBenchmarkNumToPctlRank(worknum2);
    sprintf(stringBuffForStressScore, "%d", worknum2);

    /* re-init stuff before leaving
    */
    gblTargetDayScore= 0; /* for best day on ... rpt */
    gblWeHaveTargetDayScore= 0; /* 1=yes,0=no */
    strcpy(gbl_instructions,  "");  /* init gbl */
    allow_docin_puts = 1;           /* init gbl */
//    fclose_fpdb_for_debug();
//    return(0);

//b(214);
trn("retval not used for [return only day stress score_B] ");
    return("retval not used for [return only day stress score_B] ");
  }
/* !*/


  /* tn();  ksn(" HTML HTML HTML HTML HTML HTML HTML HTML HTML HTML "); */

  /* HTML HTML HTML HTML HTML HTML HTML HTML HTML HTML 
  */
  scharswitch(fEvent_name, ' ', '_');


  /* html_f_file_name is arg to mamb_report_year_in_the_life()
  */
/*  */
/* tn();b(17);
* ks(stringBuffForStressScore);
* ks(gbl_BuffYearStressScore);
*/

/*   worknum3 = atoi(stringBuffForStressScore);
* kin(worknum3);
*   worknum3 = mapBenchmarkNumToPctlRank(worknum3);
* kin(worknum3);b(172);
* 
*   sprintf(stringBuffForStressScore, "%d", worknum3);
* ksn(stringBuffForStressScore);
*   sprintf(gbl_BuffYearStressScore, "%d", worknum3);
* ksn(gbl_BuffYearStressScore);
*/


// magic string stuff
//   # the following is inside futhum.c
//  if (strstr(gbl_ffnameHTML, "webview") != NULL) f_fnOutPutTopOfHtmlFile();  // webview version
//  else                                           f_fnBIGOutPutTopOfHtmlFile();
//


// this log shows good stuff
//
  // log what we have here
//char mylogbuf11[256];
//int  mylogidx11;
//  for (mylogidx11 = 0;  mylogidx11 <= Num_lines_in_grh_body  ; mylogidx11++)      /* iprt is num lines in grh body */
//  {
//    strcpy(mylogbuf11, Grh_body_BIG + mylogidx11 * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
//ki(mylogidx11);ksn(mylogbuf11);
//  }
//


trn("\ncalling futhtm.c / make_fut_htm_file() from futdoc.c 6328");

trn("gbl_PSV_of_SW_CSVs  SENT to make_fut_htm_file() ");
ksn(gbl_PSV_of_SW_CSVs);
// for test
int  how_many_csvs = scharcnt(gbl_PSV_of_SW_CSVs, '|'); 
tr("num SW_CSVs in gbl_PSV_of_SW_CSVs"); kin(how_many_csvs);

  // plus new arg at bottom
  retval = make_fut_htm_file(   // ----------  for BIG   --------------------------
//    "string with no magic switch string",   // magic switch string is "webview"
    gbl_thumbnailInfo,
    gbl_space_for_HTML_fut, // space malloc'ed in js,  passed into mamb_report_big_year()
    docin_lines,
    docin_idx,
    gbl_BuffYearStressScore,
    gbl_is_first_year_of_life,
         //    "this is PSV_of_SW_CSVs"        // gbl_PSV_of_SW_CSVs
    gbl_PSV_of_SW_CSVs
  );
/*  */

  if (retval != 0) {
    f_docin_free();      /* free all allocated array elements */
    rkabort("Error: html file (fut) was not produced");
  }


/* for test */
#ifdef PUT_BACK_COMMENTED_OUT_STUFF /****************************************/
#endif /* ifdef PUT_BACK_COMMENTED_OUT_STUFF ********************************/





/* for test, show all docin lines */
/* tn();trn(" #################  ALL DOCIN LINES ##############");
* trn(" #################  ALL DOCIN LINES ##############");
* int jj; for (jj = 0; jj <= docin_idx; jj++) x 
*   kin(jj);
*   strcpy(Swk, docin_lines[jj] );
*   ks(Swk);
* x
*/
/*   close_fut_output_file(); */




  f_docin_free();      /* free all allocated array elements */


  if (strstr(instructions, "return only") == NULL) {   // is arg of func
/*     trn("end of mamb_report_year_in_the_life()!"); */
  }  /* avoid dbmsg on non-rpt call */

//  fclose_fpdb_for_debug();
/* trn("end of mamb_report_year_in_the_life()"); */

// control never gets here  20180821

int lenspacef; lenspacef = strlen(gbl_space_for_HTML_fut);
//kin(lenspacef);
//  ?  trn("finished mamb_report_personality() in perdoc.c");   /* comes out a lot in trait rank rpts */
//  return(0);


trn(" end of mamb_report_big_year() ");
  return(gbl_space_for_HTML_fut);

}  // end of mamb_report_big_year  /* called from cocoa */







void do_BIGfuture(void)
{
  char s[8+1];
  double dmn,ddy,dyr,dstep;
  int ido;
  ;
  sfill(s,8,' ');
  if (Fut_start_mn == 0) {    /* special signal from mk_fut_input.c */
    dmn = atof(sfromto(s,&Date_of_order_entry[0],5,6)); /* "yyyymmdd" */
    ddy = atof(sfromto(s,&Date_of_order_entry[0],7,8));
    dyr = atof(sfromto(s,&Date_of_order_entry[0],1,4));
  } else {
    dmn = (double) Fut_start_mn;
    ddy = (double) Fut_start_dy;
    dyr = (double) Fut_start_yr;
  }
trn("do_BIGfuture() #1");


//
//trn("");
//trn("allaof P_asp_tbl  at TOP of do_BIGfuture()");
//char tstfrom[32];
//char tstto[32];
//char tstnp[32];
//char tstasp[32];
//char tsttp[32];
//char tst128b[128];
//for (int ib=0; ib <= Asp_tbl_idx; ++ib) { 
////extern char *sfromto(char *dest,char *src, int beg, int end);
//sfromto(tstfrom,P_asp_tbl[ib], 1, 8);
//sfromto(tstnp  ,P_asp_tbl[ib], 9,10);
//sfromto(tsttp  ,P_asp_tbl[ib],11,12);
//sfromto(tstasp ,P_asp_tbl[ib],13,14);
//sfromto(tstto,  P_asp_tbl[ib],15,22);
//
//sprintf(tst128b, "%s_%s_%s  %s to %s  asp=%s",
//  N_planet[atoi(tstnp)], N_aspect[atoi(tstasp)], N_trn_planet[atoi(tsttp)], tstfrom, tstto, tstasp);
//ksn(tst128b);
//}
//trn("allaof P_asp_tbl  at TOP of do_BIGfuture()");
//trn("");
//


  init_rt();

//trn("");
//trn("allbof P_asp_tbl  AFTER init_rt() ");
////char tstfrom[32];
////char tstto[32];
////char tstnp[32];
////char tstasp[32];
////char tsttp[32];
//char tst128e[128];
//for (int ib=0; ib <= Asp_tbl_idx; ++ib) { 
////extern char *sfromto(char *dest,char *src, int beg, int end);
//sfromto(tstfrom,P_asp_tbl[ib], 1, 8);
//sfromto(tstnp  ,P_asp_tbl[ib], 9,10);
//sfromto(tsttp  ,P_asp_tbl[ib],11,12);
//sfromto(tstasp ,P_asp_tbl[ib],13,14);
//sfromto(tstto,  P_asp_tbl[ib],15,22);
//
//sprintf(tst128e, "%s_%s_%s  %s to %s  asp=%s",
//  N_planet[atoi(tstnp)], N_aspect[atoi(tstasp)], N_trn_planet[atoi(tsttp)], tstfrom, tstto, tstasp);
//ksn(tst128e);
//}
//trn("allbof P_asp_tbl  AFTER init_rt() ");
//trn("");
//


  /* for each 6-month future ordered  --------------------------------------------------
  */


  Num_fut_units_ordered = 1;   // for  whole year

  for (ido=1; ido <= Num_fut_units_ordered; ido++) {
    global_flag_which_graph = ido;   /* 1 or 2 */

  // NUM_PTS_WHOLE_YEAR 182
    if (ido == 1)  dstep = 0.0;   /* WARNING v undefined 1st time thru */
    else  dstep = (double)(NUM_PTS_WHOLE_YEAR*Eph_rec_every_x_days);
    //else  dstep = (double)(NUM_PTS_FOR_FUT*Eph_rec_every_x_days);

    mk_new_date(&dmn,&ddy,&dyr,dstep);


    Grh_beg_mn = (int)dmn; /* to be adjusted- set_grh_top_and bot()  */ 
    Grh_beg_dy = (int)ddy; /* so that arg date jogs with eph file   */  
    Grh_beg_yr = (int)dyr; /* dates, e.g. past is on Wed       */  

/* kdn(dmn);kd(ddy);kd(dyr); */
/* kin(Grh_beg_mn ); ki(Grh_beg_dy ); ki(Grh_beg_yr ); */
    get_BIGeph_data((int)dmn,(int)ddy,(int)dyr);  /* args unused ? */

trn("calling do_grh_calcs_and_prt();    /* central pgm  qqq   in do_BIGfuture()  */");
    do_grh_calcs_and_prt();    /* central pgm  qqq  in do_BIGfuture()  */
trn("back from do_grh_calcs_and_prt();    /* central pgm  qqq   in do_BIGfuture()  */");

ksn(gbl_instructions);
    if(strcmp(gbl_instructions,  "return only thumbnail data") == 0) return;

//kin(gbl_yearStressScoreIsDone);
    if (gbl_yearStressScoreIsDone == 1) {
trn("ss 01b gbl_yearStressScoreIsDone == 1  RETURN from do_future()  after do_grh_calcs_and_prt(); ");
      return;   // can return  if(strcmp(gbl_instructions,  "return only year stress score") == 0) 
    }


trn("2nd do_paras()");
    do_paras();

    init_rt();

  } /*  for (ido=1; ido <= Num_fut_units_ordered; ido++) */
trn("end of do_BIGfuture(void)");
}   // end of do_BIGfuture(void)



/* populate 3 strings  Grh_bottom_array at graph bottom. Look like this:
*   (size 99 chars  with 7 chars in lf_mar[] )
*       |   |    |     |    |    |   |    |    |     |   |    |     |   |    |     |    |    |    |    |    
*       |   10   20    |    11   21  |    11   21    |   10   20    |   10   20    |    11   21   |    11   
*  2013 jan            feb           mar             apr            may            jun            jul       
*    #define SIZE_GRH_LEFT_MARGIN 7
*    #define SIZE_EPH_GRH_LINE 107
*    #define NUM_PTS_FOR_FUT 92
*    #define NUM_GRH_BOTTOM_LINES 3
*  char Grh_bottom_line1BIG[SIZE_EPH_GRH_LINE+1];  *  +1 for \0*
*/
void mk_BIGgrh_bottom(double mn,double dy,double yr)
{
  double dstep;
  int ibot;
  //char mywk[SIZE_EPH_GRH_LINE + 1];
  //char mywk[NUM_PTS_WHOLE_YEAR  + 1];
  char mywk[NUM_PTS_WHOLE_YEAR * 2];   //  assume just big enough
  ;
/* trn("in mk_BIGgrh_bottom(double mn,double dy,double yr"); */

  /* populate lines with blanks into Grh_bottom_line s
  */
  // NUM_PTS_WHOLE_YEAR 182
  //sfill(mywk, NUM_PTS_FOR_FUT, ' ');  /* line size without left margin */
  sfill(mywk, NUM_PTS_WHOLE_YEAR , ' ');  /* line size without left margin */
  strcpy(Grh_bottom_line1BIG, mywk); 
  strcpy(Grh_bottom_line2BIG, mywk); 
  strcpy(Grh_bottom_line3BIG, mywk); 

/* trn("------- after init bottom lines:");
* ksn(Grh_bottom_line1BIG);
* ksn(Grh_bottom_line2BIG);
* ksn(Grh_bottom_line3BIG);
*/

  if (Num_eph_grh_pts == NUM_PTS_WHOLE_YEAR) {  // do big graph
    put_BIGgrh_scale_dates(0,(int)mn,(int)dy,(int)yr);  /* 1st column */
  } else {
    put_grh_scale_dates(0,(int)mn,(int)dy,(int)yr);  /* 1st column */
  }

  for (ibot=1; ibot <= Num_eph_grh_pts-1; ibot++) {  /* 1= start with 2nd col */

    dstep = (double)(Eph_rec_every_x_days);
    mk_new_date(&mn,&dy,&yr,dstep);

    if (Num_eph_grh_pts == NUM_PTS_WHOLE_YEAR) {  // do big graph
      put_BIGgrh_scale_dates(ibot, (int)mn,(int)dy,(int)yr);  /* 1st column */
    } else {
      put_grh_scale_dates(ibot, (int)mn,(int)dy,(int)yr);  /* 1st column */
    }
  }
/* trn("end of mk_BIGgrh_bottom(double mn,double dy,double yr"); */
}  // end of mk_BIGgrh_bottom(double mn,double dy,double yr)



void put_BIGscale_mark_char(int col,int line) /* line is 1 or 2 */
{
/* tn();trn("in put_BIGscale_mark_char ");ki(col);ki(line); */
/*   *(Date_array+(line-1)*SIZE_EPH_GRH_LINE+col) = SCALE_MARK_CHAR; */

  if(line == 1)  memcpy(Grh_bottom_line1BIG + col, "|", 1);  
  if(line == 2)  memcpy(Grh_bottom_line2BIG + col, "|", 1);  

/*   if(line == 1)  memcpy(Grh_bottom_line1BIG + col, "@", 1);   */
/*   if(line == 2)  memcpy(Grh_bottom_line2BIG + col, "@", 1);   */
}

//
///* for 1 6-month future
//*/
//void fill_eph_buf(void) 
//{
///* trn("fill_eph_buf()"); */
//  /* init */
//  gbl_beg_last_mth_write = 0; /* beg col of mth name last written */
//  gbl_end_last_mth_write = 0; /* end col of mth name last written */
//  set_grh_top_and_bot();
//
//  fill_eph_buf_by_calc();   /* NEW NEW NEW NEW NEW NEW NEW NEW NEW */
//
//}   // end of put_BIGscale_mark_char(int col,int line) /* line is 1 or 2 */
//


/* put_grh_scale_dates()
* 
*       |   |    |     |    |    |   |    |    |     |   |    line 1
*       |   10   20    |    11   21  |    11   21    |   10   line 2
*  2013 jan            feb           mar             apr      line 3
*---------------------------------
*         1         2         3   
*123456789 123456789 123456789 123
*---------------------------------
*/
void put_BIGgrh_scale_dates(int col,int mn,int dy,int yr)
{ 
/* trn(" in  put_BIGgrh_scale_dates"); */
  /* on "J" in january, put 2 scale mark chars
  * also, no "sideline out" on these
  *       if (global_flag_which_graph != 1) x  * leave pipes on "J" in Jan *
  */
  if (global_flag_which_graph == 1 && col == 0) {
    put_BIGscale_mark_char(col,1);
    put_BIGscale_mark_char(col,2);
  }


/*   if (global_flag_which_graph == 2  &&  times_thru3 == 0) x */
/*     times_thru3++; */

  /* add scale_mth (jul) on first star of second graph
  */
  if (global_flag_which_graph == 2 && is_first_put_grh_scale_dates == 1) {
    is_first_put_grh_scale_dates = 0;
    put_BIGscale_mth(col,mn);
    return;
  }

  if (dy >= 1  &&  dy <= Eph_rec_every_x_days) { /* beg of new mth */
    if(mn == 1) {      /* beg of january */
      if(col == 0) {  /* 1st column */
        /* jan wrt only when beg of line */
/*         put_BIGscale_mth(col,mn); */
        put_BIGscale_mth(col,mn);  /* jan wrt only when beg of line */
        return;
      }
      put_BIGscale_yr(col,yr);  /* wrt yr instead of jan */
      return;
    }
    put_BIGscale_mth(col,mn);    /* wrt mth */
    return;
  }
  if (Is_past) return;  /* don't put 10, 20 */
  if (dy >= 10  &&  dy <= 10 + (Eph_rec_every_x_days-1)) {
    put_BIGscale_dy(col,dy);
    return;
  }
  if (dy >= 20  &&  dy <= 20 + (Eph_rec_every_x_days-1)) {
    put_BIGscale_dy(col,dy);
    return;
  }
}  // end of put_BIGgrh_scale_dates(int col,int mn,int dy,int yr)


void put_BIGscale_yr(int col,int yr)
{
/* trn(" in  put_BIGgrh_scale_yr"); */
  char s[5];
  ;
  put_BIGscale_mark_char(col,1);
  put_BIGscale_mark_char(col,2);

  
  /* with new 92 star graph, no room for next year
  */
  /*   return; */

  /* UNLESS col (max 92) is  <=89 (4 chars)
  */
  if (col > Num_eph_grh_pts - 3) return;

/*   sprintf(s,"%02d",(yr-(yr/100*100))); */
/*   for (i=1; i <= 4; i++) x */
/*     *(Date_array+2*SIZE_EPH_GRH_LINE+col+(i-1)) = *(s+(i-1)); */
/*   x */

  sprintf(s,"%04d",yr);

  memcpy(Grh_bottom_line3BIG + col, s, 4);   /* 2013 */
/* ksn("line3 after day:");
* ki(strlen(Grh_bottom_line3BIG));
* ksn(Grh_bottom_line3BIG);
*/
}  // end of put_BIGscale_yr(int col,int yr)


void put_BIGscale_dy(int col,int dy)
{
/* trn(" in  put_BIGgrh_scale_dy"); */
  char s[3];
  ;
  put_BIGscale_mark_char(col,1);
  sprintf(s,"%02d",dy);

/*   for (i=1; i <= 2; i++) x */
/*     *(Date_array+SIZE_EPH_GRH_LINE+col+(i-1)) = *(s+(i-1)); */
/*   x */

  memcpy(Grh_bottom_line2BIG + col, s, 2);   /* 10,11,20,21 */
/* ksn("line2 after day:");
* ki(strlen(Grh_bottom_line2BIG));
* ksn(Grh_bottom_line2BIG);
*/

}  // end of put_BIGscale_dy(int col,int dy)


void put_BIGscale_mth(int col,int mn)
{
/* trn(" in  put_BIGgrh_scale_mth"); */
  int line, len;
  ;
  line = 2;  /* fut */
  if (Is_past) line = 1;

  put_BIGscale_mark_char(col,1);

  if (Is_past == 0) put_BIGscale_mark_char(col,2);


  if (col >= Num_eph_grh_pts-1-1) return; { /* no room on line */

/*   for (i=1; i <= 3; ++i) x  * eg  3= jan feb * */
/*     *(Date_array+line*SIZE_EPH_GRH_LINE+col+(i-1)) = *(N_mth[mn]+(i-1)); */
/*   x    * ^on 3rd bottom line (line = 2) */

  /* put month names */
  /* Jan, Feb etc */

/*  memcpy(Grh_bottom_line3BIG + col, N_mth[mn], 3);*/  /* jan, feb etc */
/*   memcpy(Grh_bottom_line3BIG + col, N_mth_cap[mn], 3);   */
  /* Thu 29 May 2014 12:09:27 EDT */
  /* Jan, Feb etc */
/*   memcpy(Grh_bottom_line3BIG + col, N_mth_allcaps[mn], 3);  */



 len = (int)strlen(N_allcaps_long_mth[mn]); 
/*  tn();kin(len);ksn(N_allcaps_long_mth[mn]);  */

  /* if it's going to be an overwrite put spaces
  *  (only happens for first mth name on line)
  */
  int current_beg_mth_write;
  current_beg_mth_write = col;
/* kin(current_beg_mth_write ); */
  if (current_beg_mth_write <= gbl_end_last_mth_write) {
/* trn("WRITE SPACES!"); */
    memcpy(Grh_bottom_line3BIG + gbl_beg_last_mth_write, "                             ", 25);  
  }

/*   memcpy(Grh_bottom_line3BIG + col, N_allcaps_long_mth[mn], len);   */
  memcpy(Grh_bottom_line3BIG + col+1, N_allcaps_long_mth[mn], len);  

  gbl_beg_last_mth_write = col;       /* beg col of mth name last written */
  gbl_end_last_mth_write = col + len - 1 ;/* end col of mth name last written */

/* ki(gbl_beg_last_mth_write); ki(gbl_end_last_mth_write); */


/* ksn("line3 after mth:");
* ki(strlen(Grh_bottom_line3BIG));
* ksn(Grh_bottom_line3BIG);
*/
  }  /* put month names */


}  // end of put_BIGscale_mth(int col,int mn)


void do_aBIG_graph(int p_grh[], int grh_num)    /* qqq */
{
  int n;
  char *p = &Swk[0];
  static int fut_line_ctr;
/*   char grh_line[SIZE_EPH_GRH_LINE+1]; */
  char grh_line[8192];

  //int cols_with_pt[SIZE_EPH_GRH_LINE+1];/*for this line, col#s holding a pt*/
  int cols_with_pt[SIZE_BIG_EPH_GRH_LINE+1];/*for this line, col#s holding a pt*/

    /* cols_with_pt starts at [1] */
  int k,m,current_grh_y_val,last_grh_y_val_printed,nl,pt_ctr;
  ;                      /* nl = newest line in grh */
//trn("\nin do_aBIG_graph()");
//tr("in do_aBIG_graph()");
//kin(gbl_yearStressScoreIsDone);
ksn(gbl_instructions);
  // run twice fix
  gbl_yearStressScoreIsDone = 0;
  // run twice fix
//trn("run twice fix");
//kin(gbl_yearStressScoreIsDone);

  n = sprintf(p,"\n\n[beg_graph]\n");  /* signal to fmt_f.awk */
  /* fput(p,n,Fp_docin_file); */
  f_docin_put(p,n);

  Num_lines_in_grh_body = 0;
  last_grh_y_val_printed = 0;
  pt_ctr = 0;
  fut_line_ctr = 0;
  current_grh_y_val = *(p_grh+Num_eph_grh_pts-1);/* for 1st time thru below */
  last_grh_y_val_printed = current_grh_y_val;  /* for 1st time thru below */

  prt_BIGgrh_hdr(grh_num);   // whole year does not need header  yes it does, for blnk line of sky

  sfill(&grh_line[0],Num_eph_grh_pts,GRH_BACKGROUND_CHAR);
  for (k=Num_eph_grh_pts-1; k > -1; k--) {
    if ( (nl=*(p_grh+k)) != current_grh_y_val  &&
          Num_lines_in_grh_body < MAX_GRH_BODY_LINES  ) {

      prt_BIGgrh_line(&grh_line[0],&cols_with_pt[0],pt_ctr,
        &fut_line_ctr,Grh_top);

      for (m=1; m <= last_grh_y_val_printed-nl-1; m++) {
        prt_BIGgrh_line(&grh_line[0],&cols_with_pt[0],0,
          &fut_line_ctr,Grh_top);
      }
                /* ^ put in 'blank' lines */
      last_grh_y_val_printed = nl;
      pt_ctr = 0;
    }

    pt_ctr++;
    cols_with_pt[pt_ctr] = Grh_colnum[k];
    current_grh_y_val = nl;

/*  */
//kin(current_grh_y_val);

  }

  prt_BIGgrh_bot(&grh_line[0],&cols_with_pt[0],pt_ctr,&fut_line_ctr); // reverse_BIGgrh_body_and_prt() is in here



// for  newPlanBenchmarkLabels()
//  // log what we have here
//char mylogbuf[256];
//int  mylogidx;
//  for (mylogidx = 0;  mylogidx <= Num_lines_in_grh_body  ; mylogidx++)      /* iprt is num lines in grh body */
//  {
//    strcpy(mylogbuf, Grh_body_BIG + mylogidx * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
//ki(mylogidx);ksn(mylogbuf);
//  }
//

//  // OUTPUT of    log what we have here
////
////_mylogidx=[0]___mylogbuf=[       XXXXXXXXX*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]__
////_mylogidx=[1]___mylogbuf=[       XXXXXXXXX#*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]__
////_mylogidx=[2]___mylogbuf=[       XXXXXXXXX##XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]__
////_mylogidx=[3]___mylogbuf=[       XXXXXXXXX##*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]__
////_mylogidx=[4]___mylogbuf=[       XXXXXXXX*###**XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]__
////_mylogidx=[5]___mylogbuf=[       XXXXXXXX######XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]__
////_mylogidx=[6]___mylogbuf=[       XXXXXXX*######XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]__
////_mylogidx=[7]___mylogbuf=[       XXXXXXX#######XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]__
////_mylogidx=[8]___mylogbuf=[       XXXXXXX#######*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]__
////_mylogidx=[9]___mylogbuf=[       XXXXXXX########XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]__
////_mylogidx=[10]___mylogbuf=[       XXXXXXX########XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]_
////_mylogidx=[11]___mylogbuf=[       XXXXXXX########XXXX*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]_
////_mylogidx=[12]___mylogbuf=[       XXXXXX*########XXXX#XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]_
////_mylogidx=[13]___mylogbuf=[       XXXXXX#########XXXX#XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]_
////_mylogidx=[14]___mylogbuf=[       XXXXXX#########*XXX#XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]_
////_mylogidx=[15]___mylogbuf=[       XXXXXX##########XXX#*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]_
////_mylogidx=[16]___mylogbuf=[       XXXXXX##########XXX##XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]_
////_mylogidx=[17]___mylogbuf=[       XXXXX*##########*XX##XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]_
////_mylogidx=[18]___mylogbuf=[       XXXXX############XX##XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]_
////_mylogidx=[19]___mylogbuf=[       XXXXX############XX##XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]_
////_mylogidx=[20]___mylogbuf=[       XXXXX############XX##XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]_
////_mylogidx=[21]___mylogbuf=[       XXXXX############XX##XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]_
////_mylogidx=[22]___mylogbuf=[       XXXX*############X*##XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]_
////_mylogidx=[23]___mylogbuf=[       XXXX#############X###XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]_
////_mylogidx=[24]___mylogbuf=[       XXXX#############X###XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]_
////_mylogidx=[25]___mylogbuf=[       XXXX#############X###XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]_
////_mylogidx=[26]___mylogbuf=[       XXXX#############X###XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]_
////_mylogidx=[27]___mylogbuf=[       XXXX#############X###XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]_
////_mylogidx=[28]___mylogbuf=[       XXXX#############*###*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]_
////_mylogidx=[29]___mylogbuf=[       XXXX##################XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]_
////_mylogidx=[30]___mylogbuf=[       XXXX##################XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*]_
////_mylogidx=[31]___mylogbuf=[       XXXX##################XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX#]_
////_mylogidx=[32]___mylogbuf=[       XXX*##################XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX#]_
////_mylogidx=[33]___mylogbuf=[       XXX###################*XXXXXXXXXXXXXXXX*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX#]_
////_mylogidx=[34]___mylogbuf=[   OMG-XXX####################XXXXXXXXXXXXXXXX#XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX#]_
////_mylogidx=[35]___mylogbuf=[       XXX####################XXXXXXXXXXXXXXXX#XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX#]_
////_mylogidx=[36]___mylogbuf=[       XXX####################XXXXXXXXXXXXXXXX#XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*#]_
////_mylogidx=[37]___mylogbuf=[       XXX####################XXXXXXXXXXXXXXXX#XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX**XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*XXXX##]_
////_mylogidx=[38]___mylogbuf=[       XXX####################XXXXXXXXXXXXXXXX#XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX***##XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX#*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX#XXXX##]_
////_mylogidx=[39]___mylogbuf=[       XXX####################XXXXXXXXXXXXXXXX#XXXXXXXXXXXXXXX*XXXXX*XXXXXXX*XXXXXXXXXXXXXXXXXXXXX*#####XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX##XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX#*XX*##]_
////_mylogidx=[40]___mylogbuf=[       XXX####################*XXXXXXXXXXXXXXX#XXXXXXXXXXXXXXX#XXXXX#XXXXXXX#XXXXXXXXXXXXXXXXXXXXX######*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*##XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*##X*###]_
////_mylogidx=[41]___mylogbuf=[       XXX#####################XXXXXXXXXXXXXXX#*XXXXXXXXXXXXXX#XXXXX#XXXXXXX#XXXXXXXXXXXXXXXXXXXX*#######XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX###XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX###X####]_
////_mylogidx=[42]___mylogbuf=[       XXX#####################XXXXXXXXXXXXXXX##XXXXXXXXXXXXX*#XXXXX#XXX*XXX#*XXXXXXXXXXXXXXXXXXX########XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX###*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX###*####]_
////_mylogidx=[43]___mylogbuf=[       XXX#####################XXXXXXXXXXXXXXX##XXXXXXXXXXXXX##XXXXX#XXX#XXX##XXXXXXXXXXXXXXX*XX*########*XXXXXXXXXXXXXX*XXXXXXXXXXXXXXXXXXXXXXX####XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX########]_
////_mylogidx=[44]___mylogbuf=[       XXX#####################XXXX*XXXXXXXXXX##XXXXXXXXXXXXX##*XXX*#XXX#*XX##XXXXXXXXXXXXXXX#XX##########XXXXXXXXXXXXX*#XXXXXXXXXXXXXXXXXXXXXX*####XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX########]_
////_mylogidx=[45]___mylogbuf=[       XXX#####################XXXX#*XXXXXXXXX##*XXXXXXXXXXXX###XXX##XX*##X*##XXXXXXXXXXXXXXX#XX##########XXXXXXXXXXXXX##XXXXXXXXXXXXXXXXXXXXXX#####XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX########]_
////_mylogidx=[46]___mylogbuf=[       XX*#####################XXXX##*XXXXXXXX###XXXXXXXXXXXX###XX*##XX###X###XXXXXXXXXXXXXXX#**##########XXXXXXXXXXXXX##XXXXXXXXXXXXXXXXXXXXX*#####XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX########]_
////_mylogidx=[47]___mylogbuf=[       XX######################XXXX###*XXXXXXX###XXXXXXXXXXXX###X*###XX###X###XXXXX*X*XXXXXXX#############*XXXXXXXXXXX*##*XXXXXXXXXXXXXXXXXXXX######XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*########]_
////_mylogidx=[48]___mylogbuf=[       XX######################XXXX####XXXXXXX###XXXXXXXXXXXX###*####*X###X###XXXXX#*#***XXXX##############XXXXXXXXXXX####XXXXXXXXXXXXXXXXXXXX######XXXXXXXXXXXXXXXXXXXX*XXXXXXXXXXXXX#########]_
////_mylogidx=[49]___mylogbuf=[       XX######################*XXX####XXXXXX*###XXXXXXXXXXXX#########*###*###*XXXX######XXX*##############XXXXXXXXXXX####*XXXXXXXXXXXXXXXXXX*######XXXXXXXXXXXXXXXXXX**#*XXXXXXXXXXXX#########]_
////_mylogidx=[50]___mylogbuf=[       XX#######################XXX####XXXXXX####*XX*XXXXXXXX##################XXXX######XXX###############XXXXXXXXXXX#####XXXXXXXX***XXXXXXX#######XXXXXXXXXXXXXXXXX*####XXXXX*XXXXXX#########]_
////_mylogidx=[51]___mylogbuf=[       XX#######################XX*####XXXXXX#####*X#XXXXXXXX##################X*XX######*XX###############XXXXXXXXXXX#####*XXXXXX*###**XXXX*#######*XXXXXXXXXXXXXXXX#####*XX**#*X****#########]_
////_mylogidx=[52]___mylogbuf=[STRESS-XX#######################XX#####XXXXXX######X#*XXXXXX*##################*#XX#######XX###############*XXXXXXXXXX######*XXXX*######*XX*#########***XXXXXXXXXXXXX######**####*#############]_
////_mylogidx=[53]___mylogbuf=[       X*#######################XX#####XXXXXX######*##XXXXX*#####################X*#######XX################XXXXXXXXXX#######XXX*########**#############***XXXXXXXXX*##########################]_
////_mylogidx=[54]___mylogbuf=[       X########################XX#####*XXXXX#########XXXX*######################*########XX################XXXXXXXXXX#######***###########################*XXXXXXXX###########################]_
////_mylogidx=[55]___mylogbuf=[       X########################XX######XXXXX#########XXX*################################XX################XXXXXXXXX*######################################XXXXXXXX###########################]_
////_mylogidx=[56]___mylogbuf=[       X########################XX######*XXXX#########XX*#################################XX################XXXX*XXXX#######################################*XXXXXX*###########################]_
////_mylogidx=[57]___mylogbuf=[       X########################X*#######*XX*#########**##################################X*################XXXX#**XX########################################*XXXXX############################]_
////_mylogidx=[58]___mylogbuf=[       X########################*#########XX##############################################X#################*XX*###*X#########################################*XXXX############################]_
////_mylogidx=[59]___mylogbuf=[       X##################################*X##############################################X##################**#####*##########################################*XXX############################]_
////_mylogidx=[60]___mylogbuf=[       X###################################*##############################################X#####################################################################*X*############################]_
////
//
////  sprintf(  // PUT LINE IN TBL
////    Grh_body_BIG + (Num_lines_in_grh_body-1) * 
////               (SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE + 1),
////    "%s%s",
////    get_grh_left_margin(p_ln_ctr,top,p_line),
////    p_line
////  );
//
//
//
//
////  prt_BIGgrh_bot(&grh_line[0],&cols_with_pt[0],pt_ctr,&fut_line_ctr);
//
//
//  // new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW
//  // new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW
//  //
//  // NOTE: there are 17 lines between STRESS- and GOOD-
//  // NOTE: there are 17 lines between   GOOD- and GREAT-
//  //
//  // STEP 1. in all of the GRH lines we have, put in the benchmark labels that are supposed to be there-  "STRESS-", "GOOD-", "GREAT-"
//  // STEP 2. add sky lines and missing benchmark labels until ALL of  "STRESS-"  "GOOD-"  "GREAT-" are put in
//  //
//  // STEP 1. in all of the GRH lines we have, put in the benchmark labels that are supposed to be there-  "STRESS-", "GOOD-", "GREAT-"
//  //         read GRH  lines until we hit benchmark label STRESS- (assume it is always there - safe?    i think so       maybe)
//  //         read the rest of the GRH lines, keeping mycntlinesNEW 
//  //         and fill in any  missing benchmark labels -  GOOD- or GREAT-
//  //         populate gbl_lastBenchmarkLabel  (this will be "STRESS-", "GOOD-" or "GREAT-")
//  //
//  // STEP 2. add sky lines and missing benchmark labels until ALL of  "STRESS-"  "GOOD-"  "GREAT-" are put in
//  //         read GRH  lines until we hit gbl_lastBenchmarkLabel 
//  //         read the rest of the GRH lines, keeping mycntlinesNEW 
//  //         put in filler skylines to fill out the 17 lines between benchmark labels
//  //         after 17 lines put in the appropriate benchmark label with all sky
//  //         go until ALL of  "STRESS-"  "GOOD-"  "GREAT-" are put in
//  //
//
//  // STEP 1. in all of the GRH lines we have, put in the benchmark labels that are supposed to be there-  "STRESS-", "GOOD-", "GREAT-"
//  //   PUT MISSING LABELS
//  //
//  char linebufNEW[256];
//  int myidxNEW;
//  char GOOD_search_info[128];
//  char GREAT_search_info[128];
//  char LASTLABEL_search_info[128];
//  int numBodyLinesToProcess;     // num_lines changes on the fly in here, so use this constant number
//  int mycntlinesNEW;
//  char my184SharpsNEW[1024]; sfill(my184SharpsNEW, 184, '#'); 
//
//
//nksn("BEG  STEP 1  STEP 1  STEP 1  STEP 1  STEP 1  STEP 1  ");
//  numBodyLinesToProcess = Num_lines_in_grh_body;  // num_lines changes on the fly in here, so use this constant number
//kin(Num_lines_in_grh_body );
//kin(numBodyLinesToProcess);  
//
//
////step1BLOCK:
//do {  //  step 1 BLOCK      step 1 BLOCK      step 1 BLOCK      step 1 BLOCK      step 1 BLOCK      step 1 BLOCK      step 1 BLOCK    
//
//  for (myidxNEW = 0;  myidxNEW < numBodyLinesToProcess ; myidxNEW = myidxNEW + 1 )      // read backwards (STRESS to GOOD direction)
//  {
//    strcpy(linebufNEW, Grh_body_BIG + myidxNEW * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
//ki(myidxNEW);ksn(linebufNEW);
//
//    // read until you get to STRESS
//    //
//    if (strstr(linebufNEW, "STRESS-")  != NULL)  break;
//  }
//  //
//  // here we are on the STRESS line  (assume it is always there - safe?    i think so       maybe)
//  //
//
//  // read to find GOOD
//  mycntlinesNEW = 0;                          // INIT
//  strcpy(gbl_lastBenchmarkLabel, "STRESS-");  // INIT
//
//  for (            ;  myidxNEW < numBodyLinesToProcess;  myidxNEW = myidxNEW + 1 )      // read backwards (STRESS to GOOD direction)
//  {
//    mycntlinesNEW = mycntlinesNEW + 1;
//    strcpy(linebufNEW, Grh_body_BIG + myidxNEW * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
//ki(myidxNEW);ki(mycntlinesNEW);ksn(linebufNEW);
//    if (strstr(linebufNEW, "GOOD-")  != NULL)   { strcpy(GOOD_search_info, "found");            break; }
//    if (mycntlinesNEW ==  17 + 1)               { strcpy(GOOD_search_info, "not found");        break; }
//    if (myidxNEW == numBodyLinesToProcess -1)   { strcpy(GOOD_search_info, "ran out of lines"); break; }  // last GRH line
//  } // read to find GOOD
//ksn(GOOD_search_info);
//  
//  if (strcmp(GOOD_search_info, "ran out of lines") == 0 )  break;    // break step1BLOCK;
//  if (strcmp(GOOD_search_info, "found")            == 0 )  strcpy(gbl_lastBenchmarkLabel, "GOOD-");
//  if (strcmp(GOOD_search_info, "not found")        == 0 )  {
//    // here, "GOOD-" is supposed to be on this line and it is not
//    // put "GOOD-"  benchmark label in
//// strcpy(linebufNEW, Grh_body_BIG + myidxNEW * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
//    memcpy( Grh_body_BIG + myidxNEW * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1), " xGOOD-", 7); /* write GOOD- in */
//trn("ADDED   GOOD-");
//  }
//
//  // here GOOD_search_info = found, OR GOOD was added,  so continue with a search for "GREAT-"
//
//
//  // read to find GREAT
//  mycntlinesNEW = 0;  // INIT
//
//  for (            ;  myidxNEW < numBodyLinesToProcess;  myidxNEW = myidxNEW + 1 )      // read backwards (GOOD to GREAT direction)
//  {
//    mycntlinesNEW = mycntlinesNEW + 1;
//    strcpy(linebufNEW, Grh_body_BIG + myidxNEW * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
//ki(myidxNEW);ki(mycntlinesNEW);ksn(linebufNEW);
//    if (strstr(linebufNEW, "GREAT-")  != NULL)  { strcpy(GREAT_search_info, "found");            break; }
//    if (mycntlinesNEW ==  17 + 1)               { strcpy(GREAT_search_info, "not found");        break; }
//    if (myidxNEW == numBodyLinesToProcess -1)   { strcpy(GREAT_search_info, "ran out of lines"); break; }  // last GRH line
//  } // read to find GREAT
//ksn(GREAT_search_info);
//  
//  if (strcmp(GREAT_search_info, "ran out of lines") == 0 )  break;  // break step1BLOCK;
//  if (strcmp(GREAT_search_info, "found")            == 0 )  strcpy(gbl_lastBenchmarkLabel, "GREAT-");
//  if (strcmp(GREAT_search_info, "not found")        == 0 )  {
//    // here, "GREAT-" is supposed to be on this line and it is not
//    // put "GREAT-"  benchmark label in
//// strcpy(linebufNEW, Grh_body_BIG + myidxNEW * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
//    memcpy( Grh_body_BIG + myidxNEW * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1), " xGREAT-", 7); /* write GREAT- in */
//trn("ADDED   GREAT-");
//  }
//
//  // here GREAT was found or added so STEP 1 is over
//
//ksn("END  STEP 1  STEP 1  STEP 1  STEP 1  STEP 1  STEP 1  ");
//
//}  while (0);   //  step 1 BLOCK      step 1 BLOCK      step 1 BLOCK      step 1 BLOCK      step 1 BLOCK      step 1 BLOCK      step 1 BLOCK    
//  //
//  //   PUT MISSING LABELS
//
//trn("finished step 1"); 
//ksn(gbl_lastBenchmarkLabel);
//kin(mycntlinesNEW);
//
//  // log what we have here
//char mylogbuf32[256];
//int  mylogidx32;
//  for (mylogidx32 = 0;  mylogidx32 <= Num_lines_in_grh_body  ; mylogidx32++)      /* iprt is num lines in grh body */
//  {
//    strcpy(mylogbuf32, Grh_body_BIG + mylogidx32 * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
//ki(mylogidx32);ksn(mylogbuf32);
//  }
//
//
//
//
//
//
//
//if (strstr(gbl_lastBenchmarkLabel, "GREAT-") == NULL ) {   // NOT ALL benchmark labels are there
//
//  // STEP 2. add sky lines and missing benchmark labels until ALL of  "STRESS-"  "GOOD-"  "GREAT-" are put in
//  //         read GRH  lines until we hit gbl_lastBenchmarkLabel 
//  //         read the rest of the GRH lines, keeping mycntlinesNEW 
//  //         put in filler skylines to fill out the 17 lines between benchmark labels
//  //         after 17 lines put in the appropriate benchmark label with all sky
//  //         go until ALL of  "STRESS-"  "GOOD-"  "GREAT-" are put in
//  //
//ksn("BEG  STEP 2  STEP 2  STEP 2  STEP 2  STEP 2  STEP 2  ");
//
////  int  do17linecount;  do17linecount = 0;
////
////  for (myidxNEW = 0;  myidxNEW < numBodyLinesToProcess ; myidxNEW = myidxNEW + 1 )      // read backwards (STRESS to GOOD direction until gbl_lastBenchmarkLabel
////  {
////    strcpy(linebufNEW, Grh_body_BIG + myidxNEW * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
////ki(myidxNEW);ksn(linebufNEW);
////
////    if (do17linecount = 1) {
////      mycntlinesNEW = mycntlinesNEW + 1;
////      if (mycntlinesNEW ==  17) break;
////    }
////    if (strstr(linebufNEW, gbl_lastBenchmarkLabel)  != NULL)  {
////      // we are on line with gbl_lastBenchmarkLabel
////      // start 17 line counter to next label
////      //
////      do17linecount = 1;
////      mycntlinesNEW = 0;
////    }
////  }
////kin(mycntlinesNEW);
////
//
//
//
//  //
//  // here we are on the last line in GRH lines
//  // so, fill in sky lines up to where next benchmark label should be
//  //
//int timesthru;
//timesthru = 0;
//  do { // FILL TO GREAT
//timesthru = timesthru + 1;
//kin(timesthru);
//if (timesthru == 4) break;
//
//trn("do fill in sky lines up to where next label should be");
//    for (int mmm = mycntlinesNEW;  mmm <= 17; mmm++ )  // NOTE  MAGIC NUM 17   17 lines in between each benchmark label
//    {
//tr("NEW add fill 184sharps");ki(mmm);kin(Num_lines_in_grh_body);
//      sprintf( Grh_body_BIG + Num_lines_in_grh_body  * (SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE + 1), "%s%s", "       ", my184SharpsNEW);
//      Num_lines_in_grh_body = Num_lines_in_grh_body + 1 ;
//      strcpy(gbls_addLines, "we added lines to ensure benchmark labels STRESS, GOOD and GREAT are all present");
//ki(mmm);kin(mycntlinesNEW);
//    }
//    mycntlinesNEW = 0;  // init
//
//    // here we are at the point where there should a new line with a benchmark label
//    //
//    if   (strstr(gbl_lastBenchmarkLabel, "STRESS-") != 0) { strcpy(gbl_lastBenchmarkLabel, "  GOOD-");  }
//    else {
//      if (strstr(gbl_lastBenchmarkLabel, "GOOD-")   != 0) { strcpy(gbl_lastBenchmarkLabel, " GREAT-");  }
//    }
//ksn(gbl_lastBenchmarkLabel);
//
//trn(" here we are at the point where there should be a new benchmark label, so put it in");
//tr("add line with NEW benchmark label");ki(Num_lines_in_grh_body); ksn(gbl_lastBenchmarkLabel);
//    sprintf( Grh_body_BIG + Num_lines_in_grh_body * (SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE + 1), "%s%s", gbl_lastBenchmarkLabel, my184SharpsNEW);
//    Num_lines_in_grh_body = Num_lines_in_grh_body + 1 ;
//    strcpy(gbls_addLines, "we added lines to ensure benchmark labels STRESS, GOOD and GREAT are all present");
//
//
//ksn(gbl_lastBenchmarkLabel);
////break;  for test
//
//    if (strstr(gbl_lastBenchmarkLabel, "GREAT-") != NULL) {
//      // add one blank sky line above GREAT-
//      sprintf( Grh_body_BIG + Num_lines_in_grh_body  * (SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE + 1), "%s%s", "       ", my184SharpsNEW);
//      Num_lines_in_grh_body = Num_lines_in_grh_body + 1 ;
//      break;
//    }
//
//  } while (1); // FILL TO GREAT
//
//
//
//  //
//  // STEP 2. add sky lines and missing benchmark labels until ALL of  "STRESS-"  "GOOD-"  "GREAT-" are put in
//ksn("END  STEP 2  STEP 2  STEP 2  STEP 2  STEP 2  STEP 2  ");
//
//} // NOT ALL benchmark labels are there
//
//
//
//
//  //
//  // new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW
//  // new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW
//// for newPlanBenchmarkLabels()
//
//

  if(strcmp(gbl_instructions,  "return only thumbnail data") == 0) return;

   n = sprintf(p,"\n[end_graph]\n\n");  /* signal to fmt_f.awk */
   f_docin_put(p,n);

trn("end of  do_aBIG_graph()");
}   // end do_aBIG_graph(int p_grh[], int grh_num)    /* qqq */


void prt_BIGgrh_hdr(int grh_num)  /* grh title and 2nd line */
{
/* trn("in prt_BIGgrh_hdr"); */
  char lf_mar[SIZE_GRH_LEFT_MARGIN+1];
  char star_desc[64], star_wk[64], num1[16], num2[16];

  //char wk_line[SIZE_EPH_GRH_LINE+1];
  char wk_line[SIZE_BIG_EPH_GRH_LINE+1];

  int n;
  char *p = &Swk[0];
  long int tmp_long;
  ;
  sfill(&lf_mar[0],SIZE_GRH_LEFT_MARGIN,' ');
/*
* if (Is_past) strcpy(&star_desc[0],".(one star every Wednesday)");
* else sprintf(&star_desc[0],"(one star for every %d days)",
*   Eph_rec_every_x_days);
*/
  sfill(star_desc,26,'.');
  tmp_long =  (long int) out_of_stress;
  commafy_int(num1, tmp_long, 6);
  tmp_long =  (long int)     in_stress;
  commafy_int(num2, tmp_long, 6);
  sprintf(star_wk, "ok=%s+, stress=%s-",   /* area score  good/bad */
    strim(num1," "), strim(num2," ") );
  memcpy(star_desc, star_wk, strlen(star_wk));


  // 20141229  for BIG, no grh header
  //
// 
//   /* put name in field of dots
//   */
//   char dotfield[MAX_SIZE_PERSON_NAME+2];  /* 15 in 201309 */
//   sfill(dotfield, MAX_SIZE_PERSON_NAME+1, '.');
//   memcpy(dotfield, fEvent_name, strlen(fEvent_name));
//   dotfield[MAX_SIZE_PERSON_NAME+1] = '\0';
// 
// 
// /*    "\n\n%s .....%s..........................................%s.....%s..... \n", */
// /*     Grh_name[grh_num],   */
// /*    "\n\n%s .....%s.............................................%s.....%s..... \n", */
// /*     "\n\n%s .....%s.............................................%s.....%s..... \n",  */
// 
// /* tn(); */
// /* ksn(&lf_mar[0]); */
// /* ksn(dotfield); */
// /*     "\n\n%s ..<span class=\"bgy\">...%s.....................T.......................%s.....%s..... </span>\n",  */
// /*     "\n\n%s ..<span class=\"bgy\">...%s..................T.....................%s.....%s..... </span>\n",  */
// 
//   // this is big  version, so add 92 dots in middle
//   char dotfield_92[128];
//   sfill(dotfield_92, 92, '.'); // #define NUM_PTS_WHOLE_YEAR 184
//   n = sprintf(p,
//     "\n\n%s<span class=\"bgy\"> .....%s.................%s.......................%s.....%s..... </span>\n", 
//     &lf_mar[0],
//     dotfield,   // with person name
//     dotfield_92, // fill for big double sized graph
//     year_in_the_life_todo_yyyy,
// //    (global_flag_which_graph == 1)? "First 6 months.": "Second 6 months" 
//     (global_flag_which_graph == 1)? "               ": "               " 
//   );
// /*     (global_flag_which_graph == 1)? "First Half.": "Second Half"  */
// /* kin(strlen(p)); */
// /* ksn(p); */
// 
//   scharswitch(p, '.', ' ');  /* dots out */
// 
//   f_docin_put(p,n);
// 



  strcpy(p,"\n");  /* blank line before grh lines */
  n = (int)strlen(p);
  f_docin_put(p,n);

/* kin(strlen(p)); */


  sfill(&wk_line[0],Num_eph_grh_pts,GRH_CONNECT_CHAR);
  wk_line[0] = GRH_SIDELINE_CHAR;  
  wk_line[Num_eph_grh_pts-1] = GRH_SIDELINE_CHAR;


  n = sprintf(p,"%s%s\n",&lf_mar[0],&wk_line[0]);  /* 2nd line */

/*  scharswitch(p, '|', ' '); */ /* sideline out */;
  scharswitch(p, '|', '#');  /* sideline out */

      bracket_string_of("#", p, "<span class=\"cSky\">", "</span>");
      scharswitch(p, '#', ' ');

  n = (int)strlen(p);
/* kin(n); */
  f_docin_put(p,n);

  put_BIGgrh_blnk_lines_at_top();

}   // end of prt_BIGgrh_hdr(int grh_num)  /* grh title and 2nd line */


void put_BIGgrh_blnk_lines_at_top(void)    /* top is now the bottom */
{      /* after reversal. (high stress used to be at the top) */
  static int top_ln_ctr;
  int itop;
  int dummy[1];
  //char prt_line[SIZE_EPH_GRH_LINE+1];
  char prt_line[SIZE_BIG_EPH_GRH_LINE+1];
  ;
/* trn("in put_BIGgrh_blnk_lines_at_top"); */
  dummy[0] = 0; /* init */
  if (False_top <= Grh_top) return;
  top_ln_ctr = 0;
  sfill(&prt_line[0],Num_eph_grh_pts,GRH_BACKGROUND_CHAR);

  /* sideline out */
/*   prt_line[0] = GRH_SIDELINE_CHAR; */
/*   prt_line[Num_eph_grh_pts-1] = GRH_SIDELINE_CHAR; */


//tn();b(200);ki(Num_file_lines_top); 
//kin(Num_file_lines_top); 
  for (itop=1; itop <= Num_file_lines_top; ++itop) {
//tr("put_BIGgrh_blnk_lines_at_top()");ksn(prt_line);  
    prt_BIGgrh_line(&prt_line[0],dummy,0,&top_ln_ctr,False_top);
  }
/* ksn(gbl_save_last_line); */
} // end of put_BIGgrh_blnk_lines_at_top(void)    /* top is now the bottom */


void prt_BIGgrh_bot(char *p_line, int cols_with_pt[], int pt_ctr, int *p_ln_ctr)
{
  char lf_mar[SIZE_GRH_LEFT_MARGIN+1];
  int n,k;
  char *p = &Swk[0];
  char mywk[SIZE_GRH_LEFT_MARGIN+1];
  ;
//trn("in prt_BIGgrh_bot"); 
  sfill(&lf_mar[0],SIZE_GRH_LEFT_MARGIN,' ');

  *p_ln_ctr = -1;      /* last line marker */
  prt_BIGgrh_line(&p_line[0],&cols_with_pt[0],pt_ctr,   
    p_ln_ctr,Grh_top); /* last line */






// 20180808  try no line at top of all sky     worked
//
//  // add a line of all sky
//  char my184Sharps3[1024]; sfill(my184Sharps3, 184, '#'); 
//  sprintf( Grh_body_BIG + Num_lines_in_grh_body  * (SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE + 1), "%s%s", "       ", my184Sharps3);
//  Num_lines_in_grh_body = Num_lines_in_grh_body + 1 ;
//trn("in prt_BIGgrh_bot()   NEW add ONE LINE fill 184sharps");kin(Num_lines_in_grh_body);
//










  sfill(&p_line[0],Num_eph_grh_pts,GRH_CONNECT_CHAR);
  /* sideline out */
/*   p_line[0] = GRH_SIDELINE_CHAR; */
/*   p_line[Num_eph_grh_pts-1] = GRH_SIDELINE_CHAR; */

//  put_fill_lines_at_bot(&p_line[0]);  /* now top after reversal */

  reverse_BIGgrh_body_and_prt();
  if(strcmp(gbl_instructions,  "return only thumbnail data") == 0) return;

  sfill(&p_line[0],Num_eph_grh_pts,GRH_BACKGROUND_CHAR);

  /* sideline out */
/*   p_line[0] = GRH_SIDELINE_CHAR; */
/*   p_line[Num_eph_grh_pts-1] = GRH_SIDELINE_CHAR;  */ /* one buffer line */

  n = sprintf(p,"%s%s\n",&lf_mar[0],&p_line[0]);

  //scharswitch(p, GRH_BACKGROUND_CHAR, '|');   // change tick from apostrophe to pipe
  scharswitch(p, GRH_BACKGROUND_CHAR, '\'');

  f_docin_put(p,n);
      /* ^bot line of dots */

  /* sideline out */
/*   */
  if (global_flag_which_graph != 1) {  /* leave pipes on "J" in Jan */
    Grh_bottom_line1BIG[0] = ' ';  /* 1st col, (sideline char) */
  }
  Grh_bottom_line1BIG[Num_eph_grh_pts-1] = ' '; /* right side of grh*/

  n = sprintf(p,"%s%s\n", &lf_mar[0], Grh_bottom_line1BIG);
  f_docin_put(p,n);

  /* sideline out */
  if (global_flag_which_graph != 1) {  /* leave pipes on "J" in Jan */
    Grh_bottom_line2BIG[0] = ' ';  /* 1st col, (sideline char) */
  }

  /* right side of grh*/
/*   Grh_bottom_line2BIG[Num_eph_grh_pts] = ' ';  */
/*   Grh_bottom_line2BIG[Num_eph_grh_pts-1] = 'Q';  */

  n = sprintf(p,"%s%s\n", &lf_mar[0], Grh_bottom_line2BIG);
  f_docin_put(p,n);

  /* put year into line3 lf_mar 
  */
  sfill(mywk, SIZE_GRH_LEFT_MARGIN, ' ');
  sprintf(mywk,"%4d  ", Grh_beg_yr);    /* =magic */
  k = (int)strlen(lf_mar) -1 - 4;           /* 4= numchar in yr e.g. 1988 */
  strncpy(lf_mar+k, mywk, 4);

/*   n = sprintf(p,"%s%s\n", &lf_mar[0], Grh_bottom_line3BIG); */

  strcpy(p,"\n");  /* blank line before line with month names   may 2014 */
  n = (int)strlen(p);
  f_docin_put(p,n);

  n = sprintf(p,"%s%s\n", &lf_mar[0], Grh_bottom_line3BIG);
  f_docin_put(p,n);

/* trn("end of prt_BIGgrh_bot"); */
}   // end of prt_BIGgrh_bot(char *p_line, int cols_with_pt[], int pt_ctr, int *p_ln_ctr)


void reverse_BIGgrh_body_and_prt(void)  /* grh used to have high stress at top */
{
  int iprt, n, running_stress_level_on_line;
  int iprt_thumbnail;
  char linebuf[8192];
  char *p = &Swk[0];
  char *q = &Grh_body_BIG[0];
  int we_have_hit_great_line;  /* 1=y,0=n */
  int we_have_hit_good_line;  /* 1=y,0=n */
  int we_have_hit_stress_line;  /* 1=y,0=n */
  int we_have_hit_omg_line;  /* 1=y,0=n */
  char myLastLine[8192];
  int  first_star_is_in_great, myidx;
  int  first_star_is_in_good;
  int  first_star_is_in_neutral;
  int  first_star_is_in_stress;
  int  first_star_is_in_omg;
  ;
//tn();trn(" IN reverse_BIGgrh_body_and_prt");tn();
//kin(Grh_bot);
//int test124;
//test124 = Stress_val[SUBSCRIPT_FOR_VLO_STRESS_LEVEL]; 
//kin(test124);
//kin(False_bot);




  // log what we have here
//char mylogbuf34[256];
//int  mylogidx34;
//  for (mylogidx34 = 0;  mylogidx34 <= Num_lines_in_grh_body  ; mylogidx34++)      /* iprt is num lines in grh body */
//  {
//    strcpy(mylogbuf34, Grh_body_BIG + mylogidx34 * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
//ki(mylogidx34);ksn(mylogbuf34);
//  }
//



  // only call newPlanBenchmarkLabels();  
  // if the top star in GRH is below good line
  //
//  if (gbl_topStarBelowGood == 1)  newPlanBenchmarkLabels();
//
//      /* 223:int Stress_val[NUM_STRESS_LEVELS] = {304,250,196,142,88,34,-20,-74};   */
//      /*                                                  omg str, good, -20=great  */


  newPlanBenchmarkLabels();


  // SET  first_star_is_in VARS using gbl_topStarVal   SET  first_star_is_in VARS using gbl_topStarVal   SET  first_star_is_in VARS using gbl_topStarVal  
  //
//trn("SET first_star_is_in VARS using gbl_topStarVal  SET first_star_is_in VARS using gbl_topStarVal  SET first_star_is_in VARS using gbl_topStarVal");

          //    //
          //      /* --------------- "/Users/xxx/_PC/usr/apple/_c/_wrk/futdefs.h" -------------- */
          //      /* 128:#define SUBSCRIPT_FOR_VLO_STRESS_LEVEL 6    * Stress_val[6] = vlo- "great"*/
          //      /* 129:#define SUBSCRIPT_FOR_LO_STRESS_LEVEL 5     * Stress_val[5] = lo- "good" */
          //      /* 130:#define SUBSCRIPT_FOR_HIGH_STRESS_LEVEL 3   * Stress_val[3] = hi-"stress" */
          //      /* 131:#define SUBSCRIPT_FOR_VHIGH_STRESS_LEVEL 2  * Stress_val[2] = hi-"OMG" */
          //        //
          //        //    futdoc.h
          //        //    char *Stress_name[NUM_STRESS_LEVELS] = {
          //        //      "       ",
          //        //      "   OMG-",
          //        //      "       ",
          //        //      "STRESS-",
          //        //      "       ",
          //        //      "  GOOD-",
          //        //      "       ",
          //        //      " GREAT-",
          //        //    };
          //        //
          //      //    #define SIZE_EPH_GRH_INCREMENT 6  /* 1 '*' for every 6 Grhdata score nums */
          //      //
          //      // gbl_numLinesFillToGREAT = (Stress_val[SUBSCRIPT_FOR_VLO_STRESS_LEVEL]  -  Grh_bot ) / SIZE_EPH_GRH_INCREMENT; 
          //      //
          //      /* --------------- "/Users/xxx/_PC/usr/apple/_c/_wrk/futdoc.h" -------------- */
          //      /* 223:int Stress_val[NUM_STRESS_LEVELS] = {304,250,196,142, 88,   34,-20,-74};   */
          //      /*                                                   32  23,        5,            */
          //      /*                                                  omg str,neu, good, -20=great  */
          //      //
          // e.g.       this_line = top - (*p_ln_ctr-1) * SIZE_EPH_GRH_INCREMENT;
          //            for (ilef=0; ilef <= NUM_STRESS_LEVELS-1; ilef++) 
          //              if (this_line >= Stress_val[ilef]) 
          //                if (this_line < Stress_val[ilef] + SIZE_EPH_GRH_INCREMENT) 
          //                  sprintf(&l_mar[0],"%s",Stress_name[ilef]);
          //
  //
  // SET char first_star_is_in* VARS using  gbl_topStarVal
  // gbl_topStarVal was assigned from first line with star (*) or body (X)
  //   value is one of omg, stress, neutral good OR great (USED TO SET graph COLOR)
  //
//trn(" gbl_topStarVal was assigned from first line with star (*) or body (X)");
//trn("SET char first_star_is_in* VARS using  gbl_topStarVal");
//
//kin(gbl_topStarVal);

//  for (int itop = 0; itop < NUM_STRESS_LEVELS; itop++) 
//  { ki(itop);kin(Stress_val[itop]); } // for all STRESS_LEVELS

    first_star_is_in_great   = 0;
    first_star_is_in_good    = 0;
    first_star_is_in_neutral = 0;
    first_star_is_in_stress  = 0;
    first_star_is_in_omg     = 0;





// NOTE the below was used before and it is WRONG for OMG and GREAT
  /* --------------- "/Users/xxx/_PC/usr/apple/_c/_wrk/futdoc.h" -------------- */
  /* 223:int Stress_val[NUM_STRESS_LEVELS] = {304,250,196,142,88,34,-20,-74};   */
  /*                                                   32  23,    5,            */
  /*                                                  omg str, good, -20=great  */
// NOTE the above was used before and it is WRONG for OMG and GREAT
//
//    if (    gbl_topStarVal >= 142 )   first_star_is_in_omg     = 1;  
//
//    if (    gbl_topStarVal <  142
//        &&  gbl_topStarVal >=  88 )   first_star_is_in_stress  = 1;  
//
//    if (    gbl_topStarVal <   88
//        &&  gbl_topStarVal >   34 )   first_star_is_in_neutral = 1;  
//
//    if (    gbl_topStarVal <=  34
//        &&  gbl_topStarVal >  -20 )   first_star_is_in_good    = 1;  
//
//    if (    gbl_topStarVal <= -20 )   first_star_is_in_great   = 1;  
//

          //       -----------------------------------------------------------------
          //             int Stress_val[NUM_STRESS_LEVELS] = {304, 250, 196, 142,  88,  34, -20, -74};  
          //                                       index   =   0    1    2    3    4    5    6    7  
          //                              LABEL IN GRAPH   =       omg       str       goo       gre
          //                             COLORS IN GRAPH   =      cRe2      cRed cNeu cGre      cGr2
          //       -----------------------------------------------------------------
    if (    gbl_topStarVal >= 250 )   first_star_is_in_omg     = 1;  

    if (    gbl_topStarVal <  250
        &&  gbl_topStarVal >= 142 )   first_star_is_in_stress  = 1;  

    if (    gbl_topStarVal <  142
        &&  gbl_topStarVal >   34 )   first_star_is_in_neutral = 1;  

    if (    gbl_topStarVal <=  34
        &&  gbl_topStarVal >  -74 )   first_star_is_in_good    = 1;  

    if (    gbl_topStarVal <= -74 )   first_star_is_in_great   = 1;  





//kin(first_star_is_in_great );
//kin(first_star_is_in_good );
//kin(first_star_is_in_neutral );
//kin(first_star_is_in_stress );
//kin(first_star_is_in_omg );
  //
  // SET  first_star_is_in VARS using gbl_topStarVal   SET  first_star_is_in VARS using gbl_topStarVal   SET  first_star_is_in VARS using gbl_topStarVal  



  // set iprt
  if (Num_lines_in_grh_body-1 <  MAX_GRH_BODY_LINES-1) {
    iprt           = Num_lines_in_grh_body-1;
    iprt_thumbnail = Num_lines_in_grh_body-1;
  } else {
//tn();trn("HIT MAX_GRH_BODY_LINES = 333 ! b  holy cow");tn();
    iprt           = MAX_GRH_BODY_LINES-1;
    iprt_thumbnail = MAX_GRH_BODY_LINES-1;
  }



//int  gbl_topStarVal;              // for putting all-new benchmark labels to existing lines 
//  int  first_star_is_in_great;
//  int  first_star_is_in_good;
//  int  first_star_is_in_neutral;
//  int  first_star_is_in_stress;
//  int  first_star_is_in_omg;


//
//// old
//  // SET  first_star_is_in  VARS    SET  first_star_is_in  VARS    SET  first_star_is_in  VARS   
//  if (Num_lines_in_grh_body-1 <  MAX_GRH_BODY_LINES-1) {
//    iprt           = Num_lines_in_grh_body-1;
//    iprt_thumbnail = Num_lines_in_grh_body-1;
//  } else {
//tn();trn("HIT MAX_GRH_BODY_LINES = 333 ! b  holy cow");tn();
//    iprt           = MAX_GRH_BODY_LINES-1;
//    iprt_thumbnail = MAX_GRH_BODY_LINES-1;
//  }
//
//  /* read thru Grh_body_BIG to see if "GREAT-" or "GOOD-" is first.
//  *  (this is for coloring the first star lines.  we do not
//  *   know if Great * or Good * level is first)
//  */
//  myidx = iprt;
//  first_star_is_in_great = 0;
//  first_star_is_in_good  = 0;
//  first_star_is_in_neutral  = 0;
//  first_star_is_in_stress   = 0;
//  first_star_is_in_omg      = 1;  // default
//
//
//    if (strstr(linebuf, "GREAT")  != NULL) {
//      first_star_is_in_great = 1;
//      first_star_is_in_omg     = 0;
//      break;
//    }
//    if (strstr(linebuf, "GOOD")   != NULL) {
//      first_star_is_in_good = 1;
//      first_star_is_in_omg     = 0;
//      break;
//    }
//    if (strstr(linebuf, "STRESS")   != NULL) {
//      first_star_is_in_neutral = 1;
//      first_star_is_in_omg     = 0;
//      break;
//    }
//    if (strstr(linebuf, "OMG")   != NULL) {
//      first_star_is_in_stress = 1;
//      first_star_is_in_omg    = 0;
//      break;
//    }
//   
//kin(first_star_is_in_great );
//kin(first_star_is_in_good );
//kin(first_star_is_in_neutral );
//kin(first_star_is_in_stress );
//kin(first_star_is_in_omg );
//  // SET  first_star_is_in  VARS    SET  first_star_is_in  VARS    SET  first_star_is_in  VARS   
//
//



//  // NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW 
//  // NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW 
//  //
//ksn(" start NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW ");
//ksn(" start NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW ");
//  //
//  // try new tack  20180701  check for presence of  ALL  benchmark labels 
//  // read backwards through the data in q (Grh_body_BIG) 
//  // and make sure these 2 benchmark labels are there -  STRESS   GREAT
//  // as needed, fill in lines of '#' (blue sky) to make up the space between banchmark lines
//  //
//  
//  char linebufNEW[256];
//  int myidxNEW;
//  int mynumlinesNEW;
//  int mycntlinesNEW;
//  int myhitGREAT;
//  char my184SharpsNEW[1024]; sfill(my184SharpsNEW, 184, '#'); 
//
//  mynumlinesNEW = iprt;  /* iprt is num lines in grh body right now*/
//  myhitGREAT    = 0;
//
//
//kin(iprt                 );
//kin(iprt_thumbnail      );
//kin(Num_lines_in_grh_body );
//
//  for (myidxNEW = 0;  myidxNEW < mynumlinesNEW ; myidxNEW = myidxNEW + 1 )      // read backwards (STRESS to GREAT direction)
//  {
//    strcpy(linebufNEW, q + myidxNEW * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
//ki(myidxNEW);ksn(linebufNEW);
//
//    // read until you get to STRESS
//    //
////    if (strstr(linebufNEW, "STRESS")  == NULL)  continue;
//    if (strstr(linebufNEW, "STRESS")  != NULL)  break;
//  }
//
//  // here we are on the STRESS line 
//  // NOTE: there are 35 lines between STRESS line and GREAT line
//  // so keep reading backward (keeping a line count) until we hit the GREAT line  -  then we are finished
//  //  IF we run out of lines reading backwards
//  //  AND we have NOT hit the GREAT line  
//  //  THEN add sky lines until the line count is 35 - then   ADD the GREAT line  - then we are finished
//  // 
//trn("NEW hit STRESS");
//ki(myidxNEW);ki(mynumlinesNEW );
//  for (            ;  myidxNEW < mynumlinesNEW ; myidxNEW = myidxNEW + 1 )      // read backwards (STRESS to GREAT direction)
//  {
//    mycntlinesNEW = mycntlinesNEW + 1;
//    strcpy(linebufNEW, q + myidxNEW * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
//ki(myidxNEW);ki(mycntlinesNEW);ksn(linebufNEW);
//    if (strstr(linebufNEW, "GREAT")  != NULL) {
//      myhitGREAT    = 1;
//trn("NEW hit GREAT");
//      break;  // FINISHED!
//    }
//  }
//  if (myhitGREAT == 0 )
//  {
//trn("NEW   NO   hit GREAT");
//    // here we did not hit the GREAT line ,  do fill in sky lines
//    for (int mmm = mycntlinesNEW;  mmm <= 35; mmm++ )  // NOTE  MAGIC NUM 35   35 lines in between stress and great
//    {
//      iprt                  = iprt + 1;
//      iprt_thumbnail        = iprt_thumbnail + 1 ;
//      Num_lines_in_grh_body = Num_lines_in_grh_body + 1 ;
//tr("NEW add fill");ki(mmm);kin(Num_lines_in_grh_body);
//      sprintf( Grh_body_BIG + iprt  * (SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE + 1), "%s%s", "       ", my184SharpsNEW);
//    }
//
//    // here we are at the point where there should be the GREAT line, so put it in
//    //
//      iprt                  = iprt + 1;
//      iprt_thumbnail        = iprt_thumbnail + 1 ;
//      Num_lines_in_grh_body = Num_lines_in_grh_body + 1 ;
//tr("NEW add GREAT");;kin(Num_lines_in_grh_body);
//    sprintf( Grh_body_BIG + iprt  * (SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE + 1), "%s%s", " GREAT-", my184SharpsNEW);
//  }
//
//kin(iprt                 );
//kin(iprt_thumbnail      );
//kin(Num_lines_in_grh_body );
//
//ksn(" end NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW ");
//ksn(" end NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW ");
//  //
//  // NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW 
//  // NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW  NEW 
//
//



//
//  // New TRY on GREAT always on graph
//  if (    first_star_is_in_good    == 1         // means "  GOOD-" is there but not " GREAT-"
//      ||  first_star_is_in_neutral == 1 )       // means "  GOOD-" is NOT there and " GREAT-" is NOT there
//  {
//
//    //
//      /* --------------- "/Users/xxx/_PC/usr/apple/_c/_wrk/futdefs.h" -------------- */
//      /* 128:#define SUBSCRIPT_FOR_VLO_STRESS_LEVEL 6    * Stress_val[6] = vlo- "great"*/
//      /* 129:#define SUBSCRIPT_FOR_LO_STRESS_LEVEL 5     * Stress_val[5] = lo- "good" */
//      /* 130:#define SUBSCRIPT_FOR_HIGH_STRESS_LEVEL 3   * Stress_val[3] = hi-"stress" */
//      /* 131:#define SUBSCRIPT_FOR_VHIGH_STRESS_LEVEL 2  * Stress_val[2] = hi-"OMG" */
//        //
//        //    futdoc.h
//        //    char *Stress_name[NUM_STRESS_LEVELS] = {
//        //      "       ",
//        //      "   OMG-",
//        //      "       ",
//        //      "STRESS-",
//        //      "       ",
//        //      "  GOOD-",
//        //      "       ",
//        //      " GREAT-",
//        //    };
//        //
//      //    #define SIZE_EPH_GRH_INCREMENT 6  /* 1 '*' for every 6 Grhdata score nums */
//      //
//      // gbl_numLinesFillToGREAT = (Stress_val[SUBSCRIPT_FOR_VLO_STRESS_LEVEL]  -  Grh_bot ) / SIZE_EPH_GRH_INCREMENT; 
//      //
//      /* --------------- "/Users/xxx/_PC/usr/apple/_c/_wrk/futdoc.h" -------------- */
//      /* 223:int Stress_val[NUM_STRESS_LEVELS] = {304,250,196,142,88,34,-20,-74};   */
//      /*                                                   32  23,    5,            */
//      /*                                                  omg str, good, -20=great  */
//      //
//
//    // was here
//
//    //
//      // read thru   char *q = &Grh_body_BIG[0];     
//      //      idx 0 -> end   (direction is from stress to great)
//      // and,  AFTER hitting "STRESS-" line
//      //   1. blank out first seven chars
//      //   2. manually add  "  GOOD-"  and  " GREAT-"
//      // IF graph lines end,
//      //   1. manually add blank sky lines - all '#'  until 2 blank lines "above" GREAT line
//      int  readingAboveSTRESSline;
//      int  numLinesBetweenLABELs;
//      int  cntLinesBetweenLABELs;
//      int  isGREATprinted;
//      char nextLabelToPut[16];    // "  GOOD-"  and  " GREAT-"
//      char first7chars[16];   
//      char line184Sharps[1024]; sfill(line184Sharps, 184, '#'); 
////      char line184S[1024]; sfill(line184Sharps, 184, '*'); 
////      char line184X[1024]; sfill(line184Sharps, 184, 'X'); 
//
//      readingAboveSTRESSline = 0;
//      numLinesBetweenLABELs  = 17;
//      cntLinesBetweenLABELs  = 0;
//      isGREATprinted         = 0;
//
////tn(); 
////trn(" New TRY on GREAT always on graph    ttttttttttttttttttttttttttttttttttttttttttttttttttttt");
////tn();  
//      for (int i = 0; i < Num_lines_in_grh_body - 1; i++)   // read grh data in the direction from stress thru great
//      {
//        strcpy(linebuf, q  +  i * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE + 1) );
////ki(i);ksn(linebuf);    
//        if (strstr(linebuf, "STRESS-") != NULL) {
//          readingAboveSTRESSline = 1;
////trn(" readingAboveSTRESSline = 1");
//          strcpy(nextLabelToPut, "  GOOD-");
//          continue;
//        }
//
//        // ensure first 7 chars are = "       "
//
//        //    /* Build a string starting at "s" using consecutive chars from ptr "begarg" to ptr "end"
//        //    *  Add '\0' at end. 
//        //    *  Make sure "s" is big enough.
//        //    */
//        //    char *mkstr(char *s, char *begarg, char *end)
//        //
//        mkstr(first7chars, &linebuf[0], &linebuf[6]);
//    //ksn(first7chars);
//
//        if (readingAboveSTRESSline == 1)
//        {
//          cntLinesBetweenLABELs = cntLinesBetweenLABELs + 1;
////kin(cntLinesBetweenLABELs);
//          //
//          // if this line has length = 0,  put 7 spaces and 184 sharps in the line
//          //
//          if (strlen(linebuf) ==  0) {
////trn("    (strlen(linebuf) ==  0");
//            sprintf(  // PUT LINE IN TBL
//              Grh_body_BIG + i  * (SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE + 1),
//              "%s%s", "       ", line184Sharps
//            );
//            //  not a new line    ++Num_lines_in_grh_body;
////strcpy(linebuf, q  +  i * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE + 1) );
////ki(i);ksn(linebuf);    
//          }
//          
//
//          if (cntLinesBetweenLABELs >= numLinesBetweenLABELs )
//          {
////kin(cntLinesBetweenLABELs);
//             cntLinesBetweenLABELs = 0;
////kin(cntLinesBetweenLABELs);
////ksn(nextLabelToPut);
////trn("print above label here");
//
//
//            if (    strstr(nextLabelToPut, "  GOOD-") != NULL 
//                &&  first_star_is_in_good == 1                )
//            {
//              ;
//              // do not print "  GOOD-" if first_star_is_in_good    == 1  
//              // (that means  "  GOOD-" is there already)
//              //
//
//            } else {
//
//              sprintf(  // PUT  BENCHMARK LABEL  LINE IN TBL
//                Grh_body_BIG + i  * (SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE + 1),
//                "%s%s", nextLabelToPut, line184Sharps
//              );
//              //  not a new line    ++Num_lines_in_grh_body;
//            }
////strcpy(linebuf, q  +  i * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE + 1) );
////ki(i);ksn(linebuf);    
//
//
//
//
//            if ( strstr(nextLabelToPut, " GREAT-") != NULL ) isGREATprinted = 1;
//
//            strcpy(nextLabelToPut, " GREAT-");
////trn("print below label next");
////ksn(nextLabelToPut);
//            cntLinesBetweenLABELs = 0;
////kin(cntLinesBetweenLABELs);
//
//          } // if (cntLinesBetweenLABELs >= numLinesBetweenLABELs )
//
//        }
//
//      } // read grh data in the direction from stress thru great
//
//
//
//
//
//
//kin(cntLinesBetweenLABELs);
//kin(numLinesBetweenLABELs);
//      //
//      // if GREAT line is not printed, add lines until it is
//      //
//char testbuf256[256];
//      if (isGREATprinted == 0)
//      {
//        while (isGREATprinted == 0)
//        {       // if GREAT line is not printed, add lines until it is
//          sprintf(  // PUT LINE IN TBL
//            Grh_body_BIG + (Num_lines_in_grh_body-1) * (SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE + 1),
//            "%s%s", "       ", line184Sharps
//          );
//
//strcpy(testbuf256, Grh_body_BIG + (Num_lines_in_grh_body-1) * (SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE + 1));
//tr("21!");ksn(testbuf256);    
//          ++Num_lines_in_grh_body;
//          ++iprt;              //  iprt          = Num_lines_in_grh_body-1;
//          ++iprt_thumbnail ;   // iprt_thumbnail = Num_lines_in_grh_body-1;
//
//
//
//          cntLinesBetweenLABELs = cntLinesBetweenLABELs + 1;
//kin(cntLinesBetweenLABELs);
//kin(numLinesBetweenLABELs);
//
//          if (cntLinesBetweenLABELs >= numLinesBetweenLABELs ) {
//
//
//            sprintf(  // PUT  BENCHMARK LABEL  LINE IN TBL
//              Grh_body_BIG + (Num_lines_in_grh_body-1) * (SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE + 1),
//              "%s%s", nextLabelToPut, line184Sharps
//            );
//strcpy(testbuf256, Grh_body_BIG + (Num_lines_in_grh_body-1) * (SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE + 1));
//tr("22!");ksn(testbuf256);    
//
//            ++Num_lines_in_grh_body;
//            ++iprt;              //  iprt          = Num_lines_in_grh_body-1;
//            ++iprt_thumbnail ;   // iprt_thumbnail = Num_lines_in_grh_body-1;
//
////
////  sfill(&l_mar[0],SIZE_GRH_LEFT_MARGIN,' ');  /* mk margin = blanks */
////
//
//            sprintf(  // PUT  SKY SPACER LABEL  LINE IN TBL
//              Grh_body_BIG + (Num_lines_in_grh_body-1) * (SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE + 1),
//              "%s%s", "       ", line184Sharps
//            );
//strcpy(testbuf256, Grh_body_BIG + (Num_lines_in_grh_body-1) * (SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE + 1));
//tr("23!");ksn(testbuf256);    
//
//            ++Num_lines_in_grh_body;
//            ++iprt;              //  iprt          = Num_lines_in_grh_body-1;
//            ++iprt_thumbnail ;   // iprt_thumbnail = Num_lines_in_grh_body-1;
//
//
//            sprintf(  // PUT  SKY SPACER LABEL  LINE IN TBL
//              Grh_body_BIG + (Num_lines_in_grh_body-1) * (SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE + 1),
//              "%s%s", "       ", line184Sharps
//            );
//strcpy(testbuf256, Grh_body_BIG + (Num_lines_in_grh_body-1) * (SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE + 1));
//tr("24!");ksn(testbuf256);    
//            ++Num_lines_in_grh_body;
//            ++iprt;              //  iprt          = Num_lines_in_grh_body-1;
//            ++iprt_thumbnail ;   // iprt_thumbnail = Num_lines_in_grh_body-1;
//
//
//    //    strcpy(testbuf256, q  +  i * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE + 1) );
//    //ki(i);ksn(testbuf256);    
//
//            isGREATprinted = 1;
//            break;
//          }
//        }
//      }
//
//
////tn(); 
////trn(" New TRY on GREAT always on graph    tttttttttttt   END   tttttttttttttttttttttttttttttttt");
////tn();  
//
//  } // New TRY on GREAT always on graph
//
//





/* trn("in reverse_BIGgrh_body_and_prt"); */
  /* 20130911 ONLY use these flags to determine star coloring
  *  for good (green) and stress (red)
  */
  we_have_hit_great_line   = 0;  /* init to no */
  we_have_hit_good_line   = 0;  /* init to no */
  we_have_hit_stress_line = 0;  /* init to no */
  we_have_hit_omg_line = 0;  /* init to no */

/* tn();trn("in reverse_BIGgrh_body_and_prt()"); */



//  first_star_is_in  used below


   // start of thumbnailinfo collection   =========================================================================
   // start of thumbnailinfo collection   =========================================================================
   //
   gbl_topToGreatLine  = 0 ;        // count of lines from top of thumbnail tn to green great line
   gbl_botToStressLine = 0 ;       // count of lines from bot of thumbnail tn to red stress  line
   gbl_hitStressLine   = 0;  
   gbl_hitGreatLine    = 0;  

   // main of thumbnailinfo collection
   //


   //   sfill(myLastLine, Num_eph_grh_pts, ' '); 
// for test
  memcpy(gbl_thumbnailInfo, "\0", 4096); /* write the string */
//ksn(gbl_thumbnailInfo);

//
  // build string for constructing thumbnail of graph in javascript using canvas
  // ( char gbl_thumbnailInfo[8192]; )
  // ------------------------------------------------------------
  //  JS
  // code color 
  // ------------------------------------------------------------
  //   B  .cSky  Sky      { background-color:#3f3ffa; font-weight: bold; }
  //   *  .star  Star     { color:#f7ebd1; font-weight: bold; }
  //   G  .cGr2  Great    { background-color:#80ff40; }    Light green
  //   D  .cGre  Good     { background-color:#c0ffc0; }    darker green
  //   N  .cNeu  Neutral  { background-color:#edebd8; }
  //   S  .cRed  Stress   { background-color:#ffb5c9; }    pink
  //   O  .cRe2  OMG      { background-color:#ff7ba3; }    darker red
  //
  // format is  B084  for 84 blue sky chars
  // ------------------------------------------------------------
  //                           JS            char in
  //                          code           linebuf
  // ------------------------------------------------------------
//  #define COL_SKY "3f3ffa"    B   Blue sky   #
//  #define COL_STA "ffffff"    *   star       *
//  #define COL_GRE "80ff40"    G   Great      X  curr_color
//  #define COL_GOO "c0ffc0"    D   gooD       X  curr_color
//  #define COL_NEU "edebd8"    N   neutral    X  curr_color
//  #define COL_STR "ffb5c9"    S   Stress     X  curr_color
//  #define COL_OMG "ff7ba3"    O   OMG        X  curr_color
  // ------------------------------------------------------------
  #define SKY_CODE      "B"
  #define STAR_CODE     "*"
  #define BODY_CODE_GRE "G"
  #define BODY_CODE_GOO "D"

  #define BODY_CODE_NEU "N"
  #define BODY_CODE_STR "S"
  #define BODY_CODE_OMG "O"
  #define LINE_GREAT    "<"  // green benchmark line
  #define LINE_STRESS   ">"  // red   benchmark line
  // ------------------------------------------------------------
  // javascript will take these codes and paint the colors above
  // ------------------------------------------------------------

  // _linebuf=[       ######*XXXXXX*#####*XXXXXXXXX##X#######*XXX#################################
  // ###############*XXXXXXXXXXX#####################****#####XXXXXXXXXXXXXXXXXXXXXXXXXXXXX######################]

  char curr_BODY_CODE[4]; // the color code for chars in the graph body  ("X" in linebuf)
  char thumbnail_buf[16]; // like   "D034"
//  char lin;   // LineBuf Line
  char lbc;  // LineBuf Char
  int are_in_SKY;
//  int are_in_STAR;
  int are_in_BODY;
  int grh_char_ctr;
  int this_is_first_line;

  are_in_SKY  = 0;
//  are_in_STAR = 0;
  are_in_BODY = 0;
  grh_char_ctr = 0;
  this_is_first_line = 1;

  // set the starting color of graph body chars
  if (first_star_is_in_great    == 1)  { strcpy(curr_BODY_CODE, BODY_CODE_GRE); }
  if (first_star_is_in_good     == 1)  { strcpy(curr_BODY_CODE, BODY_CODE_GOO); }
  if (first_star_is_in_neutral  == 1)  { strcpy(curr_BODY_CODE, BODY_CODE_NEU); }
  if (first_star_is_in_stress   == 1)  { strcpy(curr_BODY_CODE, BODY_CODE_STR); }
  if (first_star_is_in_omg      == 1)  { strcpy(curr_BODY_CODE, BODY_CODE_OMG); }

  gbl_putThumbnailInfoHERE = 0;  // INIT

    
//
//  // insert 3 empty SKY lines at the top
//  memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE, "B184Z000", 8); /* write the string */
//  gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 8;
//  memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE, "B184Z000", 8); /* write the string */
//  gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 8;
//  memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE, "B184Z000", 8); /* write the string */
//  gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 8;

  // insert 3 empty SKY lines at the top
  sprintf(thumbnail_buf, "B%02xZZZ", 184);  // javascript  eol is  ZZZ
  // put 3 neutral color pixels at top (N01)
//  sprintf(thumbnail_buf, "N01B%02xZZZ", 183);  // javascript  eol is  ZZZ

  memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE, thumbnail_buf, 6); /* write the string */
  gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 6;
  gbl_topToGreatLine       = gbl_topToGreatLine + 1;        // count of lines from top of thumbnail tn to green great line
  memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE, thumbnail_buf, 6); /* write the string */
  gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 6;
  gbl_topToGreatLine       = gbl_topToGreatLine + 1;        // count of lines from top of thumbnail tn to green great line
  memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE, thumbnail_buf, 6); /* write the string */
  gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 6;
  gbl_topToGreatLine       = gbl_topToGreatLine + 1;        // count of lines from top of thumbnail tn to green great line

//ki(gbl_putThumbnailInfoHERE); ks(gbl_thumbnailInfo); ksn(thumbnail_buf);


  // do  not use iprt twice, so use iprt_thumnail
  // go BACKWARDS thru lines to get correct top-down order
  //
//kin(iprt_thumbnail);

//    unsigned char mywkchar;
//    char mywkstring[8];
//trn("test repeat = hex");

//trn("hit  START  line =======");
//ki(iprt_thumbnail);

gbl_hitGreatLine  = 0;   // init
gbl_hitStressLine = 0;   // init

//char linebufTN[2048];
// init linebufTN
gbl_fromGreatToStress = 0;

//int debugLine1;
//debugLine1 = 1;


int printSKYlineAftergreat = 0;

for ( ;  iprt_thumbnail > -1  ; --iprt_thumbnail) /* iprt_thumbnail is num lines in grh body */
{

    strcpy(linebuf, q+iprt_thumbnail*(SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
//ki(iprt_thumbnail); ksn(linebuf);

    if (strlen(linebuf) == 0) continue;
//
// for test
// strcpy(linebuf, "       ######*XXXXXX*#####*XXXXXXXXX##X#######*XXX################################################*XXXXXXXXXXX#####################****#####XXXXXXXXXXXXXXXXXXXXXXXXXXXXX######################");

      // on the FIRST LINE, FIRST NON-SPACE CHAR 
      // set appropriate are_in_* var to 1
      if (this_is_first_line == 1) {
        this_is_first_line = 0;
//trn("first line");ksn(linebuf);
//kcn(linebuf[7]);
        if (strstr(linebuf, "X") != NULL) {          // fix flakes
//trn("first line  has  X     PRINT line of sky");
          printSKYlineAftergreat = 1;                // fix flakes
        }

        if (linebuf[7] == 'X') are_in_BODY = 1;   // hit BODY CHAR

//        if (linebuf[7] == '*') are_in_STAR = 1; // treat * STAR like its an X  BODY
        if (linebuf[7] == '*') are_in_BODY = 1;   // treat * STAR like its an X  BODY

        if (linebuf[7] == '#') are_in_SKY  = 1;   // hit BODY CHAR
//kin(are_in_SKY );
//kin(are_in_STAR );
//kin(are_in_BODY );

        continue;  // should not have body char in top line  ( should be star )
      }


    // set the current color of graph body chars
    if (strstr(linebuf, "GREAT" )   != NULL) { strcpy(curr_BODY_CODE, BODY_CODE_GOO); 
//trn("hit  GREAT  line =======");
//ki(iprt_thumbnail);
    }
    if (strstr(linebuf, "GOOD"  )   != NULL) { strcpy(curr_BODY_CODE, BODY_CODE_NEU); 
//trn("hit  GOOD   line =======");
//ki(iprt_thumbnail);
    }
    if (strstr(linebuf, "STRESS")   != NULL) { strcpy(curr_BODY_CODE, BODY_CODE_STR); 
//trn("hit  STRESS line =======");
//ki(iprt_thumbnail);
      gbl_hitStressLine = 1;  
    }
    if (strstr(linebuf, "OMG"   )   != NULL) { strcpy(curr_BODY_CODE, BODY_CODE_OMG); 
//trn("hit  OMG    line =======");
//ki(iprt_thumbnail);
    }


    // put in green (<)  and  red (>)  benchmark lines
    if (strstr(linebuf, "GREAT" )   != NULL) { 
      gbl_hitGreatLine = 1;  
      sprintf(thumbnail_buf, "Q%02xZZZ",  184);
      memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE, thumbnail_buf, 6); /* write the string */
      gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 6;

      if ( printSKYlineAftergreat == 1 ) {  // fix flakes
        printSKYlineAftergreat = 0;
        sprintf(thumbnail_buf, "B%02xZZZ",  184);
        memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE, thumbnail_buf, 6); /* write the string */
        gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 6;
      }
      continue;
    }

    if (strstr(linebuf, "STRESS")   != NULL) { 
      sprintf(thumbnail_buf, "W%02xZZZ",  184);
      memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE, thumbnail_buf, 6); /* write the string */
      gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 6;
      continue;
    }

    for (int i=0; linebuf[i] != '\0'; i++)    // for each char in linebuf  of grh body
    {
      lbc  = linebuf[i]; 

//ki(i); kcn(lbc);

      // treat * STAR like its an X  BODY
      //
      if (lbc == '*')  lbc = 'X';  // hit STAR CHAR         // treat * STAR like its an X  BODY

      if (lbc == 'X') {  // hit BODY CHAR
        if   (are_in_BODY == 1) grh_char_ctr = grh_char_ctr + 1;
        else {
          if (are_in_SKY  == 1) {
            // example
            //  n = sprintf(p,"%s%s", lin, myEOL);
            //  memcpy(gbl_space_for_HTML_fut + gbl_put_html_here, p, n); /* write the string */
            //  gbl_put_html_here = gbl_put_html_here + n;

//            sprintf(thumbnail_buf, "%s%03d", SKY_CODE, grh_char_ctr);
//            memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE, thumbnail_buf, 4); /* write the string */
//            gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 4;

            sprintf(thumbnail_buf, "%s%02x", SKY_CODE, grh_char_ctr);

//if (debugLine1 == 1   &&  strstr(year_in_the_life_todo_yyyy , "2020")  != NULL)  { // for test
//tr("first line debug (sky )"); ks(SKY_CODE); ki(grh_char_ctr);ksn(thumbnail_buf);
//}
//

//if(grh_char_ctr == 0) {trn("00  write SKY");}
            if (grh_char_ctr != 0) {
              memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE, thumbnail_buf, 3); /* write the string */
              gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 3;
            }
            are_in_SKY  = 0;  are_in_BODY = 1;  grh_char_ctr = 1;
          }
//          if (are_in_STAR == 1) {
//            sprintf(thumbnail_buf, "%s%03d", STAR_CODE, grh_char_ctr);
//            memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE, thumbnail_buf, 4); /* write the string */
//            gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 4;
//
//            are_in_STAR  = 0;  are_in_BODY = 1;  grh_char_ctr = 1;
//          }
        }
      }

//      if (lbc == '*') {  // hit STAR CHAR
//        if   (are_in_STAR == 1) grh_char_ctr = grh_char_ctr + 1;
//        else {
//          if (are_in_SKY  == 1) {
//            sprintf(thumbnail_buf, "%s%03d", SKY_CODE, grh_char_ctr);
//            memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE, thumbnail_buf, 4); /* write the string */
//            gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 4;
//
//            are_in_SKY  = 0;  are_in_STAR  = 1;  grh_char_ctr = 1;
//          }
//          if (are_in_BODY == 1) {
//            sprintf(thumbnail_buf, "%s%03d", curr_BODY_CODE, grh_char_ctr);
//            memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE, thumbnail_buf, 4); /* write the string */
//            gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 4;
//
//            are_in_BODY  = 0;  are_in_BODY = 1;  grh_char_ctr = 1;
//          }
//        }
//      }
//

      if (lbc == '#') {  // hit SKY CHAR
        if   (are_in_SKY  == 1) grh_char_ctr = grh_char_ctr + 1;
        else {
          if (are_in_BODY  == 1) {
//            sprintf(thumbnail_buf, "%s%03d", curr_BODY_CODE, grh_char_ctr);
//            memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE, thumbnail_buf, 4); /* write the string */
//            gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 4;
            sprintf(thumbnail_buf, "%s%02x", curr_BODY_CODE, grh_char_ctr);

//if (debugLine1 == 1   &&  strstr(year_in_the_life_todo_yyyy , "2020")  != NULL)  { // for test
//tr("first line debug (body)"); ks(curr_BODY_CODE); ki(grh_char_ctr);ksn(thumbnail_buf);
//}
//

//if(grh_char_ctr == 0) {trn("00  write BODY");}
            if (grh_char_ctr != 0) {
              memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE, thumbnail_buf, 3); /* write the string */
              gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 3;
            }
            are_in_BODY  = 0;  are_in_SKY  = 1;  grh_char_ctr = 1;
          }
//          if (are_in_STAR == 1) {
//            sprintf(thumbnail_buf, "%s%03d", STAR_CODE, grh_char_ctr);
//            memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE, thumbnail_buf, 4); /* write the string */
//            gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 4;
//
//            are_in_STAR  = 0;  are_in_SKY = 1;  grh_char_ctr = 1;
//          }
        }
      }

    } // for each char in linebuf  of grh body

    //
    // here we have finished all of the chars in this graph line
    //

    // HERE we hit END OF LINE CHAR   '\0'
    //

//debugLine1 = 0;   // for test


    if (are_in_SKY  == 1) {
      sprintf(thumbnail_buf, "%s%02x", SKY_CODE, grh_char_ctr);
      grh_char_ctr = 0;
      memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE, thumbnail_buf, 3); /* write the string */
      gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 3;
    }

//    if (are_in_STAR == 1) {
//      sprintf(thumbnail_buf, "%s%03d", STAR_CODE, grh_char_ctr);
//      grh_char_ctr = 0;
//      memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE, thumbnail_buf, 4); /* write the string */
//      gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 4;
//    }
    if (are_in_BODY  == 1) {
      sprintf(thumbnail_buf, "%s%02x", curr_BODY_CODE, grh_char_ctr);
      grh_char_ctr = 0;
      memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE, thumbnail_buf, 3); /* write the string */
      gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 3;
    }

    memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE, "ZZZ", 3); /* write javascript EOL marker  ZZZ */
    gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 3;


    if (gbl_hitGreatLine == 0) {
      gbl_topToGreatLine = gbl_topToGreatLine + 1; // count of lines from top of thumbnail tn to green great line 
    }
    if (gbl_hitStressLine == 1) {
      gbl_botToStressLine = gbl_botToStressLine + 1; // count of lines from bot of thumbnail tn to red stress line 
//tr("add 1 to gbl_botToStressLine ");ki(gbl_botToStressLine); ksn(linebuf);
    }
    if (    gbl_hitGreatLine  == 1
        &&  gbl_hitStressLine == 0 )
    {
      gbl_fromGreatToStress = gbl_fromGreatToStress + 1 ;
    }

} // for each line in grh body 





//trn(" here we have finished all of the graph lines ");
//b(302);
//kin(gbl_fromGreatToStress);

    // here we have finished all of the graph lines 



//
//    // write lines of space on the bottom  lines are 2 * 92 = 184 chars
//    sprintf(thumbnail_buf, "%s%02xZZZ", curr_BODY_CODE, 184);  // javascript eol is  ZZZ
//
//
//    // above prt            = Num_lines_in_grh_body-1;
//    //       iprt_thumbnail = Num_lines_in_grh_body-1;
//
////kin(gbl_putThumbnailInfoHERE);
//    memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE, thumbnail_buf, 6); /* write the string */
//    gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 6;
//    Num_lines_in_grh_body = Num_lines_in_grh_body + 1;
//    gbl_botToStressLine = gbl_botToStressLine + 1; // count of lines from top of thumbnail tn to green great line 
//
//    memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE, thumbnail_buf, 6); /* write the string */
//    gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 6;
//    Num_lines_in_grh_body = Num_lines_in_grh_body + 1;
//    gbl_botToStressLine = gbl_botToStressLine + 1; // count of lines from top of thumbnail tn to green great line 
//
//    memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE, thumbnail_buf, 6); /* write the string */
//    gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 6;
//    Num_lines_in_grh_body = Num_lines_in_grh_body + 1;
//    gbl_botToStressLine = gbl_botToStressLine + 1; // count of lines from top of thumbnail tn to green great line 
//






    // write END OF STRING char
    memcpy(gbl_thumbnailInfo + gbl_putThumbnailInfoHERE, "\0", 1); /* write the string */
    gbl_putThumbnailInfoHERE = gbl_putThumbnailInfoHERE + 1;

//kin(gbl_putThumbnailInfoHERE);




//tn();
//if (strstr(year_in_the_life_todo_yyyy , "2020")  != NULL)  {
//ksn(gbl_thumbnailInfo);
//}





   //
   // end of thumbnailinfo collection   =========================================================================
   // end of thumbnailinfo collection   =========================================================================





  if(strcmp(gbl_instructions,  "return only thumbnail data") == 0) return;


  /* graph top (used to be on bot)
  *  this stress level num increases as graph moves down.
  */
  running_stress_level_on_line = Grh_bot; /* graph top (used to be on bot) */

int  have_printed_blank_top_line;  /*  take out */
  have_printed_blank_top_line = 0;

//trn("hey lines START"); tn();
//kin(first_star_is_in_great);
//kin(first_star_is_in_good);
//kin(first_star_is_in_neutral);
//kin(first_star_is_in_stress);
//kin(first_star_is_in_omg);

  for ( ;  iprt > -1  ; --iprt)
  {    /* iprt is num lines in grh body */

    // strcpy(linebuf, q+iprt*(SIZE_GRH_LEFT_MARGIN+SIZE_EPH_GRH_LINE+1));
    strcpy(linebuf, q+iprt*(SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
//ksn(linebuf);

/*  show iprt and how many stars in linebuf  */
/* int starcnt; starcnt = scharcnt(linebuf, '*'); */
/* kin(iprt);ki(starcnt); */
/*  show iprt and how many stars in linebuf  */


    if (strstr(linebuf, "GREAT")  != NULL)   we_have_hit_great_line  = 1;
    if (strstr(linebuf, "GOOD")   != NULL)   we_have_hit_good_line   = 1;
    if (strstr(linebuf, "STRESS") != NULL)   we_have_hit_stress_line = 1;
    if (strstr(linebuf, "OMG")    != NULL)   we_have_hit_omg_line    = 1;


  // 20180425  change to put GREAT in at top always
    /* we want no blank lines above the GOOD green line level (or GREAT
    *  They must contain a * or X.
    *  TOP LINE OF GRAPH CANNOT BE "EMPTY" of * or X  UNLESS it is GOOD line
    */

/* OLD */
/*         && we_have_hit_great_line == 0  */
/* trn("  !!!   no blank lines above GREAT line !!!"); */

    /* line contains no  * or X  */  
    /* this is bot/ now top line of all connect_CHARS (#)
    */
    if (   sall(linebuf, " |#") 
        && have_printed_blank_top_line == 0
        && we_have_hit_good_line == 0 ) {

        strcat(linebuf, "##");  /* weird bug fix */

      bracket_string_of("#", linebuf, "<span class=\"cSky\">", "</span>");
      scharswitch(linebuf, '#', ' ');

      scharswitch(linebuf, '|', ' ');  /* sideline out */

      n = sprintf(p,"%s\n", linebuf);
      f_docin_put(p,n);
      have_printed_blank_top_line = 1;

      continue;

    }

#ifdef PUT_BACK_COMMENTED_OUT_STUFF /****************************************/
#endif /* ifdef PUT_BACK_COMMENTED_OUT_STUFF ********************************/


/* if(i==41)xstrcpy(linebuf, "X  *X  *XX XX  XX   * X* X  *X  *XX XX  XX   * X* X  *X  *XX XX  XX   * X* X  *X  *XX XX  XX   * X*");x */
/* if(i==40)xtn();tr("-----------ordinary(40) ----------line---");ksn(linebuf);tn();x */
/* if(i==41)xstrcpy(linebuf, "X  *X  *XX XX  XX   * X* X  *X  *XX XX  XX X * X* X  *X  *XX XX  XX   * X* X  *X  *XX XX *");x */
/* if(i==41)xstrcpy(linebuf, "       |X  *X  *XX XX  XX   * X* X  *X  *XX XX  XX X * X* X  *X  *XX XX  XX   * X* X  *X  *XX XX *|");x */
/* if(i==41)xstrcpy(linebuf, "       |                            *X  *XX XX  XX X * X* X  *X  *XX X                            |");x  */
/* if(i==41)xstrcpy(linebuf, "       |                            *X  *XX XX  XX X *                                            |");x  */


/* kin(running_stress_level_on_line); ki(Stress_val[SUBSCRIPT_FOR_LO_STRESS_LEVEL]); */
/*    if (running_stress_level_on_line < Stress_val[SUBSCRIPT_FOR_LO_STRESS_LEVEL] *//* is GOOD */

    /* here we have not hit the GREAT line OR the GOOD LINE 
    *  we are either  in Great color or GOOD color
    */
    if (   we_have_hit_great_line == 0
        && we_have_hit_good_line  == 0
        && strstr(linebuf, "GOOD") == NULL    /* not on GOOD line */
        && strstr(linebuf, "GREAT") == NULL ) /* not on GREAT line */
    {
      /* here we are in GREAT territory- color cGr2
      */
/*       strsubg(linebuf, "X ", "<span class=\"cGr2\">X</span> ");
*       strsubg(linebuf, " X", " <span class=\"cGr2\">X</span>"); 
*       strsubg(linebuf, "*" , "<span class=\"cGr2\">*</span>");
* 
*       strsubg(linebuf, 
*         "<span class=\"cGr2\">*</span><span class=\"cGr2\">*</span>",
*         "<span class=\"cGr2\">**</span>"
*       );
*       strsubg(linebuf, 
*         "<span class=\"cGr2\">**</span><span class=\"cGr2\">**</span>",
*         "<span class=\"cGr2\">****</span>"
*       );
*/
/*       bracket_string_of("X*", linebuf, "<span class=\"cGr2\">", "</span> "); */

      /* great or good
      */
      if (first_star_is_in_great   == 1) { bracket_string_of("X", linebuf, "<span class=\"cGr2\">", "</span>"); }
      if (first_star_is_in_good    == 1) { bracket_string_of("X", linebuf, "<span class=\"cGre\">", "</span>"); }
      if (first_star_is_in_neutral == 1) { bracket_string_of("X", linebuf, "<span class=\"cNeu\">", "</span>"); }
      if (first_star_is_in_stress  == 1) { bracket_string_of("X", linebuf, "<span class=\"cRed\">", "</span>"); }
      if (first_star_is_in_omg     == 1) { bracket_string_of("X", linebuf, "<span class=\"cRe2\">", "</span>"); }

      scharswitch(linebuf, 'X', ' ');
      bracket_string_of("#", linebuf, "<span class=\"cSky\">", "</span>");
      scharswitch(linebuf, '#', ' ');
      scharswitch(linebuf, '|', ' ');  /* sideline out */

      /* turn star (*) into caret (^) with star color */
      bracket_string_of("*", linebuf, "<span class=\"star\">", "</span>");
//      scharswitch(linebuf, '*', '^');
      scharswitch(linebuf, '*', ' ');
//      scharswitch(linebuf, '*', 'O');
//      scharswitch(linebuf, '*', '|');
//      scharswitch(linebuf, '*', 'n');
//      strsubg(linebuf, " ", "i");

      n = sprintf(p,"%s\n", linebuf);
      f_docin_put(p,n);
      running_stress_level_on_line += SIZE_EPH_GRH_INCREMENT;
      continue;
    }

    /* here we have hit the GREAT line, but not the GOOD line
    *  we are in GOOD color
    **/
    if (   we_have_hit_good_line == 0 
        && strstr(linebuf, "GOOD") == NULL    /* not on GOOD line */
        && strstr(linebuf, "GREAT") == NULL ) /* not on GREAT line */
    {
      /* here we are in GOOD territory- color cGre
      */
/*       strsubg(linebuf, "X ", "<span class=\"cGre\">X</span> ");
*       strsubg(linebuf, " X", " <span class=\"cGre\">X</span>"); 
*       strsubg(linebuf, "*" , "<span class=\"cGre\">*</span>");
* 
*       strsubg(linebuf, 
*         "<span class=\"cGre\">*</span><span class=\"cGre\">*</span>",
*         "<span class=\"cGre\">**</span>"
*       );
*       strsubg(linebuf, 
*         "<span class=\"cGre\">**</span><span class=\"cGre\">**</span>",
*         "<span class=\"cGre\">****</span>"
*       );
*/
      bracket_string_of("X", linebuf, "<span class=\"cGre\">", "</span>");
      scharswitch(linebuf, 'X', ' ');
      bracket_string_of("#", linebuf, "<span class=\"cSky\">", "</span>");
      scharswitch(linebuf, '#', ' ');
      scharswitch(linebuf, '|', ' ');  /* sideline out */

      /* turn star (*) into caret (^) with star color */
      bracket_string_of("*", linebuf, "<span class=\"star\">", "</span>");
//      scharswitch(linebuf, '*', '^');
      scharswitch(linebuf, '*', ' ');
//      scharswitch(linebuf, '*', 'O');
//      scharswitch(linebuf, '*', 'n');
//      strsubg(linebuf, " ", "l");

      n = sprintf(p,"%s\n", linebuf);
      f_docin_put(p,n);
      running_stress_level_on_line += SIZE_EPH_GRH_INCREMENT;
      continue;
    }


    /*  we are in Neutral color  (no stress line yet) */
    if (   we_have_hit_stress_line == 0
        && strstr(linebuf, "GOOD") == NULL    /* not on GOOD line */
        && strstr(linebuf, "GREAT") == NULL) {/* not on GREAT line */
      bracket_string_of("X", linebuf, "<span class=\"cNeu\">", "</span>");
      scharswitch(linebuf, 'X', ' ');
      bracket_string_of("#", linebuf, "<span class=\"cSky\">", "</span>");
      scharswitch(linebuf, '#', ' ');
      scharswitch(linebuf, '|', ' ');  /* sideline out */
    }


    if (   we_have_hit_stress_line == 1
        && we_have_hit_omg_line != 1
        && strstr(linebuf, "STRESS") == NULL  /* not on STRESS line */
        && strstr(linebuf, "OMG")    == NULL) /* not on    OMG line */
    {
      /* here we are in STRESS territory- color Red
      */
/*       strsubg(linebuf, "X ", "<span class=\"cRed\">X</span> ");
*       strsubg(linebuf, " X", " <span class=\"cRed\">X</span>"); 
*       strsubg(linebuf, "*" , "<span class=\"cRed\">*</span>");
*/

      bracket_string_of("X", linebuf, "<span class=\"cRed\">", "</span>");
      scharswitch(linebuf, 'X', ' ');
      bracket_string_of("#", linebuf, "<span class=\"cSky\">", "</span>");
      scharswitch(linebuf, '#', ' ');
      scharswitch(linebuf, '|', ' ');  /* sideline out */

      /* turn star (*) into caret (^) with star color */
      bracket_string_of("*", linebuf, "<span class=\"star\">", "</span>");
//      scharswitch(linebuf, '*', '^');
      scharswitch(linebuf, '*', ' ');
//      scharswitch(linebuf, '*', 'O');
//      scharswitch(linebuf, '*', 'n');
//      strsubg(linebuf, " ", "X");

      n = sprintf(p,"%s\n", linebuf);
      f_docin_put(p,n);
      running_stress_level_on_line += SIZE_EPH_GRH_INCREMENT;
      continue;
    }


    if (   we_have_hit_omg_line == 1
        && strstr(linebuf, "OMG")    == NULL) /* not on    OMG line */
    {
      /* here we are in OMG territory- color Re2
      */
/*       strsubg(linebuf, "X ", "<span class=\"cRe2\">X</span> ");
*       strsubg(linebuf, " X", " <span class=\"cRe2\">X</span>"); 
*       strsubg(linebuf, "*" , "<span class=\"cRe2\">*</span>");
*/

//trn("here we are in OMG territory- color Re2");
//ksn(linebuf);
      bracket_string_of("X", linebuf, "<span class=\"cRe2\">", "</span>");
//ksn(linebuf);
      scharswitch(linebuf, 'X', ' ');
//ksn(linebuf);
      bracket_string_of("#", linebuf, "<span class=\"cSky\">", "</span>");
//ksn(linebuf);
      scharswitch(linebuf, '#', ' ');
//ksn(linebuf);
      scharswitch(linebuf, '|', ' ');  /* sideline out */
//ksn(linebuf);

      /* turn star (*) into caret (^) with star color */
      bracket_string_of("*", linebuf, "<span class=\"star\">", "</span>");
//ksn(linebuf);
//      scharswitch(linebuf, '*', '^');
      scharswitch(linebuf, '*', ' ');
//      scharswitch(linebuf, '*', 'O');
//      scharswitch(linebuf, '*', 'n');
//      strsubg(linebuf, " ", "Y");

//ksn(linebuf);

      n = sprintf(p,"%s\n", linebuf);
      f_docin_put(p,n);
      running_stress_level_on_line += SIZE_EPH_GRH_INCREMENT;
      continue;
    }


    /* NOTE it looks like GREAT falls thru to here  (maybe the others) */

    /* turn star (*) into caret (^) with star color */
    bracket_string_of("*", linebuf, "<span class=\"star\">", "</span>");
//    scharswitch(linebuf, '*', '^');
      scharswitch(linebuf, '*', ' ');
//      scharswitch(linebuf, '*', 'O');
//      scharswitch(linebuf, '*', 'n');
//      strsubg(linebuf, " ", "Z");



    n = sprintf(p,"%s\n", linebuf);
    f_docin_put(p,n);
    running_stress_level_on_line += SIZE_EPH_GRH_INCREMENT;

  }  /* for each line in grh body */
//tn();trn("hey lines  END");

  /* put extra line at bottom for esthetics
  *  (saving last line preserves its color)
  */
  /* get color of last line and print an empty grh line with it */
/* tn();b(420);ksn(gbl_save_last_line); */
  if (strstr(gbl_save_last_line, "STRESS") == NULL) {  /* only if not on stress line */
    if (strstr(gbl_save_last_line, "cRed") != NULL) {
      sfill(myLastLine, Num_eph_grh_pts, ' '); 
      bracket_string_of(" ", myLastLine, "<span class=\"cRed\">", "</span>");
      n = sprintf(p,"       %s\n", myLastLine );  /* left margin = 7 spaces */
      f_docin_put(p,n);
    }
    if (strstr(gbl_save_last_line, "cRe2") != NULL) {
      sfill(myLastLine, Num_eph_grh_pts, ' '); 
      bracket_string_of(" ", myLastLine, "<span class=\"cRe2\">", "</span>");
      n = sprintf(p,"       %s\n", myLastLine );  /* left margin = 7 spaces */
      f_docin_put(p,n);
    }
  }


  scharswitch(gbl_save_last_line, 'X', ' ');
  scharswitch(gbl_save_last_line, '#', ' ');

//  scharswitch(gbl_save_last_line, '*', ' ');
  scharswitch(gbl_save_last_line, '*', 'O');

  scharswitch(gbl_save_last_line, '|', ' ');  /* sideline out */
/* b(300); */
  n = sprintf(p,"%s\n", gbl_save_last_line);
  f_docin_put(p,n);
/* trn(" end of reverse_BIGgrh_body_and_prt()"); */

}  /* end of reverse_BIGgrh_body_and_prt() */
// ===================================================================================================================
// ===================================================================================================================










/* with \n at end */
void prt_BIGgrh_line(char *p_line, int cols_with_pt[],int pt_ctr, int *p_ln_ctr, int top) 
{
  int ilin;
  ;
//
//tr("in prt_BIGgrh_line");
//ksn(p_line);


  ++Num_lines_in_grh_body;

  /* do not walk the plank */
  if (Num_lines_in_grh_body >= MAX_GRH_BODY_LINES)
  {
//tn();trn("HIT MAX_GRH_BODY_LINES = 333 ! d  holy cow");tn();
    return;
  }
 
  /* pts in graph
  */
  for (ilin=1; ilin <= pt_ctr; ilin++) {
    *(p_line+cols_with_pt[ilin]) = EPH_GRH_CHAR;
  } 

  /* PUT LINE IN TBL
   */
  //             (SIZE_GRH_LEFT_MARGIN+SIZE_EPH_GRH_LINE+1),
  sprintf(  // PUT LINE IN TBL
    Grh_body_BIG + (Num_lines_in_grh_body-1) * 
               (SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE + 1),
    "%s%s",
    get_grh_left_margin(p_ln_ctr,top,p_line),
    p_line
  );

  strcpy(gbl_save_last_line, p_line);

  for (ilin=1; ilin <= pt_ctr; ilin++)
    *(p_line+cols_with_pt[ilin]) = GRH_CONNECT_CHAR;  /*ch pt to connect*/

  if (Just_did_good_line == 1) {
    Just_did_good_line = 0;
    undo_good_line(p_line);

    for (ilin=1; ilin <= pt_ctr; ilin++)
      *(p_line+cols_with_pt[ilin]) = GRH_CONNECT_CHAR;  /*ch pt to connect*/
  }
}  /* end of prt_BIGgrh_line() */


/* for 1 *12-MONTH* future
*/
void get_BIGeph_data(int m,int d,int y)  /* args unused ? */
{
/* trn("in get_BIGeph_data(int "); */
  /* Only free eph_space stuff if calloc_eph_space has run already
  *  during this call to mamb_report_year_in_the_life()
  */
  if (is_first_calloc_eph_space == 1) {
    is_first_calloc_eph_space = 0;
  } else {
    free_eph_space();
  }
  // NUM_PTS_WHOLE_YEAR 182
  // Num_eph_grh_pts = (Is_past)? NUM_PTS_FOR_PAST: NUM_PTS_FOR_FUT;
  Num_eph_grh_pts = (Is_past)? NUM_PTS_FOR_PAST: NUM_PTS_WHOLE_YEAR; // <-----
  calloc_eph_space();

  Eph_rec_every_x_days = STEP_SIZE_FOR_FUT;

  fill_eph_buf();

}  /* end of get_BIGeph_data() */


// ===  end of  =================  BIG report renamed functions  ===============================
// ===  end of  =================  BIG report renamed functions  ===============================
// ===  end of  =================  BIG report renamed functions  ===============================





// stuff from futasp.c ==========================================================
// stuff from futasp.c ==========================================================

/*****************  more on do_running_table()   -  do_rt()
*
*   aspect?  y->  startthere?  y->  lastday?  y->  dspl_aspect()  -  end
*     |      |          |
*     |      |          end
*     |    lastday?  y-> end 
*     |      |            (ignore aspects beginning 
*     |    putstart()     on last day)
*     |      |
*     |      end
*     |
*   startthere?  y->  dspl_aspect()  -  end
*     |
*     end
*
*/
void do_rt(int nat_plt, int aspect_num, int trn_plt, int day_num)
{
//trn("do_rt() in futdoc.c");  // version in futasp.c is never called
/* 24,000 trn("do_rt(int nat_plt, int aspect_num, int trn_plt, int day_num)"); */

//
//// for test
//char rttst[32];
////  char *N_planet[]     = {"   ","sun","moo","mer","ven","mar","jup","sat","ura","nep","plu", "nod","asc","mc_"};
////  char *N_trn_planet[] = {"   ","jup","sat","ura","nep","plu","mar"};
////  char *N_aspect[]     = {"   ","cnj","sxt","squ","tri","opp","tri","squ","sxt","cnj"};
//if (nat_plt == 3 && trn_plt == 1) {
//sprintf(rttst, "%s_%s_%s dn=%d asp=%d",      N_planet[nat_plt], N_aspect[aspect_num], N_trn_planet[trn_plt], day_num, aspect_num);
//tr("do_rt");ksn(rttst);
//}
//// for test
//
//


  if (nat_plt <  IDX_FOR_NAT_SUN  || nat_plt >  IDX_FOR_NAT_MAR)
    return;


    // fyi
    //  char *N_planet[]     = {"   ","sun","moo","mer","ven","mar","jup","sat","ura","nep","plu", "nod","asc","mc_"};
    //  char *N_trn_planet[] = {"   ","jup","sat","ura","nep","plu","mar"};
    //  char *N_aspect[]     = {"   ","cnj","sxt","squ","tri","opp","tri","squ","sxt","cnj"};

    // #define IDX_FOR_TRN_JUP 1  /* trn goes ju,sa,ur,ne,pl,ma 1-6 */
    // #define IDX_FOR_TRN_PLU 5
    // #define IDX_FOR_TRN_MAR 6  // new for mars include


  // 
  // possible do transiting mars here
  // 

//  if (trn_plt <  IDX_FOR_TRN_JUP  || trn_plt >  IDX_FOR_TRN_MAR)     /* trn goes ju,sa,ur,ne,pl,ma 1-6 */
//    return;    /* don't record unless nat 1-5, trn 1-6 */ 
// if mars used (NO) use above   ELSE  use below
  if (trn_plt <  IDX_FOR_TRN_JUP  || trn_plt >  IDX_FOR_TRN_PLU)
  return;    /* don't record unless nat 1-5, trn 1-5 */ 


  if (aspect_num != 0)    /* aspect? */
  {
    if(Rt[nat_plt].from_date.mn != 0)      /* start of aspect there? */ 
    {
      if (day_num == Num_eph_grh_pts)    /* last day? */
        dspl_aspect(nat_plt,trn_plt,day_num+1);
      
    } else {

      if (day_num == Num_eph_grh_pts) return;/* last day? */
      put_start_of_aspect(day_num,nat_plt,aspect_num,trn_plt);
    }
    return;

  } else {

    if(Rt[nat_plt].from_date.mn != 0)  /* start of aspect there? */ 
      dspl_aspect(nat_plt,trn_plt,day_num);
    return;
  }
}  /* end of do_rt */


// STRANGE HISTORICAl NAME = dspl_aspect()              this is in futdoc.c
// 
//   Here, this aspect in this current calendar year is "finished"
//
//   Therefore, store the aspect info into global ARR  P_asp_tbl[Asp_tbl_idx]
//
//            P_asp_tbl looks like this:
//          i=000, [20200101010105202001050309]x
//          i=001, [20200321040105202007110410]x
//          i=002, [20201112040105202012060410]x
//          i=003, [20201226050105202101010401]x   end date is changed to 1231
//          i=004, [20200113040205202002240410]x
//          i=005, [20200416050205202006050410]x
//          i=006, [20200804040205202011200410]x
//          i=007, [20201230050205202101010412]  too short to GO ON THE SCREEN
//          i=008, [20200101020302202002080301]x
//          i=009, [20200101050303202004160401]x
//          i=010, [20200202010302202005240301]x
//          i=011, [20201114010302202101010312]x   end date is changed to 1231
//          i=012, [20200115040505202008240410]x
//          i=013, [20201112040505202101010412]x   end date is changed to 1231
//
// could be called         = store_this_aspect_info()   this is in futdoc.c
//
// FYI in futhtm.c  -  aspects whose text GO ON THE SCREEN
//
//   doing make_fut_htm_file() in futdoc.c 4422)__
//   _(in make_fut_htm_file())__
//   _(futhtm.c BEG -->  now read and print aspects until we hit [end_aspects])
//   _doclin=[from Jan  1 to Jan  5 ^(subju)]__
//   _doclin=[from Jan  1 to Feb  8 ^(mogur)]__
//   _doclin=[from Jan  1 to Apr 16 ^(mabur)]__
//   _doclin=[from Jan 13 to Feb 24  and also from Aug  4 to Nov 20 ^(vebsa)]__
//   _doclin=[from Jan 15 to Aug 24  and also from Nov 12 to Dec 31 ^(vebpl)]__
//   _doclin=[from Feb  2 to May 24  and also from Nov 14 to Dec 31 ^(sugur)]__
//   _doclin=[from Mar 21 to Jul 11  and also from Nov 12 to Dec  6 ^(vebju)]__
//   _doclin=[from Apr 16 to Jun  5 ^(mabsa)]__
//   _doclin=[from Dec 26 to Dec 31 ^(mabju)]__
//   _doclin=[[end_aspects]]__                                                 
//   _(futhtm.c END -->  now read and print aspects until we hit [end_aspects])
//

//_(pass 01)___sinewave_60char=[sun_opp_jup,20200101,20200105,positive,00000,00655,00112]__
//_(pass 01)___sinewave_60char=[ven_opp_jup,20200321,20200711,positive,00000,00655,00112]__
//_(pass 01)___sinewave_60char=[ven_opp_jup,20201112,20201206,positive,00000,00655,00112]__
//_(pass 01)___sinewave_60char=[mar_opp_jup,20201226,20210101,positive,00000,00655,00112]__
//_(pass 01)___sinewave_60char=[ven_opp_sat,20200113,20200224,positive,00000,00655,00112]__
//_(pass 01)___sinewave_60char=[mar_opp_sat,20200416,20200605,positive,00000,00655,00112]__
//_(pass 01)___sinewave_60char=[ven_opp_sat,20200804,20201120,positive,00000,00655,00112]__
//_(pass 01)___sinewave_60char=[mar_opp_sat,20201230,20210101,positive,00000,00655,00112]__
//_(pass 01)___sinewave_60char=[moo_sxt_ura,20200101,20200208,positive,00000,00655,00112]__
//_(pass 01)___sinewave_60char=[mar_squ_ura,20200101,20200416,positive,00000,00655,00112]__
//_(pass 01)___sinewave_60char=[sun_sxt_ura,20200202,20200524,positive,00000,00655,00112]__
//_(pass 01)___sinewave_60char=[sun_sxt_ura,20201114,20210101,positive,00000,00655,00112]__
//_(pass 01)___sinewave_60char=[ven_opp_plu,20200115,20200824,positive,00000,00655,00112]__
//_(pass 01)___sinewave_60char=[ven_opp_plu,20201112,20210101,positive,00000,00655,00112]__
//


// dspl_aspect  adds aspect to P_asp_tbl[]  array
//
// descriptive NAME = add_the_influence_of_this_aspect
//
/* writes asp to array strings */ 
/* format 26 char: from_date 1-8 yyyymmdd, nat 9-10, trn 11,12, asp 13,14 */
/*     to_date 15-22 yyyymmdd, nat_hse 23-24, trn_hse 25,26 */
void dspl_aspect(int np, int tp, int dn)
{
  int asp,np_hse,tp_hse,fy,fm,fd,ty,tm,td;
  ;
  asp = Rt[np].aspect_id;
  np_hse = get_house(Ar_minutes_natal[np],get_minutes(Arco[13]));/*13=mc*/
  if (dn == Num_eph_grh_pts) --dn;  /* last day? */
  tp_hse = get_house((Eph_buf+dn)->positions[tp],get_minutes(Arco[13]));
  if (dn == Num_eph_grh_pts) ++dn;  /* last day? */
  fy = Rt[np].from_date.yr;
  fm = Rt[np].from_date.mn;
  fd = Rt[np].from_date.dy;

  put_start_of_aspect(dn-1,np,0,tp);  /* sets up to_date */

  ty = Rt[np].from_date.yr;
  tm = Rt[np].from_date.mn;
  td = Rt[np].from_date.dy;
  zero_runrec(np);
//  ++Asp_tbl_idx;  /* init=-1 */  // points to LAST P_ / asp_tbl element
  Asp_tbl_idx = Asp_tbl_idx + 1;  /* init=-1 */  // points to LAST P_ / asp_tbl element



  // due to some previous processing, bad dates beyond rpt calendar year
  // can get into P_asp_tbl[]  array   (OK otherwise, but messes up SW processing)
  // e.g.  below curr rpt yr= 2022,  date 20230102 got in there
        //
        //  _(all of P_asp_tbl)__
        //   _i=[0]___P_asp_tbl[i]=[20220101010106202201150311]__
        //   _i=[1]___P_asp_tbl[i]=[20220101030206202201090211]__
        //   _i=[2]___P_asp_tbl[i]=[20220101040406202201210412]__
        //   _i=[3]___P_asp_tbl[i]=[20220127020207202203100211]__
        //   _i=[4]___P_asp_tbl[i]=[20220129050107202202180212]__
        //   _i=[5]___P_asp_tbl[i]=[20220204030107202202240212]__
        //   _i=[6]___P_asp_tbl[i]=[20220306020108202203240212]__
        //   _i=[7]___P_asp_tbl[i]=[20220312040106202203300412]__
        //   _i=[8]___P_asp_tbl[i]=[20220503010107202205290312]__
        //   _i=[9]___P_asp_tbl[i]=[20220507020301*20230102*0212]__  <----------==
        //  _i=[10]___P_asp_tbl[i]=[20220602040302202211230402]__
        //  _i=[11]___P_asp_tbl[i]=[20220624050102202209020212]__
        //  _i=[12]___P_asp_tbl[i]=[20220708030102202208170212]__
        //  _i=[13]___P_asp_tbl[i]=[20220912020207202212010211]__
        //  _i=[14]___P_asp_tbl[i]=[20220928010103*20230102*0312]__  <----------==
        //  _(all of P_asp_tbl)__                                
        //
  // THEREFORE,
  // do not allow bad dates beyond rpt calendar year -  gbls_currentFUTyear
  //
//tr("dspl_aspect() = end of asp date info"); ki(fy);ki(fm);ki(fd);ki(ty);ki(tm);kin(td);

  if (ty  >  gbl_year_todo_yyyy_INT)
  {
tr("dspl_aspect() = changed TO date with year too big"); ki(ty); ki(tm); kin(td);
    ty = ty - 1;
    tm = 12; 
    td = 31;
  }
  //
  // do not allow bad dates beyond rpt calendar year -  gbls_currentFUTyear


//tr("in dspl_aspect() END ASPECT");
  // new rule:  20200429  no asp < 14 days long
  //
  int    aspect_TOO_SHORT;
         //  FYI  double day_of_year(double year, double month, double day)  /* return jd in year from year, month & day */
  double DOY_dbl_from;
  double DOY_dbl_to;
  double dbl_fy;
  double dbl_fm;
  double dbl_fd;
  double dbl_ty;
  double dbl_tm;
  double dbl_td;
  double numDaysinSW;

  dbl_fy = (double) fy;
  dbl_fm = (double) fm;
  dbl_fd = (double) fd;
  dbl_ty = (double) ty;
  dbl_tm = (double) tm;
  dbl_td = (double) td;

  DOY_dbl_from = day_of_year(dbl_fy, dbl_fm, dbl_fd);  /* julian day in year */
  DOY_dbl_to   = day_of_year(dbl_ty, dbl_tm, dbl_td);  /* julian day in year */

  numDaysinSW = DOY_dbl_to - DOY_dbl_from + 1;

// test angel/2020
//kdn(dbl_fy); kdn(dbl_fm); kdn(dbl_fd);
//kdn(dbl_ty); kdn(dbl_tm); kdn(dbl_td);
//kdn(numDaysinSW);

//  if (DOY_dbl_to - DOY_dbl_from  >= 14) aspect_TOO_SHORT = 0;
//  if (DOY_dbl_to - DOY_dbl_from  <  14) aspect_TOO_SHORT = 1;

    if (numDaysinSW < 14)  aspect_TOO_SHORT = 1;  // less than 14 days 
    else                   aspect_TOO_SHORT = 0;  // 14 days or more

  //
  // new rule:  20200429  no asp < 14 days long
//kd(dbl_fy); kd(dbl_fm); kd(dbl_fd); kd(dbl_ty); kd(dbl_tm); kd(dbl_td); kin(aspect_TOO_SHORT);

//kdn(dbl_fy); kdn(dbl_fm); kdn(dbl_fd); kdn(dbl_ty); kdn(dbl_tm); kdn(dbl_td);
//kin(aspect_TOO_SHORT);

// try <.>  done in JS now may24,2020    ONLY SW drawing in js
//  if (aspect_TOO_SHORT == 0 )
//  {
      // not too short
      // ======  add item to P_asp_tbl[]  ==================
      // ======  add item to P_asp_tbl[]  ==================
      sprintf(P_asp_tbl[Asp_tbl_idx],
        "%04d%02d%02d%02d%02d%02d%04d%02d%02d%02d%02d",
        fy,fm,fd,np,tp,asp,ty,tm,td,np_hse,tp_hse);
      // ======  add item to P_asp_tbl[]  ==================
      // ======  add item to P_asp_tbl[]  ==================
//  }

//
//// for test   pass 02
//// rkt
//  char *N_planet[]     = {"   ","sun","moo","mer","ven","mar","jup","sat","ura","nep","plu", "nod","asc","mc_"};
//  char *N_trn_planet[] = {"   ","jup","sat","ura","nep","plu","mar"};
//  char *N_aspect[]     = {"   ","cnj","sxt","squ","tri","opp","tri","squ","sxt","cnj"};
//tr("pass 02 completed-->"); ks(N_planet[np]); ks(N_aspect[asp]);ks(N_trn_planet[tp]); kin(dn);
////ksn(gbl_PSV_of_SW_CSVs);
//char csV[1024]; strcpy(csV,"junk");
//for (int ifl = 1; strlen(csV) != 0; ifl++) { // for each SW_CSV in gbl_PSV_of_SW_CSVs
//  strcpy(csV, csv_get_field(gbl_PSV_of_SW_CSVs, "|", ifl));  // one-based fldnum
//  ksn(csV); 
//}
//// for test   pass 02
//
//


  // Here, this aspect in this current calendar year is "finished"
  // so,
  if (strcmp(gbl_instructions, "do Sine Wave data collection") == 0)
  {
    complete_this_SW_CSV(np, asp, tp);  // mark the SW_CSV as "done"
//    complete_this_SW_CSV(np, asp, tp, aspect_TOO_SHORT);  // mark the SW_CSV as "done" or delete it IF too short
  }


}  /* end of dspl_aspect() */



void complete_this_SW_CSV(int np, int asp, int tp)
{
//trn("\nin  complete_this_SW_CSV()");
  char SW_CSV_ASP_string[32];   // like "sun_opp_jup"
  char SW_CSV_current[1024];
  char SW_CSV_updated[1024];
  char SW_CSV_forLoop[1024];
  char SW_CSV_toPutIn[1024];

  char NEW_PSV_of_SW_CSVs[8192] = ""; 

  int  SW_CSV_FOUND;
  char SW_CSV_open_or_done[32];

  SW_CSV_FOUND = 0;
  strcpy(SW_CSV_current, "token for first SW_CSV");  // so strlen()  is not zero
  strcpy(SW_CSV_forLoop, "token for first SW_CSV");  // so strlen()  is not zero


  char *N_planet[]     = {"   ","sun","moo","mer","ven","mar","jup","sat","ura","nep","plu", "nod","asc","mc_"};
  char *N_trn_planet[] = {"   ","jup","sat","ura","nep","plu","mar"};
  char *N_aspect[]     = {"   ","cnj","sxt","squ","tri","opp","tri","squ","sxt","cnj"};

  // the UNIQUE KEY into gbl_PSV_of_SW_CSVs is first 2 flds like "sun_opp_jup,045"   45 is dayOfYear (1-366) (not day_num 1->183)
  sprintf(SW_CSV_ASP_string, "%s_%s_%s",      N_planet[np], N_aspect[asp], N_trn_planet[tp] );
//ksn(SW_CSV_ASP_string);
//ksn(gbl_PSV_of_SW_CSVs);
  for (int ifld = 1; strlen(SW_CSV_current) != 0; ifld++)   // FOR EACH   SW_CSV in gbl_PSV_of_SW_CSVs
  {
    strcpy(SW_CSV_current, csv_get_field(gbl_PSV_of_SW_CSVs, "|", ifld));  // one-based fldnum
//ki(ifld);ksn(SW_CSV_current);

    if (strncmp(SW_CSV_current, SW_CSV_ASP_string, strlen(SW_CSV_ASP_string)) == 0)  // if SW_CSV_current starts with SW_CSV_ASP_string
    {
      // here we FOUND this aspect in gbl_PSV_of_SW_CSVs  string
//trn(" here we FOUND this aspect in gbl_PSV_of_SW_CSVs  string");
      strcpy(SW_CSV_open_or_done, csv_get_field(SW_CSV_current, ",", 9));  // one-based fldnum
//ksn(SW_CSV_open_or_done);
      if (strcmp(SW_CSV_open_or_done, "done") == 0 ) continue;

      // here, status (f9) is not "done",  so update SW_CSV to "done"  
      //       leave other fields the same
      //  TERRIBLE TRICK 
      //  we are only changing 4 chars from "open" to "done"
      strcpy(SW_CSV_updated, SW_CSV_current);

      // FYI -> mambutil.c  void strsubg(char *s, char *replace_me, char *with_me) // on str s (max 2048) does  :s/replace_me/with_me/g
      //                       * strsubg    on str s (max 2048) does  :s/replace_me/with_me/g
      //
      strsubg(SW_CSV_updated, "open", "done");   // on str s (max 2048) does  :s/replace_me/with_me/g
//ksn(SW_CSV_current);
//ksn(SW_CSV_updated);


//tr("compl a");ksn(gbl_PSV_of_SW_CSVs);
        //
        // in gbl_PSV_of_SW_CSVs, replace SW_CSV_current with SW_CSV_updated
        //
        for (int jfld = 1; strlen(SW_CSV_forLoop) != 0; jfld++) {
          strcpy(SW_CSV_forLoop, csv_get_field(gbl_PSV_of_SW_CSVs, "|", jfld));  // one-based fldnum

//          if ( strcmp(SW_CSV_forLoop, SW_CSV_current) == 0 )  strcpy(SW_CSV_toPutIn, SW_CSV_updated);
          if ( strcmp(SW_CSV_forLoop, SW_CSV_current) == 0 )
          {
            strcpy(SW_CSV_toPutIn, SW_CSV_updated);
//tr("update_at_complete_time -"); ksn(SW_CSV_toPutIn);

          } else {
            strcpy(SW_CSV_toPutIn, SW_CSV_forLoop);
          }

          if (strlen(NEW_PSV_of_SW_CSVs) == 0 )  sprintf(NEW_PSV_of_SW_CSVs, "%s|",                       SW_CSV_toPutIn); 
          else                                   sprintf(NEW_PSV_of_SW_CSVs, "%s%s|", NEW_PSV_of_SW_CSVs, SW_CSV_toPutIn);
        }
      strcpy( gbl_PSV_of_SW_CSVs, NEW_PSV_of_SW_CSVs );


//ksn(gbl_PSV_of_SW_CSVs);

//
//// for test show all sw in gbl_PSV_of_SW_CSVs
//trn("for test show all sw in gbl_PSV_of_SW_CSVs");
//char atst[513];
//strcpy(atst,"something len > 0");
//for (int itst = 1; strlen(atst) != 0; itst++)   // FOR EACH   SW_CSV in gbl_PSV_of_SW_CSVs
//{
//  strcpy(atst, csv_get_field(gbl_PSV_of_SW_CSVs, "|", itst));  // one-based fldnum
//ki(itst);ksn(atst);
//}
//// for test show all sw in gbl_PSV_of_SW_CSVs
//
//



    }
//trn("");
  } // FOR EACH   SW_CSV in gbl_PSV_of_SW_CSVs


// for test
//int  how_many_csvs = scharcnt(gbl_PSV_of_SW_CSVs, '|'); 
//tr("num SW_CSVs in gbl_PSV_of_SW_CSVs"); kin(how_many_csvs);

} // end of  complete_this_SW_CSV()





//// by updating these 2 fields when the SW_csv ENDS
////      int_SW_END_DayOfYear      
////      int_SW_day_num_updated           // this field is SET FOR EVERY day_num so that we can reckon when a new SW_CSV should start
////
//void complete_this_SW_CSV (    // by updating 2 flds
//  int dn,
//  int fy, int fm,  int fd,  
//  int np, int asp, int tp,  
//  int ty, int tm,  int td
//) 
//{
//trn("\nin complete_this_SW_CSV()  SW");
//// ki(nat_plt);kin(trn_plt);
//
//
//  char SW_CSV_ASP_string[32];   // like "sun_opp_jup"
//  char SW_CSV_current[128];
//  char SW_CSV_updated[128];
//  char SW_CSV_forLoop[128];
//  char SW_CSV_toPutIn[128];
//  int  SW_CSV_FOUND;
//  char NEW_PSV_of_SW_CSVs[8192] = "";   // this is updated after each aspect in this current calendar year is "finished"
//
//  SW_CSV_FOUND = 0;
//  strcpy(SW_CSV_current, "token for first SW_CSV");  // so strlen()  is not zero
//  strcpy(SW_CSV_forLoop, "token for first SW_CSV");  // so strlen()  is not zero
//
//
//  char *N_planet[]     = {"   ","sun","moo","mer","ven","mar","jup","sat","ura","nep","plu", "nod","asc","mc_"};
//  char *N_trn_planet[] = {"   ","jup","sat","ura","nep","plu","mar"};
//  char *N_aspect[]     = {"   ","cnj","sxt","squ","tri","opp","tri","squ","sxt","cnj"};
//
//  int  int_SW_BEG_DayOfYear     ;
//  int  int_SW_END_DayOfYear     ;
//  char str_SW_amplitude_sign[32];     // "positive" or "negative" for sinewave amplitude
//  int  int_SW_amplitude_at_BEG  ;
//  int  int_SW_amplitude_at_MAX  ;
//  int  int_SW_amplitude_at_END  ;
//  int  int_SW_day_num_updated   ;     // the day_num this SW_CSV  was last updated
//
//
//  sprintf(SW_CSV_ASP_string, "%s_%s_%s",      N_planet[nat_plt], N_aspect[aspect_num], N_trn_planet[trn_plt]              );
//
//
//  // search gbl_PSV_of_SW_CSVs  SW_CSV aspect string -- like "sun_opp_jup"
//  // if the SW_CSV aspect string is NOT THERE,  create an NEW SW_CSV with int_SW_BEG_DayOfYear = -1
//  //
//  // NOTE: gbl_PSV_of_SW_CSVs ends in a zero-legth CSV = " csv...|csv...|csv...||"
//  //
//  for (int ifld = 1; strlen(SW_CSV_current) != 0; ifld++)   // for each SW_CSV in gbl_PSV_of_SW_CSVs
//  {
//    strcpy(SW_CSV_current, csv_get_field(gbl_PSV_of_SW_CSVs, "|", ifld));  // one-based fldnum
////ksn(SW_CSV_current);
//
//    if (strncmp(SW_CSV_current, SW_CSV_ASP_string, strlen(SW_CSV_ASP_string)) == 0)  // if SW_CSV_current starts with SW_CSV_ASP_string
//    {
//      SW_CSV_FOUND = 1;
//      
//      // int_SW_day_num_updated  
//      int SW_CSV_FOUND_day_num;
//      SW_CSV_FOUND_day_num = atoi(csv_get_field(SW_CSV_current, ",", 8));  // one-based fldnum.  8th fld is day_num
//
//tr("aspect STRING FOUND!");ks(SW_CSV_current);ks(SW_CSV_ASP_string);ki(SW_CSV_FOUND_day_num);kin(day_num);
////kin(arg_addval);
//
//tr("UPDATE this SW_CSV  in gbl_PSV_of_SW_CSVs"); 
//        // create an updated version of  SW_CSV_current  in  SW_CSV_updated
//        //
//        // these 3 flds will be updated
//        //    update int_SW_amplitude_at_MAX    f6   possibly update
//        //    update int_SW_amplitude_at_END    f7   always   update so when the end comes, it is there
//        //    update int_SW_day_num_updated     f8   always   update
//        //
//        int old_max_ampl;
//        old_max_ampl = atoi( csv_get_field(SW_CSV_current, ",", 6) );
//
//        char f1[64]; char f4[64];  
//        int  f2,f3,f5,f6,f7,f8;
//        strcpy(f1, csv_get_field(SW_CSV_current, ",", 1));
//        f2 = atoi( csv_get_field(SW_CSV_current, ",", 2)); 
//        f3 = atoi( csv_get_field(SW_CSV_current, ",", 3)); 
//        strcpy(f4, csv_get_field(SW_CSV_current, ",", 4));
//        f5 = atoi( csv_get_field(SW_CSV_current, ",", 5)); 
//        f6 = ( abs(arg_addval) > old_max_ampl )? abs(arg_addval) : old_max_ampl ;  // adjust max if necessary
//        f7 = abs(arg_addval)                             ;                         // ampl at end
//        f8 = day_num                                 ;                         // day_num last updated
//           // int_SW_day_num_updated
//           // this field is SET FOR EVERY day_num so that we can reckon when a new SW_CSV should start
//           // This day_num field in gbl_PSV_of_SW_CSVs is normally 1 less than the current day_num 
//           // That means arg_addval belongs to the current SW_CSV.
//           // But, if this field is more than 1 less the day_num
//           //      then this day_num must be the start a new SW_CSV to put into gbl_PSV_of_SW_CSVs
//
//        sprintf(SW_CSV_updated,                   // create an UPDATED SW_CSV to replace the current one in gbl_PSV_of_SW_CSVs 
//          "%s,%03d,%03d,%s,%03d,%03d,%03d,%03d", f1,f2,f3,f4,f5,f6,f7,f8 ); // 37 chars
//ksn(SW_CSV_updated);
//ksn(gbl_PSV_of_SW_CSVs);
//
//        // in gbl_PSV_of_SW_CSVs, replace SW_CSV_current with SW_CSV_updated
//        //
//        for (int jfld = 1; strlen(SW_CSV_forLoop) != 0; jfld++) {
//          strcpy(SW_CSV_forLoop, csv_get_field(gbl_PSV_of_SW_CSVs, "|", jfld));  // one-based fldnum
//
//          if ( strcmp(SW_CSV_forLoop, SW_CSV_current) == 0 )  strcpy(SW_CSV_toPutIn, SW_CSV_updated);
//          else                                                strcpy(SW_CSV_toPutIn, SW_CSV_forLoop);
//
//          if (strlen(NEW_PSV_of_SW_CSVs) == 0 )  sprintf(NEW_PSV_of_SW_CSVs, "%s|",                       SW_CSV_toPutIn); 
//          else                                   sprintf(NEW_PSV_of_SW_CSVs, "%s%s|", NEW_PSV_of_SW_CSVs, SW_CSV_toPutIn);
//        }
//ksn(NEW_PSV_of_SW_CSVs);
//      strcpy( gbl_PSV_of_SW_CSVs, NEW_PSV_of_SW_CSVs );
//// tr("END of   UPDATE this SW_CSV"); 
//
//    } // SW_CSV_FOUND = 1  in  gbl_PSV_of_SW_CSVs
//
//  } // for each SW_CSV in gbl_PSV_of_SW_CSVs
//
//
//
////
////  // this is in complete_this_SW_CSV()   
////
////  // for test
////  char SW_unique_key[32];  // like "sun_opp_jup|045"  = aspect_desc,SW_BEG_DayOfYear  = 15chars   KEY is for  gbl_SW_data_amplitude
////  char *SW_planet[]     = {"   ","sun","moo","mer","ven","mar","jup","sat","ura","nep","plu", "nod","asc","mc_"};
////  char *SW_aspect[]     = {"   ","cnj","sxt","squ","tri","opp","tri","squ","sxt","cnj"};
////  char *SW_trn_planet[] = {"   ","jup","sat","ura","nep","plu","mar"};
////  //                                    // is 58 chars  use 60-char fixed-length string field
////  sprintf(curr_SW_CSV,              // looks like   "sun_opp_jup,20200106,20200521,positive,00000,00655,00112"
////    "%s_%s_%s,%03d,%03d",
////    N_planet[np], N_aspect[asp], N_trn_planet[tp],
////    (int) dbl_SW_BEG_DayOfYear,
////    (int) dbl_SW_END_DayOfYear
////  );                              // curr_SW_CSV about 32 chars
////tr("pass 01");ksn(curr_SW_CSV);
////  // for test
////
//
//
//} //end of complete_this_SW_CSV()
//
//








void put_start_of_aspect(int day_num, int nat_plt, int aspect_num, int trn_plt)
{
            /* assumption: nat 1-5, trn 1-5 */ 
  double dy,mn,yr,step;
  ;
  Rt[nat_plt].aspect_id = aspect_num;
  mn = (double)Grh_beg_mn;  /* calc from_date from day_num */
  dy = (double)Grh_beg_dy;
  yr = (double)Grh_beg_yr;
  if(trn_plt == 6) day_num++;  /* this is a mystery. 6=mars */
    /* ^why does this old comment say 6=mars. new: it's ok (jsunpm) */

  step = (double)((day_num-1) * Eph_rec_every_x_days);
  mk_new_date(&mn,&dy,&yr,step);

  Rt[nat_plt].from_date.mn = (int)mn;
  Rt[nat_plt].from_date.dy = (int)dy;
  Rt[nat_plt].from_date.yr = (int)yr;
}  /* end of put_start_of_aspect() */




void zero_runrec(int nat_plt)
{
  Rt[nat_plt].aspect_id = 0;
  Rt[nat_plt].from_date.mn = 0;
  Rt[nat_plt].from_date.dy = 0;
  Rt[nat_plt].from_date.yr = 0;
}  /* end of zero_runrec() */


void init_rt(void)
{
  int i;
  ;
  for (i=0; i <= MAX_IN_ASP_TBL-1; ++i) {
    P_asp_tbl[i] = &Asp_tbl[i*(SIZE_ASP_REC+1)];
  }
  Asp_tbl_idx = -1;  /* ++ before use as subscript to write str */
}  /* end of init_rt() */

/**** for db */
void prt_asp_tbl(void)
{
  int i;
  ;
  for (i=0; i <= MAX_IN_ASP_TBL-1; ++i) {
    fprintf(stdout,"i=%03d, [%s]\n",  i, P_asp_tbl[i]);
    if (strlen(P_asp_tbl[i]) == 0) break;
  }
}  /* end of prt_asp_tbl() */



void do_paras(void)
{
trn("in do_paras() ");
  int is_done[MAX_IN_ASP_TBL],i,k,m;
//  char s1[6+1],s2[6+1];  /* 6-char keys (nat,trn,asp) */
  char *do_me;
  char *do_also[NUM_POSSIBLE_INSTANCES_PER_ASP-1];
  int n;
  char *p = &Swk[0];

  char nat_plt_2char[16];
  char trn_plt_2char[16];
  char currASP_2char[16];
  char aspect_to_look_for[16];
  char np_tp_to_look_for[32];  /* char keys (nat,trn,asp) */
  char np_tp_4_current[32];
  int  the_aspect_codes_MATCH;
  ;
  n = sprintf(p,"\n\n[beg_aspects]\n"); 
  f_docin_put(p,n);

  strsort(P_asp_tbl,Asp_tbl_idx+1);    /* sort by fromdate */

  for (i=0; i <= MAX_IN_ASP_TBL-1; ++i) is_done[i] = 0;


//
//// for test
//trn("");
//trn("all of P_asp_tbl");
//for (int ia=0; ia <= Asp_tbl_idx; ++ia) { 
//ki(ia);ksn(P_asp_tbl[ia]);  
//}
//trn("all of P_asp_tbl");
//trn("");
//
//trn("");
//trn("all2of P_asp_tbl  at TOP of do_paras()");
//char tstfrom[32];
//char tstto[32];
//char tstnp[32];
//char tstasp[32];
//char tsttp[32];
//char tst128c[128];
//for (int ib=0; ib <= Asp_tbl_idx; ++ib) { 
////extern char *sfromto(char *dest,char *src, int beg, int end);
//sfromto(tstfrom,P_asp_tbl[ib], 1, 8);
//sfromto(tstnp  ,P_asp_tbl[ib], 9,10);
//sfromto(tsttp  ,P_asp_tbl[ib],11,12);
//sfromto(tstasp ,P_asp_tbl[ib],13,14);
//sfromto(tstto,  P_asp_tbl[ib],15,22);
//
//sprintf(tst128c, "%s_%s_%s  %s to %s  asp=%s",
//  N_planet[atoi(tstnp)], N_aspect[atoi(tstasp)], N_trn_planet[atoi(tsttp)], tstfrom, tstto, tstasp);
//ksn(tst128c);
//}
//trn("all2of P_asp_tbl  at TOP of do_paras()");
//trn("");
////  char *N_planet[]     = {"   ","sun","moo","mer","ven","mar","jup","sat","ura","nep","plu", "nod","asc","mc_"};
////  char *N_trn_planet[] = {"   ","jup","sat","ura","nep","plu","mar"};
////  char *N_aspect[]     = {"   ","cnj","sxt","squ","tri","opp","tri","squ","sxt","cnj"};
//// for test
//





        // FYI
        //   Therefore, store the aspect info into global ARR  P_asp_tbl[Asp_tbl_idx]
        //
        //            P_asp_tbl looks like this:
        //          i=000, [20200101010105202001050309]x
        //          i=001, [20200321040105202007110410]x
        //          i=002, [20201112040105202012060410]x
        //          i=003, [20201226050105202101010401]x   end date is changed to 1231

        //   FYI P_asp_tbl[]  FORMAT
        //
          //  // ======  add item to P_asp_tbl[]  ==================
          //  sprintf(P_asp_tbl[Asp_tbl_idx],
          //    "%04d%02d%02d%02d%02d%02d%04d%02d%02d%02d%02d",
          //    fy,fm,fd,np,tp,asp,ty,tm,td,np_hse,tp_hse);
          //  // ======  add item to P_asp_tbl[]  ==================
        //
        //   FYI P_asp_tbl[]  FORMAT
        //

  for (i=0; i <= Asp_tbl_idx; ++i)    // no -1(idx pts to last element) 
  {
    do_also[0] = NULL;
    do_also[1] = NULL;
    if (is_done[i]) continue;

//    do_me = P_asp_tbl[i];    // found asp to do 
//ks(do_me);
//    is_done[i] = 1;
//    sfromto(s1, P_asp_tbl[i],9,14);  // key for this asp 

    do_me = P_asp_tbl[i];    // found asp to work with 
//ks(do_me);
    is_done[i] = 1;

    sfromto(np_tp_to_look_for,  P_asp_tbl[i], 9, 12);  // grab the 4-char code for nat_plt + trn_plt 
    sfromto(aspect_to_look_for, P_asp_tbl[i],13, 14);  // grab the 2-char code for aspect



    // find all sames for this entry from P_asp_tbl[] array
    //
//tr("find all sames for "); ks(np_tp_to_look_for); ksn(aspect_to_look_for);


    // FYI
    // char *N_aspect[] = {"   ","cnj","sxt","squ","tri","opp","tri","squ","sxt","cnj"};  // ASP IDXS THE SAME are  1=9, 2=8, 3=7, 4=6 
    //
    // NOTE that some aspect indexes are for the same aspect  ==---- >  ASP IDXS THE SAME are  1=9, 2=8, 3=7, 4=6 
    // NOTE that some aspect indexes are for the same aspect  ==---- >  ASP IDXS THE SAME are  1=9, 2=8, 3=7, 4=6 
    //

    for (m=0, k=i+1; k <= Asp_tbl_idx; ++k)
    { 
      //  ORIG
      //      sfromto(s2,P_asp_tbl[k],9,14);
      //ks(s1);ksn(s2);
      //      if(strcmp(s1,s2) != 0) continue;  // keep looking for sames 
      
      // FYI   from futasp.c
      //    ++Asp_tbl_idx;  // init=-1 //
      //    sprintf(P_asp_tbl[Asp_tbl_idx],
      //      "%04d%02d%02d%02d%02d%02d%04d%02d%02d%02d%02d",
      //      fy,fm,fd,np,tp,asp,ty,tm,td,np_hse,tp_hse);
      //      fyyyfmfdnptpastyyyhtmtd  ,np_hse,tp_hse);
      //               1          2    ...               
      //      123456789012134567890123 ...               
      // FYI
      //
      // FYI   from futdoc.h
      //  char *N_planet[]     = {"   ","sun","moo","mer","ven","mar","jup","sat","ura","nep","plu", "nod","asc","mc_"}; 
      //  char *N_trn_planet[] = {"   ","jup","sat","ura","nep","plu","mar"};
      //  char *N_sign[] = { "sgn","ari","tau","gem","can","leo","vir","lib","scp","sag","cap","aqu","pis"};
      //  char *N_aspect[] = {"   ","cnj","sxt","squ","tri","opp","tri","squ","sxt","cnj"};  // ASP IDXS THE SAME are  1=9, 2=8, 3=7, 4=6 
      // FYI
      //


      sfromto(nat_plt_2char, P_asp_tbl[k],  9, 10);  
      sfromto(trn_plt_2char, P_asp_tbl[k], 11, 12);  
      sfromto(currASP_2char, P_asp_tbl[k], 13, 14);  
      
      sprintf(np_tp_4_current, "%s%s", nat_plt_2char, trn_plt_2char);
//ki(k); ks(np_tp_4_current); ksn(currASP_2char);

//      if(strcmp(s1,s2) != 0) continue;  // keep looking for sames 
      if (strcmp(np_tp_4_current, np_tp_to_look_for) != 0) continue;   // these 2 do not match. keep looking for sames

      // here the current P_asp_tbl  (index i) has the same nat_plt and trn_plt as current P_asp_tbl
      // now compare the  2 char aspect codes
      // keeping in mind this crazy stuff:
      //
      //  char *N_aspect[] = {"   ","cnj","sxt","squ","tri","opp","tri","squ","sxt","cnj"};  // ASP IDXS THE SAME are  1=9, 2=8, 3=7, 4=6 
      //
      // ASP IDXS THE SAME are  1=9, 2=8, 3=7, 4=6 
      //
      the_aspect_codes_MATCH = 0;
      
      if (strcmp(currASP_2char, aspect_to_look_for) == 0)  the_aspect_codes_MATCH = 1;

      if (    atoi(currASP_2char)      == 1     // cnj
          &&  atoi(aspect_to_look_for) == 9 )              the_aspect_codes_MATCH = 1;
      if (    atoi(currASP_2char)      == 9
          &&  atoi(aspect_to_look_for) == 1 )              the_aspect_codes_MATCH = 1;

      if (    atoi(currASP_2char)      == 2     // sxt
          &&  atoi(aspect_to_look_for) == 8 )              the_aspect_codes_MATCH = 1;
      if (    atoi(currASP_2char)      == 8
          &&  atoi(aspect_to_look_for) == 2 )              the_aspect_codes_MATCH = 1;

      if (    atoi(currASP_2char)      == 3     // squ
          &&  atoi(aspect_to_look_for) == 7 )              the_aspect_codes_MATCH = 1;
      if (    atoi(currASP_2char)      == 7
          &&  atoi(aspect_to_look_for) == 3 )              the_aspect_codes_MATCH = 1;

      if (    atoi(currASP_2char)      == 4     // tri
          &&  atoi(aspect_to_look_for) == 6 )              the_aspect_codes_MATCH = 1;
      if (    atoi(currASP_2char)      == 6
          &&  atoi(aspect_to_look_for) == 4 )              the_aspect_codes_MATCH = 1;


      if (the_aspect_codes_MATCH == 0) continue;  // these 2 do not match. keep looking for sames 


//trn("found a same");
      do_also[m] = P_asp_tbl[k];      // found a same 
      ++m;
//ki(m);ksn(do_also[m]);
      is_done[k] = 1;

    } // for each P_asp_tbl  array with INDEX k

    do_a_para(do_me,do_also[0],do_also[1]);

  } // for each P_asp_tbl  array with INDEX i

  n = sprintf(p,"[end_aspects]\n"); 
  f_docin_put(p,n);

}  /* end of do_paras() */


void do_a_para(char *first, char *other1, char *other2)
{
//trn("in do_a_para()   QQQQQQQQQQQQQQQQ "); 
  char *line[NUM_POSSIBLE_INSTANCES_PER_ASP];
  char s[4+1];
  int i,yr,mn,dy,nat,transiting,asp;
  int yr_to,mn_to,dy_to;  // check for "from" date being the same as "to" date
  int mn_from,dy_from;  // check for "from" date being the same as "to" date
  int n;
  char mywork[512];
  char mywork2[512];
  int ctr_from_to;
  ;
  line[0] = first;
  line[1] = other1; 
  line[2] = other2;
  ctr_from_to = 0;
//trn("do_a_para()");  
//ksn(line[0]);
//ksn(line[1]);
//ksn(line[2]);
  //    _(in do_a_para()   QQQQQQQQQQQQQQQQ )__
  //    _line[0]=[20180101050304201804290501]__
  //    _line[1]=[20181203050304201901020512]__
  //

  strcpy(mywork,  "");
  strcpy(mywork2, "");




  for (i=0; i <= NUM_POSSIBLE_INSTANCES_PER_ASP-1; ++i)
  {
    if (line[i] == NULL) break;
    yr = atoi(sfromto(s,line[i],1,4));
    mn = atoi(sfromto(s,line[i],5,6));
    dy = atoi(sfromto(s,line[i],7,8));
    mn_from = atoi(sfromto(s,line[i],5,6));
    dy_from = atoi(sfromto(s,line[i],7,8));

    // check for "from" date being the same as "to" date
    yr_to = atoi(sfromto(s,line[i],15,18));
    mn_to = atoi(sfromto(s,line[i],19,20));
    dy_to = atoi(sfromto(s,line[i],21,22));

//ki(yr);ki(mn_from);ki(dy_from);ki(yr_to);ki(mn_to);kin(dy_to);
//trn("check for same from/to");  
//ki(yr);ki(mn);kin(dy);
//ki(yr_to);ki(mn_to);kin(dy_to);
    if (   mn == 12
        && dy >= 28) 
    {
        // if aspect starts dec 28 or later, do not bother reporting it
//trn("found same from/to  dec 28 or later");  
        continue; //  "from" date  IS  the same as "to" date (do not include)
    }
    if (   yr == yr_to
        && mn == mn_to
        && dy == dy_to )
    {
//trn("found same from/to");  
        continue; //  "from" date  IS  the same as "to" date (do not include)
    }
    ctr_from_to = ctr_from_to + 1;




    /* Collect these 4 f_docin_puts into 1 string and f_docin_put that 
    *  at the end.
    */
//    n = sprintf(wk1,"%s%s %d, %d",
//      (ctr_from_to == 1)? "  From ":" and also from ",
//      N_long_mth[mn],dy,yr
//    );
// new
//    n = sprintf(wk1,"%s%s %2d",
//      (ctr_from_to == 1)? "  From ":" and also from ",
//      N_mth_cap[mn],dy
//    );
    char ch8[8];
    sprintf(ch8, "%2d", dy);
//ksn(ch8);
    n = sprintf(wk1,"%s%s %2s",
//      (ctr_from_to == 1)? "  From ":" and also from ",
      (ctr_from_to == 1)? "from ":"  and also from ",
      N_mth_cap[mn], ch8
    );

    /* append this to the end of mywork
    */
    sprintf(mywork2, "%s%s", mywork, wk1);   
    strcpy(mywork, mywork2);

    yr = atoi(sfromto(s,line[i],15,18));
    mn = atoi(sfromto(s,line[i],19,20));
    dy = atoi(sfromto(s,line[i],21,22));

//    n = sprintf(wk2," to %s %d, %d",
//      N_long_mth[mn],dy,yr
//    );
// new
//char *N_mth_cap[] = {
//"Mth","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};

//  e.g.   printf("%*d\n",width,x); // Leading Space

//    n = sprintf(wk2," to %s %2d",
//      N_mth_cap[mn],dy


    // 201806      problem:  from xxx xx to Jan  1
    // to date     change to from xxx xx to Dec 31
    if (mn == 1  &&  dy == 1) {
      mn = 12;
      dy = 31;
    }
    // also "to Jan  2"
    // note:  mn and dy are TO DATEs now
    if (mn == 1  &&  dy == 2 ) {
      if (mn_from == 1  &&  dy_from == 1) {
//trn(" return for jan 1 to jan 2");
        return; // ignore from jan 1 to jan 2
      }
      // here it is from xxx xx to Jan 2
      mn = 12;
      dy = 31;
    }

    sprintf(ch8, "%2d", dy);
    n = sprintf(wk2," to %s %2s",
      N_mth_cap[mn], ch8
    );

    /* append this to the end of mywork
    */
    sprintf(mywork2, "%s%s", mywork, wk2);   
    strcpy(mywork, mywork2);

  } // end of   for (i=0; i <= NUM_POSSIBLE_INSTANCES_PER_ASP-1; ++i)




  // if from /to string is empty, do not print this para
  if (strlen(mywork) == 0) {
//trn("only same from/to print nothing (return)");  
      return;
  }

//  n = sprintf(wk3,".  ");
  n = sprintf(wk3," ");

  /* append this to the end of mywork
  */
  sprintf(mywork2, "%s%s", mywork, wk3);   
  strcpy(mywork, mywork2);

  nat = atoi(sfromto(s,line[0],9,10));  /* [0] has info for sure */
  transiting = atoi(sfromto(s,line[0],11,12));
  asp = atoi(sfromto(s,line[0],13,14));

  n = sprintf(wk4,"^(%s%s%s)\n",
    N_short_nat_plt[nat],
    N_short_doc_aspect[Aspect_type[asp]],
    N_short_trn_plt[transiting]
  );

//ksn(wk4);  // for debug   show the apects with no dates

  /* append this to the end of mywork
  */
  sprintf(mywork2, "%s%s", mywork, wk4);   
  strcpy(mywork, mywork2);

  n = sprintf(mywork, "%s\n", mywork);
  f_docin_put(mywork, n);
//tr("end of do_a_para()"); ksn(mywork);
//tr("");

}  /* end of do_a_para() */


/* mk_new_date.c */
/* calculates new date as below */

extern double Day_tab[][13];

/* add dstep days to previous date  mn/dy/yr
 */
void mk_new_date(double *pm, double *pd, double *py, double dstep)  
{
  int i,leap,retvalnewdate;
  double temp,jd;    /* jd julian date */
  double prev_year_num_days;    /* jd julian date */
  double prev_year_jd;    /* jd julian date */
  ;
  retvalnewdate = isinnewyear(*py, *pm, *pd, dstep);
//kin(retvalnewdate );
  if (retvalnewdate == 999) {  // new date  is in same year as arg year
    temp = day_of_year(*py, *pm, *pd);  /* julian day in year */
    month_day(*py, temp + dstep, pm, pd);  /* get mn dy, yr  for jd in year *py */
    return;
  }
  else if (retvalnewdate == 1) {  // in future  year
    jd = day_of_year(*py, *pm, *pd) + dstep;  /* (here, this julian date  is > 365 (or 364) */

    while (isinnewyear(*py, *pm, *pd, dstep) == 1) {

      i = (int)*py;  /* is the arg starting year  leap? */
      leap = (i%4 == 0 && i%100) != 0 || i%400 == 0;

      jd -= Day_tab[leap][0];    /* jd in the new year (or subsequent yr) */
                                 /* Day_tab[leap][0] is 365 or 366 depending on leap */
      dstep = jd;  *py += 1.0;  *pm = 1.0;  *pd = 0.0;
        /* 01Jan of new year (0 for month_day()) */
    }

    month_day(*py, jd, pm, pd);  /* get mn, dy  for jd in year *py,  */
    return;
  }
  else { // (retvalnewdate is 0 or negative)  new date is in past   year
    // this assumes new date is in arg year minus ONE
//tn();trn("in PreV YEAR!");
    // get  prev_year_num_days
    //
    i = (int) ( *py - 1) ;  /* is the arg starting year  leap? */
    leap = (i%4 == 0 && i%100) != 0 || i%400 == 0;
    prev_year_num_days = Day_tab[leap][0]; /* Day_tab[leap][0] is 365 or 366 depending on leap */
    prev_year_jd = prev_year_num_days - retvalnewdate;
               /* returns  num days to subtract from num days in prev year  if new date ymd is in past year */
    *py = *py - 1;
    month_day(*py, prev_year_jd, pm, pd);  /* get mn, dy  for jd in year *py,  */
    return;
  }


}  /* end of mk_new_date() */

/* is date + step in new year? */
             /* NO  returns 1 if yes, 0 if in this year */
/* returns  num days to subtract from num days in prev year  if new date ymd is in past year 
*  returns  1  if new date ymd is in future year
*  returns  0  if new date ymd is in same   year
*/
int isinnewyear(double y, double m, double d, double step) 
{
//tn();trn(" int isinnewyear(double y, double m, double d, double step) ");
//tn();kd(y);kd(m);kd(d);
  int i,leap;
  double temp;
  ;
  i = (int)y;
  leap = (i%4 == 0 && i%100) != 0 || i%400 == 0;
  temp = day_of_year(y,m,d) + step;

  if ( temp >  Day_tab[leap][0]) {  // [0] is num days in year (365 or 366)
    return (1);   // new date is in future year
  } 

  if ( temp <  1 ) {            // added 20150406  (backward for what color report)
    // here, temp could be 0, meaning new date is last day in prev year
    return (temp);  // (retval is 0 or negative)  new date is in past   year
  } 

  return(999);    // new date is in same   year
 
}  

/* return jd in year from year, month & day */
      //
      // FYI  (from futdoc.h)
      //
      //      /* the following is for K&R fns day_of_year() & month_day() */
      //      double Day_tab[2][13] = {
      //        {365.0,31.0,28.0,31.0,30.0,31.0,30.0,31.0,31.0,30.0,31.0,30.0,31.0},
      //        {366.0,31.0,29.0,31.0,30.0,31.0,30.0,31.0,31.0,30.0,31.0,30.0,31.0}
      //      };
      //
double day_of_year(double year, double month, double day)  /* return jd in year from year, month & day */
{
  int leap;
  int ri;
  ;
  ri = (int)year;
  leap = (ri%4 == 0 && ri%100) != 0 || ri%400 == 0;
  for (ri=1; ri <  month; ++ri) day += Day_tab[leap][ri];
  return(day);
}  /* end of day_of_year() */

/* set month, day  for jd=yearday in year */
void month_day(double year, double yearday, double *pmonth, double *pday)
{
  int leap;
  int ri;
  ;
  ri = (int)year;
  leap = (ri%4 == 0 && ri%100) != 0 || ri%400 == 0;
  for (ri=1; yearday  > Day_tab[leap][ri]; ++ri) 
    yearday -= Day_tab[leap][ri];
  *pmonth = (double)ri;
  *pday = yearday;
}  /* end of month_day() */

//
//// should be left with raw chars no html
////
//void  remove_spans(char *linethird) {
//  char workstr[8192], mychar;
//  int  mylen, are_in_a_span, write_idx;
//
//  mylen = (int)strlen(linethird);
//  are_in_a_span = 0;
//  write_idx     = -1;
//
//  for (int i=0; i < mylen; i++) {
//    mychar =  linethird[i];
//    if (mychar == '<') {
//      are_in_a_span = 1;
//      continue;
//    } 
//    if (mychar == '>') {
//      are_in_a_span = 0;
//      continue;
//    }
//    if (are_in_a_span == 1) {
//      continue;
//    } else {
//      write_idx = write_idx + 1;
//      workstr[write_idx] = mychar;
//    }
//  }
//  write_idx = write_idx + 1;
//  workstr[write_idx] = '\0';
//
//  strcpy (linethird, workstr);
//
//} // end of  remove_spans()
//

// end of stuff from futasp.c ==========================================================
// end of stuff from futasp.c ==========================================================



void newPlanBenchmarkLabels(void)
{
//trn("\n in newPlanBenchmarkLabels()\n");
// for  newPlanBenchmarkLabels()

  // log what we have here
//char mylogbuf34[256];
//int  mylogidx34;
//  for (mylogidx34 = 0;  mylogidx34 <= Num_lines_in_grh_body  ; mylogidx34++)      /* iprt is num lines in grh body */
//  {
//    strcpy(mylogbuf34, Grh_body_BIG + mylogidx34 * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
//ki(mylogidx34);ksn(mylogbuf34);
//  }
//




//  sprintf(  // PUT LINE IN TBL
//    Grh_body_BIG + (Num_lines_in_grh_body-1) * 
//               (SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE + 1),
//    "%s%s",
//    get_grh_left_margin(p_ln_ctr,top,p_line),
//    p_line
//  );




//  prt_BIGgrh_bot(&grh_line[0],&cols_with_pt[0],pt_ctr,&fut_line_ctr);


  // new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW
  // new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW
  //
  // NOTE: there are 17 lines between STRESS- and GOOD-
  // NOTE: there are 17 lines between   GOOD- and GREAT-
  //
  // STEP 1. in all of the GRH lines we have, put in the benchmark labels that are supposed to be there-  "STRESS-", "GOOD-", "GREAT-"
  // STEP 2. add sky lines and missing benchmark labels until ALL of  "STRESS-"  "GOOD-"  "GREAT-" are put in
  //
  // STEP 1. in all of the GRH lines we have, put in the benchmark labels that are supposed to be there-  "STRESS-", "GOOD-", "GREAT-"
  //         read GRH  lines until we hit benchmark label STRESS- (assume it is always there - safe?    i think so       maybe)
  //         read the rest of the GRH lines, keeping mycntlinesNEW 
  //         and fill in any  missing benchmark labels -  GOOD- or GREAT-
  //         populate gbl_lastBenchmarkLabel  (this will be "STRESS-", "GOOD-" or "GREAT-")
  //
  // STEP 2. add sky lines and missing benchmark labels until ALL of  "STRESS-"  "GOOD-"  "GREAT-" are put in
  //         read GRH  lines until we hit gbl_lastBenchmarkLabel 
  //         read the rest of the GRH lines, keeping mycntlinesNEW 
  //         put in filler skylines to fill out the 17 lines between benchmark labels
  //         after 17 lines put in the appropriate benchmark label with all sky
  //         go until ALL of  "STRESS-"  "GOOD-"  "GREAT-" are put in
  //

  // STEP 1. in all of the GRH lines we have, put in the benchmark labels that are supposed to be there-  "STRESS-", "GOOD-", "GREAT-"
  //   PUT MISSING LABELS
  //
  char linebufNEW[256];
  int myidxNEW;
  int myidxallnew;
  char LABEL_search_info[128];
  char LASTLABEL_search_info[128];
// now gbl_numBodyLinesToProcess  int numBodyLinesToProcess;     // num_lines changes on the fly in here, so use this constant number

  char my184SharpsNEW[1024]; sfill(my184SharpsNEW, 184, '#'); 


//nksn("BEG  STEP 1  STEP 1  STEP 1  STEP 1  STEP 1  STEP 1  ");
  gbl_numBodyLinesToProcess = Num_lines_in_grh_body;  // num_lines changes on the fly in here, so use this constant number
//kin(Num_lines_in_grh_body );
//kin(gbl_numBodyLinesToProcess);  


//step1BLOCK:
//do lb  //  step 1 BLOCK      step 1 BLOCK      step 1 BLOCK      step 1 BLOCK      step 1 BLOCK      step 1 BLOCK      step 1 BLOCK    


  // take existing lines and add all-new labels  using gbl_topStarVal
  //
        //        /* --------------- "/Users/xxx/_PC/usr/apple/_c/_wrk/futdefs.h" -------------- */
        //        /* 128:#define SUBSCRIPT_FOR_VLO_STRESS_LEVEL 6    * Stress_val[6] = vlo- "great"*/
        //        /* 129:#define SUBSCRIPT_FOR_LO_STRESS_LEVEL 5     * Stress_val[5] = lo- "good" */
        //        /* 130:#define SUBSCRIPT_FOR_HIGH_STRESS_LEVEL 3   * Stress_val[3] = hi-"stress" */
        //        /* 131:#define SUBSCRIPT_FOR_VHIGH_STRESS_LEVEL 2  * Stress_val[2] = hi-"OMG" */
        //          //
        //          //    futdoc.h
        //          //    char *Stress_name[NUM_STRESS_LEVELS] = {
        //          //      "       ",
        //          //      "   OMG-",
        //          //      "       ",
        //          //      "STRESS-",
        //          //      "       ",
        //          //      "  GOOD-",
        //          //      "       ",
        //          //      " GREAT-",
        //          //    };
        //          //
        //        //    #define SIZE_EPH_GRH_INCREMENT 6  /* 1 '*' for every 6 Grhdata score nums */
        //        //
        //        // gbl_numLinesFillToGREAT = (Stress_val[SUBSCRIPT_FOR_VLO_STRESS_LEVEL]  -  Grh_bot ) / SIZE_EPH_GRH_INCREMENT; 
        //        //
        //        /* --------------- "/Users/xxx/_PC/usr/apple/_c/_wrk/futdoc.h" -------------- */
        //        /* 223:int Stress_val[NUM_STRESS_LEVELS] =  304,250,196,142,88,34,-20,-74 ;   */
        //        /*                                                   32  23,    5,            */
        //        /*                                                  omg str, good, -20=great  */
        //        //


  // log what we have here
//char mylogbuf42[256];
//for (myidxallnew = gbl_numBodyLinesToProcess - 1;  myidxallnew >= 0 ; myidxallnew = myidxallnew - 1 )      // read in GREAT to STRESS direction
//{
// strcpy(mylogbuf42, Grh_body_BIG + myidxallnew * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
//ki(myidxallnew);ksn(mylogbuf42);
//} 
//


//trn(" take existing lines and add all-new  AN  labels  using gbl_topStarVal");
//trn("read in GREAT to STRESS direction");
    int linVal;  linVal = -9999;
    int  ANidx;        // AN = allnew
    char ANbuf[256];   // AN = allnew
    char ANlmar[16];   // AN = allnew
    int  encounteredSTRESSline;

    encounteredSTRESSline = 0;            // INIT
    strcpy(gbl_lastBenchmarkLabel, "" );  // INIT
//    strcpy(gbl_lastBenchmarkLabel, " GREAT-" );  // INIT
//ksn(gbl_lastBenchmarkLabel);
//kin(ANidx);
//kin(encounteredSTRESSline);
//kin(gbl_numBodyLinesToProcess );
//kin(Num_lines_in_grh_body);


    for (ANidx = gbl_numBodyLinesToProcess - 1;  ANidx >= 0 ; ANidx = ANidx - 1 )      // read in GREAT to STRESS direction
    {
//trn("do i get here");
      strcpy(ANbuf, Grh_body_BIG + ANidx * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
//ksn(ANbuf);
//kin(linVal);
      if (    linVal == -9999 ) {
        if (    strstr(ANbuf, "*") != NULL
            ||  strstr(ANbuf, "X") != NULL ) {

          linVal = gbl_topStarVal ;
//ki(linVal); trn(" assign gbl_topStarVal to first line with star (*) or body (X)");

        } else {
          ;  // do not change linVal until we hit a star or X
          // HOWEVER this line might have no star or X but it MIGHT be a benchmark label line
          // if do,  add the benchmark label

// where was this line added before any star ?
        }
      } else {
        // here linVal is NOT = -9999
        linVal = linVal + SIZE_EPH_GRH_INCREMENT ;
//ki(linVal); trn(" increment linVal   -here linVal is NOT = -9999");
      }

      // loop thru the stress levels and (if applicable) put in stress name (benchmark label)
      //
      strcpy(ANlmar, "       ");  // default left margin
      int ilef3;

      for (ilef3=0; ilef3 <= NUM_STRESS_LEVELS-1; ilef3++) {
        if (linVal >= Stress_val[ilef3]) {
          if (linVal < Stress_val[ilef3] + SIZE_EPH_GRH_INCREMENT) {
//            sprintf(&l_mar[0],"%s",Stress_name[ilef3]);
//trn("have read a line deserving a Stress_name[]");
            strcpy(ANlmar, Stress_name[ilef3] );    // left margin with benchmark label
//ksn(ANlmar);
            if (strstr(ANlmar, "STRESS") != NULL) encounteredSTRESSline = 1;
//kin(encounteredSTRESSline);
 
            if ( sall( ANlmar, " ") == 0 )    // 0 false = means str IS NOT all spaces
            {
char mytstbuf5[256];
//trn("grh line before new lmar");
strcpy(mytstbuf5, Grh_body_BIG + ANidx * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
//ksn(mytstbuf5);
              memcpy( Grh_body_BIG + ANidx * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1), ANlmar, 7);
//trn("grh line after  new lmar");
strcpy(mytstbuf5, Grh_body_BIG + ANidx * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
//ksn(mytstbuf5);
            }


//            strcpy(gbl_lastBenchmarkLabel, ANlmar );  
//ksn(gbl_lastBenchmarkLabel);
            // if not all spaces, save FIRST ENCOUNTERED benchmark label as gbl_lastBenchmarkLabel
            //
//int sallret;
////sallret = sall( Stress_name[ilef3], " ");
//sallret = sall( ANlmar, " ");
//kin(sallret);

            if (    strlen(gbl_lastBenchmarkLabel) == 0     // len=0  means not populated
                &&  sall( ANlmar, " ") == 0     // not all spaces
            ) {
//tr("copied into gbl_lastBenchmarkLabel");
              strcpy(gbl_lastBenchmarkLabel, ANlmar );  
//ksn(gbl_lastBenchmarkLabel);

            }

          } else {
            strcpy(ANlmar, "       ");              // left margin with 7 spaces
          }
        }
      }
     
// log each line
//ki(ANidx);ki(linVal);ks(ANlmar);ksn(ANbuf);

    } // read in GREAT to STRESS direction


//trn("\nstep 1 top part is finished\n");

  // log what we have here
//char mylogbuf43[256];
//for (myidxallnew = gbl_numBodyLinesToProcess - 1;  myidxallnew >= 0 ; myidxallnew = myidxallnew - 1 )      // read in GREAT to STRESS direction
//{
// strcpy(mylogbuf43, Grh_body_BIG + myidxallnew * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
//ki(myidxallnew);ksn(mylogbuf43);
//} 
//



  // check for edge case (like Kim jong Un -2106) where entire graph is below the stress line
  //
  if (encounteredSTRESSline == 0) {
    missingSTRESSline();  // edge case (like Kim jong Un -2106) where entire graph is below the stress line


// log what we have here
//char mylogbuf51[256];
//int  mylogidx51;
//for (mylogidx51 = 0;  mylogidx51 <= Num_lines_in_grh_body  ; mylogidx51++)      /* iprt is num lines in grh body */
//{
// strcpy(mylogbuf51, Grh_body_BIG + mylogidx51 * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
// ki(mylogidx51);ksn(mylogbuf51);
//}
//




    return;
  }
 


  // unfortunate fix needed - it happened that the first line (all sky) happened to be a GOOD- benchmark label line
  // so we have to read in the other direction and count 17 and fill in any missing benchmark labels
  //
//trn(" unfortunate fix \"UF\"  needed - it happened that the first line (all sky) happened to be a GOODF- benchmark label line");
char UFbuf[256];
int  UF17ctr;
int  UFdoing17ctr;        
int  sawLabelSTRESS;
int  sawLabelGOOD;
int  sawLabelGREAT;
char UFlastLABEL[16];
char UFfirst7chars[16];
    sfill(UFfirst7chars, 12 , '\0');  /* line size without left margin */

    sawLabelSTRESS = 0;
    sawLabelGOOD   = 0;
    sawLabelGREAT  = 0;
    UF17ctr = 0; UFdoing17ctr = 0;

    for (int UFidx = 0;  UFidx < gbl_numBodyLinesToProcess ;  UFidx = UFidx + 1 )      // UF read in STRESS to GREAT direction
    {
      strcpy(UFbuf, Grh_body_BIG + UFidx * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
      sfromto(UFfirst7chars, Grh_body_BIG + UFidx * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1),  1, 7);


// log each line
//ki(UFidx);ks(UFfirst7chars);ksn(UFbuf);


      if (strstr(UFfirst7chars, "STRESS") != NULL )  sawLabelSTRESS = 1; 
      if (strstr(UFfirst7chars,   "GOOD") != NULL )  sawLabelGOOD   = 1;
      if (strstr(UFfirst7chars,  "GREAT") != NULL )  sawLabelGREAT  = 1; 

      if (UFdoing17ctr == 1) {
        UF17ctr = UF17ctr + 1 ;
//ki(UF17ctr);
      }
      if (UF17ctr == 18) {
        // if UF17ctr is 18, then we have 17 lines since last benchmark label, put a benchmark label on this line
        // BUT only if it has no benchmark label already
//trn("if UF17ctr is 18, then we have 17 lines since last benchmark label, put a benchmark label on this line");
//trn(" use this is pick label to put");
//ksn(UFlastLABEL);
        UF17ctr = 0;
//kin(UF17ctr);

        // if this line label is all spaces, put the next label in
        //
        if (sall(UFfirst7chars, " ") == 1) {  // str IS all spaces
               if ( strstr(UFlastLABEL, "OMG")    != NULL )  strcpy(UFlastLABEL, "STRESS-");
          else if ( strstr(UFlastLABEL, "STRESS") != NULL ) { strcpy(UFlastLABEL, "  GOOD-"); }
          else if ( strstr(UFlastLABEL, "GOOD")   != NULL ) { strcpy(UFlastLABEL, " GREAT-"); }
          else if ( strstr(UFlastLABEL, "GREAT")  != NULL ) { strcpy(UFlastLABEL, "       "); }

//tr("putting in LABEl");ksn(UFlastLABEL);
          // ---------------------------------------------------------------------------------------------------
          memcpy( Grh_body_BIG + UFidx * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1), UFlastLABEL, 7);
          // ---------------------------------------------------------------------------------------------------

          // if   we just printed GREAT-
          // then we are finished this unfortunate fix.
          // BUT there is no need for step 2 now, so return from newPlanBenchmarkLabels()
          //
          if ( strstr(UFlastLABEL, "       ")  != NULL )  return; // if we just printed GREAT-, UFlastLABEL was changed to all spaces

          strcpy(gbl_lastBenchmarkLabel, UFlastLABEL);
//tr("NEW val for gbl_lastBenchmarkLabel"); ksn(gbl_lastBenchmarkLabel);

        } // all spaces, so put benchmark label

      } // 17 lines are behind this line


      if (sall(UFfirst7chars, " ") == 0) {  // str is NOT all spaces
        UFdoing17ctr = 1;                   // do the increment of UF17ctr
        strcpy(UFlastLABEL,  UFfirst7chars);
//ksn(UFlastLABEL);
      }
    } // UF read in STRESS to GREAT direction




//trn("unfortunate fix main part is finished");
//trn("it is STILL possible GREAT label is missing");
//kin(UF17ctr);
//kin(Num_lines_in_grh_body);
//kin(sawLabelSTRESS);
//kin(sawLabelGOOD  );
//kin(sawLabelGREAT );

    if (   sawLabelGOOD  == 0  )
    {
//trn("                     GOOD label is missing and it is the FIRST line to be added");
      if (UF17ctr == 17) {

        // write in all sky line with  GOOD- label for that line
        // ---------------------------------------------------------------------------------------------------------------------------------------
        sprintf( Grh_body_BIG + Num_lines_in_grh_body  * (SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE + 1), "%s%s", "  GOOD-", my184SharpsNEW);
        Num_lines_in_grh_body = Num_lines_in_grh_body + 1 ;
        gbl_numBodyLinesToProcess = Num_lines_in_grh_body;  // num_lines changes on the fly in here, so use this constant number
        // ---------------------------------------------------------------------------------------------------------------------------------------
//kin(Num_lines_in_grh_body);
//kin(gbl_numBodyLinesToProcess);
//tr("copied into 2 gbl_lastBenchmarkLabel");
        strcpy(gbl_lastBenchmarkLabel, "  GOOD-" );   // just added  GOOD line
//ksn(gbl_lastBenchmarkLabel);
        sawLabelGOOD = 1;
//kin(sawLabelGOOD);

        // write in all sky line on top of GOOD line
        // ---------------------------------------------------------------------------------------------------------------------------------------
        sprintf( Grh_body_BIG + Num_lines_in_grh_body  * (SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE + 1), "%s%s", "       ", my184SharpsNEW);
        Num_lines_in_grh_body = Num_lines_in_grh_body + 1 ;
        gbl_numBodyLinesToProcess = Num_lines_in_grh_body;  // num_lines changes on the fly in here, so use this constant number
        // ---------------------------------------------------------------------------------------------------------------------------------------
//kin(Num_lines_in_grh_body);
//kin(gbl_numBodyLinesToProcess);
      }
    }
    else if (    sawLabelGREAT == 0
             &&  sawLabelGOOD  == 1  )
    {
//trn("                     GREAT label is missing and it is the FIRST line to be added");
      if (UF17ctr == 17) {

        // write in all sky line with GREAT- label for that line
        // ---------------------------------------------------------------------------------------------------------------------------------------
        sprintf( Grh_body_BIG + Num_lines_in_grh_body  * (SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE + 1), "%s%s", " GREAT-", my184SharpsNEW);
        Num_lines_in_grh_body = Num_lines_in_grh_body + 1 ;
        gbl_numBodyLinesToProcess = Num_lines_in_grh_body;  // num_lines changes on the fly in here, so use this constant number
        // ---------------------------------------------------------------------------------------------------------------------------------------
//kin(Num_lines_in_grh_body);
//kin(gbl_numBodyLinesToProcess);
//tr("copied into 2 gbl_lastBenchmarkLabel");
        strcpy(gbl_lastBenchmarkLabel, " GREAT-" );   // just added GREAT line
//ksn(gbl_lastBenchmarkLabel);
        sawLabelGREAT = 1;
//kin(sawLabelGREAT);

        // write in all sky line on top of GREAT line
        // ---------------------------------------------------------------------------------------------------------------------------------------
        sprintf( Grh_body_BIG + Num_lines_in_grh_body  * (SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE + 1), "%s%s", "       ", my184SharpsNEW);
        Num_lines_in_grh_body = Num_lines_in_grh_body + 1 ;
        gbl_numBodyLinesToProcess = Num_lines_in_grh_body;  // num_lines changes on the fly in here, so use this constant number
        // ---------------------------------------------------------------------------------------------------------------------------------------
//kin(Num_lines_in_grh_body);
//kin(gbl_numBodyLinesToProcess);
      }
    }






  //
  // unfortunate fix needed - it happened that the first line (all sky) happened to be a GOOD- benchmark label line
  // so we have to read in the other direction and count 17 and fill in any missing benchmark labels


//trn("all of unfortunate fix is done");



  // log what we have here
//char mylogbuf45[256];
//for (myidxallnew = gbl_numBodyLinesToProcess - 1;  myidxallnew >= 0 ; myidxallnew = myidxallnew - 1 )      // read in GREAT to STRESS direction
//{
// strcpy(mylogbuf45, Grh_body_BIG + myidxallnew * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
//ki(myidxallnew);ksn(mylogbuf45);
//} 
//

  //
  // take existing lines and add all-new labels  using gbl_topStarVal














//
//  // populate gbl_lastBenchmarkLabel
//  // also add labels if missing
//  //
//  char first7chars[16];
//  int doCountLines;
//  doCountLines = 0;  // starting counting to 17 after hitting STRESS
//  mycntlinesNEW = 0; // INIT
//
////trn(" populate gbl_lastBenchmarkLabel");
//  for (myidxNEW = 0;  myidxNEW < gbl_numBodyLinesToProcess ; myidxNEW = myidxNEW + 1 )      // read backwards (STRESS to GOOD direction)
//  {
//    if (doCountLines == 1) mycntlinesNEW = mycntlinesNEW + 1;
//    if (mycntlinesNEW == 17 + 1) {
//      // we are on line where should be benchmark label
//      if (strstr(gbl_lastBenchmarkLabel,    "OMG") != NULL)   strcpy(gbl_lastBenchmarkLabel, "STRESS-");
//      if (strstr(gbl_lastBenchmarkLabel, "STRESS") != NULL)   strcpy(gbl_lastBenchmarkLabel, "  GOOD-");
//      if (strstr(gbl_lastBenchmarkLabel,   "GOOD") != NULL)   strcpy(gbl_lastBenchmarkLabel, " GREAT-");
//
//      memcpy( Grh_body_BIG + myidxNEW * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1), gbl_lastBenchmarkLabel, 7); // write next benchmark label
//tr("ADDED gbl_lastBenchmarkLabel to existing line"); ksn(gbl_lastBenchmarkLabel);
//tr("new gbl_lastBenchmarkLabel");ksn(gbl_lastBenchmarkLabel);
//    }
//
//    sfill(first7chars, 12 , '\0');  /* line size without left margin */
////ksn(first7chars);
//    sfromto(first7chars, Grh_body_BIG + myidxNEW * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1),  1, 7);
//
//    if (sall(first7chars, " ") == 0) {
//      strcpy(gbl_lastBenchmarkLabel, first7chars);
//tr("new gbl_lastBenchmarkLabel");ksn(gbl_lastBenchmarkLabel);
//      
//      if (strstr(gbl_lastBenchmarkLabel, "STRESS") != NULL) doCountLines = 1;
//    }
////ki(myidxNEW);ksn(first7chars);
//  }
//



//
//  // read until line with  gbl_lastBenchmarkLabel
//  for (myidxNEW = 0;  myidxNEW < gbl_numBodyLinesToProcess ; myidxNEW = myidxNEW + 1 )      // read backwards (STRESS to GOOD direction)
//  {
//    strcpy(linebufNEW, Grh_body_BIG + myidxNEW * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
//ki(myidxNEW);ksn(linebufNEW);
//
//    // read until you get to gbl_lastBenchmarkLabel
//    //
//    if (strstr(linebufNEW, "gbl_lastBenchmarkLabel")  != NULL)  break;
//  }
//  //
//  // here we are on the gbl_lastBenchmarkLabel line 
//  //
//
//  mycntlinesNEW = 0;                          // INIT
//
//  // read until we get to where the first benchmark label should be
//trn(" read until we get to where the first benchmark label should be");
//  for (myidxNEW = 0;  myidxNEW < gbl_numBodyLinesToProcess;  myidxNEW = myidxNEW + 1 )      // read backwards (STRESS to GOOD direction)
//  {
//    mycntlinesNEW = mycntlinesNEW + 1;
//    strcpy(linebufNEW, Grh_body_BIG + myidxNEW * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
//ki(myidxNEW);ki(mycntlinesNEW);ksn(linebufNEW);
//
//    if (mycntlinesNEW ==  17)                   { strcpy(LABEL_search_info, "next label goes here");   break; }
//    if (myidxNEW == gbl_numBodyLinesToProcess -1)   { strcpy(LABEL_search_info, "ran out of lines");       break; }  // last GRH line
//  } 
//ksn(LABEL_search_info);
//  
//  if (strcmp(LABEL_search_info, "ran out of lines")     == 0 )  break;    // break step1BLOCK;
//
//  if (strcmp(LABEL_search_info, "next label goes here") == 0 )  {
//
//    if (strstr(gbl_lastBenchmarkLabel,    "OMG") != NULL)   strcpy(gbl_lastBenchmarkLabel, "STRESS-");
//    if (strstr(gbl_lastBenchmarkLabel, "STRESS") != NULL)   strcpy(gbl_lastBenchmarkLabel, "  GOOD-");
//    if (strstr(gbl_lastBenchmarkLabel,   "GOOD") != NULL)   strcpy(gbl_lastBenchmarkLabel, " GREAT-");
//
////
////// strcpy(linebufNEW, Grh_body_BIG + myidxNEW * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
////    memcpy( Grh_body_BIG + myidxNEW * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1), gbl_lastBenchmarkLabel, 7); // write next benchmark label
////tr("ADDED gbl_lastBenchmarkLabel to existing line"); ksn(gbl_lastBenchmarkLabel);
////    if (strstr(gbl_lastBenchmarkLabel, "GREAT") != NULL) break;
//
//  }
//

//
//  // read to find GREAT
//  mycntlinesNEW = 0;  // INIT
//
//  for (            ;  myidxNEW < gbl_numBodyLinesToProcess;  myidxNEW = myidxNEW + 1 )      // read backwards (GOOD to GREAT direction)
//  {
//    mycntlinesNEW = mycntlinesNEW + 1;
//    strcpy(linebufNEW, Grh_body_BIG + myidxNEW * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
//ki(myidxNEW);ki(mycntlinesNEW);ksn(linebufNEW);
//    if (strstr(linebufNEW, "GREAT-")  != NULL)  { strcpy(LABEL_search_info, "found");            break; }
//    if (mycntlinesNEW ==  17 + 1)               { strcpy(LABEL_search_info, "not found");        break; }
//    if (myidxNEW == gbl_numBodyLinesToProcess -1)   { strcpy(LABEL_search_info, "ran out of lines"); break; }  // last GRH line
//  } // read to find GREAT
//ksn(LABEL_search_info);
//  
//  if (strcmp(LABEL_search_info, "ran out of lines") == 0 )  break;  // break step1BLOCK;
//  if (strcmp(LABEL_search_info, "found")            == 0 )  strcpy(gbl_lastBenchmarkLabel, " GREAT-");
//  if (strcmp(LABEL_search_info, "not found")        == 0 )  {
//    // here, "GREAT-" is supposed to be on this line and it is not
//    // put "GREAT-"  benchmark label in
//// strcpy(linebufNEW, Grh_body_BIG + myidxNEW * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
//    memcpy( Grh_body_BIG + myidxNEW * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1), " GREAT-", 7); /* write GREAT- in */
//trn("ADDED   GREAT-");
//
//  }

  // here GREAT was found or added so STEP 1 is over

//ksn("END  STEP 1  STEP 1  STEP 1  STEP 1  STEP 1  STEP 1  ");

//rb  while (0);   //  step 1 BLOCK      step 1 BLOCK      step 1 BLOCK      step 1 BLOCK      step 1 BLOCK      step 1 BLOCK      step 1 BLOCK    


  //
  //   PUT MISSING LABELS

//trn("finished step 1"); 
//trn("step 1 GUARANTEES all the correct benchmark labels are there in the existing lines"); 

//
//  // here all existing lines have the right benchmark labels
//  // log what we have here
//trn(" here all existing lines have the right benchmark labels");
//char mylogbuf41[256];
//int  mylogidx41;
//  for (mylogidx41 = 0;  mylogidx41 <= Num_lines_in_grh_body  ; mylogidx41++)      /* iprt is num lines in grh body */
//  {
//    strcpy(mylogbuf41, Grh_body_BIG + mylogidx41 * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
//ki(mylogidx41);ksn(mylogbuf41);
//  }
//



//ksn(gbl_lastBenchmarkLabel);

//
//  // log what we have here
//char mylogbuf32[256];
//int  mylogidx32;
//  for (mylogidx32 = 0;  mylogidx32 <= Num_lines_in_grh_body  ; mylogidx32++)      /* iprt is num lines in grh body */
//  {
//    strcpy(mylogbuf32, Grh_body_BIG + mylogidx32 * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
//ki(mylogidx32);ksn(mylogbuf32);
//  }
//

//return; // for test

int ctrUpTo17;  ctrUpTo17 = 0;  // magic num = 17 lines  between benchmark labels


if (strstr(gbl_lastBenchmarkLabel, "GREAT-") == NULL ) {   // NOT ALL benchmark labels are there

  // STEP 2. add sky lines and missing benchmark labels until ALL of  "STRESS-"  "GOOD-"  "GREAT-" are put in
  //  part A - read GRH  lines until we hit gbl_lastBenchmarkLabel 
  //         - read the rest of the GRH lines, keeping ctrUpTo17 
  //  part B = put in filler skylines to fill out the 17 lines between benchmark labels
  //         - after 17 lines put in the appropriate benchmark label with all sky
  //         - go until ALL of  "STRESS-"  "GOOD-"  "GREAT-" are put in
  //
//ksn("BEG  STEP 2  STEP 2  STEP 2  STEP 2  STEP 2  STEP 2  ");

//
//  for (myidxNEW = 0;  myidxNEW < gbl_numBodyLinesToProcess ; myidxNEW = myidxNEW + 1 )      // read backwards (STRESS to GOOD direction until gbl_lastBenchmarkLabel
//  {
//    strcpy(linebufNEW, Grh_body_BIG + myidxNEW * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
//ki(myidxNEW);ksn(linebufNEW);
//
//    if (do17linecount = 1) {
//      mycntlinesNEW = mycntlinesNEW + 1;
//      if (mycntlinesNEW ==  17) break;
//    }
//    if (strstr(linebufNEW, gbl_lastBenchmarkLabel)  != NULL)  {
//      // we are on line with gbl_lastBenchmarkLabel
//      // start 17 line counter to next label
//      //
//      do17linecount = 1;
//      mycntlinesNEW = 0;
//    }
//  }
//kin(mycntlinesNEW);

  int  do17linecounting;  do17linecounting = 0;
  
  // read backwards (STRESS to GOOD direction until gbl_lastBenchmarkLabel
  // and then to the end of existing lines
  //
  for (myidxNEW = 0;  myidxNEW < gbl_numBodyLinesToProcess ; myidxNEW = myidxNEW + 1 )    
  {
    strcpy(linebufNEW, Grh_body_BIG + myidxNEW * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));

// log each line
//ki(myidxNEW);ksn(linebufNEW);


    if (do17linecounting == 1) {
      ctrUpTo17 = ctrUpTo17 + 1;
//kin(ctrUpTo17);
      if (ctrUpTo17 ==  17) ctrUpTo17 = 0;  // should not happen
    }

    if (strstr(linebufNEW, gbl_lastBenchmarkLabel)  != NULL)  {
      // we are on line with gbl_lastBenchmarkLabel
      // start 17 line counter to next label
      //
      do17linecounting = 1;
      ctrUpTo17     = 0;
//trn(" we are on line with gbl_lastBenchmarkLabel, so start ctrUpTo17");
    }
  } // read all existing GRH lines

//trn("here we have read all the existing lines -----------------------------------------------------------------------------");
//ksn(gbl_lastBenchmarkLabel);
//kin(gbl_numBodyLinesToProcess);
//kin(Num_lines_in_grh_body);
//kin(myidxNEW);
//kin(ctrUpTo17);
//trn("ready to add new lines");


  //
  // here we are on the last line in GRH lines
  // so, fill in sky lines up to where next benchmark label should be
  //

  //
  int lastLineIsGreatLine; lastLineIsGreatLine = 0;
  do { // FILL TO GREAT
//trn("do fill in sky lines up to where next label should be");
//    for (int mmm = ctrUpTo17;  mmm <= 17; mmm++ )  // NOTE  MAGIC NUM 17   17 lines in between each benchmark label
    for (int mmm = ctrUpTo17;  mmm <  17; mmm++ )  // NOTE  MAGIC NUM 17   17 lines in between each benchmark label
    {
//tr("NEW add fill 184sharps");ki(mmm);kin(Num_lines_in_grh_body);
      // ---------------------------------------------------------------------------------------------------------------------------------------
      sprintf( Grh_body_BIG + Num_lines_in_grh_body  * (SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE + 1), "%s%s", "       ", my184SharpsNEW);
      Num_lines_in_grh_body = Num_lines_in_grh_body + 1 ;
      // ---------------------------------------------------------------------------------------------------------------------------------------

      strcpy(gbls_addLines, "we added lines to ensure benchmark labels STRESS, GOOD and GREAT are all present");

      ctrUpTo17 = ctrUpTo17 + 1 ;
//ki(mmm);kin(ctrUpTo17);
    }

    ctrUpTo17 = 0;  // set for new fills

    // here we are at the point where there should a new line with a benchmark label
    //
//trn("here we are at the point where there should a new line with a benchmark label");
//kin(ctrUpTo17);
//ksn(gbl_lastBenchmarkLabel);
    if   (strstr(gbl_lastBenchmarkLabel, "STRESS-") != NULL) { strcpy(gbl_lastBenchmarkLabel, "  GOOD-");  }
    else {
      if (strstr(gbl_lastBenchmarkLabel, "GOOD-")   != NULL) { strcpy(gbl_lastBenchmarkLabel, " GREAT-");  }
    }

//tr("add line with NEW benchmark label"); ksn(gbl_lastBenchmarkLabel);

//char mytstbuf6[256];
//sfill(mytstbuf6, 250 , '\0');
//trn("grh line before new line with new lmar");
//strcpy(mytstbuf6, Grh_body_BIG + Num_lines_in_grh_body * (SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE + 1) );
//ksn(mytstbuf6);
//kin(Num_lines_in_grh_body );
//ksn(gbl_lastBenchmarkLabel);
//ksn(my184SharpsNEW);

    sprintf( Grh_body_BIG + Num_lines_in_grh_body * (SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE + 1), "%s%s", gbl_lastBenchmarkLabel, my184SharpsNEW);
//bn(11);
    Num_lines_in_grh_body = Num_lines_in_grh_body + 1 ;
//bn(12);
    strcpy(gbls_addLines, "we added lines to ensure benchmark labels STRESS, GOOD and GREAT are all present");
//bn(14);

//trn("grh line after  new line with new lmar   numlines - 1");
//strcpy(mytstbuf6, Grh_body_BIG + Num_lines_in_grh_body    - 1     * (SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE + 1) );
//ksn(mytstbuf6);
//kin(Num_lines_in_grh_body );


    if (strstr(gbl_lastBenchmarkLabel, "GREAT-") != NULL) {
      // add one blank sky line above GREAT-
//trn(" add one blank sky line above GREAT-");
      sprintf( Grh_body_BIG + Num_lines_in_grh_body  * (SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE + 1), "%s%s", "       ", my184SharpsNEW);
      Num_lines_in_grh_body = Num_lines_in_grh_body + 1 ;
      break;
    }

  } while (1); // FILL TO GREAT


  //
  // STEP 2. add sky lines and missing benchmark labels until ALL of  "STRESS-"  "GOOD-"  "GREAT-" are put in
//ksn("END  STEP 2  STEP 2  STEP 2  STEP 2  STEP 2  STEP 2  ");

} // NOT ALL benchmark labels are there



  // log what we have here
//char mylogbuf33[256];
//int  mylogidx33;
//  for (mylogidx33 = 0;  mylogidx33 <= Num_lines_in_grh_body  ; mylogidx33++)      /* iprt is num lines in grh body */
//  {
//    strcpy(mylogbuf33, Grh_body_BIG + mylogidx33 * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
//ki(mylogidx33);ksn(mylogbuf33);
//  }
//trn("outside idx33 loop at the end");
//ki(mylogidx33);ksn(mylogbuf33);
//



//trn("tstix if the first line (top line)  has great");
  int tstix; tstix = gbl_numBodyLinesToProcess - 1;   
  char tstixbuf[256];
  strcpy(tstixbuf, Grh_body_BIG + tstix * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
//kin(tstix);
//ksn(tstixbuf);
  if(strstr(tstixbuf, "GREAT") != NULL) {
    // here the top line (last line = idx = gbl_numBodyLinesToProcess - 1) has GREAT
//trn(" add one blank sky line2above GREAT-");
      sprintf( Grh_body_BIG + Num_lines_in_grh_body  * (SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE + 1), "%s%s", "       ", my184SharpsNEW);
      Num_lines_in_grh_body = Num_lines_in_grh_body + 1 ;
      gbl_numBodyLinesToProcess = Num_lines_in_grh_body;
  }


  //
  // new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW
  // new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW new PLAN for NEW NEW
// for newPlanBenchmarkLabels()

} // end of newPlanBenchmarkLabels()



          //    //
          //      /* --------------- "/Users/xxx/_PC/usr/apple/_c/_wrk/futdefs.h" -------------- */

  // only used one might be SUBSCRIPT_FOR_HIGH_STRESS_LEVEL 3   
          //      /* 128:#define SUBSCRIPT_FOR_VLO_STRESS_LEVEL 6    * Stress_val[6] = vlo- "great"*/
          //      /* 129:#define SUBSCRIPT_FOR_LO_STRESS_LEVEL 5     * Stress_val[5] = lo- "good" */
          //      /* 130:#define SUBSCRIPT_FOR_HIGH_STRESS_LEVEL 3   * Stress_val[3] = hi-"stress" */
          //      /* 131:#define SUBSCRIPT_FOR_VHIGH_STRESS_LEVEL 2  * Stress_val[2] = hi-"OMG" */

          //        //
          //        //    futdoc.h
          //        //    char *Stress_name[NUM_STRESS_LEVELS] = {
          //        //      "       ",
          //        //      "   OMG-",
          //        //      "       ",
          //        //      "STRESS-",
          //        //      "       ",
          //        //      "  GOOD-",
          //        //      "       ",
          //        //      " GREAT-",
          //        //    };
          //        //
          //      //    #define SIZE_EPH_GRH_INCREMENT 6  /* 1 '*' for every 6 Grhdata score nums */
          //      //
          //      // gbl_numLinesFillToGREAT = (Stress_val[SUBSCRIPT_FOR_VLO_STRESS_LEVEL]  -  Grh_bot ) / SIZE_EPH_GRH_INCREMENT; 
          //      //
          //      /* --------------- "/Users/xxx/_PC/usr/apple/_c/_wrk/futdoc.h" -------------- */
          //      /* 223:int Stress_val[NUM_STRESS_LEVELS] = {304,250,196,142, 88,   34,-20,-74};   */
          //      /*                                                   32  23,        5,            */
          //      /*                                                  omg str,neu, good, -20=great  */
          //      //
          // e.g.       this_line = top - (*p_ln_ctr-1) * SIZE_EPH_GRH_INCREMENT;
          //            for (ilef=0; ilef <= NUM_STRESS_LEVELS-1; ilef++) 
          //              if (this_line >= Stress_val[ilef]) 
          //                if (this_line < Stress_val[ilef] + SIZE_EPH_GRH_INCREMENT) 
          //                  sprintf(&l_mar[0],"%s",Stress_name[ilef]);
          //

          //       -----------------------------------------------------------------
          //             int Stress_val[NUM_STRESS_LEVELS] = {304, 250, 196, 142,  88,  34, -20, -74};  
          //                                       index   =   0    1    2    3    4    5    6    7  
          //                              LABEL IN GRAPH   =       omg       str       goo       gre
          //                             COLORS IN GRAPH   =      cRe2      cRed cNeu cGre      cGr2
          //       -----------------------------------------------------------------
          //
          //                    _NUM_STRESS_LEVELS=[8]__
          //          for(int idxSV = 0;  idxSV < NUM_STRESS_LEVELS; idxSV++) 
          //          strcpy(nameSV,  Stress_name[idxSV]);                    ---------
          //          valSV         = Stress_val[idxSV] ;                       color
          //                    _idxSV=[0]___nameSV=[       ]___valSV=[304]__ ---------
          //                    _idxSV=[1]___nameSV=[   OMG-]___valSV=[250]__   cRe2
          //                    _idxSV=[2]___nameSV=[       ]___valSV=[196]__
          //                    _idxSV=[3]___nameSV=[STRESS-]___valSV=[142]__   cRed
          //                    _idxSV=[4]___nameSV=[       ]___valSV=[ 88]__
          //                    _idxSV=[5]___nameSV=[  GOOD-]___valSV=[ 34]__   cGre
          //                    _idxSV=[6]___nameSV=[       ]___valSV=[-20]__
          //                    _idxSV=[7]___nameSV=[ GREAT-]___valSV=[-74]__   cGr2
          //       --------------------------------------------------------------------
          //
void missingSTRESSline(void) // edge case (like Kim jong Un -2016) where entire graph is below the stress line
{
trn("\nin  function missingSTRESSline()\n");
//kin(Num_lines_in_grh_body );
//kin(gbl_numBodyLinesToProcess);  
//kin(gbl_topStarVal);

//trn("return\n"); return;

// for test   show all Stress_val s
//kin(NUM_STRESS_LEVELS);
//int valSV;
//char nameSV[16];
//for(int idxSV = 0;  idxSV < NUM_STRESS_LEVELS; idxSV++) {
//valSV = Stress_val[idxSV] ;
//strcpy(nameSV,  Stress_name[idxSV]);
//ki(idxSV);ks(nameSV);kin(valSV);
//}
// for test   show all Stress_val s



  char MSbuf[256];   // MS = Missing Stress line
  int  MS17ctr;
  int  MSdoing17ctr;        
  int  MSlinVal;
  char MSlastLABEL[16];
  char MSfirst7chars[16];
  char MS184Sharps[1024]; sfill(MS184Sharps, 184, '#'); 

  sfill(MSfirst7chars, 12 , '\0');  /* line size without left margin */

  MS17ctr      = 0;      // init
  MSdoing17ctr = 0;      // init
  MSlinVal     = -9999;  // init

  // MS reading EXISTING lines    in STRESS to GREAT direction
//trn("\nMS reading EXISTING lines    in STRESS to GREAT direction -  put labels in existing lines");
  for (int MSidx = 0;  MSidx < gbl_numBodyLinesToProcess ;  MSidx = MSidx + 1 )      // MS read in STRESS to GREAT direction
  {
    strcpy(MSbuf, Grh_body_BIG + MSidx * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
    sfromto(MSfirst7chars, Grh_body_BIG + MSidx * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1),  1, 7);



    MSlinVal = gbl_topStarVal  +  ( (gbl_numBodyLinesToProcess - MSidx - 1) * SIZE_EPH_GRH_INCREMENT ) ;  // SIZE_EPH_GRH_INCREMENT = 6
//ki(MSidx);ki(MSlinVal);ks(MSfirst7chars);ksn(MSbuf);



          //       -----------------------------------------------------------------
          //             int Stress_val[NUM_STRESS_LEVELS] = {304, 250, 196, 142,  88,  34, -20, -74};  
          //                                       index   =   0    1    2    3    4    5    6    7  
          //                              LABEL IN GRAPH   =       omg       str       goo       gre
          //                             COLORS IN GRAPH   =      cRe2      cRed cNeu cGre      cGr2
          //       -----------------------------------------------------------------
      for (int iSL=0; iSL <= NUM_STRESS_LEVELS-1; iSL++) {   // SL = Stress Level for benchmark label
        if (MSlinVal >= Stress_val[iSL]) {
          if (MSlinVal < Stress_val[iSL] + SIZE_EPH_GRH_INCREMENT) {

//trn("have read a line MAYBE deserving a Stress_name[]");
//trn("stress level benchmark label fits the MSMSlinVal of this line");
            strcpy(MSfirst7chars, Stress_name[iSL] );    // left margin with benchmark label
//ksn(MSfirst7chars);
 
            if ( sall( MSfirst7chars, " ") == 0 )    // 0 false = means str IS NOT all spaces
            {
//char mytstbuf7[256];
////trn("grh line before new lmar");
//strcpy(mytstbuf7, Grh_body_BIG + MSidx * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
//ksn(mytstbuf7);
              memcpy( Grh_body_BIG + MSidx * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1), MSfirst7chars, 7);
//trn("grh line after  new lmar");
//strcpy(mytstbuf7, Grh_body_BIG + MSidx * (SIZE_GRH_LEFT_MARGIN+SIZE_BIG_EPH_GRH_LINE+1));
//ksn(mytstbuf7);
            }


          } else {
            // here the fist 7 chars do NOT match a MSlinVal for a stress level benchmark label
            strcpy(MSfirst7chars, "       ");              // left margin with 7 spaces
          }
        } // find which stress level benchmark label fits the MSlinVal of this line
      } // for each stress level
     
//ki(MSidx);ki(MSlinVal);ks(MSfirst7chars);ksn(MSbuf);

  } // MS reading EXISTING lines    in STRESS to GREAT direction

//trn("FINISHED    MS reading EXISTING lines    in STRESS to GREAT direction -  put labels in existing lines\n");

//trn("\nMS ADDING lines    in STRESS to GREAT direction  +  putting labels in until GREAT has been added");
//kin(MSlinVal);ksn(MSbuf);

  for ( ; ; )   {
    MSlinVal = MSlinVal - SIZE_EPH_GRH_INCREMENT ;  // "-"  for going stress to great direction
//tr("NEW add fill 184sharps");kin(Num_lines_in_grh_body);



      strcpy(MSfirst7chars, "       "        );    // DEFAULT left margin with benchmark label
      for (int iMS=0; iMS <= NUM_STRESS_LEVELS-1; iMS++) {   // SL = Stress Level for benchmark label
        if (    MSlinVal >= Stress_val[iMS]
            &&  MSlinVal <  Stress_val[iMS] + SIZE_EPH_GRH_INCREMENT) {
//trn("have read a line MAYBE deserving a Stress_name[]");
//trn("stress level benchmark label fits the MSMSlinVal of this line");
            strcpy(MSfirst7chars, Stress_name[iMS] );    // left margin with benchmark label
        }
      }
//ksn(MSfirst7chars);

      // ---------------------------------------------------------------------------------------------------------------------------------------
      sprintf( Grh_body_BIG + Num_lines_in_grh_body  * (SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE + 1), "%s%s", MSfirst7chars,  MS184Sharps);
      Num_lines_in_grh_body = Num_lines_in_grh_body + 1 ;
      // ---------------------------------------------------------------------------------------------------------------------------------------

//ki(MSlinVal);ks(MSfirst7chars);trn("  ALL SKY -> 184 SHARPS");

    if (strstr(MSfirst7chars, "GREAT") != NULL) {
//trn("MS - ADDED GREAT !");
      // here we have added the GREAT line, so add an all-sky line above it
      // ---------------------------------------------------------------------------------------------------------------------------------------
      sprintf( Grh_body_BIG + Num_lines_in_grh_body  * (SIZE_GRH_LEFT_MARGIN + SIZE_BIG_EPH_GRH_LINE + 1), "%s%s", "       ",      MS184Sharps);
      Num_lines_in_grh_body = Num_lines_in_grh_body + 1 ;
      // ---------------------------------------------------------------------------------------------------------------------------------------
      break;
    }
  }

//




//trn("FINISHED   MS ADDING lines    in STRESS to GREAT direction  +  putting labels in\n");




//trn("END function missingSTRESSline()\n");
} // end of  missingSTRESSline()   // edge case (like Kim jong Un -2106) where entire graph is below the stress line





// end of futdoc.c

