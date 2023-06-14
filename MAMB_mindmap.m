// MAMB_mindmap.m 

//
// ---------------------------------------------------------------------------------------------------------
// MIND MAP       All Report Menu Screens     (table reports are RPT1         and          RPT2) 
// ---------------------------------------------------------------------------------------------------------
//  on home     22 RPTS come from report        report param     13 home      7 RPTs come  16 level2        
// --screen--   ----menu descriptions--------   --selection--    -RPTs------  from data--  -RPTs------       
//          
// tap person  >                                                                           MENU homp* 
//              MENU homp*
//              -----------------------------
//              Calendar Year ...             > select year    > RPT -hompcy                            LEAF
//              Personality                   >                  RPT -homppe                            LEAF
//              Compatibility Paired with ... > select person2 > RPT -hompco                            LEAF
//              Best Match for x in Group ... > select group   > RPT1-hompbm, tap pair   > MENU pbm* 
//              What Color is the Day? ...    > select day     > RPT -hompwc                            LEAF
//          
//                  MENU pbm*
//                  -------------------------
//                  Compatibility Potential   >                                            RPT =pbmco   LEAF  
//                  .
//                  select perA Personality   >                                            RPT =pbm1pe  LEAF
//                  select perB Personality   >                                            RPT =pbm2pe  LEAF
//                  .
//                  select perB's Best Match  >                                            RPT2=pbm2bm  LEAF
//          
// tap group   >                                                                           MENU homg* 
//              MENU homg*
//              -----------------------------
<.>
//              Best Match in Group           >                  RPT1-homgbm, tap pair   > MENU gbm* 
<.>
//              .
//              Most Assertive Person         >                  RPT1-homgma, tap person > RPT =gmappe  LEAF
//              Most Emotional                >                  RPT1-homgme, tap person > RPT =gmeppe  LEAF
//              Most Restless                 >                  RPT1-homgmr, tap person > RPT =gmrppe  LEAF
//              Most Passionate               >                  RPT1-homgmp, tap person > RPT =gmpppe  LEAF
//              Most Down-to-earth            >                  RPT1-homgmd, tap person > RPT =gmdppe  LEAF
//              .
//              Best Year ...                 > select year    > RPT1-homgby, tap person > RPT =gbypcy  LEAF
//              Best Day ...                  > select day     > RPT1-homgbd, tap person > RPT =gbdpwc  LEAF
//          
//                  MENU gbm*
//                  -------------------------
//                  Compatibility Potential   >                                            RPT =gbmco   LEAF 
//                  .
//                  select perA Personality   >                                            RPT =gbm1pe  LEAF
//                  select perB Personality   >                                            RPT =gbm2pe  LEAF
//                  .
//                  select perA's Best Match  >                                            RPT2=gbm1bm  LEAF
//                  select perB's Best Match  >                                            RPT2=gbm2bm  LEAF
// ---------------------------------------------------------------------------------------------------------

    =========================================================
    report DIV      gbls_routeToHere
    =========================================================
    pDIV_menu       pHOME_menu
    pDIV_rpts       pHOME_menu_caly
    pDIV_tlgr       pHOME_menu_piky_tlgr
    pDIV_rpts       pHOME_menu_piky_tlgr_caly
    pDIV_tlst       pHOME_menu_tlst
    pDIV_rpts       pHOME_menu_tlst_caly
    pDIV_tend       pHOME_menu_tend
    pDIV_rpts       pHOME_menu_pers
    pDIV_rpts       pHOME_menu_pikp_comp
    pDIV_bmpe       pHOME_menu_pikg_bmpe

        pDIV_menu2      pHOME_menu_bmpe_menu2
        pDIV_rpts       pHOME_menu_bmpe_menu2_comp
        pDIV_rpts       pHOME_menu_bmpe_menu2_pers  (1 + 2)
        pDIV_bmpe2      pHOME_menu_bmpe_menu2_bmpe 


    gDIV_menu       gHOME_menu
    gDIV_bmgr       gHOME_menu_bmgr
    gDIV_rank       gHOME_menu_memo
                    gHOME_menu_mass
                    gHOME_menu_mpas
                    gHOME_menu_mres
                    gHOME_menu_mdow
                    gHOME_menu_bday
                    gHOME_menu_byer
    pDIV_rpts       gHOME_menu_byer_caly

        gDIV_menu2      gHOME_menu_bmgr_menu2
        pDIV_rpts       gHOME_menu_bmgr_menu2_comp
        pDIV_rpts       gHOME_menu_bmgr_menu2_pers  (1 + 2)
        gDIV_bmpe       gHOME_menu_bmgr_menu2_bmpe  (1 + 2)
    =========================================================

if (gbls_nav_initiator == 'CLICK on pair in #pDIV_bmpe')   //  CLICK on line in grpone rpt
{
smup_log('gbls_routeToHere homep  =[' + gbls_routeToHere     + ']');
  gbls_navigation_direction   = 'away from home';
  if (    gbls_routeToHere   == 'pHOME_menu_bmpe' )  {
smup_log('phome yes');
    gbls_routeTo_newScreen    = 'pHOME_menu_bmpe_menu2';
    gbls_DIV_moreCloseTo_home = '#pDIV_bmpe';
    gbls_DIV_fartherFrom_home = '#pDIV_menu2';
  }
  navToNewScreen();
  return;
}


<.>
  EXAMPLE
if (gbls_nav_initiator == 'CLICK on pe report')       // CLICK on REPORT in pMENU   pe
{
  gbls_navigation_direction   = 'away from home';
  if (    gbls_routeToHere   == 'pHOME_menu' )  {  
    gbls_routeTo_newScreen    = 'pHOME_menu_pers';
    gbls_DIV_moreCloseTo_home = '#pDIV_menu';
    gbls_DIV_fartherFrom_home = '#pDIV_rpts';
  }
  navToNewScreen();
  return;
}
<.>



    // -------------------------------------------------------------------------------------------------------------------------
    // MAMB09viewTBLRPTs_1_TableViewController.m 
    // -------------------------------------------------------------------------------------------------------------------------
    //     - displays 9 RPTs  hompbm,homgbm, homgma,homgme,homgmr,homgmp,homgmd homgby,homgbd
    //
    //     - goes to 16 RPTs  from hompbm ==>  pbmco,pbm1pe,pbm2pe,       pbm2bm
    //     - goes to 16 RPTs  from homgbm ==>  gbmco,gbm1pe,gbm2pe,gbm1bm,gbm2bm
    //     - goes to 16 RPTs  from homgma ==>  gmappe
    //     - goes to 16 RPTs  from homgme ==>  gmeppe
    //     - goes to 16 RPTs  from homgmr ==>  gmrppe
    //     - goes to 16 RPTs  from homgmp ==>  gmpppe
    //     - goes to 16 RPTs  from homgmd ==>  gmdppe
    //     - goes to 16 RPTs  from homgby ==>  gbypcy
    //     - goes to 16 RPTs  from homgbd ==>  gbdpwc
    //
    // NOTE that gbl_currentMenuPlusReportCode changes when the user goes to a report from any of these 9 RPTs 
    //      so, in viewWillAppear(), when the user returns, we have to re-set  gbl_currentMenuPlusReportCode  (check it out)
    //
    //      this is 16+9=25 reports   FYI, the other 4 reports are  hompcy,homppe,hompco,hompwc
    // -------------------------------------------------------------------------------------------------------------------------



// FYI   mind map
//
// 21 rpts need  a person selection  (p)
//  8 rpts need no person selection  (g  homg*)
//---
// 29
//
//    -----------------------------------------------------------
//    29 report navigations
//    -----------------------------------------------------------
//    13 home rpts (on left)
//        16 level2 (one tab to right)    13 + 16 = 29
//                 WHERE DISPLAYED
//    -----------------------------------------------------------
//       "now" refers to pe and co going to TBLRPT
//    -----------------------------------------------------------
//    hompcy       ViewHTML
//    homppe       ViewHTML     now TBLRPTs_1
//    hompco       ViewHTML     now TBLRPTs_1
//    hompbm       TBLRPTs_1
//        pbmco    ViewHTML     now TBLRPTs_2
//        pbm1pe   ViewHTML     now TBLRPTs_2
//        pbm2pe   ViewHTML     now TBLRPTs_2
//        pbm2bm   TBLRPTs_2
//    hompwc       ViewHTML
//
//    homgbm       TBLRPTs_1
//        gbmco    ViewHTML     now TBLRPTs_2
//        gbm1pe   ViewHTML     now TBLRPTs_2
//        gbm2pe   ViewHTML     now TBLRPTs_2
//        gbm1bm   TBLRPTs_2
//        gbm2bm   TBLRPTs_2
//    homgma       TBLRPTs_1
//        gmappe   ViewHTML     now TBLRPTs_2
//    homgme       TBLRPTs_1
//        gmeppe   ViewHTML     now TBLRPTs_2
//    homgmr       TBLRPTs_1
//        gmrppe   ViewHTML     now TBLRPTs_2
//    homgmp       TBLRPTs_1
//        gmpppe   ViewHTML     now TBLRPTs_2
//    homgmd       TBLRPTs_1
//        gmdppe   ViewHTML     now TBLRPTs_2
//    homgby       TBLRPTs_1
//        gbypcy   ViewHTML 
//    homgbd       TBLRPTs_1
//        gbdpwc   ViewHTML
//
//    -----------------------------------------------------------
//    29 report destinations
//    -----------------------------------------------------------
//                 ViewHTML  displays 17 report destinations   now  4
//                 TBLRPTs_1 displays  9 report destinations   now 11
//                 TBLRPTs_2 displays  3 report destinations   now 14
//                                   ---                          ---
//                                    29                           29
//    -----------------------------------------------------------
//
//    -------------------------
//    8 report types
//    -------------------------
//         cy      2 rpts   p
//         pe     10 rpts   p
//         co      3 rpts   p
//         grpone  4 rpts   p
//         wc      2 rpts   p
//         grpall  1 rpts   g  homg*
//         most    5 rpts   g  homg*
//         best    2 rpts   g  homg*
//               ---
//                29 rpts
//               ---
//    -------------------------
//<.>
//  hompcy
//  homppe
//  hompco
//  hompbm
//  hompwc
//
//  pbmco
//  pbm1pe
//  pbm2pe
//  pbm2bm
//
//  homgbm
//
//  homgma
//  homgme
//  homgmr
//  homgmp
//  homgmd
//
//  homgby
//  homgbd
//
//  gmappe
//  gmeppe
//  gmrppe
//  gmpppe
//  gmeppe
//  gbypcy
//  gbdpwc
//
//  gbmco
//  gbm1pe
//  gbm2pe
//  gbm1bm
//  gbm2bm
//<.>
//


// 
// -----------------------------------------------------------------------------------------------
//             MAMB Navigation Summary   ">" is a tap of a data item or report
// -----------------------------------------------------------------------------------------------
//                                                          select
// num    ----- home ------                                 report   --------- report ----------- 
// taps  segment   tap data  ------- select report ------   param    ------ ViewController ------
// -----------------------------------------------------------------------------------------------
//  4    >person  >a person  >hompcy  calendar year         >year    viewHTMLViewController
//  3    >person  >a person  >homppe  personality                    viewHTMLViewController
//  4    >person  >a person  >hompco  compat paired with    >person  viewHTMLViewController
//  4    >person  >a person  >hompwc  what color            >date    viewHTMLViewController
//  4    >person  >a person  >hompbm  my best match in grp  >group   viewTBLRPTs_1_ViewController
//  3    >group   >a group   >homgbm  best match                     viewTBLRPTs_1_ViewController
//  3    >group   >a group   >6 most  6 trait reports                viewTBLRPTs_1_ViewController
//  4    >group   >a group   >2 best  best year or day      >yr/dy   viewTBLRPTs_1_ViewController
// 
// -----------------------------------------------------------------------------------------------
//                                                  
// num    ----- home------    -------- 1st report --------   -------- 2nd report --------   
// taps   entity  tap data    -- select report -  tap data   ------ select report --------
// -----------------------------------------------------------------------------------------------
//  5    >group   >a group   >homgbm  best match  >a pair   >hompbm  my best match in grp
//                                    |                              |
//                                    |                               viewTBLRPTs_2_ViewController
//                                    |
//                                     viewTBLRPTs_1_ViewController      
// -----------------------------------------------------------------------------------------------
// 
// ===============================================================================================
// From the home screen, there is a maximum of 2 other screens to get to any of the 14 reports
//   (home  >  maximum 2 other screens  >  report).
// From the home screen, there is a maximum of 5 taps/selections to get to any of the 14 reports.
// ===============================================================================================
//




==============
    //     field 2  last report selected for this Group:
    //              ="gbm"  for   "Best Match"
    //              ="gma"  for   "Most Assertive Person"
    //              ="gme"  for   "Most Emotional"
    //              ="gmr"  for   "Most Restless"
    //              ="gmp"  for   "Most Passionate"
    //              ="gmd"  for   "Most Down-to-earth"
    //              ="gmu"  for   "Most Ups and Downs"
    //              ="gby"  for   "Best Year ..."
    //              ="gbd"  for   "Best Day ..."

==============

    //     field 2  last report selected for this Person:
    //              ="pbm"  for   "Best Match"
    //              ="pcy"  for   "Calendar Year ...",
    //              ="ppe"  for   "Personality",
    //              ="pco"  for   "Compatibility Paired with ...",
    //              ="pbg"  for   "My Best Match in Group ...",
    //              ="pwc"  for   "What color is today? ...",
==============



    gbl_mambReports = // all reports in all report selection menus, "homp*" "homg*" "gbm*" or "pbm*" 
    @[  // field 1 = menu code + rptcode, field 2 = menu text
    // REPORTS from home PERSON segment
        @"homp|",     // these empty ones are spacers on the tableview
        @"hompcy|Calendar Year ...",             // from home in "People" > tap on a Person  - display homp*
        @"homppe|Personality",
        @"hompco|Compatibility Paired with ...",
        @"homp|",
        @"hompbm|My Best Match in Group ...",           // in pbm, tap Pair   > direct pco for pre-selected pair (now 2 lines)
        @"homp|",
        @"hompwc|What Color is Today? ...",
    // REPORTS from home GROUP  segment
        @"homg|",     // these empty ones are spacers
        @"homgbm|Best Match",           // from home in "Group"  > tap on a Group    - display homg*
        @"homg|",
        @"homgma|Most Assertive Person",                // in gma, tap Person > direct ppe for pre-selected person
        @"homgme|Most Emotional",                       // in gme, tap Person > direct ppe for pre-selected person
        @"homgmr|Most Restless",                        // in gmr, tap Person > direct ppe for pre-selected person
        @"homgmp|Most Passionate",                      // in gmp, tap Person > direct ppe for pre-selected person
        @"homgmd|Most Down-to-earth",                   // in gmd, tap Person > direct ppe for pre-selected person
        //   @"homgmu|Most Ups and Downs",                   // in gmu, tap Person > direct ppe for pre-selected person
        @"homg|",
        @"homgby|Best Year ...",                        // in gby, tap Person > direct pcy for pre-selected year
        @"homgbd|Best Day ...",                         // in gbd, tap Person > direct pwc for pre-selected date
    // REPORTS from homgbm  "Best Match" report
        @"gbm|",     // these empty ones are spacers on the tableview
        @"gbmco|Compatibility Potential",       // from homgbm > tap on a pair  - display gbm*
        @"gbm|",            
        @"gbm1pe|<per1> Personality",
        @"gbm2pe|<per2> Personality",
        @"gbm|",
        @"gbm1bm|<per1>'s Best Match",                 // in gbm1bm, tap Pair> direct pco for pre-selected pair
        @"gbm2bm|<per2>'s Best Match",                 // in gbm2bm, tap Pair> direct pco for pre-selected pair
    // REPORTS from hompbm  "My Best Match in Group ..." report
        @"pbm|",     // these empty ones are spacers on the tableview
        @"pbmco|Compatibility Potential",       // from hompbm > tap on a pair  - display pbm*
        @"pbm|",            
        @"pbm1pe|<per1> Personality",
        @"pbm2pe|<per2> Personality",
        @"pbm|",            
        @"pbm2bm|<per2>'s Best Match",                 // in 21bm, tap Pair> direct pco for pre-selected pair
    ];
    //




// MAMB_mindmap.m
