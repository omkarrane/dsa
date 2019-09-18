#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<int> get_primes()
{
  vector<int> temp;
  int num = 2;
  while(temp.size() < 1201)
  {
    bool prime = true;
    for(int i = 2; i * i <= num; i++)
    {
      if(num % i == 0)
      {
        prime = false;
        break;
      }
    }
    if(prime)
      temp.push_back(num);
    num++;
  } 

  return temp;
}

/*
 * Complete the waiter function below.
 */
vector<int> waiter(vector<int> number, int q)
{
  stack<int> b[q+1], a[q+1];

  for (int i = 0; i < number.size(); i++)
    a[0].push(number[i]);

  vector<int> prime = get_primes();

  for (int i = 1; i <= q; i++)
  {
    while (!a[i - 1].empty())
    {
      int a_top = a[i - 1].top();
      a[i - 1].pop();
      if (a_top % prime[i - 1] == 0)
      {
        b[i - 1].push(a_top);
      }
      else
      {
        a[i].push(a_top);
      }
    }
  }

  vector<int> result;
  for(int i = 0; i < q; i++)
  {
    while(!b[i].empty())
    {
      result.push_back(b[i].top());
      b[i].pop();
    }
  }

  while(!a[q].empty())
  {
    result.push_back(a[q].top());
    a[q].pop();
  }

  return result;
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  string nq_temp;
  getline(cin, nq_temp);

  vector<string> nq = split_string(nq_temp);

  int n = stoi(nq[0]);

  int q = stoi(nq[1]);

  string number_temp_temp;
  getline(cin, number_temp_temp);

  vector<string> number_temp = split_string(number_temp_temp);

  vector<int> number(n);

  for (int number_itr = 0; number_itr < n; number_itr++)
  {
    int number_item = stoi(number_temp[number_itr]);

    number[number_itr] = number_item;
  }

  vector<int> result = waiter(number, q);

  for (int result_itr = 0; result_itr < result.size(); result_itr++)
  {
    fout << result[result_itr];

    if (result_itr != result.size() - 1)
    {
      fout << "\n";
    }
  }

  fout << "\n";

  fout.close();

  return 0;
}

vector<string> split_string(string input_string)
{
  string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
    return x == y and x == ' ';
  });

  input_string.erase(new_end, input_string.end());

  while (input_string[input_string.length() - 1] == ' ')
  {
    input_string.pop_back();
  }

  vector<string> splits;
  char delimiter = ' ';

  size_t i = 0;
  size_t pos = input_string.find(delimiter);

  while (pos != string::npos)
  {
    splits.push_back(input_string.substr(i, pos - i));

    i = pos + 1;
    pos = input_string.find(delimiter, i);
  }

  splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

  return splits;
}