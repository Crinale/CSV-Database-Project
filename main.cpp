#include <iostream> 
#include <pqxx/pqxx>  
#include <fstream> 


using namespace std; 
using namespace pqxx; 
 
int main(int argc, char* argv[]) { 
  string sql1,sql2, sql3,sql4,sql5,sql6,sql7; 
  string sql;

  int flag = 0;


  // open DAY csv and declares the necessary string variables 
  ifstream file1 ("DAYV2PUB.CSV");
  string   HOUSEID,   PERSONID,   FRSTHM,     OUTOFTWN,   ONTD_P1,    ONTD_P2,    ONTD_P3,    ONTD_P4,
           ONTD_P5,   ONTD_P6,    ONTD_P7,    ONTD_P8,    ONTD_P9,    ONTD_P10,   ONTD_P11,   ONTD_P12,
           ONTD_P13,  ONTD_P14,   ONTD_P15,   TDCASEID,   HH_HISP,    HH_RACE,    DRIVER,     R_SEX, 
           WORKER,    DRVRCNT,    HHFAMINC,   HHSIZE,     HHVEHCNT,   NUMADLT,    FLAG100,    LIF_CYC,    
           TRIPPURP,  AWAYHOME,   CDIVMSAR,   CENSUS_D,   CENSUS_R,   DROP_PRK,   DRVR_FLG,   EDUC,       
           ENDTIME,   HH_ONTD,    HHMEMDRV,   HHRESP,     HHSTATE,    HHSTFIPS,   INTSTATE,   MSACAT,     
           MSASIZE,   NONHHCNT,   NUMONTRP,   PAYTOLL,    PRMACT,     PROXY,      PSGR_FLG,   R_AGE,      
           RAIL,      STRTTIME,   TRACC1,     TRACC2,     TRACC3,     TRACC4,     TRACC5,     TRACCTM,    
           TRAVDAY,   TREGR1,     TREGR2,     TREGR3,     TREGR4,     TREGR5,     TREGRTM,    TRPACCMP,   
           TRPHHACC,  TRPHHVEH,   TRPTRANS,   TRVL_MIN,   TRVLCMIN,   TRWAITTM,   URBAN,      URBANSIZE,  
           URBRUR,    USEINTST,   USEPUBTR,   VEHID,      WHODROVE,   WHYFROM,    WHYTO,      WHYTRP1S,  
           WRKCOUNT,  DWELTIME,   WHYTRP90,   TDTRPNUM,   TDWKND,     TDAYDATE,   TRPMILES,   WTTRDFIN,   
           VMT_MILE,  PUBTRANS,   HOMEOWN,    HOMETYPE,   HBHUR,      HTRESDN,    HTHTNRNT,   HTPPOPDN,   
           HTEEMPDN,  HBRESDN,    HBHTNRNT,   HBPPOPDN,   GASPRICE,   VEHTYPE,    HH_CBSA,    HHC_MSA;

//opens VEH cvs and declares the necessary string variables            
ifstream file2 ("VEHV2PUB.CSV");
string /*HOUSEID,*/  WTHHFIN, /*VEHID,*/ /*DRVRCNT,*/ /*HHFAMINC,*/  /*HHSIZE,*/  /*HHVEHCNT,*/  /*NUMADLT,*/ /*FLAG100,*/ /*CDIVMSAR,*/  /*CENSUS_D,*/  /*CENSUS_R,*/  /*HHSTATE,*/ /*HHSTFIPS,*/  HYBRID,  MAKECODE,  MODLCODE,  /*MSACAT,*/  /*MSASIZE,*/ OD_READ, /*RAIL,*/  /*TRAVDAY,*/ /*URBAN,*/ /*URBANSIZE,*/ /*URBRUR,*/  VEHCOMM, VEHOWNMO,
       VEHYEAR, WHOMAIN, /*WRKCOUNT,*/  /*TDAYDATE,*/  VEHAGE,  /*PERSONID,*/  /*HH_HISP,*/ /*HH_RACE,*/ /*HOMEOWN,*/ /*HOMETYPE,*/  /*LIF_CYC,*/ ANNMILES,  /*HBHUR,*/ /*HTRESDN,*/ /*HTHTNRNT,*/  /*HTPPOPDN,*/  /*HTEEMPDN,*/  /*HBRESDN,*/ /*HBHTNRNT,*/  /*HBPPOPDN,*/  BEST_FLG,  BESTMILE,  BEST_EDT,  BEST_OUT,  FUELTYPE,  
       GSYRGAL, GSCOST,  GSTOTCST,  EPATMPG, EPATMPGF,  EIADMPG /*VEHTYPE,*/ /*HH_CBSA,*/ /*HHC_MSA*/;

//opens PER cvs and declares the necessary string variables            
ifstream file3 ("PERV2PUB.CSV");
string  /*HOUSEID,*/  /*PERSONID,*/  /*VARSTRAT,*/  WTPERFIN,  SFWGT, /*HH_HISP,*/ /*HH_RACE,*/ /*DRVRCNT,*/ /*HHFAMINC,*/  /*HHSIZE,*/  /*HHVEHCNT,*/  /*NUMADLT,*/ /*WRKCOUNT,*/  /*FLAG100,*/ /*LIF_CYC,*/ CNTTDTR, BORNINUS,  CARRODE, /*CDIVMSAR,*/  /*CENSUS_D,*/  
        /*CENSUS_R,*/  CONDNIGH,  CONDPUB, CONDRIDE,  CONDRIVE,  CONDSPEC,  CONDTAX, CONDTRAV,  DELIVER, DIARY, DISTTOSC,  /*DRIVER,*/  DTACDT,  DTCONJ,  DTCOST,  DTRAGE,  DTRAN,  DTWALK,  /*EDUC,*/  EVERDROV,  
        FLEXTIME,  FMSCSIZE,  /*FRSTHM,*/  FXDWKPL, GCDWORK, GRADE, GT1JBLWK,  /*HHRESP,*/  /*HHSTATE,*/ /*HHSTFIPS,*/  ISSUE, OCCAT, LSTTRDAY,  MCUSED,  MEDCOND, MEDCOND6,  MOROFTEN,  /*MSACAT,*/  /*MSASIZE,*/ NBIKETRP,  
        NWALKTRP,  OUTCNTRY,  /*OUTOFTWN,*/  PAYPROF, /*PRMACT,*/  /*PROXY,*/ PTUSED,  PURCHASE,  /*R_AGE,*/ R_RELAT, /*R_SEX,*/ /*RAIL,*/  SAMEPLC, SCHCARE, SCHCRIM, SCHDIST, SCHSPD,  SCHTRAF, SCHTRN1, SCHTRN2, SCHTYP,  
        SCHWTHR, SELF_EMP,  TIMETOSC,  TIMETOWK,  TOSCSIZE,  /*TRAVDAY,*/ /*URBAN,*/ /*URBANSIZE,*/ /*URBRUR,*/  /*USEINTST,*/  /*USEPUBTR,*/  WEBUSE,  WKFMHMXX,  WKFTPT,  WKRMHM,  WKSTFIPS,  /*WORKER,*/  WRKTIME, WRKTRANS,  
        YEARMILE,  YRMLCAP, YRTOUS,  DISTTOWK  /*TDAYDATE,*/  /*HOMEOWN,*/ /*HOMETYPE,*/  /*HBHUR,*/ /*HTRESDN,*/ /*HTHTNRNT,*/  /*HTPPOPDN,*/  /*HTEEMPDN,*/  /*HBRESDN,*/ /*HBHTNRNT,*/  /*HBPPOPDN,*/  /*HH_CBSA,*/ /*HHC_MSA*/;

//opens HH cvs and declares the necessary string variables            
ifstream file4 ("HHV2PUB.CSV");
string /*HOUSEID,*/ VARSTRAT,  /*WTHHFIN,*/ /*DRVRCNT,*/ /*CDIVMSAR,*/  /*CENSUS_D,*/  /*CENSUS_R,*/  /*HH_HISP,*/ /*HH_RACE,*/ /*HHFAMINC,*/  HHRELATD,  /*HHRESP,*/  /*HHSIZE,*/  /*HHSTATE,*/ /*HHSTFIPS,*/ /*HHVEHCNT,*/
          /*HOMEOWN,*/ /*HOMETYPE,*/  /*MSACAT,*/  /*MSASIZE,*/ /*NUMADLT,*/ /*RAIL,*/  RESP_CNT,  SCRESP,  /*TRAVDAY,*/ /*URBAN,*/ /*URBANSIZE,*/ /*URBRUR,*/  /*WRKCOUNT,*/  /*TDAYDATE,*/  /*FLAG100,*/ /*LIF_CYC,*/ CNTTDHH /*HBHUR,*/
          /*HTRESDN,*/ /*HTHTNRNT,*/  /*HTPPOPDN,*/  /*HTEEMPDN,*/  /*HBRESDN,*/ /*HBHTNRNT,*/  /*HBPPOPDN,*/  /*HH_CBSA,*/ /*HHC_MSA*/;


ifstream file5 ("EIA_CO2_Electric_2014.csv");
ifstream file6 ("EIA_CO2_Transportation_2014.csv");
ifstream file7 ("EIA_MkWh_2014.csv");
string MSN,  YYYYMM,  Value, Column_Order,  Description, Unit;



  try { 
    // Inorder to connect to the postgresql database, you need to create a database (testdb) and an user (dbuser). 
    connection C("dbname=YouAndI user=dbuser password=1"); 
    // connection C("dbname=company user=postgres password=1 hostaddr=127.0.0.1 port=5432"); 
    if (C.is_open()) { 
      cout << "Opened database successfully: " << C.dbname() << endl; 
    } else { 
      cout << "Can't open database" << endl; 
      return 1; 
    } 



   // Create table schema for day 
   //   Create SQL statement 
    sql1 = "CREATE TABLE day("  
     " HOUSEID        NUMERIC,  "  
     " PERSONID       NUMERIC,  "  
   //  " FRSTHM         NUMERIC,  " 
  //  " OUTOFTWN       NUMERIC,  " 
  //  " ONTD_P1        NUMERIC,  "  
  //  " ONTD_P2        NUMERIC,  " 
  //  " ONTD_P3        NUMERIC,  "  
  //  " ONTD_P4        NUMERIC,  "           
  //   " ONTD_P5        NUMERIC,  "           
  //   " ONTD_P6        NUMERIC,  "    
  //   " ONTD_P7        NUMERIC,  "    
  //   " ONTD_P8        NUMERIC,  "   
  //   " ONTD_P9        NUMERIC,  "
  //   " ONTD_P10       NUMERIC,  "
  //   " ONTD_P11       NUMERIC,  "
  //   " ONTD_P12       NUMERIC,  "
  //   " ONTD_P13       NUMERIC,  "
  //   " ONTD_P14       NUMERIC,  "
  //    " ONTD_P15       NUMERIC,  "
  //   " TDCASEID       NUMERIC,  "
  //   " HH_HISP        NUMERIC,  "
  //   " HH_RACE        NUMERIC,  "
   //  " DRIVER         NUMERIC,  "
  //   " R_SEX          NUMERIC,  "
  //   " WORKER         NUMERIC,  "
  //   " DRVRCNT        NUMERIC,  "
  //  " HHFAMINC       NUMERIC,  "
  //   " HHSIZE         NUMERIC,  "
  //  " HHVEHCNT       NUMERIC,  "
  //   " NUMADLT        NUMERIC,  "
  //   " FLAG100        NUMERIC,  "
  //   " LIF_CYC        NUMERIC,  "
  //   " TRIPPURP      VARCHAR(10), "
   //  " AWAYHOME       NUMERIC,  "
   //  " CDIVMSAR       NUMERIC,  "
   //  " CENSUS_D       NUMERIC,  "
   //  " CENSUS_R       NUMERIC,  "
   //  " DROP_PRK       NUMERIC,  "
   //  " DRVR_FLG       NUMERIC,  "
   //  " EDUC           NUMERIC,  "
  //   " ENDTIME        NUMERIC,  "
  //   " HH_ONTD        NUMERIC,  "
  //   " HHMEMDRV       NUMERIC,  "
   //  " HHRESP         NUMERIC,  "
  //   " HHSTATE        VARCHAR(10),  "
  //   " HHSTFIPS       NUMERIC,  "
  //   " INTSTATE       NUMERIC,  "
   //  " MSACAT         NUMERIC,  "
  //   " MSASIZE        NUMERIC,  "
  //   " NONHHCNT       NUMERIC,  "
  //   " NUMONTRP       NUMERIC,  "
  //   " PAYTOLL        NUMERIC,  "
  //   " PRMACT         NUMERIC,  "
  //   " PROXY          NUMERIC,  "
  //   " PSGR_FLG       NUMERIC,  "
 //    " R_AGE          NUMERIC,  "
 //    " RAIL           NUMERIC,  "
 //    " STRTTIME       NUMERIC,  "
 //    " TRACC1         NUMERIC,  "
 //    " TRACC2         NUMERIC,  "
 //    " TRACC3         NUMERIC,  "
 //    " TRACC4         NUMERIC,  "
 //    " TRACC5         NUMERIC,  "
  //   " TRACCTM        NUMERIC,  "
  //   " TRAVDAY        NUMERIC,  "
 //    " TREGR1         NUMERIC,  "
 //    " TREGR2         NUMERIC,  "
 //    " TREGR3         NUMERIC,  "
 //    " TREGR4         NUMERIC,  "
 //    " TREGR5         NUMERIC,  "
  //   " TREGRTM        NUMERIC,  "
  //   " TRPACCMP       NUMERIC,  "
  //   " TRPHHACC       NUMERIC,  "
  //   " TRPHHVEH       NUMERIC,  "
     " TRPTRANS       NUMERIC,  "
  //   " TRVL_MIN       NUMERIC,  "
  //   " TRVLCMIN       NUMERIC,  "
 //    " TRWAITTM       NUMERIC,  "
 //    " URBAN          NUMERIC,  "
 //    " URBANSIZE      NUMERIC,  "
 //   " URBRUR         NUMERIC,  "
 //    " USEINTST       NUMERIC,  "
  //   " USEPUBTR       NUMERIC,  "
     " VEHID          NUMERIC,  "
  //   " WHODROVE       NUMERIC,  "
  //   " WHYFROM        NUMERIC,  "
  //   " WHYTO          NUMERIC,  "
 //    " WHYTRP1S       NUMERIC,  "
 //    " WRKCOUNT       NUMERIC,  "
 //    " DWELTIME       NUMERIC,  "
  //   " WHYTRP90       NUMERIC,  "
  //   " TDTRPNUM       NUMERIC,  "
   //  " TDWKND         NUMERIC,  "
     " TDAYDATE       NUMERIC,  "
     " TRPMILES       NUMERIC,  "
  //   " WTTRDFIN       NUMERIC,  "
  //   " VMT_MILE       NUMERIC,  "
   //  " PUBTRANS       NUMERIC,  "
 //    " HOMEOWN        NUMERIC,  "
 //    " HOMETYPE       NUMERIC,  "
  //   " HBHUR          VARCHAR(10),  "
  //   " HTRESDN        NUMERIC,  "
  //   " HTHTNRNT       NUMERIC,  "
   //  " HTPPOPDN       NUMERIC,  "
   //  " HTEEMPDN       NUMERIC,  "
   //  " HBRESDN        NUMERIC,  "
   //  " HBHTNRNT       NUMERIC,  "
   //  " HBPPOPDN       NUMERIC,  "
   //  " GASPRICE       NUMERIC,  "
     " VEHTYPE        NUMERIC); ";

   //  " HH_CBSA        NUMERIC,  "
   //  " HHC_MSA        NUMERIC ); ";


    //  Create a transactional object. 
    work W1(C); 
       
     // Execute SQL query 
    W1.exec( sql1 ); 
    W1.commit(); 
    cout << "day Table created successfully" << endl; 


    // Create table schema for vehicale 
    sql2 = "CREATE TABLE vehicle("  
     " HOUSEID        NUMERIC, "
//     " WTHHFIN        NUMERIC, "     
//     " VEHID          NUMERIC, "   
//     " DRVRCNT        NUMERIC, "     
//     " HHFAMINC       NUMERIC, "     
//     " HHSIZE         NUMERIC, "   
//     " HHVEHCNT       NUMERIC, "     
//     " NUMADLT        NUMERIC, "     
//     " FLAG100        NUMERIC, "     
//     " CDIVMSAR       NUMERIC, "     
//     " CENSUS_D       NUMERIC, "     
//     " CENSUS_R       NUMERIC, "     
//     " HHSTATE        VARCHAR(10), "     
//     " HHSTFIPS       NUMERIC, "     
//     " HYBRID         NUMERIC, "   
//     " MAKECODE       NUMERIC, "     
//     " MODLCODE       NUMERIC, "     
//     " MSACAT         NUMERIC, "   
//     " MSASIZE        NUMERIC, "     
//     " OD_READ        NUMERIC, "     
//     " RAIL           NUMERIC, " 
//     " TRAVDAY        NUMERIC, "     
//     " URBAN          NUMERIC, "   
//     " URBANSIZE      NUMERIC, "       
//     " URBRUR         NUMERIC, "   
//     " VEHCOMM        NUMERIC, "     
//     " VEHOWNMO       NUMERIC, "     
//     " VEHYEAR        NUMERIC, "     
//     " WHOMAIN        NUMERIC, "     
//     " WRKCOUNT       NUMERIC, "     
//     " TDAYDATE       NUMERIC, "     
//     " VEHAGE         NUMERIC, "   
     " PERSONID       NUMERIC, "     
//     " HH_HISP        NUMERIC, "     
//     " HH_RACE        NUMERIC, "     
//     " HOMEOWN        NUMERIC, "     
//     " HOMETYPE       NUMERIC, "     
//     " LIF_CYC        NUMERIC, "     
//     " ANNMILES       NUMERIC, "     
//     " HBHUR          VARCHAR(10), "   
//     " HTRESDN        NUMERIC, "     
//     " HTHTNRNT       NUMERIC, "     
//     " HTPPOPDN       NUMERIC, "     
//     " HTEEMPDN       NUMERIC, "     
//     " HBRESDN        NUMERIC, "     
//     " HBHTNRNT       NUMERIC, "     
//     " HBPPOPDN       NUMERIC, "     
//     " BEST_FLG       NUMERIC, "     
//     " BESTMILE       NUMERIC, "     
//     " BEST_EDT       NUMERIC, "     
//     " BEST_OUT       NUMERIC, "     
//     " FUELTYPE       NUMERIC, "     
//     " GSYRGAL        NUMERIC, "     
//     " GSCOST         NUMERIC, "   
//     " GSTOTCST       NUMERIC, "     
     " EPATMPG        NUMERIC, "     
//     " EPATMPGF       NUMERIC, "     
     " EIADMPG        NUMERIC); " ;      
//     " VEHTYPE        NUMERIC, "     
//     " HH_CBSA        NUMERIC, "     
//     " HHC_MSA        NUMERIC); " ;    
        
    //  Create a transactional object. 
    work W2(C); 
       
     // Execute SQL query 
    W2.exec( sql2 ); 
    W2.commit(); 
    cout << "vehicle Table created successfully" << endl;            



    // Create table schema for person 
 sql3 = "CREATE TABLE person("  
      " HOUSEID         NUMERIC,  " 
      " PERSONID        NUMERIC);  ";       
//      " VARSTRAT        NUMERIC,  "       
//      " WTPERFIN        NUMERIC,  "       
//      " SFWGT           NUMERIC,  "     
//      " HH_HISP         NUMERIC,  "     
//      " HH_RACE         NUMERIC,  "     
//      " DRVRCNT         NUMERIC,  "     
//      " HHFAMINC        NUMERIC,  "       
//      " HHSIZE          NUMERIC,  "     
//      " HHVEHCNT        NUMERIC,  "       
//      " NUMADLT         NUMERIC,  "     
//      " WRKCOUNT        NUMERIC,  "       
//      " FLAG100         NUMERIC,  "     
//      " LIF_CYC         NUMERIC,  "     
//      " CNTTDTR         NUMERIC,  "     
//      " BORNINUS        NUMERIC,  "       
//      " CARRODE         NUMERIC,  "     
//      " CDIVMSAR        NUMERIC,  "       
//      " CENSUS_D        NUMERIC,  "       
//      " CENSUS_R        NUMERIC,  "       
//      " CONDNIGH        NUMERIC,  "       
//      " CONDPUB         NUMERIC,  "     
//      " CONDRIDE        NUMERIC,  "       
//      " CONDRIVE        NUMERIC,  "       
//      " CONDSPEC        NUMERIC,  "       
//      " CONDTAX         NUMERIC,  "     
//      " CONDTRAV        NUMERIC,  "       
//      " DELIVER         NUMERIC,  "     
//      " DIARY           NUMERIC,  "   
//      " DISTTOSC        NUMERIC,  "       
//      " DRIVER          NUMERIC,  "     
//      " DTACDT          NUMERIC,  "     
//      " DTCONJ          NUMERIC,  "     
//      " DTCOST          NUMERIC,  "     
//      " DTRAGE          NUMERIC,  "     
//      " DTRAN           NUMERIC,  "   
//      " DTWALK          NUMERIC,  "     
//      " EDUC            NUMERIC,  "   
//      " EVERDROV        NUMERIC,  "       
//      " FLEXTIME        NUMERIC,  "       
//      " FMSCSIZE        NUMERIC,  "       
//      " FRSTHM          NUMERIC,  "     
//      " FXDWKPL         NUMERIC,  "     
//      " GCDWORK         NUMERIC,  "     
//      " GRADE           NUMERIC,  "   
//      " GT1JBLWK        NUMERIC,  "       
//      " HHRESP          NUMERIC,  "     
//      " HHSTATE         VARCHAR(10),  "     
//      " HHSTFIPS        NUMERIC,  "       
//      " ISSUE           NUMERIC,  "   
//      " OCCAT           NUMERIC,  "   
//      " LSTTRDAY        NUMERIC,  "       
//      " MCUSED          NUMERIC,  "     
//      " MEDCOND         NUMERIC,  "     
//      " MEDCOND6        NUMERIC,  "       
//      " MOROFTEN        NUMERIC,  "       
//      " MSACAT          NUMERIC,  "     
//      " MSASIZE         NUMERIC,  "     
//      " NBIKETRP        NUMERIC,  "       
//      " NWALKTRP        NUMERIC,  "       
//      " OUTCNTRY        NUMERIC,  "       
//      " OUTOFTWN        NUMERIC,  "       
//      " PAYPROF         NUMERIC,  "     
//      " PRMACT          NUMERIC,  "     
//      " PROXY           NUMERIC,  "   
//      " PTUSED          NUMERIC,  "     
//      " PURCHASE        NUMERIC,  "       
//      " R_AGE           NUMERIC,  "   
//      " R_RELAT         NUMERIC,  "     
//      " R_SEX           NUMERIC,  "   
//      " RAIL            NUMERIC,  "   
//      " SAMEPLC         NUMERIC,  "     
//      " SCHCARE         NUMERIC,  "     
//      " SCHCRIM         NUMERIC,  "     
//      " SCHDIST         NUMERIC,  "     
//      " SCHSPD          NUMERIC,  "     
//      " SCHTRAF         NUMERIC,  "     
//      " SCHTRN1         NUMERIC,  "     
//      " SCHTRN2         NUMERIC,  "     
//      " SCHTYP          NUMERIC,  "     
//      " SCHWTHR         NUMERIC,  "     
//      " SELF_EMP        NUMERIC,  "       
//      " TIMETOSC        NUMERIC,  "       
//      " TIMETOWK        NUMERIC,  "       
//      " TOSCSIZE        NUMERIC,  "       
//      " TRAVDAY         NUMERIC,  "     
//      " URBAN           NUMERIC,  "   
//      " URBANSIZE       NUMERIC,  "       
//      " URBRUR          NUMERIC,  "     
//      " USEINTST        NUMERIC,  "       
//      " USEPUBTR        NUMERIC,  "       
//      " WEBUSE          NUMERIC,  "     
//      " WKFMHMXX        NUMERIC,  "       
//      " WKFTPT          NUMERIC,  "     
//      " WKRMHM          NUMERIC,  "     
//      " WKSTFIPS        NUMERIC,  "       
//      " WORKER          NUMERIC,  "     
//      " WRKTIME         VARCHAR(10),  "     
//      " WRKTRANS        NUMERIC,  "       
//      " YEARMILE        NUMERIC,  "       
//      " YRMLCAP         NUMERIC,  "     
//      " YRTOUS          NUMERIC,  "     
//      " DISTTOWK        NUMERIC,  "       
//      " TDAYDATE        NUMERIC,  "       
//      " HOMEOWN         NUMERIC,  "     
//      " HOMETYPE        NUMERIC,  "       
//      " HBHUR           VARCHAR(10),  "   
//      " HTRESDN         NUMERIC,  "     
//      " HTHTNRNT        NUMERIC,  "       
//      " HTPPOPDN        NUMERIC,  "       
//      " HTEEMPDN        NUMERIC,  "       
//      " HBRESDN         NUMERIC,  "     
//      " HBHTNRNT        NUMERIC,  "       
//      " HBPPOPDN        NUMERIC,  "       
//      " HH_CBSA         NUMERIC,  "     
//      " HHC_MSA         NUMERIC);  ";       
      
 //  Create a transactional object. 
    work W3(C); 
       
     // Execute SQL query 
    W3.exec( sql3 ); 
    W3.commit(); 
    cout << "person Table created successfully" << endl;



  // Create table schema for household 
 sql4 = "CREATE TABLE household("  
      " HOUSEID           NUMERIC);  ";     
//      " VARSTRAT          NUMERIC,  "           
//      " WTHHFIN           NUMERIC,  "           
//      " DRVRCNT           NUMERIC,  "           
//      " CDIVMSAR          NUMERIC,  "           
//      " CENSUS_D          NUMERIC,  "           
//      " CENSUS_R          NUMERIC,  "           
//      " HH_HISP           NUMERIC,  "           
//      " HH_RACE           NUMERIC,  "           
//      " HHFAMINC          NUMERIC,  "           
//      " HHRELATD          NUMERIC,  "           
//      " HHRESP            NUMERIC,  "         
//      " HHSIZE            NUMERIC,  "         
//      " HHSTATE           VARCHAR(10),  "           
//      " HHSTFIPS          NUMERIC,  "           
//      " HHVEHCNT          NUMERIC,  "           
//      " HOMEOWN           NUMERIC,  "         
//      " HOMETYPE          NUMERIC,  "           
//      " MSACAT            NUMERIC,  "         
//      " MSASIZE           NUMERIC,  "           
//      " NUMADLT           NUMERIC,  "           
//      " RAIL              NUMERIC,  "       
//      " RESP_CNT          NUMERIC,  "           
//      " SCRESP            NUMERIC,  "         
//      " TRAVDAY           NUMERIC,  "           
//      " URBAN             NUMERIC,  "         
//      " URBANSIZE         NUMERIC,  "             
//      " URBRUR            NUMERIC,  "         
//      " WRKCOUNT          NUMERIC,  "           
//      " TDAYDATE          NUMERIC,  "           
//      " FLAG100           NUMERIC,  "           
//      " LIF_CYC           NUMERIC,  "           
//      " CNTTDHH           NUMERIC,  "           
//      " HBHUR             VARCHAR(10),  "       
//      " HTRESDN           NUMERIC,  "         
//      " HTHTNRNT          NUMERIC,  "           
//      " HTPPOPDN          NUMERIC,  "           
//      " HTEEMPDN          NUMERIC,  "           
//      " HBRESDN           NUMERIC,  "           
//      " HBHTNRNT          NUMERIC,  "           
//      " HBPPOPDN          NUMERIC,  "           
//      " HH_CBSA           NUMERIC,  "           
//      " HHC_MSA           NUMERIC);  "  ;       
      
 //  Create a transactional object. 
    work W4(C); 
       
     // Execute SQL query 
    W4.exec( sql4 ); 
    W4.commit(); 
    cout << "household Table created successfully" << endl;




      sql5 = "CREATE TABLE electric("  
        "MSN              VARCHAR(10), "  
        "YYYYMM           NUMERIC, "  
        "Value            NUMERIC, "
        "Column_Order     NUMERIC, "  
        "Description      VARCHAR(500), " 
        "Unit             VARCHAR(500)); ";      

        //  Create a transactional object. 
    work W5(C); 
     // Execute SQL query 
    W5.exec( sql5 ); 
    W5.commit(); 
    cout << "electric Table created successfully" << endl;     



      sql6 = "CREATE TABLE transportation("  
        "MSN              VARCHAR(10), "  
        "YYYYMM           NUMERIC, "  
        "Value            NUMERIC, "
        "Column_Order     NUMERIC, "  
        "Description      VARCHAR(500), " 
        "Unit             VARCHAR(500)); ";    

    work W6(C); 
     // Execute SQL query 
    W6.exec( sql6 ); 
    W6.commit(); 
    cout << "transportation Table created successfully" << endl;   



      sql7 = "CREATE TABLE mkwh("  
        "MSN              VARCHAR(10), "  
        "YYYYMM           NUMERIC, "  
        "Value            NUMERIC, "
        "Column_Order     NUMERIC, "  
        "Description      VARCHAR(500), " 
        "Unit             VARCHAR(500)); ";    

    work W7(C);   
     // Execute SQL query 
    W7.exec( sql7 ); 
    W7.commit(); 
    cout << "mkwh Table created successfully" << endl;   
    

    //reading from DAY data and putting into database
   //while not end of file 
   while (!(file1.eof())){
          //comma is the delimiter 
          //comma is not stored and the next input 
          //operation happens right after
          getline (file1, HOUSEID,  ',');
          //incase there is an extra empty line at EOF
          if (HOUSEID == ""){             
              break;
            } 
          getline (file1, PERSONID,  ',');
          getline (file1, FRSTHM,    ',');
          getline (file1, OUTOFTWN,  ',');
          getline (file1, ONTD_P1,   ',');
          getline (file1, ONTD_P2,   ',');
          getline (file1, ONTD_P3,   ',');
          getline (file1, ONTD_P4,',');
          getline (file1, ONTD_P5,  ',');
          getline (file1, ONTD_P6,    ',');
          getline (file1, ONTD_P7,    ',');
          getline (file1, ONTD_P8,    ',');
          getline (file1, ONTD_P9,    ',');
          getline (file1, ONTD_P10,   ',');
          getline (file1, ONTD_P11, ',');
          getline (file1, ONTD_P12,',');
          getline (file1, ONTD_P13, ',');
          getline (file1, ONTD_P14,   ',');
          getline (file1, ONTD_P15,   ',');
          getline (file1, TDCASEID,   ',');
          getline (file1, HH_HISP,    ',');
          getline (file1, HH_RACE,    ',');
          getline (file1, DRIVER,  ',');
          getline (file1, R_SEX,',');
          getline (file1, WORKER, ',');
          getline (file1, DRVRCNT,  ',');
          getline (file1, HHFAMINC,   ',');
          getline (file1, HHSIZE,     ',');
          getline (file1, HHVEHCNT,   ',');
          getline (file1, NUMADLT,    ',');
          getline (file1, FLAG100,    ',');
          getline (file1, LIF_CYC, ',');
          getline (file1, TRIPPURP,  ',');
          getline (file1, AWAYHOME,  ',');
          getline (file1, CDIVMSAR,   ',');
          getline (file1, CENSUS_D,   ',');
          getline (file1, CENSUS_R,   ',');
          getline (file1, DROP_PRK,   ',');
          getline (file1, DRVR_FLG,   ',');
          getline (file1, EDUC,    ',');
          getline (file1, ENDTIME, ',');
          getline (file1, HH_ONTD,   ',');
          getline (file1, HHMEMDRV,   ',');
          getline (file1, HHRESP,     ',');
          getline (file1, HHSTATE,    ',');
          getline (file1, HHSTFIPS,   ',');
          getline (file1, INTSTATE,   ',');
          getline (file1, MSACAT,  ',');
          getline (file1, MSASIZE, ',');
          getline (file1, NONHHCNT,  ',');
          getline (file1, NUMONTRP,   ',');
          getline (file1, PAYTOLL,    ',');
          getline (file1, PRMACT,     ',');
          getline (file1, PROXY,      ',');
          getline (file1, PSGR_FLG,   ',');
          getline (file1, R_AGE,   ',');
          getline (file1, RAIL,  ',');
          getline (file1, STRTTIME,  ',');
          getline (file1, TRACC1,     ',');
          getline (file1, TRACC2,     ',');
          getline (file1, TRACC3,     ',');
          getline (file1, TRACC4,     ',');
          getline (file1, TRACC5,     ',');
          getline (file1, TRACCTM, ',');
          getline (file1, TRAVDAY, ',');
          getline (file1, TREGR1,    ',');
          getline (file1, TREGR2,     ',');
          getline (file1, TREGR3,     ',');
          getline (file1, TREGR4,     ',');
          getline (file1, TREGR5,     ',');
          getline (file1, TREGRTM,    ',');
          getline (file1, TRPACCMP,',');
          getline (file1, TRPHHACC,  ',');
          getline (file1, TRPHHVEH,  ',');
          getline (file1, TRPTRANS,   ',');
          getline (file1, TRVL_MIN,   ',');
          getline (file1, TRVLCMIN,   ',');
          getline (file1, TRWAITTM,   ',');
          getline (file1, URBAN,      ',');
          getline (file1, URBANSIZE,  ',');
          getline (file1, URBRUR,  ',');
          getline (file1, USEINTST, ',');
          getline (file1, USEPUBTR,   ',');
          getline (file1, VEHID,      ',');
          getline (file1, WHODROVE,   ',');
          getline (file1, WHYFROM,    ',');
          getline (file1, WHYTO,      ',');
          getline (file1, WHYTRP1S,',');
          getline (file1, WRKCOUNT, ',');
          getline (file1, DWELTIME,  ',');
          getline (file1, WHYTRP90,   ',');
          getline (file1, TDTRPNUM,   ',');
          getline (file1, TDWKND,     ',');
          getline (file1, TDAYDATE,   ',');
          getline (file1, TRPMILES,   ',');
          getline (file1, WTTRDFIN,',');
          getline (file1, VMT_MILE, ',');
          getline (file1, PUBTRANS,  ',');
          getline (file1, HOMEOWN,    ',');
          getline (file1, HOMETYPE,   ',');
          getline (file1, HBHUR,      ',');
          getline (file1, HTRESDN,    ',');
          getline (file1, HTHTNRNT,   ',');
          getline (file1, HTPPOPDN,',');
          getline (file1, HTEEMPDN,  ',');
          getline (file1, HBRESDN, ',');
          getline (file1, HBHTNRNT,  ',');
          getline (file1, HBPPOPDN,   ',');
          getline (file1, GASPRICE,  ',');
          getline (file1, VEHTYPE,   ',');
          getline (file1, HH_CBSA,    ',');
          if (HH_CBSA == "XXXXX"){             
              HH_CBSA = "0";
            } 
          getline (file1, HHC_MSA,'\n');
          //for some reason unit has ^M at the end, will look into later
          HHC_MSA = HHC_MSA.substr(0, HHC_MSA.length()- 1);
          if (HHC_MSA == "XXXX"){             
              HHC_MSA = "0";
            }
          //to remove the variable print out
          if (flag != 0){

  sql = "INSERT INTO day VALUES ("+  HOUSEID + "," +   PERSONID + "," +   
          //FRSTHM + "," +     OUTOFTWN + "," +  
           /*
           ONTD_P1 + "," +    ONTD_P2 + "," +    ONTD_P3 + "," +    ONTD_P4 + "," +
           ONTD_P5 + "," +   ONTD_P6 + "," +    ONTD_P7 + "," +    ONTD_P8 + "," +    ONTD_P9 + "," +    ONTD_P10 + "," +   ONTD_P11 + "," +    ONTD_P12 + "," +
           ONTD_P13 + "," +  ONTD_P14 + "," +   ONTD_P15 + "," +   
           */
           //TDCASEID + "," +  
           // HH_HISP + "," +    HH_RACE + "," +   
           //  DRIVER + "," +    
           // R_SEX +  "," +
           //WORKER + "," +   
           // DRVRCNT + "," +    
            //HHFAMINC + "," +   
           // HHSIZE + "," +     HHVEHCNT + "," +   
           // NUMADLT + "," +    FLAG100 + "," +   
           //  LIF_CYC + ",'" +
          // TRIPPURP + "'," +  AWAYHOME + "," +   CDIVMSAR + "," +   
           //CENSUS_D + "," +   CENSUS_R + "," +   DROP_PRK + "," +  
          //  DRVR_FLG + "," +   EDUC + "," +       
          // ENDTIME + "," +   HH_ONTD + "," +    HHMEMDRV + "," +   HHRESP + ",'" +    HHSTATE + "'," +    HHSTFIPS + "," +   INTSTATE + "," +   
          // MSACAT + "," +     
          // MSASIZE + "," + 
           //  NONHHCNT + "," +   NUMONTRP + "," +  
             // PAYTOLL + "," +   
           //    PRMACT + "," +     PROXY + "," +      PSGR_FLG + "," + 
              //   R_AGE + "," +      
         //  RAIL + "," +     
          //  STRTTIME + "," +   
            //TRACC1 + "," +     TRACC2 + "," +     TRACC3 + "," +     TRACC4 + "," +     TRACC5 + "," +    
          //   TRACCTM + "," +    
         //  TRAVDAY + "," +  
          //  TREGR1 + "," +     TREGR2 + "," +     TREGR3 + "," +     TREGR4 + "," +     TREGR5 + "," +    
         //    TREGRTM + "," +    TRPACCMP + "," +   
         //  TRPHHACC + "," +  TRPHHVEH + "," +  
            TRPTRANS + "," +   
            //TRVL_MIN + "," +   TRVLCMIN + "," +   TRWAITTM + "," +   
          // URBAN + "," +      URBANSIZE + "," +  
          // URBRUR + "," +    
          // USEINTST + "," +   USEPUBTR + "," +   
           VEHID + "," +     
          //  WHODROVE + "," +  
           // WHYFROM + "," +    WHYTO + "," +      WHYTRP1S + "," +   
          // WRKCOUNT + "," +  DWELTIME + "," +  
           // WHYTRP90 + "," +  
          //  TDTRPNUM + "," +   TDWKND + "," +     
            TDAYDATE + "," +   TRPMILES + "," +  
            // WTTRDFIN + "," +   
         //  VMT_MILE + "," +  PUBTRANS + ",'" +  
           // HOMEOWN + "," +    HOMETYPE + ",'" +  
          //   HBHUR + "'," +    
             //  HTRESDN + "," +   
          //      HTHTNRNT + "," +  
                // HTPPOPDN + "," +   
          // HTEEMPDN + "," +  HBRESDN + "," +    HBHTNRNT + "," +   HBPPOPDN + "," +   GASPRICE + "," +  
            VEHTYPE + ");";    
            //HH_CBSA + "," +    HHC_MSA + ");";  
           


 //  Create a transactional object. 
    work W5(C); 
       
     // Execute SQL query 
    W5.exec( sql ); 
    W5.commit(); 

  }
      flag = 1;
} //end while loop

flag = 0;


  while (!(file2.eof())){
          getline (file2,HOUSEID, ',');
           if (HOUSEID == ""){             
              break;
            } 
          getline (file2, WTHHFIN, ',');
          getline (file2, VEHID, ',');
          getline (file2, DRVRCNT, ',');
          getline (file2, HHFAMINC, ',');
          getline (file2, HHSIZE, ',');
          getline (file2, HHVEHCNT, ',');
          getline (file2, NUMADLT, ',');
          getline (file2, FLAG100, ',');
          getline (file2, CDIVMSAR, ',');
          getline (file2, CENSUS_D, ',');
          getline (file2, CENSUS_R, ',');
          getline (file2, HHSTATE, ',');
          getline (file2, HHSTFIPS, ',');
          getline (file2, HYBRID, ',');
          getline (file2, MAKECODE, ',');
          getline (file2, MODLCODE, ',');
           if (MODLCODE == "XXX"){             
              MODLCODE = "1000";        // XXX = Suppressed for confidential reason
                                        //made it 1000 because the valid range is 000-998
            } 
          getline (file2, MSACAT, ',');
          getline (file2, MSASIZE, ',');
          getline (file2, OD_READ, ',');
          getline (file2, RAIL, ',');
          getline (file2, TRAVDAY, ',');
          getline (file2, URBAN, ',');
          getline (file2, URBANSIZE, ',');
          getline (file2, URBRUR, ',');
          getline (file2, VEHCOMM, ',');
          getline (file2, VEHOWNMO, ',');
          getline (file2, VEHYEAR, ',');
          getline (file2, WHOMAIN, ',');
          getline (file2, WRKCOUNT, ',');
          getline (file2, TDAYDATE, ',');
          getline (file2, VEHAGE, ',');
          getline (file2, PERSONID, ',');
          getline (file2, HH_HISP, ',');
          getline (file2, HH_RACE, ',');
          getline (file2, HOMEOWN, ',');
          getline (file2, HOMETYPE, ',');
          getline (file2, LIF_CYC, ',');
          getline (file2, ANNMILES, ',');
          getline (file2, HBHUR, ',');
          getline (file2, HTRESDN, ',');
          getline (file2, HTHTNRNT, ',');
          getline (file2, HTPPOPDN, ',');
          getline (file2, HTEEMPDN, ',');
          getline (file2, HBRESDN, ',');
          getline (file2, HBHTNRNT, ',');
          getline (file2, HBPPOPDN, ',');
          getline (file2, BEST_FLG, ',');
          getline (file2, BESTMILE, ',');
          getline (file2, BEST_EDT, ',');
          getline (file2, BEST_OUT, ',');
          getline (file2, FUELTYPE, ',');
          getline (file2, GSYRGAL, ',');
          getline (file2, GSCOST, ',');
          getline (file2, GSTOTCST, ',');
          getline (file2, EPATMPG, ',');
          getline (file2, EPATMPGF, ',');
          getline (file2, EIADMPG, ',');
          getline (file2, VEHTYPE, ',');
          getline (file2, HH_CBSA, ',');
           if (HH_CBSA == "XXXXX"){             
              HH_CBSA = "0";
         }
          getline (file2, HHC_MSA, '\n');
          HHC_MSA = HHC_MSA.substr(0, HHC_MSA.length()- 1);
          if (HHC_MSA == "XXXX"){             
            HHC_MSA = "0";
        }

if (flag != 0){

sql = "INSERT INTO vehicle VALUES ("+  HOUSEID  + "," + 
     //WTHHFIN  + "," + 
     VEHID  + "," + 
    // DRVRCNT  + "," + HHFAMINC  + "," +  HHSIZE  + "," +  HHVEHCNT  + "," +  NUMADLT  + "," + FLAG100  + "," + CDIVMSAR  + "," +  CENSUS_D  + "," +  CENSUS_R  + ",'" +  HHSTATE  + "'," + HHSTFIPS  + "," +  HYBRID  + "," +  MAKECODE  + "," +  MODLCODE  + "," +  MSACAT  + "," +  MSASIZE  + "," + OD_READ  + "," + RAIL  + "," +  TRAVDAY  + "," + URBAN  + "," + URBANSIZE  + "," + URBRUR  + "," +  VEHCOMM  + "," + VEHOWNMO  + "," +
     //  VEHYEAR  + "," + WHOMAIN  + "," + WRKCOUNT  + "," +  TDAYDATE  + "," +  VEHAGE  + "," +  PERSONID  + "," +  HH_HISP  + "," + HH_RACE  + "," + HOMEOWN  + "," + HOMETYPE  + "," +  LIF_CYC  + "," + ANNMILES  + ",'" +  HBHUR  + "'," + HTRESDN  + "," + HTHTNRNT  + "," +  HTPPOPDN  + "," +  HTEEMPDN  + "," +  HBRESDN  + "," + HBHTNRNT  + "," +  HBPPOPDN  + "," +  BEST_FLG  + "," +  BESTMILE  + "," +  BEST_EDT  + "," +  BEST_OUT  + "," +  FUELTYPE  + "," +  
     //  GSYRGAL  + "," + GSCOST  + "," +  GSTOTCST  + "," +  
       EPATMPG  + "," +
        //EPATMPGF  + "," +  
        EIADMPG + ");"; 
        //VEHTYPE  + "," + HH_CBSA  + "," + HHC_MSA + ");"; 

//  Create a transactional object. 
    work W6(C); 
       
     // Execute SQL query 
    W6.exec( sql ); 
    W6.commit(); 

}


 flag = 1;
} //end while loop


flag = 0;

 while (!(file3.eof())){
        getline( file3, HOUSEID, ','); 
        if (HOUSEID == ""){             
              break;
            }
        getline( file3, PERSONID, ',');
        getline( file3, VARSTRAT, ',');
        getline( file3, WTPERFIN, ',');
        getline( file3, SFWGT, ','); 
        getline( file3, HH_HISP, ',');
        getline( file3, HH_RACE, ',');
        getline( file3, DRVRCNT, ',');
        getline( file3, HHFAMINC, ',');
        getline( file3, HHSIZE, ',');
        getline( file3, HHVEHCNT, ',');
        getline( file3, NUMADLT, ',');
        getline( file3, WRKCOUNT, ',');
        getline( file3, FLAG100, ',');
        getline( file3, LIF_CYC, ',');
        getline( file3, CNTTDTR, ',');
        getline( file3, BORNINUS, ',');
        getline( file3, CARRODE, ',');
        getline( file3, CDIVMSAR, ',');
        getline( file3, CENSUS_D, ',');
        getline( file3, CENSUS_R, ',');
        getline( file3, CONDNIGH, ',');
        getline( file3, CONDPUB, ',');
        getline( file3, CONDRIDE, ',');
        getline( file3, CONDRIVE, ',');
        getline( file3, CONDSPEC, ',');
        getline( file3, CONDTAX, ',');
        getline( file3, CONDTRAV, ',');
        getline( file3, DELIVER, ',');
        getline( file3, DIARY, ',');
        getline( file3, DISTTOSC, ',');
        getline( file3, DRIVER, ',');
        getline( file3, DTACDT, ',');
        getline( file3, DTCONJ, ',');
        getline( file3, DTCOST, ',');
        getline( file3, DTRAGE, ',');
        getline( file3, DTRAN, ',');
        getline( file3, DTWALK, ',');
        getline( file3, EDUC, ',');
        getline( file3, EVERDROV, ',');
        getline( file3, FLEXTIME, ',');
        getline( file3, FMSCSIZE, ',');
        getline( file3, FRSTHM, ',');
        getline( file3, FXDWKPL, ',');
        getline( file3, GCDWORK, ',');
        getline( file3, GRADE, ',');
        getline( file3, GT1JBLWK, ',');
        getline( file3, HHRESP, ',');
        getline( file3, HHSTATE, ',');
        getline( file3, HHSTFIPS, ',');
        getline( file3, ISSUE, ',');
        getline( file3, OCCAT, ',');
        getline( file3, LSTTRDAY, ',');
        getline( file3, MCUSED, ',');
        getline( file3, MEDCOND, ',');
        getline( file3, MEDCOND6, ',');
        getline( file3, MOROFTEN, ',');
        getline( file3, MSACAT, ',');
        getline( file3, MSASIZE, ',');
        getline( file3, NBIKETRP, ',');
        getline( file3, NWALKTRP, ',');
        getline( file3, OUTCNTRY, ',');
        getline( file3, OUTOFTWN, ',');
        getline( file3, PAYPROF, ',');
        getline( file3, PRMACT, ',');
        getline( file3, PROXY, ',');
        getline( file3, PTUSED, ',');
        getline( file3, PURCHASE, ',');
        getline( file3, R_AGE, ',');
        getline( file3, R_RELAT, ',');
        getline( file3, R_SEX, ',');
        getline( file3, RAIL, ',');
        getline( file3, SAMEPLC, ',');
        getline( file3, SCHCARE, ',');
        getline( file3, SCHCRIM, ',');
        getline( file3, SCHDIST, ',');
        getline( file3, SCHSPD, ',');
        getline( file3, SCHTRAF, ',');
        getline( file3, SCHTRN1, ',');
        getline( file3, SCHTRN2, ',');
        getline( file3, SCHTYP, ',');
        getline( file3, SCHWTHR, ',');
        getline( file3, SELF_EMP, ',');
        getline( file3, TIMETOSC, ',');
        getline( file3, TIMETOWK, ',');
        getline( file3, TOSCSIZE, ',');
        getline( file3, TRAVDAY, ',');
        getline( file3, URBAN, ',');
        getline( file3, URBANSIZE, ',');
        getline( file3, URBRUR, ',');
        getline( file3, USEINTST, ',');
        getline( file3, USEPUBTR, ',');
        getline( file3, WEBUSE, ',');
        getline( file3, WKFMHMXX, ',');
        getline( file3, WKFTPT, ',');
        getline( file3, WKRMHM, ',');
        getline( file3, WKSTFIPS, ',');
        getline( file3, WORKER, ',');
        getline( file3, WRKTIME, ',');
        getline( file3, WRKTRANS, ',');
        getline( file3, YEARMILE, ',');
        getline( file3, YRMLCAP, ',');
        getline( file3, YRTOUS, ',');
        getline( file3, DISTTOWK, ',');
        getline( file3, TDAYDATE, ',');
        getline( file3, HOMEOWN, ',');
        getline( file3, HOMETYPE, ',');
        getline( file3, HBHUR, ',');
        getline( file3, HTRESDN, ',');
        getline( file3, HTHTNRNT, ',');
        getline( file3, HTPPOPDN, ',');
        getline( file3, HTEEMPDN, ',');
        getline( file3, HBRESDN, ',');
        getline( file3, HBHTNRNT, ',');
        getline( file3, HBPPOPDN, ',');
        getline( file3, HH_CBSA, ',');
        if (HH_CBSA == "XXXXX"){             
              HH_CBSA = "0";
         }
        getline( file3, HHC_MSA, '\n');
        HHC_MSA = HHC_MSA.substr(0, HHC_MSA.length()- 1);
        if (HHC_MSA == "XXXX"){             
            HHC_MSA = "0";
        }

if (flag != 0){
sql =  "INSERT INTO person VALUES ("+   HOUSEID + "," +  PERSONID +");"; 

      /*
        VARSTRAT + "," +  WTPERFIN + "," +  SFWGT + "," + HH_HISP + "," + HH_RACE + "," + DRVRCNT + "," + HHFAMINC + "," +  HHSIZE + "," +  HHVEHCNT + "," +  NUMADLT + "," + WRKCOUNT + "," +  FLAG100 + "," + LIF_CYC + "," + CNTTDTR + "," + BORNINUS + "," +  CARRODE + "," + CDIVMSAR + "," +  CENSUS_D + "," +  
        CENSUS_R + "," +  CONDNIGH + "," +  CONDPUB + "," + CONDRIDE + "," +  CONDRIVE + "," +  CONDSPEC + "," +  CONDTAX + "," + CONDTRAV + "," +  DELIVER + "," + DIARY + "," + DISTTOSC + "," +  DRIVER + "," +  DTACDT + "," +  DTCONJ + "," +  DTCOST + "," +  DTRAGE + "," +  DTRAN + "," +  DTWALK + "," +  EDUC + "," +  EVERDROV + "," +  
        FLEXTIME + "," +  FMSCSIZE + "," +  FRSTHM + "," +  FXDWKPL + "," + GCDWORK + "," + GRADE + "," + GT1JBLWK + "," +  HHRESP + ",'" +  HHSTATE + "'," + HHSTFIPS + "," +  ISSUE + "," + OCCAT + "," + LSTTRDAY + "," +  MCUSED + "," +  MEDCOND + "," + MEDCOND6 + "," +  MOROFTEN + "," +  MSACAT + "," +  MSASIZE + "," + NBIKETRP + "," +  
        NWALKTRP + "," +  OUTCNTRY + "," +  OUTOFTWN + "," +  PAYPROF + "," + PRMACT + "," +  PROXY + "," + PTUSED + "," +  PURCHASE + "," +  R_AGE + "," + R_RELAT + "," + R_SEX + "," + RAIL + "," +  SAMEPLC + "," + SCHCARE + "," + SCHCRIM + "," + SCHDIST + "," + SCHSPD + "," +  SCHTRAF + "," + SCHTRN1 + "," + SCHTRN2 + "," + SCHTYP + "," +  
        SCHWTHR + "," + SELF_EMP + "," +  TIMETOSC + "," +  TIMETOWK + "," +  TOSCSIZE + "," +  TRAVDAY + "," + URBAN + "," + URBANSIZE + "," + URBRUR + "," +  USEINTST + "," +  USEPUBTR + "," +  WEBUSE + "," +  WKFMHMXX + "," +  WKFTPT + "," +  WKRMHM + "," +  WKSTFIPS + "," +  WORKER + ",'" +  WRKTIME + "'," + WRKTRANS + "," +  
        YEARMILE + "," +  YRMLCAP + "," + YRTOUS + "," +  DISTTOWK + "," +  TDAYDATE + "," +  HOMEOWN + "," + HOMETYPE + ",'" +  HBHUR + "'," + HTRESDN + "," + HTHTNRNT + "," +  HTPPOPDN + "," +  HTEEMPDN + "," +  HBRESDN + "," + HBHTNRNT + "," +  HBPPOPDN + "," +  HH_CBSA + "," + HHC_MSA  + ");"; 
      */

//  Create a transactional object. 
    work W7(C); 
       
     // Execute SQL query 
    W7.exec( sql ); 
    W7.commit(); 



} 



 flag = 1;

} //end while loop

flag = 0;


 while (!(file4.eof())){

          getline (file4, HOUSEID , ',' ); 
          if (HOUSEID == ""){             
              break;
            }
          getline (file4, VARSTRAT , ',' );
          getline (file4, WTHHFIN , ',' ); 
          getline (file4, DRVRCNT , ',' ); 
          getline (file4, CDIVMSAR , ',' );  
          getline (file4, CENSUS_D , ',' );  
          getline (file4, CENSUS_R , ',' );  
          getline (file4, HH_HISP , ',' ); 
          getline (file4, HH_RACE , ',' ); 
          getline (file4, HHFAMINC , ',' );  
          getline (file4, HHRELATD , ',' );  
          getline (file4, HHRESP , ',' );  
          getline (file4, HHSIZE , ',' );  
          getline (file4, HHSTATE , ',' ); 
          getline (file4, HHSTFIPS , ',' );  
          getline (file4, HHVEHCNT , ',' );
          getline (file4, HOMEOWN , ',' );
          getline (file4, HOMETYPE , ',' ); 
          getline (file4, MSACAT , ',' );  
          getline (file4, MSASIZE , ',' ); 
          getline (file4, NUMADLT , ',' ); 
          getline (file4, RAIL , ',' );  
          getline (file4, RESP_CNT , ',' );  
          getline (file4, SCRESP , ',' );  
          getline (file4, TRAVDAY , ',' ); 
          getline (file4, URBAN , ',' ); 
          getline (file4, URBANSIZE , ',' ); 
          getline (file4, URBRUR , ',' );  
          getline (file4, WRKCOUNT , ',' );  
          getline (file4, TDAYDATE , ',' );  
          getline (file4, FLAG100 , ',' ); 
          getline (file4, LIF_CYC , ',' ); 
          getline (file4, CNTTDHH , ',' ); 
          getline (file4, HBHUR , ',' );
          getline (file4, HTRESDN , ',' );
          getline (file4, HTHTNRNT , ',' ); 
          getline (file4, HTPPOPDN , ',' );            
          getline (file4, HTEEMPDN , ',' );  
          getline (file4, HBRESDN , ',' ); 
          getline (file4, HBHTNRNT , ',' );  
          getline (file4, HBPPOPDN , ',' );  
          getline (file4, HH_CBSA , ',' ); 
           if (HH_CBSA == "XXXXX"){             
              HH_CBSA = "0";
         } 
          getline (file4, HHC_MSA , '\n');
           HHC_MSA = HHC_MSA.substr(0, HHC_MSA.length()- 1);
          if (HHC_MSA == "XXXX"){             
              HHC_MSA = "0";
            }

if (flag != 0){
       sql =  "INSERT INTO household VALUES ("+   HOUSEID +");"; 

          /*
          VARSTRAT + "," +   WTHHFIN + "," +  DRVRCNT + "," +  CDIVMSAR + "," +   CENSUS_D + "," +   CENSUS_R + "," +   HH_HISP + "," +  HH_RACE + "," +  HHFAMINC + "," +   HHRELATD + "," +   HHRESP + "," +   HHSIZE + ",'" +   HHSTATE + "'," +  HHSTFIPS + "," +   HHVEHCNT + "," + 
          HOMEOWN + "," +  HOMETYPE + "," +   MSACAT + "," +   MSASIZE + "," +  NUMADLT + "," +  RAIL + "," +   RESP_CNT + "," +   SCRESP + "," +   TRAVDAY + "," +  URBAN + "," +  URBANSIZE + "," +  URBRUR + "," +   WRKCOUNT + "," +   TDAYDATE + "," +   FLAG100 + "," +  LIF_CYC + "," +  CNTTDHH + ",'" +  HBHUR + "'," + 
          HTRESDN + "," +  HTHTNRNT + "," +   HTPPOPDN + "," +   HTEEMPDN + "," +   HBRESDN + "," +  HBHTNRNT + "," +   HBPPOPDN + "," +   HH_CBSA + "," +  HHC_MSA + ");";
          */


          //  Create a transactional object. 
    work W8(C); 
       
     // Execute SQL query 
    W8.exec( sql ); 
    W8.commit(); 


}
flag = 1;



}//end while loops

flag = 0;

 while (!(file5.eof())){

      //comma is the delimiter 
      //comma is not stored and the next input 
      //operation happens right after
      getline (file5, MSN,',');
       //incase there is an extra empty line at EOF
         if (MSN == ""){             
            break;
         } 

      getline (file5, YYYYMM,',');

      getline (file5, Value,',');
       if (Value == "Not Available"){             
              Value = "0";
            } 


      getline (file5, Column_Order,',');
      //removes quotes around column_order
      Column_Order = Column_Order.substr(1, Column_Order.length()- 2);

      getline (file5, Description,',');
      Description = Description.substr(1, Description.length()- 1);

      //new line is delimiter 
      //discards the new line and moves on
      getline (file5, Unit,'\n');
      //for some reason unit has ^M at the end, will look into later
      Unit = Unit.substr(1, Unit.length()- 3);

      //inserts into output file5
      if (flag != 0){
         sql = "INSERT INTO electric VALUES ('" + MSN + "'," + YYYYMM
         + "," +Value + "," + Column_Order + ",'" + Description + "','"  + Unit 
         + "');";

    work W9(C); 
       
     // Execute SQL query 
    W9.exec( sql ); 
    W9.commit(); 
      }
      flag = 1;
   }  //end while look



flag = 0;

 while (!(file6.eof())){

      //comma is the delimiter 
      //comma is not stored and the next input 
      //operation happens right after
      getline (file6, MSN,',');
       //incase there is an extra empty line at EOF
         if (MSN == ""){             
            break;
         } 

      getline (file6, YYYYMM,',');

      getline (file6, Value,',');
         if (Value == "Not Available"){             
              Value = "0";
            } 

      getline (file6, Column_Order,',');
      //removes quotes around column_order
      Column_Order = Column_Order.substr(1, Column_Order.length()- 2);

      getline (file6, Description,',');
      Description = Description.substr(1, Description.length()- 1);

      //new line is delimiter 
      //discards the new line and moves on
      getline (file6, Unit,'\n');
      //for some reason unit has ^M at the end, will look into later
      Unit = Unit.substr(1, Unit.length()- 3);

      //inserts into output file6
      if (flag != 0){
         sql = "INSERT INTO transportation VALUES ('" + MSN + "'," + YYYYMM
         + "," +Value + "," + Column_Order + ",'" + Description + "','"  + Unit 
         + "');";

    work W10(C); 
       
     // Execute SQL query 
    W10.exec( sql ); 
    W10.commit(); 
      }
      flag = 1;
   }  //end while look


flag = 0;

 while (!(file7.eof())){

      //comma is the delimiter 
      //comma is not stored and the next input 
      //operation happens right after
      getline (file7, MSN,',');
       //incase there is an extra empty line at EOF
         if (MSN == ""){             
            break;
         } 

      getline (file7, YYYYMM,',');

      getline (file7, Value,',');
       if (Value == "Not Available"){             
              Value = "0";
            } 


      getline (file7, Column_Order,',');
      //removes quotes around column_order
      Column_Order = Column_Order.substr(1, Column_Order.length()- 2);

      getline (file7, Description,',');
      Description = Description.substr(1, Description.length()- 1);

      //new line is delimiter 
      //discards the new line and moves on
      getline (file7, Unit,'\n');
      //for some reason unit has ^M at the end, will look into later
      Unit = Unit.substr(1, Unit.length()- 3);

      //inserts into output file7
      if (flag != 0){
         sql = "INSERT INTO mkwh VALUES ('" + MSN + "'," + YYYYMM
         + "," +Value + "," + Column_Order + ",'" + Description + "','"  + Unit 
         + "');";

    work W9(C); 
       
     // Execute SQL query 
    W9.exec( sql ); 
    W9.commit(); 
      }
      flag = 1;
   }  //end while look





    C.disconnect (); 
  } catch (const std::exception &e){ 
    cerr << e.what() << std::endl; 
    return 1; 
}


  return 0; 



}
