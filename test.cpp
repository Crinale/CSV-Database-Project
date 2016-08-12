#include <iostream> 
#include <pqxx/pqxx>  
#include <fstream> 
#include <vector>



using namespace std; 
using namespace pqxx; 
 
int main(int argc, char* argv[]) { 
  string sql1,sql2, sql3,sql4,sql5,sql6,sql7; 
  string sql;

  int flag = 0;
  int count = 0;

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

  try { 
    // Inorder to connect to the postgresql database, you need to create a database (testdb) and an user (dbuser). 
    connection C("dbname=bulk user=dbuser password=1"); 
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

        std::vector<string> v;
                std::vector<string> v2;


    string line, field; 

    ofstream myfile;
    myfile.open("bulk.txt");
    sql =  "INSERT INTO day (HOUSEID, PERSONID,TRPTRANS,VEHID ,TDAYDATE,TRPMILES,VEHTYPE) VALUES ";
    int y = 0 ;
 while (getline(file1, line)){
          stringstream ss(line);
          //comma is the delimiter 
          y++;
          if (y >500000){
            while(getline(ss, field, ',')){
                        v2.push_back(field);}
                        cout << "count:" << y<< endl;

          }
          //comma is not stored and the next input 
          //operation happens right after
          while(getline(ss, field, ',')){
                        v.push_back(field);}
                        cout << "count:" << y<< endl;

            }

            /*
       ss  >>    HOUSEID >> c >>    PERSONID >> c >>    FRSTHM >> c >>      OUTOFTWN >> c >>    ONTD_P1 >> c >>     ONTD_P2 >> c >>     ONTD_P3 >> c >>     ONTD_P4 >> c >> 
           ONTD_P5 >> c >>    ONTD_P6 >> c >>     ONTD_P7 >> c >>     ONTD_P8 >> c >>     ONTD_P9 >> c >>     ONTD_P10 >> c >>    ONTD_P11 >> c >>    ONTD_P12 >> c >> 
           ONTD_P13 >> c >>   ONTD_P14 >> c >>    ONTD_P15 >> c >>    TDCASEID >> c >>    HH_HISP >> c >>     HH_RACE >> c >>     DRIVER >> c >>      R_SEX >> c >>  
           WORKER >> c >>     DRVRCNT >> c >>     HHFAMINC >> c >>    HHSIZE >> c >>      HHVEHCNT >> c >>    NUMADLT >> c >>     FLAG100 >> c >>     LIF_CYC >> c >>     
           TRIPPURP >> c >>   AWAYHOME >> c >>    CDIVMSAR >> c >>    CENSUS_D >> c >>    CENSUS_R >> c >>    DROP_PRK >> c >>    DRVR_FLG >> c >>    EDUC >> c >>        
           ENDTIME >> c >>    HH_ONTD >> c >>     HHMEMDRV >> c >>    HHRESP >> c >>      HHSTATE >> c >>     HHSTFIPS >> c >>    INTSTATE >> c >>    MSACAT >> c >>      
           MSASIZE >> c >>    NONHHCNT >> c >>    NUMONTRP >> c >>    PAYTOLL >> c >>     PRMACT >> c >>      PROXY >> c >>       PSGR_FLG >> c >>    R_AGE >> c >>       
           RAIL >> c >>       STRTTIME >> c >>    TRACC1 >> c >>      TRACC2 >> c >>      TRACC3 >> c >>      TRACC4 >> c >>      TRACC5 >> c >>      TRACCTM >> c >>     
           TRAVDAY >> c >>    TREGR1 >> c >>      TREGR2 >> c >>      TREGR3 >> c >>      TREGR4 >> c >>      TREGR5 >> c >>      TREGRTM >> c >>     TRPACCMP >> c >>    
           TRPHHACC >> c >>   TRPHHVEH >> c >>    TRPTRANS >> c >>    TRVL_MIN >> c >>    TRVLCMIN >> c >>    TRWAITTM >> c >>    URBAN >> c >>       URBANSIZE >> c >>   
           URBRUR >> c >>     USEINTST >> c >>    USEPUBTR >> c >>    VEHID >> c >>       WHODROVE >> c >>    WHYFROM >> c >>     WHYTO >> c >>       WHYTRP1S >> c >>   
           WRKCOUNT >> c >>   DWELTIME >> c >>    WHYTRP90 >> c >>    TDTRPNUM >> c >>    TDWKND >> c >>      TDAYDATE >> c >>    TRPMILES >> c >>    WTTRDFIN >> c >>    
           VMT_MILE >> c >>   PUBTRANS >> c >>    HOMEOWN >> c >>     HOMETYPE >> c >>    HBHUR >> c >>       HTRESDN >> c >>     HTHTNRNT >> c >>    HTPPOPDN >> c >>    
           HTEEMPDN >> c >>   HBRESDN >> c >>     HBHTNRNT >> c >>    HBPPOPDN >> c >>    GASPRICE >> c >>    VEHTYPE >> c >>     HH_CBSA >> c >>     HHC_MSA;
          cout << fields << endl; 
*/
          /*
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

            */
          //to remove the variable print out

          if (flag != 0){

  sql = sql  +  "("  + HOUSEID  + ","   +    PERSONID  + ","  +   
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
            TRPTRANS +   "," +    
            //TRVL_MIN + "," +   TRVLCMIN + "," +   TRWAITTM + "," +   
          // URBAN + "," +      URBANSIZE + "," +  
          // URBRUR + "," +    
          // USEINTST + "," +   USEPUBTR + "," +   
           VEHID +  "," +      
          //  WHODROVE + "," +  
           // WHYFROM + "," +    WHYTO + "," +      WHYTRP1S + "," +   
          // WRKCOUNT + "," +  DWELTIME + "," +  
           // WHYTRP90 + "," +  
          //  TDTRPNUM + "," +   TDWKND + "," +     
            TDAYDATE +  ","  +   TRPMILES +   "," +  
            // WTTRDFIN + "," +   
         //  VMT_MILE + "," +  PUBTRANS + ",'" +  
           // HOMEOWN + "," +    HOMETYPE + ",'" +  
          //   HBHUR + "'," +    
             //  HTRESDN + "," +   
          //      HTHTNRNT + "," +  
                // HTPPOPDN + "," +   
          // HTEEMPDN + "," +  HBRESDN + "," +    HBHTNRNT + "," +   HBPPOPDN + "," +   GASPRICE + "," +  
            VEHTYPE +  "),";    
            //HH_CBSA + "," +    HHC_MSA + ");";  
           

//cout << sql << endl;
//count++;
//cout <<"reading row: " << count << endl;
 //  Create a transactional object. 
   // work W5(C); 
       
     // Execute SQL query 
    //W5.exec( sql ); 
    //W5.commit(); 


  }

      sql =  "INSERT INTO day (HOUSEID, PERSONID,TRPTRANS,VEHID ,TDAYDATE,TRPMILES,VEHTYPE) VALUES ";


      cout << "V:" << v.size() << endl;      
       cout << "V2: "<<v2.size() << endl; 

  for (int i = 112; i < v.size(); i=i+112){
    HOUSEID = v[i];
    PERSONID = v[i+1];
    TRPTRANS = v[i+74];
    VEHID = v[i+83];
    TDAYDATE = v[i + 93];
    TRPMILES = v[i+94];
    VEHTYPE = v[i+109];

      sql = sql  +  "("  + HOUSEID  + ","   +    PERSONID  + ","  +    TRPTRANS +   "," +   VEHID +  "," +   TDAYDATE +  ","  +   TRPMILES +   "," +  VEHTYPE +  "),";    

      cout << "IIII::: " << i << endl;
  }


//  flag = 1;

  sql =  sql +  "(-1000, -1000,-1000,-1000,-1000,-1000,-1000);";
      work W5(C); 
       
     // Execute SQL query 
    W5.exec( sql ); 
    W5.commit(); 

cout <<" fishshed"  << endl;

  myfile.close();
    
    C.disconnect (); 
  } catch (const std::exception &e){ 
    cerr << e.what() << std::endl; 
    return 1; 
}


  return 0; 



}
