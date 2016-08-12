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
      nontransaction N(C);
      
      /* Execute SQL query */
      result R( N.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
            five =  c[0].as<float>();

         cout << " <= 15 = " << five << endl;
      
      }
       N.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=20)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N(C);
      
      /* Execute SQL query */
      result R( N.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
            five =  c[0].as<float>();

         cout << " <= 20 = " << five << endl;
      
      }
       N.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=25)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N(C);
      
      /* Execute SQL query */
      result R( N.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
            five =  c[0].as<float>();

         cout << " <= 25 = " << five << endl;
      
      }
       N.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=30)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N(C);
      
      /* Execute SQL query */
      result R( N.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
            five =  c[0].as<float>();

         cout << " <= 30 = " << five << endl;
      
      }
       N.commit();


 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=35)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N(C);
      
      /* Execute SQL query */
      result R( N.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
            five =  c[0].as<float>();

         cout << " <= 35 = " << five << endl;
      
      }
       N.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=40)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N(C);
      
      /* Execute SQL query */
      result R( N.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
            five =  c[0].as<float>();

         cout << " <= 40 = " << five << endl;
      
      }
       N.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=45)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N(C);
      
      /* Execute SQL query */
      result R( N.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
            five =  c[0].as<float>();

         cout << " <= 45 = " << five << endl;
      
      }
       N.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=50)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N(C);
      
      /* Execute SQL query */
      result R( N.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
            five =  c[0].as<float>();

         cout << " <= 50 = " << five << endl;
      
      }
       N.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=55)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N(C);
      
      /* Execute SQL query */
      result R( N.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
            five =  c[0].as<float>();

         cout << " <= 55 = " << five << endl;
      
      }
       N.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=60)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N(C);
      
      /* Execute SQL query */
      result R( N.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
            five =  c[0].as<float>();

         cout << " <= 60 = " << five << endl;
      
      }
       N.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=65)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N(C);
      
      /* Execute SQL query */
      result R( N.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
            five =  c[0].as<float>();

         cout << " <= 65 = " << five << endl;
      
      }
       N.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=70)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N(C);
      
      /* Execute SQL query */
      result R( N.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
            five =  c[0].as<float>();

         cout << " <= 70 = " << five << endl;
      
      }
       N.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=75)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N(C);
      
      /* Execute SQL query */
      result R( N.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
            five =  c[0].as<float>();

         cout << " <= 75 = " << five << endl;
      
      }
       N.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=80)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N(C);
      
      /* Execute SQL query */
      result R( N.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
            five =  c[0].as<float>();

         cout << " <= 80 = " << five << endl;
      
      }
       N.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=85)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N(C);
      
      /* Execute SQL query */
      result R( N.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
            five =  c[0].as<float>();

         cout << " <= 85 = " << five << endl;
      
      }
       N.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=90)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N(C);
      
      /* Execute SQL query */
      result R( N.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
            five =  c[0].as<float>();

         cout << " <= 90 = " << five << endl;
      
      }
       N.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=95)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N(C);
      
      /* Execute SQL query */
      result R( N.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
            five =  c[0].as<float>();

         cout << " <= 95 = " << five << endl;
      
      }
       N.commit();

 sql = "SELECT (CAST(dist.d AS DECIMAL)/dall.h)*100 AS Percent FROM (SELECT COUNT(TRPMILES) AS d FROM day WHERE TRPMILES >= 0 AND TRPMILES <=100)dist, (SELECT COUNT(TRPMILES) AS h FROM day WHERE TRPMILES >= 0)dall;";

      /* Create a non-transactional object. */
      nontransaction N(C);
      
      /* Execute SQL query */
      result R( N.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
            five =  c[0].as<float>();

         cout << " <= 100 = " << five << endl;
      
      }
       N.commit();

      cout << "Operation done successfully" << endl;
      C.disconnect ();
   }catch (const std::exception &e){
      cerr << e.what() << std::endl;
      return 1;
   }

   return 0;
}
