#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string input1;

    getline ( cin , input1 );
    int size = input1.length();

    //reading the matrix
        //reading columns
    int n = 1;

    for ( int i = 0 ; i < size ; i++ )
    {
        if ( input1[i] == ' ') n++;
        if ( input1[i] == ';') break;
    }
        //reading rows
    int m = 1;

        for ( int i = 0 ; i < size ; i++ )
        {
            if (input1[i] == ';' )m++;
        }


        //reading elements

        float mat1[m][n];
        int x = 1;

        for ( int i = 0 ; i < m ; i++ )
        {
            for ( int j = 0 ; j < n ; j++ )
            {
                int c = 0;

                for ( int k = x ; k < size ; k++ )
                {
                    c++;
                    if ( input1[k] == ' ' || input1[k] == ';' || input1[k] == ']' ) break;
                }
               stringstream sstr;
//             cout<<input1.substr( x , c-1 )<<endl;
               sstr << input1.substr( x , c-1 );
               sstr >> mat1[i][j];
                x += c;
            }
        }
//outputs
/*
    cout<<"n = "<<n<<" m = "<<m<<endl;

    for ( int i = 0 ; i < m ; i++ )
    {
        for ( int j = 0 ; j < n ; j++ )
        {
               cout<<mat1[i][j]<<endl;
        }
    }
*/


// Reading the sign of operation
    string input2;

   string op;
    getline ( cin , op );

// Reading the second matrix

    getline ( cin , input2 );
    int size2 = input2.length();

    //reading the matrix
        //reading columns
    int n2 = 1;

    for ( int i = 0 ; i < size2 ; i++ )
    {
        if ( input2[i] == ' ') n2++;
        if ( input2[i] == ';') break;
    }
        //reading rows
    int m2 = 1;

        for ( int i = 0 ; i < size2 ; i++ )
        {
            if (input2[i] == ';' )m2++;
        }


        //reading elements

        float mat2[m2][n2];
        int x2 = 1;

        for ( int i = 0 ; i < m2 ; i++ )
        {
            for ( int j = 0 ; j < n2 ; j++ )
            {
                int c2 = 0;

                for ( int k = x2 ; k < size2 ; k++ )
                {
                    c2++;
                    if ( input2[k] == ' ' || input2[k] == ';' || input2[k] == ']' ) break;
                }
               stringstream sstr2;
//             cout<<input1.substr( x , c-1 )<<endl;
               sstr2 << input2.substr( x2 , c2-1 );
               sstr2 >> mat2[i][j];
                x2 += c2;
            }
        }
/*
    cout<<"n = "<<n2<<" m = "<<m2<<endl;

    for ( int i = 0 ; i < m2 ; i++ )
    {
        for ( int j = 0 ; j < n2 ; j++ )
        {
               cout<<mat2[i][j]<<endl;
        }
    }
    */

    ///Conversion the operation sign

    stringstream sstr;
    sstr << op;
    char sign;
    sstr >> sign;

  //  cout<<endl<<sign;


    ///The results

    int flag = 0;

  switch(sign) {
      case '+' : //matrix addition
{
        float result[m][n] = {0};

        if ( m != m2 || n != n2 ) { flag = 1; break; }
    for ( int i = 0 ; i < m ; i++ )
    {
        for ( int j = 0 ; j < n ; j++ )
        {
        result [i][j] = mat1 [i][j] + mat2 [i][j];
        }
    }
                //printing
    cout<<"[";

    for ( int i = 0 ; i < m ; i++ )
    {
        for ( int j = 0 ; j < n ; j++ )
        {
        cout << result [i][j];
        if ( j != n - 1 ) cout<<" ";
        }
        if ( i != m - 1 ) cout<<";";
    }

    cout<<"]";

             break;
}

            //matrix subtraction
      case '-' :
            {
        float result[m][n] = {0};

        if ( m != m2 || n != n2 ) { flag = 1; break; }
    for ( int i = 0 ; i < m ; i++ )
    {
        for ( int j = 0 ; j < n ; j++ )
        {
        result [i][j] = mat1 [i][j] - mat2 [i][j];
        }
    }
                //printing
    cout<<"[";

    for ( int i = 0 ; i < m ; i++ )
    {
        for ( int j = 0 ; j < n ; j++ )
        {
        cout << result [i][j];
        if ( j != n - 1 ) cout<<" ";
        }
        if ( i != m - 1 ) cout<<";";
    }

    cout<<"]";

    break;
            }
            //Matrix multiplication
      case '*' :
        {

    if ( n != m2 ) { flag = 1 ; break; }
    float result[m][n2] = {0};

    float multi = 0;

    for ( int i = 0 ; i < m ; i++ )
    {
        for ( int j = 0 ; j < n2 ; j++ )
        {
            multi = 0;
            for ( int k = 0 ; k < n ; k++ )
            {
                multi += ( mat1[i][k] * mat2[k][j] );
            }

            result[i][j] = multi;
        }
    }
            //printing
    cout<<"[";

    for ( int i = 0 ; i < m ; i++ )
    {
        for ( int j = 0 ; j < n2 ; j++ )
        {
        cout << result [i][j];
        if ( j != n2 - 1 ) cout<<" ";
        }
        if ( i != m - 1 ) cout<<";";
    }

    cout<<"]";

            break;
        }
}

        //error output
    if ( flag == 1 ){ cout << "ERROR "; }
}
