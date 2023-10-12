import java.util.Scanner;

abstract class Beverage {
    final void prepareBeverage() {
        boilWater();
        brew();
        pourInCup();
        if (customerWantsCondiments()) {
            addCondiments();
        }
    }
    abstract void brew();
    abstract void addCondiments();
    void pourInCup() {
        System.out.println("To Cup");
    }
    void boilWater() {
        System.out.println("boling water");
    }
    boolean customerWantsCondiments() {
        return true;
    }
}


class Coffee extends Beverage {
    void brew() {
        System.out.println("Brewed coffee powder ");
    }
    void addCondiments() {
        System.out.println("Add milk and suger");
    }
    boolean customerWantsCondiments() {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("weather to add condiment? (y/n): ");
            String choice = scanner.nextLine();
            return choice.equalsIgnoreCase("y");
        }
    }
}


class Tea extends Beverage {
    void brew() {
        System.out.println("Soaking tea leaves");
    }
    void addCondiments() {
        System.out.println("add lemon");
    }
}

public class Main {
    public static void main(String[] args) {
        Beverage coffee = new Coffee();
        Beverage tea = new Tea();

        System.out.println("make coffee:");
        coffee.prepareBeverage();

        System.out.println("\nmake tea:");
        tea.prepareBeverage();
    }
}
