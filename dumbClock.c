#include <time.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

#define TWO_MONTHS 5097600
#define SECONDS_IN_YEAR 31536000


double tSeconds(int seconds) {
  double sec = (double) seconds;
  return seconds + sec / 1460;
}

void printTTime(double time) {
  int minutes = (int) time / 60;
  double seconds = time - minutes * 60;

  int hours = minutes / 60;
  minutes = minutes % 60;

  int days = hours / 24;
  hours = hours % 24;

  time_t date = time;
  struct tm *t = localtime(&date);
  printf("%d/%d/%d - ", t->tm_mday, t->tm_mon+1, t->tm_year+1900);

  printf("%2d:%2d:%6.3f\n", hours, minutes, seconds);
}

void handleSIGALRM() {
}

int main() {
  signal(SIGALRM, handleSIGALRM);
  int baseTime = time(NULL);
  int timeCount = 0;

  while (1) {
    alarm(1);

    time_t unixTime = baseTime + timeCount++;

    struct tm *t = localtime(&unixTime);
    int yearInLeap = t->tm_year % 4;
    int currentLeap = (t->tm_year-72) / 4;
    if (t->tm_mon < 3) {
      yearInLeap--;
    }

    int leapStart = currentLeap * (SECONDS_IN_YEAR * 4 + SECONDS_IN_YEAR / 365) + SECONDS_IN_YEAR * 2;
    int secsInLeap = unixTime - leapStart;

    /*unixTime = secsInLeap;
    t = localtime(&unixTime);
    printf("%d %d %d %d:%d:%d\n", t->tm_mday, t->tm_mon, t->tm_year+1900,
           !t->tm_isdst + t->tm_hour, t->tm_min, t->tm_sec);*/

    double tTime = tSeconds(secsInLeap) + leapStart;
    printTTime(tTime);

    pause();
  }
}
