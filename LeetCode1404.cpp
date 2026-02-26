class Solution {
public:
    int numSteps(string s) {
         
        unsigned long long decimal = std::bitset<64>(s).to_ulong();
        int pasos = 0;

         while (decimal != 1 || decimal < 1) {
            if (decimal%2 == 0)
            {
                decimal = decimal / 2;
                pasos++;
            }
            else
            {
                decimal = decimal + 1;
                pasos++;
            }
         }
        return pasos;
    }
};
