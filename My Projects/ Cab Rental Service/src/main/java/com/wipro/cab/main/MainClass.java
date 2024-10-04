package com.wipro.cab.main;

import com.wipro.cab.entity.Cab;
import com.wipro.cab.entity.CabDepot;
import com.wipro.cab.service.CabRentalService;

public class MainClass {
    public static void main(String[] args) throws Exception {
        // Cab depot initialization
        Cab[] cabs = new Cab[3];
        cabs[0] = new Cab(601, "mini", "TN37AP0007", true);
        cabs[1] = new Cab(602, "micro", "TN06CX7536", false);
        cabs[2] = new Cab(603, "sedan", "TN28JA1234", true);

        CabDepot.setCabs(cabs);

        // Cab rental service
        CabRentalService cabService = new CabRentalService();
        System.out.println(cabService.bookCab("TEN", "CBE", "mini", 2));
    }
}
