#include "iostream"
using namespace std;

int main(int argc, char const *argv[]) {
  double fractions[3][25]  =
{{0.011449,
0.011342,
0.011128,
0.036059,
0.036059,
0.011342,
0.011236,
0.011024,
0.035722,
0.035722,
0.011128,
0.011024,
0.010816,
0.035048,
0.035048,
0.036059,
0.035722,
0.035048,
0.113569,
0.113569,
0.036059,
0.035722,
0.035048,
0.113569,
0.113569},
{2,2,2,1,1, 2,2,2,1,1 ,2,2,2,1,1, 1,1,1,0,0, 1,1,1,0,0},
{0,0,1,0,0, 0,0,1,0,0, 1,1,1,1,1, 0,0,1,0,0, 0,0,1,0,0}}; // Data from 1 higgs decay. Second layaer shows how much leptons we have in decay. Third layer shows how much Tau we have (just 1 or 0 means we have it or not)

double r_fractions[3][25]  =
{{0.011664,
0.011556,
0.01134,
0.03672,
0.03672,
0.011556,
0.011449,
0.011235,
0.03638,
0.03638,
0.01134,
0.011235,
0.011025,
0.0357,
0.0357,
0.03672,
0.03638,
0.0357,
0.1156,
0.1156,
0.03672,
0.03638,
0.0357,
0.1156,
0.1156},
{2,2,2,1,1, 2,2,2,1,1 ,2,2,2,1,1, 1,1,1,0,0, 1,1,1,0,0},
{0,0,1,0,0, 0,0,1,0,0, 1,1,1,1,1, 0,0,1,0,0, 0,0,1,0,0}}; // The same, but with relative fractions. All fractions are in the same order as in papper.

double sum_fractions = 0;
double sum_r_fractions = 0;
for (size_t i = 0; i < 25; i++) {
  sum_fractions += fractions[0][i];
  sum_r_fractions += r_fractions[0][i];
  //std::cout << "Fractions sum: " << fractions[0][i] << '\n';
  //std::cout << "Relative fractions sum: " << r_fractions[0][i] << '\n';
}

std::cout << "Fractions sum: " << sum_fractions << '\n';
std::cout << "Relative fractions sum: " << sum_r_fractions << '\n';

double HH_Fractrions[25][25][3];
double HH_r_Fractrions[25][25][3];

for (size_t i = 0; i < 25; i++) {
  for (size_t j = 0; j < 25; j++) {
    for (size_t k = 0; k < 3; k++) {
      HH_Fractrions[i][j][k] = 0;
      HH_r_Fractrions[i][j][k] = 0;

    }
  }
}


for (size_t i = 0; i < 25; i++) {
  for (size_t j = 0; j < 25; j++) {
    HH_Fractrions[i][j][0] += fractions[0][i]*fractions[0][j]; // Calulation of channel fraction for double Higgs.
    HH_Fractrions[i][j][1] += fractions[1][i] + fractions[1][j]; // Calulations of how muchg leptons we have in channel.
    if ((fractions[2][i] || fractions[2][j]) == 1) HH_Fractrions[i][j][2] = 1; // Check for leptton channel;
  }
}


//Same stuff as above, but for relative fraction;
for (size_t i = 0; i < 25; i++) {
  for (size_t j = 0; j < 25; j++) {
    HH_r_Fractrions[i][j][0] += r_fractions[0][i]*r_fractions[0][j];
    HH_r_Fractrions[i][j][1] += r_fractions[1][i] + r_fractions[1][j];
    if ((r_fractions[2][i] || r_fractions[2][j]) == 1) HH_r_Fractrions[i][j][2] = 1;
  }
}

double HH_Frac_full = 0;
double HH_Frac_4l_w = 0;
double HH_Frac_3l1q_w = 0;
double HH_Frac_2l2q_w = 0;
double HH_Frac_1l3q_w = 0;
double HH_Frac_4q_w = 0;

double HH_r_Frac_full = 0;
double HH_r_Frac_4l_w = 0;
double HH_r_Frac_3l1q_w = 0;
double HH_r_Frac_2l2q_w = 0;
double HH_r_Frac_1l3q_w = 0;
double HH_r_Frac_4q_w = 0;


double HH_Frac_t = 0;
double HH_r_Frac_t = 0;


for (size_t i = 0; i < 25; i++) {
  for (size_t j = 0; j < 25; j++) {
    HH_Frac_full    += HH_Fractrions[i][j][0];
    HH_r_Frac_full  += HH_r_Fractrions[i][j][0];

    // 4 quarcs channel (8 in totoal)
    if (HH_Fractrions[i][j][1] == 0 && HH_r_Fractrions[i][j][2] == 0) {
      HH_Frac_4q_w   += HH_Fractrions[i][j][0];
      HH_r_Frac_4q_w += HH_r_Fractrions[i][j][0];
    }

    if (HH_Fractrions[i][j][1] == 1 && HH_r_Fractrions[i][j][2] == 0) {
      HH_Frac_1l3q_w   += HH_Fractrions[i][j][0];
      HH_r_Frac_1l3q_w += HH_r_Fractrions[i][j][0];
    }

    if (HH_Fractrions[i][j][1] == 2 && HH_r_Fractrions[i][j][2] == 0) {
      HH_Frac_2l2q_w   += HH_Fractrions[i][j][0];
      HH_r_Frac_2l2q_w += HH_r_Fractrions[i][j][0];
    }

    if (HH_Fractrions[i][j][1] == 3 && HH_r_Fractrions[i][j][2] == 0) {
      HH_Frac_3l1q_w   += HH_Fractrions[i][j][0];
      HH_r_Frac_3l1q_w += HH_r_Fractrions[i][j][0];
    }

    if (HH_Fractrions[i][j][1] == 4 && HH_r_Fractrions[i][j][2] == 0) {
      HH_Frac_4l_w   += HH_Fractrions[i][j][0];
      HH_r_Frac_4l_w += HH_r_Fractrions[i][j][0];
    }

    if (HH_r_Fractrions[i][j][2] == 1) {
      HH_Frac_t += HH_Fractrions[i][j][0];
      HH_r_Frac_t += HH_r_Fractrions[i][j][0];
    }

  }
}

cout << "Full Fraction:      " << HH_Frac_full    << " " << HH_r_Frac_full <<'\n';
cout << "4 quarcks channel:  " << HH_Frac_4q_w    << " " << HH_r_Frac_4q_w <<'\n';
cout << "3 quarcs 1 lepton:  " << HH_Frac_1l3q_w  << " " << HH_r_Frac_1l3q_w <<'\n';
cout << "2 quarcs 2 leptons: " << HH_Frac_2l2q_w  << " " << HH_r_Frac_2l2q_w <<'\n';
cout << "1 quarc  3 leptons: " << HH_Frac_3l1q_w  << " " << HH_r_Frac_3l1q_w <<'\n';
cout << "4 lepton channel:   " << HH_Frac_4l_w    << " " << HH_r_Frac_4l_w <<'\n';
cout << "Tau channels:       " << HH_Frac_t       << " " << HH_r_Frac_t <<'\n';

cout << "Full Fractions dc:      " << HH_Frac_4q_w + HH_Frac_1l3q_w + HH_Frac_2l2q_w + HH_Frac_3l1q_w + HH_Frac_4l_w + HH_Frac_t << " " <<  HH_r_Frac_4q_w + HH_r_Frac_1l3q_w + HH_r_Frac_2l2q_w  + HH_r_Frac_3l1q_w + HH_r_Frac_4l_w + HH_r_Frac_t <<'\n';



  return 0;
}
