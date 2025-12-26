class Solution {
public:
    int bestClosingTime(string customers) {
        int penal = 0;
        for(auto each: customers){
            if(each == 'Y'){
                penal++;
            }
        }
        int min = penal;
        int count = 0;

        for(int i = 0; i < customers.length() ; i++){
            if(customers[i] == 'Y'){
                penal--;
            }
            else{
                penal++;
            }
            if(penal < min){
                min = penal;
                count = i+1;
            }
        }
        return count;
    }
};
