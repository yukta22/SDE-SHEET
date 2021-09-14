//https://www.geeksforgeeks.org/naive-algorithm-for-pattern-searching/

void solve() {

	string txt,pat;
    cin >> txt >> pat;

    int n = txt.size();
    int m = pat.size();

    for(int i = 0 ; i <= n-m ; i++){

        int j;
        for(j = 0 ; j < m ; j++){
            if(txt[i+j] != pat[j]){
                break;
            }
        }
        if(j == m){
            cout << i <<"\n";
        }
    } 

}
