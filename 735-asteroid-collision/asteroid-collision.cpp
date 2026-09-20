class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int asteroid : asteroids) {
            
            // Collision can happen only when:
            // top asteroid is moving right (+)
            // current asteroid is moving left (-)
            bool destroyed = false;

            while (!st.empty() && st.back() > 0 && asteroid < 0) {
                
                if (st.back() < -asteroid) {
                    // Stack asteroid is smaller -> it explodes
                    st.pop_back();
                }
                else if (st.back() == -asteroid) {
                    // Both are same size -> both explode
                    st.pop_back();
                    destroyed = true;
                    break;
                }
                else {
                    // Current asteroid is smaller -> it explodes
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push_back(asteroid);
            }
        }

        return st;
    }
};