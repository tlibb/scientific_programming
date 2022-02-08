#include <vector>
#include <cstdio>

using namespace std;

vector<double> interpolation(vector<double> const& x, vector<double> const& y, vector<double> &x1)
{

  // --- fill in your interpolation routine here! --- //
    
    
    int np1 = x1.size();
    int np = x.size();
    vector<double> y1(np1);
    
    // we assume x and x1 are sorted
    
    int ii=0;
    int jj=0;
    while(ii<np1){
            if(x1[ii] <= x[0]){
                y1[ii] = y[0];
                ii++;
            }
            else if(x1[ii] > x[jj] && x1[ii] <= x[jj+1]){
                y1[ii] = (y[jj+1]-y[jj])/(x[jj+1]-x[jj])*(x1[ii]-x[jj])+y[jj];
                ii++;
            }
            else if(x1[ii] >= x[np-1]){
                y1[ii] = y[np-1];
                ii++;
            }
        if (jj <= np) {
            jj++;
            ii++;
        }
    }
    
  return y1;
}



int main(){

  // --- input vectors --- //
  vector<double> x = {0, 1.5, 2.0, 4.13, 5};
  vector<double> y = {0,  -3, 0.1, 0.1, -1};


  // --- output grid --- //
  int const nGrid = 1001;
  vector<double> x1(nGrid, 0);

  for(int ii=0; ii<nGrid; ++ii)
    x1[ii] = ii * 5.4 / (nGrid - 1.0) - 0.2; // takes values between (-0.2 and 5.2)


  // --- interpolate --- //
  vector<double> y1 = interpolation(x, y, x1);


  // --- Write input arrays to original.txt --- //
  int nInput = x.size();
  FILE* f = fopen("original.txt", "w");
  for(int ii=0; ii<nInput; ++ii)
    fprintf(f, "%lf %lf\n",x[ii], y[ii]);
  fclose(f);
    
  // --- now you should write x1 and y1 to result.txt --- //
  
  FILE* f2 = fopen("result.txt", "w");
  for(int ii=0; ii<nGrid; ++ii)
    fprintf(f2, "%lf %lf\n",x1[ii], y1[ii]);
  fclose(f2);


  
  
  
  
}
