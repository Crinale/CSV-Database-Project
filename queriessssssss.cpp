#include <iostream>
#include <fstream> 
#include <pqxx/pqxx> 

using namespace std;
using namespace pqxx;



int main(int argc, char* argv[])
{
   string sql;
   float  totalDistance, five, ten, fiften, twenty, twentyFive, thirty, thirtyFive, forthy, forthyFive,
         fifty, fiftyFive, sixty, sixtyFive, seventy, seventyFive, eighty, eightyFive, ninty, nintyFive, oneHundred;  
   
   try{
      connection C("dbname=YouAndI user=dbuser password=1");
      if (C.is_open()) {
         cout << "Opened database successfully: " << C.dbname() << endl;
      } else {
         cout << "Can't open database" << endl;
         return 1;
      }



      //**************************************BEGIN OF 3A***********************************************************************


      /* Create SQL statement */
      sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=5)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N(C);
      
      /* Execute SQL query */
      result R( N.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
            five =  c[0].as<float>();

         cout << " <= five = " << five << endl;
      
      }
       N.commit();
   /* Create SQL statement */
     sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES <= 10 AND TRPMILES >= 0)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
     nontransaction N2(C);
      
      /* Execute SQL query */
     result R2( N2.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c2 = R2.begin(); c2 != R2.end(); ++c2) {
           ten =  c2[0].as<float>();
         cout << " <= ten = " << ten << endl;      
   }

       N2.commit();




	 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=15)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N3(C);
      
      /* Execute SQL query */
      result R3( N3.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c3 = R3.begin(); c3 != R3.end(); ++c3) {
            five =  c3[0].as<float>();

         cout << " <= 15 = " << five << endl;
      
      }
       N3.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=20)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N4(C);
      
      /* Execute SQL query */
      result R4( N4.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c4 = R4.begin(); c4 != R4.end(); ++c4) {
            five =  c4[0].as<float>();

         cout << " <= 20 = " << five << endl;
      
      }
       N4.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=25)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N5(C);
      
      /* Execute SQL query */
      result R5( N5.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c5 = R5.begin(); c5 != R5.end(); ++c5) {
            five =  c5[0].as<float>();

         cout << " <= 25 = " << five << endl;
      
      }
       N5.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=30)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N6(C);
      
      /* Execute SQL query */
      result R6( N6.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c6 = R6.begin(); c6 != R6.end(); ++c6) {
            five =  c6[0].as<float>();

         cout << " <= 30 = " << five << endl;
      
      }
       N6.commit();


 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=35)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N7(C);
      
      /* Execute SQL query */
      result R7( N7.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c7 = R7.begin(); c7 != R7.end(); ++c7) {
            five =  c7[0].as<float>();

         cout << " <= 35 = " << five << endl;
      
      }
       N7.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=40)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N8(C);
      
      /* Execute SQL query */
      result R8( N8.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c8 = R8.begin(); c8 != R8.end(); ++c8) {
            five =  c8[0].as<float>();

         cout << " <= 40 = " << five << endl;
      
      }
       N8.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=45)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N9(C);
      
      /* Execute SQL query */
      result R9( N9.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c9 = R9.begin(); c9 != R9.end(); ++c9) {
            five =  c9[0].as<float>();

         cout << " <= 45 = " << five << endl;
      
      }
       N9.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=50)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N10(C);
      
      /* Execute SQL query */
      result R10( N10.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c10 = R10.begin(); c10 != R10.end(); ++c10) {
            five =  c10[0].as<float>();

         cout << " <= 50 = " << five << endl;
      
      }
       N10.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=55)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N11(C);
      
      /* Execute SQL query */
      result R11( N11.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c11 = R11.begin(); c11 != R11.end(); ++c11) {
            five =  c11[0].as<float>();

         cout << " <= 55 = " << five << endl;
      
      }
       N11.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=60)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N12 (C);
      
      /* Execute SQL query */
      result R12( N12.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c12 = R12.begin(); c12 != R12.end(); ++c12) {
            five =  c12[0].as<float>();

         cout << " <= 60 = " << five << endl;
      
      }
       N12.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=65)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N13(C);
      
      /* Execute SQL query */
      result R13( N13.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c13 = R13.begin(); c13 != R13.end(); ++c13) {
            five =  c13[0].as<float>();

         cout << " <= 65 = " << five << endl;
      
      }
       N13.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=70)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N14(C);
      
      /* Execute SQL query */
      result R14( N14.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c14 = R14.begin(); c14 != R14.end(); ++c14) {
            five =  c14[0].as<float>();

         cout << " <= 70 = " << five << endl;
      
      }
       N14.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=75)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N15(C);
      
      /* Execute SQL query */
      result R15( N15.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c15 = R15.begin(); c15 != R15.end(); ++c15) {
            five =  c15[0].as<float>();

         cout << " <= 75 = " << five << endl;
      
      }
       N15.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=80)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N16(C);
      
      /* Execute SQL query */
      result R16( N16.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c16 = R16.begin(); c16 != R16.end(); ++c16) {
            five =  c16[0].as<float>();

         cout << " <= 80 = " << five << endl;
      
      }
       N16.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=85)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N17(C);
      
      /* Execute SQL query */
      result R17( N17.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c17 = R17.begin(); c17 != R17.end(); ++c17) {
            five =  c17[0].as<float>();

         cout << " <= 85 = " << five << endl;
      
      }
       N17.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=90)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N18(C);
      
      /* Execute SQL query */
      result R18( N18.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c18 = R18.begin(); c18 != R18.end(); ++c18) {
            five =  c18[0].as<float>();

         cout << " <= 90 = " << five << endl;
      
      }
       N18.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=95)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N19(C);
      
      /* Execute SQL query */
      result R19( N19.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c19 = R19.begin(); c19 != R19.end(); ++c19) {
            five =  c19[0].as<float>();

         cout << " <= 95 = " << five << endl;
      
      }
       N19.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=100)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N20(C);
      
      /* Execute SQL query */
      result R20( N20.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c20 = R20.begin(); c20 != R20.end(); ++c20) {
            five =  c20[0].as<float>();

         cout << " <= 100 = " << five << endl;
      
      }
       N20.commit();

       //**************************************END OF 3A***********************************************************************


      //**************************************BEGIN OF 3***********************************************************************

sql = "SELECT l.DIST/l.GALLON AS AVG_FUEL FROM(SELECT SUM(trpmiles / EPATMPG) AS GALLON, Distance AS DIST FROM (SELECT HOUSEID,PERSONID,trpmiles, EPATMPG, trp.Cooo AS Distance FROM
(SELECT HOUSEID,PERSONID,trpmiles, coo.SU AS Cooo
FROM day,(SELECT SUM(trpmiles) AS SU FROM day WHERE trpmiles <= 5 AND trpmiles >0)coo
WHERE trpmiles <= 5 AND trpmiles > 0 AND VEHID >=1)trp NATURAL JOIN
(SELECT HOUSEID, PERSONID, EPATMPG
FROM vehicle)veh)gal GROUP BY Distance)l;";

 nontransaction N21(C);
      
      /* Execute SQL query */
      result R21( N21.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c21 = R21.begin(); c21 != R21.end(); ++c21) {
            five =  c21[0].as<float>();

         cout << " <= AVG_FUEL for 5 = " << five << endl;
      
      }
       N21.commit();

sql = "SELECT l.DIST/l.GALLON AS AVG_FUEL FROM(SELECT SUM(trpmiles / EPATMPG) AS GALLON, Distance AS DIST FROM (SELECT HOUSEID,PERSONID,trpmiles, EPATMPG, trp.Cooo AS Distance FROM
(SELECT HOUSEID,PERSONID,trpmiles, coo.SU AS Cooo
FROM day,(SELECT SUM(trpmiles) AS SU FROM day WHERE trpmiles <= 10 AND trpmiles >0)coo
WHERE trpmiles <= 10 AND trpmiles > 0 AND VEHID >=1)trp NATURAL JOIN
(SELECT HOUSEID, PERSONID, EPATMPG
FROM vehicle)veh)gal GROUP BY Distance)l;";

 nontransaction N22(C);
      
      /* Execute SQL query */
      result R22( N22.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c22 = R22.begin(); c22 != R22.end(); ++c22) {
            five =  c22[0].as<float>();

         cout << " <= AVG_FUEL for 10 = " << five << endl;
      
      }
       N22.commit();



sql = "SELECT l.DIST/l.GALLON AS AVG_FUEL FROM(SELECT SUM(trpmiles / EPATMPG) AS GALLON, Distance AS DIST FROM (SELECT HOUSEID,PERSONID,trpmiles, EPATMPG, trp.Cooo AS Distance FROM
(SELECT HOUSEID,PERSONID,trpmiles, coo.SU AS Cooo
FROM day,(SELECT SUM(trpmiles) AS SU FROM day WHERE trpmiles <= 15 AND trpmiles >0)coo
WHERE trpmiles <= 15 AND trpmiles > 0 AND VEHID >=1)trp NATURAL JOIN
(SELECT HOUSEID, PERSONID, EPATMPG
FROM vehicle)veh)gal GROUP BY Distance)l;";

 nontransaction N23(C);
      
      /* Execute SQL query */
      result R23( N23.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c23 = R23.begin(); c23 != R23.end(); ++c23) {
            five =  c23[0].as<float>();

         cout << " <= AVG_FUEL for 15 = " << five << endl;
      
      }
       N23.commit();

sql = "SELECT l.DIST/l.GALLON AS AVG_FUEL FROM(SELECT SUM(trpmiles / EPATMPG) AS GALLON, Distance AS DIST FROM (SELECT HOUSEID,PERSONID,trpmiles, EPATMPG, trp.Cooo AS Distance FROM
(SELECT HOUSEID,PERSONID,trpmiles, coo.SU AS Cooo
FROM day,(SELECT SUM(trpmiles) AS SU FROM day WHERE trpmiles <= 20 AND trpmiles >0)coo
WHERE trpmiles <= 20 AND trpmiles > 0 AND VEHID >=1)trp NATURAL JOIN
(SELECT HOUSEID, PERSONID, EPATMPG
FROM vehicle)veh)gal GROUP BY Distance)l;";

 nontransaction N24(C);
      
      /* Execute SQL query */
      result R24( N24.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c24 = R24.begin(); c24 != R24.end(); ++c24) {
            five =  c24[0].as<float>();

         cout << " <= AVG_FUEL for 20 = " << five << endl;
      
      }
       N24.commit();

sql = "SELECT l.DIST/l.GALLON AS AVG_FUEL FROM(SELECT SUM(trpmiles / EPATMPG) AS GALLON, Distance AS DIST FROM (SELECT HOUSEID,PERSONID,trpmiles, EPATMPG, trp.Cooo AS Distance FROM
(SELECT HOUSEID,PERSONID,trpmiles, coo.SU AS Cooo
FROM day,(SELECT SUM(trpmiles) AS SU FROM day WHERE trpmiles <= 25 AND trpmiles >0)coo
WHERE trpmiles <= 25 AND trpmiles > 0 AND VEHID >=1)trp NATURAL JOIN
(SELECT HOUSEID, PERSONID, EPATMPG
FROM vehicle)veh)gal GROUP BY Distance)l;";

 nontransaction N25(C);
      
      /* Execute SQL query */
      result R25( N25.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c25 = R25.begin(); c25 != R25.end(); ++c25) {
            five =  c25[0].as<float>();

         cout << " <= AVG_FUEL for 25 = " << five << endl;
      
      }
       N25.commit();


sql = "SELECT l.DIST/l.GALLON AS AVG_FUEL FROM(SELECT SUM(trpmiles / EPATMPG) AS GALLON, Distance AS DIST FROM (SELECT HOUSEID,PERSONID,trpmiles, EPATMPG, trp.Cooo AS Distance FROM
(SELECT HOUSEID,PERSONID,trpmiles, coo.SU AS Cooo
FROM day,(SELECT SUM(trpmiles) AS SU FROM day WHERE trpmiles <= 30 AND trpmiles >0)coo
WHERE trpmiles <= 30 AND trpmiles > 0 AND VEHID >=1)trp NATURAL JOIN
(SELECT HOUSEID, PERSONID, EPATMPG
FROM vehicle)veh)gal GROUP BY Distance)l;";

 nontransaction N26(C);
      
      /* Execute SQL query */
      result R26( N26.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c26 = R26.begin(); c26 != R26.end(); ++c26) {
            five =  c26[0].as<float>();

         cout << " <= AVG_FUEL for 30 = " << five << endl;
      
      }
       N26.commit();

sql = "SELECT l.DIST/l.GALLON AS AVG_FUEL FROM(SELECT SUM(trpmiles / EPATMPG) AS GALLON, Distance AS DIST FROM (SELECT HOUSEID,PERSONID,trpmiles, EPATMPG, trp.Cooo AS Distance FROM
(SELECT HOUSEID,PERSONID,trpmiles, coo.SU AS Cooo
FROM day,(SELECT SUM(trpmiles) AS SU FROM day WHERE trpmiles <= 35 AND trpmiles >0)coo
WHERE trpmiles <= 35 AND trpmiles > 0 AND VEHID >=1)trp NATURAL JOIN
(SELECT HOUSEID, PERSONID, EPATMPG
FROM vehicle)veh)gal GROUP BY Distance)l;";

 nontransaction N27(C);
      
      /* Execute SQL query */
      result R27( N27.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c27 = R27.begin(); c27 != R27.end(); ++c27) {
            five =  c27[0].as<float>();

         cout << " <= AVG_FUEL for 35 = " << five << endl;
      
      }
       N27.commit();

sql = "SELECT l.DIST/l.GALLON AS AVG_FUEL FROM(SELECT SUM(trpmiles / EPATMPG) AS GALLON, Distance AS DIST FROM (SELECT HOUSEID,PERSONID,trpmiles, EPATMPG, trp.Cooo AS Distance FROM
(SELECT HOUSEID,PERSONID,trpmiles, coo.SU AS Cooo
FROM day,(SELECT SUM(trpmiles) AS SU FROM day WHERE trpmiles <= 40 AND trpmiles >0)coo
WHERE trpmiles <= 40 AND trpmiles > 0 AND VEHID >=1)trp NATURAL JOIN
(SELECT HOUSEID, PERSONID, EPATMPG
FROM vehicle)veh)gal GROUP BY Distance)l;";

 nontransaction N28(C);
      
      /* Execute SQL query */
      result R28( N28.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c28 = R28.begin(); c28 != R28.end(); ++c28) {
            five =  c28[0].as<float>();

         cout << " <= AVG_FUEL for 40 = " << five << endl;
      
      }
       N28.commit();

       sql = "SELECT l.DIST/l.GALLON AS AVG_FUEL FROM(SELECT SUM(trpmiles / EPATMPG) AS GALLON, Distance AS DIST FROM (SELECT HOUSEID,PERSONID,trpmiles, EPATMPG, trp.Cooo AS Distance FROM
(SELECT HOUSEID,PERSONID,trpmiles, coo.SU AS Cooo
FROM day,(SELECT SUM(trpmiles) AS SU FROM day WHERE trpmiles <= 45 AND trpmiles >0)coo
WHERE trpmiles <= 45 AND trpmiles > 0 AND VEHID >=1)trp NATURAL JOIN
(SELECT HOUSEID, PERSONID, EPATMPG
FROM vehicle)veh)gal GROUP BY Distance)l;";

 nontransaction N29(C);
      
      /* Execute SQL query */
      result R29( N29.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c29 = R29.begin(); c29 != R29.end(); ++c29) {
            five =  c29[0].as<float>();

         cout << " <= AVG_FUEL for 45 = " << five << endl;
      
      }
       N29.commit();

       sql = "SELECT l.DIST/l.GALLON AS AVG_FUEL FROM(SELECT SUM(trpmiles / EPATMPG) AS GALLON, Distance AS DIST FROM (SELECT HOUSEID,PERSONID,trpmiles, EPATMPG, trp.Cooo AS Distance FROM
(SELECT HOUSEID,PERSONID,trpmiles, coo.SU AS Cooo
FROM day,(SELECT SUM(trpmiles) AS SU FROM day WHERE trpmiles <= 50 AND trpmiles >0)coo
WHERE trpmiles <= 50 AND trpmiles > 0 AND VEHID >=1)trp NATURAL JOIN
(SELECT HOUSEID, PERSONID, EPATMPG
FROM vehicle)veh)gal GROUP BY Distance)l;";

 nontransaction N29(C);
      
      /* Execute SQL query */
      result R29( N29.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c29 = R29.begin(); c29 != R29.end(); ++c29) {
            five =  c29[0].as<float>();

         cout << " <= AVG_FUEL for 50 = " << five << endl;
      
      }
       N29.commit();


       sql = "SELECT l.DIST/l.GALLON AS AVG_FUEL FROM(SELECT SUM(trpmiles / EPATMPG) AS GALLON, Distance AS DIST FROM (SELECT HOUSEID,PERSONID,trpmiles, EPATMPG, trp.Cooo AS Distance FROM
(SELECT HOUSEID,PERSONID,trpmiles, coo.SU AS Cooo
FROM day,(SELECT SUM(trpmiles) AS SU FROM day WHERE trpmiles <= 55 AND trpmiles >0)coo
WHERE trpmiles <= 55 AND trpmiles > 0 AND VEHID >=1)trp NATURAL JOIN
(SELECT HOUSEID, PERSONID, EPATMPG
FROM vehicle)veh)gal GROUP BY Distance)l;";

 nontransaction N30(C);
      
      /* Execute SQL query */
      result R30( N30.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c30 = R30.begin(); c30 != R30.end(); ++c30) {
            five =  c30[0].as<float>();

         cout << " <= AVG_FUEL for 55 = " << five << endl;
      
      }
       N30.commit();



       sql = "SELECT l.DIST/l.GALLON AS AVG_FUEL FROM(SELECT SUM(trpmiles / EPATMPG) AS GALLON, Distance AS DIST FROM (SELECT HOUSEID,PERSONID,trpmiles, EPATMPG, trp.Cooo AS Distance FROM
(SELECT HOUSEID,PERSONID,trpmiles, coo.SU AS Cooo
FROM day,(SELECT SUM(trpmiles) AS SU FROM day WHERE trpmiles <= 60 AND trpmiles >0)coo
WHERE trpmiles <= 60 AND trpmiles > 0 AND VEHID >=1)trp NATURAL JOIN
(SELECT HOUSEID, PERSONID, EPATMPG
FROM vehicle)veh)gal GROUP BY Distance)l;";

 nontransaction N31(C);
      
      /* Execute SQL query */
      result R31( N31.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c31 = R31.begin(); c31 != R31.end(); ++c31) {
            five =  c31[0].as<float>();

         cout << " <= AVG_FUEL for 60 = " << five << endl;
      
      }
       N31.commit();




sql = "SELECT l.DIST/l.GALLON AS AVG_FUEL FROM(SELECT SUM(trpmiles / EPATMPG) AS GALLON, Distance AS DIST FROM (SELECT HOUSEID,PERSONID,trpmiles, EPATMPG, trp.Cooo AS Distance FROM
(SELECT HOUSEID,PERSONID,trpmiles, coo.SU AS Cooo
FROM day,(SELECT SUM(trpmiles) AS SU FROM day WHERE trpmiles <= 65 AND trpmiles >0)coo
WHERE trpmiles <= 65 AND trpmiles > 0 AND VEHID >=1)trp NATURAL JOIN
(SELECT HOUSEID, PERSONID, EPATMPG
FROM vehicle)veh)gal GROUP BY Distance)l;";

 nontransaction N32(C);
      
      /* Execute SQL query */
      result R32( N32.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c32 = R32.begin(); c32 != R32.end(); ++c32) {
            five =  c32[0].as<float>();

         cout << " <= AVG_FUEL for 65 = " << five << endl;
      
      }
       N32.commit();

       sql = "SELECT l.DIST/l.GALLON AS AVG_FUEL FROM(SELECT SUM(trpmiles / EPATMPG) AS GALLON, Distance AS DIST FROM (SELECT HOUSEID,PERSONID,trpmiles, EPATMPG, trp.Cooo AS Distance FROM
(SELECT HOUSEID,PERSONID,trpmiles, coo.SU AS Cooo
FROM day,(SELECT SUM(trpmiles) AS SU FROM day WHERE trpmiles <= 70 AND trpmiles >0)coo
WHERE trpmiles <= 70 AND trpmiles > 0 AND VEHID >=1)trp NATURAL JOIN
(SELECT HOUSEID, PERSONID, EPATMPG
FROM vehicle)veh)gal GROUP BY Distance)l;";

 nontransaction N33(C);
      
      /* Execute SQL query */
      result R33( N33.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c33 = R33.begin(); c33 != R33.end(); ++c33) {
            five =  c33[0].as<float>();

         cout << " <= AVG_FUEL for 70 = " << five << endl;
      
      }
       N33.commit();


       sql = "SELECT l.DIST/l.GALLON AS AVG_FUEL FROM(SELECT SUM(trpmiles / EPATMPG) AS GALLON, Distance AS DIST FROM (SELECT HOUSEID,PERSONID,trpmiles, EPATMPG, trp.Cooo AS Distance FROM
(SELECT HOUSEID,PERSONID,trpmiles, coo.SU AS Cooo
FROM day,(SELECT SUM(trpmiles) AS SU FROM day WHERE trpmiles <= 75 AND trpmiles >0)coo
WHERE trpmiles <= 75 AND trpmiles > 0 AND VEHID >=1)trp NATURAL JOIN
(SELECT HOUSEID, PERSONID, EPATMPG
FROM vehicle)veh)gal GROUP BY Distance)l;";

 nontransaction N34(C);
      
      /* Execute SQL query */
      result R34( N34.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c34 = R34.begin(); c34 != R34.end(); ++c34) {
            five =  c34[0].as<float>();

         cout << " <= AVG_FUEL for 75 = " << five << endl;
      
      }
       N34.commit();

       sql = "SELECT l.DIST/l.GALLON AS AVG_FUEL FROM(SELECT SUM(trpmiles / EPATMPG) AS GALLON, Distance AS DIST FROM (SELECT HOUSEID,PERSONID,trpmiles, EPATMPG, trp.Cooo AS Distance FROM
(SELECT HOUSEID,PERSONID,trpmiles, coo.SU AS Cooo
FROM day,(SELECT SUM(trpmiles) AS SU FROM day WHERE trpmiles <= 80 AND trpmiles >0)coo
WHERE trpmiles <= 80 AND trpmiles > 0 AND VEHID >=1)trp NATURAL JOIN
(SELECT HOUSEID, PERSONID, EPATMPG
FROM vehicle)veh)gal GROUP BY Distance)l;";

 nontransaction N35(C);
      
      /* Execute SQL query */
      result R35( N35.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c35 = R35.begin(); c35 != R35.end(); ++c35) {
            five =  c35[0].as<float>();

         cout << " <= AVG_FUEL for 80 = " << five << endl;
      
      }
       N35.commit();

sql = "SELECT l.DIST/l.GALLON AS AVG_FUEL FROM(SELECT SUM(trpmiles / EPATMPG) AS GALLON, Distance AS DIST FROM (SELECT HOUSEID,PERSONID,trpmiles, EPATMPG, trp.Cooo AS Distance FROM
(SELECT HOUSEID,PERSONID,trpmiles, coo.SU AS Cooo
FROM day,(SELECT SUM(trpmiles) AS SU FROM day WHERE trpmiles <= 85 AND trpmiles >0)coo
WHERE trpmiles <= 85 AND trpmiles > 0 AND VEHID >=1)trp NATURAL JOIN
(SELECT HOUSEID, PERSONID, EPATMPG
FROM vehicle)veh)gal GROUP BY Distance)l;";

 nontransaction N36(C);
      
      /* Execute SQL query */
      result R36( N36.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c36 = R36.begin(); c36 != R36.end(); ++c36) {
            five =  c36[0].as<float>();

         cout << " <= AVG_FUEL for 85 = " << five << endl;
      
      }
       N36.commit();


sql = "SELECT l.DIST/l.GALLON AS AVG_FUEL FROM(SELECT SUM(trpmiles / EPATMPG) AS GALLON, Distance AS DIST FROM (SELECT HOUSEID,PERSONID,trpmiles, EPATMPG, trp.Cooo AS Distance FROM
(SELECT HOUSEID,PERSONID,trpmiles, coo.SU AS Cooo
FROM day,(SELECT SUM(trpmiles) AS SU FROM day WHERE trpmiles <= 90 AND trpmiles >0)coo
WHERE trpmiles <= 90 AND trpmiles > 0 AND VEHID >=1)trp NATURAL JOIN
(SELECT HOUSEID, PERSONID, EPATMPG
FROM vehicle)veh)gal GROUP BY Distance)l;";

 nontransaction N37(C);
      
      /* Execute SQL query */
      result R37( N37.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c37 = R37.begin(); c37 != R37.end(); ++c37) {
            five =  c37[0].as<float>();

         cout << " <= AVG_FUEL for 90 = " << five << endl;
      
      }
       N37.commit();


sql = "SELECT l.DIST/l.GALLON AS AVG_FUEL FROM(SELECT SUM(trpmiles / EPATMPG) AS GALLON, Distance AS DIST FROM (SELECT HOUSEID,PERSONID,trpmiles, EPATMPG, trp.Cooo AS Distance FROM
(SELECT HOUSEID,PERSONID,trpmiles, coo.SU AS Cooo
FROM day,(SELECT SUM(trpmiles) AS SU FROM day WHERE trpmiles <= 95 AND trpmiles >0)coo
WHERE trpmiles <= 95 AND trpmiles > 0 AND VEHID >=1)trp NATURAL JOIN
(SELECT HOUSEID, PERSONID, EPATMPG
FROM vehicle)veh)gal GROUP BY Distance)l;";

 nontransaction N38(C);
      
      /* Execute SQL query */
      result R38( N38.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c38 = R38.begin(); c38 != R38.end(); ++c38) {
            five =  c38[0].as<float>();

         cout << " <= AVG_FUEL for 95 = " << five << endl;
      
      }
       N38.commit();

sql = "SELECT l.DIST/l.GALLON AS AVG_FUEL FROM(SELECT SUM(trpmiles / EPATMPG) AS GALLON, Distance AS DIST FROM (SELECT HOUSEID,PERSONID,trpmiles, EPATMPG, trp.Cooo AS Distance FROM
(SELECT HOUSEID,PERSONID,trpmiles, coo.SU AS Cooo
FROM day,(SELECT SUM(trpmiles) AS SU FROM day WHERE trpmiles <= 100 AND trpmiles >0)coo
WHERE trpmiles <= 100 AND trpmiles > 0 AND VEHID >=1)trp NATURAL JOIN
(SELECT HOUSEID, PERSONID, EPATMPG
FROM vehicle)veh)gal GROUP BY Distance)l;";

 nontransaction N39(C);
      
      /* Execute SQL query */
      result R39( N39.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c39 = R39.begin(); c39 != R39.end(); ++c39) {
            five =  c39[0].as<float>();

         cout << " <= AVG_FUEL for 100 = " << five << endl;
      
      }
       N39.commit();



      cout << "Operation done successfully" << endl;
      C.disconnect ();
   }catch (const std::exception &e){
      cerr << e.what() << std::endl;
      return 1;
   }

   return 0;
}
