#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
  string x;
  getline(cin, x);
  
  stringstream ss(x);
  string token;
  vector<string> time_part;

  while (getline(ss, token, ':')) {
    if (token.find("AM") != string::npos) {
      token.erase(token.length() - 2, 2);
      time_part.push_back(token);
      time_part.push_back("AM");
    }
    else if (token.find("PM") != string::npos) {
      token.erase(token.length() - 2, 2);
      time_part.push_back(token);
      time_part.push_back("PM");
    }
    else time_part.push_back(token);
  }

  string time_period = *time_part.rbegin();
  int hour = stoi(time_part[0]);

  if (time_period == "AM") {
    if (hour == 12) hour = 0;
  } else if (hour != 12) hour += 12;

  cout << setfill('0') << setw(2) << hour;
  for (int i = 1; i < time_part.size() - 1; i++) {
    cout << ":" << time_part[i];
  }

  return 0;
}