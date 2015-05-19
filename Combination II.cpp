
class Solution {
public:
    vector<int> a;
    int target;
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort( num.begin(), num.end());
        this->target = target;
        this->a = num;
        //Can you guarantee the uniqueness of the candidate set?
        //Assume so, then:
        vector<vector<int> > result;
        vector<int> temp;
        int chosen = 0;
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
        int last_num = -1;//All posiive numbers( in the question, given )
        int counter = 0;
        for( int i=index; i<a.size(); i++){
            //Counter hao hao xie a !!!! laolao shishi xie jiu keyi dui le ,tai huashao rongyi cuo 
            if(a[i] == last_num && counter >=1 ) {
                counter ++;
                continue;
            }else if( a[i] == last_num && counter ==0){
                counter++;
            }else if(a[i]!=last_num){
                counter = 0;
            }
            //previsit:
            sum+=a[i];
            temp.push_back(a[i]);
            //dfs
            dfs( sum, i+1 , result, temp );
            //post visit
            sum-=a[i];
            temp.pop_back();
            last_num = a[i];
            counter ++;
        }
        
        
    }
};