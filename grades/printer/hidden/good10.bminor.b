//	CSE 40243 B-Minor Parser
//	Enter a valid  B-Minor Code 

//	Scan Successful
//	Parse Successful
a: array [] integer  = { 100, 200, 300, 400, 500, 600, 700, 800, 900 };
b: array [] integer ;
c: array [] array [] integer ;
testfunc: function void()  = 
{
    i: integer ;
    
    j: integer ;
    
    for (i = 0; i < 10; i++ )
        
        {
            b[i] = a[i] * 10;
            
        }
        for (i = 0; i < 5; i++ )
        
        {
            b[i * 2] = a[i] + b[i];
            
        }
        for (j = 0; j < 10; i++ )
        
        {
            for (i = 0; i < 10; i++ )
                
                {
                    c[i][j] = i * j;
                    
                }
                
        }
        for (j = 0; j < 10; i++ )
        
        {
            for (i = 0; i < 10; i++ )
                
                {
                    print c[i][j];
                    print " ";
                    
                }
                print "\n";
            
        }
        
}

