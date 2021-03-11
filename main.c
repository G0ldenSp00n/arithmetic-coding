#include <stdio.h>
#include <string.h>

void encode(char currSymbol, double currInterval[2]) {
  double currIncrement = (currInterval[1] - currInterval[0]) * 0.25;
  switch (currSymbol) {
    case 'W':
      currInterval[1] = currInterval[0] + currIncrement;
      break;
    case 'I':
      currInterval[1] = currInterval[0] + currIncrement * 3;
      currInterval[0] = currInterval[0] + currIncrement;
      break;
    case 'K':
      currInterval[0] = currInterval[0] + currIncrement * 3;
      break;
    default:
      break;
  }
}

void decode(double encodedString, int len) {
  char result[len];
  float currInterval[2] = {0, 1};
  for (int i = 0; i < len; i++) {
    float currIncrement = (currInterval[1] - currInterval[0]) * 0.25;
    float p25 = currInterval[0] + currIncrement;
    float p75 = currInterval[0] + currIncrement * 3;
    if (encodedString < p25) {
      result[i] = 'W';
      printf("W");
      currInterval[1] = p25;
    } else if (p25 <= encodedString && encodedString < p75) {
      result[i] = 'I';
      printf("I");
      currInterval[0] = p25;
      currInterval[1] = p75;
    } else {
      result[i] = 'K';
      printf("K");
      currInterval[0] = p75;
    }
  }
  printf("\n");
}

int main() {
  char compString[] = "WIKIWIKIWIKIWIKI";
  double interval[2] = {0, 1};
  for (int i = 0; i < sizeof(compString) - 1; i++) {
    encode(compString[i], interval);
  }

  printf("encoded: %f\n", interval[0]);
  decode(interval[0], sizeof(compString)-1);
  return 0;
}
