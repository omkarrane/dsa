#include <bits/stdc++.h>
#define s_int(num) scanf("%d", &num)

using namespace std;
void solve();

class Heap
{
  int size, current = 0;
  int *arr;

public:
  Heap(int n)
  {
    size = n;
    arr = new int[size];
  };

  void insert(int num)
  {
    int curr = current;
    arr[current++] = num;
    while (arr[curr] < arr[get_parent_index(curr)])
    {
      swap(arr[get_parent_index(curr)], arr[curr]);
      curr = get_parent_index(curr);
    }
  };

  int get_parent_index(int pos)
  {
    return floor((pos - 1) / 2);
  };

  int get_left_child_index(int pos)
  {
    return (pos * 2) + 1;
  };

  int get_right_child_index(int pos)
  {
    return (pos * 2) + 2;
  };

  bool has_left_child(int pos)
  {
    return current > get_left_child_index(pos);
  };

  bool has_right_child(int pos)
  {
    return current > get_right_child_index(pos);
  };

  int pop()
  {
    int popped = arr[0];
    int curr = 0;
    arr[0] = arr[current - 1];
    while (has_left_child(curr))
    {
      int max_index = get_left_child_index(curr);
      if (has_right_child(curr) && arr[max_index] >= arr[get_right_child_index(curr)])
        max_index = get_right_child_index(curr);

      if (arr[curr] < arr[max_index])
        break;

      swap(arr[max_index], arr[curr]);
      curr = max_index;
    }
    current--;
    return popped;
  }
};

void solve()
{
  int n;
  s_int(n);
  Heap heap = Heap(n);

  int num;
  for (int i = 0; i < n; i++)
  {
    s_int(num);
    heap.insert(num);
  }

  for (int i = 0; i < n; i++)
    printf("%d ", heap.pop());

  printf("\n");
};

int main()
{
  int t;
  s_int(t);
  while (t--)
  {
    solve();
  }
}