class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        array<int, 12> mon = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        int alarmon = stoi(arriveAlice.substr(0, 2));
        int allvmon = stoi(leaveAlice.substr(0, 2));
        int bobarmon = stoi(arriveBob.substr(0, 2));
        int boblvmon = stoi(leaveBob.substr(0, 2));
        if(allvmon < bobarmon || alarmon > boblvmon){
            return 0;
        }

        int alard = stoi(arriveAlice.substr(3, 2));
        int allvd = stoi(leaveAlice.substr(3, 2));
        int bobard = stoi(arriveBob.substr(3, 2));
        int boblvd = stoi(leaveBob.substr(3, 2));
        
        int cnt = 0;
        for(int i = 1; i <= 12; i++){
            if(i < alarmon || i > allvmon || i < bobarmon || i > boblvmon){
                continue;
            }

            int alst = (i == alarmon) ? alard : 1;
            int alend = (i == allvmon) ? allvd : mon[i-1];
            int bobst = (i == bobarmon) ? bobard : 1;
            int bobend = (i == boblvmon) ? boblvd : mon[i-1];

            for(int j = 1; j <= mon[i-1]; j++){
                if(j >= alst && j >= bobst && j <= alend && j <= bobend){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};