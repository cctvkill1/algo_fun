// qsort.cpp :  分治法-快速排序
//

#include <iostream>  
#include <ctime>  
#include <cstdlib> // 产生随机数  

using namespace std;

void exchange(int *arElem, int m, int n)
{
  int tmp = arElem[m];
  arElem[m] = arElem[n];
  arElem[n] = tmp;
}

int partion(int *arElem, int p, int r)
{
  int x = arElem[r];
  int i = p;
  for(int j = p; j < r; j++)
  {
    if(arElem[j] < x)
    {
      if(i != j)
      {
        exchange(arElem, i, j);
      }
      i++;
    }
  }
  exchange(arElem, i, r);
  return i;
}

void quick_sort(int *arElem, int p, int r)
{
  if(p < r)
  {
    int mid = partion(arElem, p, r);
    quick_sort(arElem, p, mid - 1);
    quick_sort(arElem, mid + 1, r);
  }
}

void Quick_Sort(int *arElem, int n)
{
  quick_sort(arElem, 0, n - 1);
}

void print(int *list, int length) {  
 int count = 0;  
 for(int i = 0; i < length; i++) {  
  cout << list[i]<<' ';  
  count++;  
  if(count % 10 == 0)  
   cout << endl;  
}  
}  


int main(int argc, char* argv[])
{ 

 int length = 100;
 int num;
 int num_list[length];  
 for (int i = 0; i < length; i++){  
  num = (rand() + time(0)) %1000;   
  num_list[i] = num;    
}  
cout << "intList before sorting: " << endl;  
print(num_list, length);  
Quick_Sort(num_list,length); 
cout << "intList after quick sort: " << endl;   
print(num_list, length);  
cout << endl;  


system("Pause");  
return 0;  

}  

