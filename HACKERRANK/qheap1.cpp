#include <bits/stdc++.h>

using namespace std;
#define si(num) scanf("%d", &num)
#define fo(k, n) for (int i = k; i < n; i++)

class Heap
{
  vector<int> arr;

public:
  Heap(){

  };

  int get_left_child_index(int index)
  {
    return index * 2 + 1;
  };

  int get_right_child_index(int index)
  {
    return index * 2 + 2;
  };

  int has_left_child(int index)
  {
    return get_left_child_index(index) <= arr.size();
  };

  int has_right_child(int index)
  {
    return get_right_child_index(index) <= arr.size();
  };

  int get_left_child(int index)
  {
    return arr[get_left_child_index(index)];
  };

  int get_right_child(int index)
  {
    return arr[get_right_child_index(index)];
  };

  int get_parent_index(int index)
  {
    if (index & 1)
      return index / 2;
    return (index / 2) - 1;
  };

  int has_parent(int index)
  {
    return index != 0;
  };

  int get_parent(int index)
  {
    return arr[get_parent_index(index)];
  };

  int get_elem_at(int index)
  {
    return arr[index];
  };

  void insert(int elem)
  {
    arr.push_back(elem);
    heapify_up();
  };

  void remove_elem(int elem)
  {
    int index = -1;
    fo(0, arr.size())
    {
      if (arr[i] == elem)
      {
        index = i;
        break;
      }
    };

    swap_elements(index, arr.size() - 1);

    heapify_down();
    heapify_up();
  };

  void heapify_up()
  {
    int curr_index = arr.size();
    while (has_parent(curr_index) && get_elem_at(curr_index) > get_parent(curr_index))
    {
      swap_elements(curr_index, get_parent_index(curr_index));
      curr_index = get_parent_index(curr_index);
    };
  };

  void heapify_down()
  {
    int curr_index = 0;
    while (has_left_child(curr_index))
    {
      int smaller_index = get_left_child_index(curr_index);

      if (has_right_child(curr_index) && get_elem_at(smaller_index) > get_elem_at(get_right_child_index(curr_index)))
        smaller_index = get_right_child_index(curr_index);

      if (get_elem_at(curr_index) > get_elem_at(smaller_index))
      {
        swap_elements(curr_index, smaller_index);
        curr_index = smaller_index;
      }
      else
        break;
    }
  };

  void swap_elements(int pos1, int pos2)
  {
    int temp_elem = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp_elem;
  };
};

int main()
{
  int n, temp;
  si(n);

  Heap heap = Heap();
  fo(0, n)
  {
    int q, elem;
    si(q);

    if (q == 1)
    {
      si(elem);
      heap.insert(elem);
    }
    else if (q == 2)
    {
      si(elem);
      heap.remove_elem(elem);
    }
    else
    {
      cout << heap.get_elem_at(0) << "\n";
    }
  }

  return 0;
}