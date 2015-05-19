
Combinaion:
class Solution {
public:
    vector<int> a;
    int target;
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort( candidates.begin(), candidates.end());
	this->target = target;
        this->a = candidates;
        //Can you guarantee the uniqueness of the candidate set?
        //Assume so, then:
        vector<vector<int> > result;
        vector<int> temp;
        dfs(0, 0, result, temp);
        return result;
        
    }
    void dfs(int sum, int index, vector<vector<int> > &result, vector<int> &temp){
        
        
        //termination
        if(sum == target ){
            result.push_back(temp);
            return;
        }
        
        //prune
        
        //IMPORTANT!!! Always put termination before prune: Good for error-proof
        if( (target-sum)<a[index] ) return;
        
        //check for adjacent vertices:
        for( int i=index; i<a.size(); i++){
            //previsit:
            sum+=a[i];
            temp.push_back(a[i]);
            //dfs
            dfs( sum, i, result, temp);
            //post visit
            sum-=a[i];
            temp.pop_back();
        }
        
        
    }
};