package com.wipro.cab.entity;

public class CabDepot {
    private static Cab[] cabs;
    private float rentAmount;
    private Cab bookedCab;

    public static Cab[] getCabs() {
        return cabs;
    }

    public static void setCabs(Cab[] cabs) {
        CabDepot.cabs = cabs;
    }

    public void calculateRent(String cabType, int days) {
        for (Cab cab : cabs) {
            if (cab.isAvailable() && cab.getCabType().equalsIgnoreCase(cabType)) {
                rentAmount = getRatePerDay(cabType) * days;
                bookedCab = cab;
                cab.setAvailable(false);
                return;
            }
        }
        rentAmount = 0.0f;
    }

    public float getRatePerDay(String cabType) {
        switch (cabType.toLowerCase()) {
            case "micro":
                return 2525.0f * 1.1f;
            case "mini":
                return 3110.0f * 1.12f;
            case "sedan":
                return 3500.0f * 1.16f;
            default:
                return 0.0f;
        }
    }

    public String getBookedCabDetails() {
        if (bookedCab != null) {
            return "Cab Type:" + bookedCab.getCabType() +
                   "\nCab No:" + bookedCab.getRegNo() +
                   "\nAmount:Rs." + rentAmount;
        }
        return "Car Not Available";
    }
}
