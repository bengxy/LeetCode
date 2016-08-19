class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    	int sq1 = (D-B)*(C-A);
    	int sq2 = (H-F)*(G-E);

    	int lowerTop = std::min(D,H);
    	int upperBot = std::min(B,F);
    	int lefterRight = std::min(C, G);
    	int righterLeft = std::min(A, E);

    	int overlap = 0;
    	if( (lowerTop > upperBot) && (lefterRight > righterLeft))
    		overlap = (lowerTop - upperBot) * (lefterRight - righterLeft);
    	return sq1 + sq2 - overlap;
    }
};