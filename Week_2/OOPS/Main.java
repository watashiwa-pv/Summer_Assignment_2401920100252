public class Main {
    public static void main(String[] args) {

        System.out.println("===== Car =====");
        Car car = new Car("UP32AB1234", "Amit Kumar", 80, true);
        car.displayInfo();
        double carFare = car.calculateFare(15);
        System.out.println("Fare for 15 km: " + carFare);

        System.out.println();
        System.out.println("===== Bike =====");
        Bike bike = new Bike("UP32XY5678", "Neha Gupta", 60, true);
        bike.displayInfo();
        double bikeFare = bike.calculateFare(10);
        System.out.println("Fare for 10 km: " + bikeFare);

        System.out.println();
        System.out.println("===== Bus =====");
        Bus bus = new Bus("UP32CD9999", "Rajesh Transport", 50, 40);
        bus.displayInfo();
        bus.bookSeat();
        bus.bookSeat();
        bus.bookSeat();
        double busFare = bus.calculateFare(20);
        System.out.println("Fare per person for 20 km: " + busFare);

        System.out.println();
        System.out.println("===== Polymorphism Demo =====");
        Vehicle[] vehicles = { car, bike, bus };
        double distance = 12;
        for (Vehicle v : vehicles) {
            System.out.println(v.getClass().getSimpleName() + " fare for " + distance + " km: " + v.calculateFare(distance));
        }
    }
}
