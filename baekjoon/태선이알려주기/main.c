#include <stdio.h>

#include <string.h>

#define COUNT 10

struct movie {

   char title[20]; // 제목

   float rate; // 평점

   int release; // 개봉년도

   char country[5]; // 제작 국가

} MV[10];



int calcLength(struct movie* MV);

int calcRate(struct movie* MV);

float sumRate(struct movie* MV);

int calcRelease(struct movie* MV);

int matchCountry(struct movie* MV);



int main()

{

   struct movie MV[10] = {

   {"007CasinoRoyale", 8.06, 2006, "US" },

    {"Matrix", 9.39, 1999, "US" },

   {"MidnightInParis", 8.53, 2011 , "US" },

   {"BourneIdentity", 8.75, 2002 , "US" },

   {"SpiderManHomeComing", 8.36, 2017 , "US" },

   {"NewWorld", 8.91, 2012, "KR" },

   {"XMan", 8.04, 2000, "US" },

   {"Titanic", 9.34, 1997, "US" },

   {"Terminator2", 9.43, 1991, "US" },

   {"Transformer2", 8.11, 2009, "US" } };

   
   struct movie temp;
   
   

   for (int i = 0; i < COUNT - 1 ; i++)
   {
      for (int j = 0 ; j < COUNT - 1 - i; j++)
      {
         if (MV[j].release > MV[j + 1].release)
         {
            temp = MV[j];
            MV[j] = MV[j+1];
            MV[j+1] = temp;
         }
      }
   }

   int i, titleCount, rateCount, releaseCount, countryCount;

   float rateSum;



   titleCount = calcLength(MV);  //영화제목 길이

   rateCount = calcRate(MV);    //평점

   rateSum = sumRate(MV);       //평점 누적 합계

   releaseCount = calcRelease(MV);   //개봉년도

   countryCount = matchCountry(MV);   //제작 국가



   printf("1. 영화 제목이 7자 이상 (7 포함)인 영화의 개수: %d\n", titleCount);

   printf("2. 영화 평점이 9.00 이상 (9.00 포함)인 영화의 개수: %d\n", rateCount);

   printf("3. 10개의 영화의 누적 평점: %.2f\n", rateSum);

   printf("4. 개봉년도가 2000년 이후(2000년 포함하지 않음) 영화의 개수: %d\n", releaseCount);

   printf("5. 제작국가가 한국(KR)인 영화의 개수: %d\n", countryCount);

   printf("6. 버블 정렬 알고리즘을 이용한 개봉년도의 오름차순 정렬 : ");
   for (int i = 0; i < COUNT; i++)
   {
      printf("%s / ", MV[i].title);
   }

}



int calcLength(struct movie* MV)

{

   int i, len, count = 0;

   for (i = 0; i < 10; i++)

   {

      len = strlen(MV[i].title);

      if (len > 7 || len == 7)

         count++;

   }

   return count;

}



int calcRate(struct movie* MV)

{

   int i, count = 0;

   float rate;

   for (i = 0; i < 10; i++)

   {

      rate = MV[i].rate;

      if (rate > 9.00 || rate == 9)

         count++;

   }

   return count;



}



float sumRate(struct movie* MV)

{

   int i;

   float sum = 0;

   for (i = 0; i < 10; i++)

   {

      sum += MV[i].rate;

   }

   return sum;



}



int calcRelease(struct movie* MV)

{

   int i, release, count = 0;

   for (i = 0; i < 10; i++)

   {

      release = MV[i].release;

      if (release > 2000)

         count++;

   }

   return count;



}



int matchCountry(struct movie* MV)

{

   int i, country, count = 0;

   for (i = 0; i < 10; i++)

   {

      country = !strcmp(MV[i].country, "KR");

      if (country)

         count++;

   }

   return count;



}