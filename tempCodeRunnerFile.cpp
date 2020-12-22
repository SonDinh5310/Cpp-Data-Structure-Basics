void basicsort(vector<int> &a)// n^2 && o(1)
{
    int i, j, temp;
    for(i = 0 ; i < a.size() ; i++)
    {
        for(j = i+1 ; j < a.size(); j++)
        {
            if(a[i]>a[j])
            {
                temp = a[i];
                a[i]= a[j];
                a[j] =temp;
            }
        }
    }
}
void selectionSort(vector<int> &arr)  
{  
    int min_index;
    for(int i = 0; i < arr.size()-1; i++){
    	min_index = i;
    	for(int j = i+1; j < arr.size(); j++){
    	 	if(arr[j] < arr[min_index]){
    			min_index = j;
    			
			}
			
		}
		swap(arr[min_index], arr[i]);
	}
} 
void Merge(vector<int>& arr,int low,int mid,int high){
    vector<int> aux(high-low+1);
    //co 3 truong hop
    int i = low ,j = mid + 1,k;
    for(k = 0; k < aux.size(); k++){
        //truong hop chi co trai (left)
        if(j > high){
            aux[k] = arr[i++];
            continue;
        }
        //truong hop chi co phai (right)
        if(i > mid){
            aux[k] = arr[j++];
            continue;
        }
        //truong hop co ca hai
        if(arr[i] <= arr[j]){
            aux[k] = arr[i++];
        }else aux[k] = arr[j++];
    }
    for(int temp = low; temp <= high; temp++){
        arr[temp] = aux[temp-low];
    }
}
void merge_sort(vector<int>& arr, int low, int high){
    if(low >= high){
        return;
    }
    int mid = low + (high - low)/2; 
    //ben trai 
    merge_sort(arr, low, mid);
    //ben phai
    merge_sort(arr, mid+1, high);
    //
    Merge(arr, low, mid, high);
}

int main()
{
    vector <int> v;
    v.push_back(20);
    v.push_back(90);
    v.push_back(80);
    v.push_back(0);
    v.push_back(-22);
    v.push_back(100);
    v.push_back(5);
    merge_sort(v,0,v.size()-1);
    for(int i = 0 ; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}
