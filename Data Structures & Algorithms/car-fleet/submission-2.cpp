class Solution {
public:
    struct Car{
        int position;
        int speed;
        float time;
        Car(int target, int position, int speed){
            this->position = position;
            this->speed = speed;
            time = (float)(target - position)/speed;
        }
        bool operator <(const Car thatCar) const {
            return position > thatCar.position;
        }
    };

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int result = 0;
        vector<Car> fleets;
        float slowestTimeInFront = 0.0;
        // add all items to the fleets vector
        for (int i = 0 ; i < position.size(); i++){
            fleets.push_back(Car(target, position[i], speed[i]));
        }
        sort(fleets.begin(), fleets.end());

        
        for (int i = 0; i < fleets.size(); i++){          
            //check to see if this car arives before the car infront of it 
            if (fleets[i].time > slowestTimeInFront) {
                result++;
                slowestTimeInFront = fleets[i].time;
            }
            
        }

        

        return result;
    }
};
