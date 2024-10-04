package com.wipro.cab.service;

import com.wipro.cab.entity.CabDepot;
import com.wipro.cab.exception.InvalidDataException;
import com.wipro.cab.exception.ServiceUnavailableException;

public class CabRentalService {

    public String validateRoute(String source, String destination) throws ServiceUnavailableException {
        if (source == null || destination == null || source.isEmpty() || destination.isEmpty() || source.equalsIgnoreCase(destination)) {
            return "Invalid Route";
        }

        String[] validRoutes = {"CBE", "MAD", "TEN", "KDL", "OTY"};
        boolean validSource = false, validDestination = false;

        for (String route : validRoutes) {
            if (route.equalsIgnoreCase(source)) validSource = true;
            if (route.equalsIgnoreCase(destination)) validDestination = true;
        }

        if (validSource && validDestination) {
            return "Available";
        } else {
            throw new ServiceUnavailableException();
        }
    }

    public String validateData(String source, String destination, String cabType, int days) {
        try {
            String routeValidation = validateRoute(source, destination);
            if ("Available".equalsIgnoreCase(routeValidation)) {
                if ((cabType.equalsIgnoreCase("mini") || cabType.equalsIgnoreCase("micro") || cabType.equalsIgnoreCase("sedan")) && days > 1) {
                    return "Valid";
                } else {
                    throw new InvalidDataException();
                }
            } else {
                return routeValidation;
            }
        } catch (ServiceUnavailableException e) {
            return e.toString();
        } catch (InvalidDataException e) {
            return e.toString();
        }
    }

    public String bookCab(String source, String destination, String cabType, int days) {
        String validation = validateData(source, destination, cabType, days);
        if ("Valid".equals(validation)) {
            CabDepot depot = new CabDepot();
            depot.calculateRent(cabType, days);
            return depot.getBookedCabDetails();
        } else {
            return validation;
        }
    }
}
