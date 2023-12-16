module simple_function
    use iso_c_binding, only: c_double

    implicit none
    private
    
    public:: sum2
    
contains

! ----------------------------------------
! Sum two real values
pure function sum2(x,y) result(z) bind(c)
    implicit none
    real(c_double), value:: x, y
    real(c_double):: z
    
    z = x+y

end function sum2
! ----------------------------------------


end module simple_function