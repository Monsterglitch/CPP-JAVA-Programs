package Sample;

class parent {
    int a = 10;
    parent() {
        System.out.println("In parent constructor");
    }
    void show() {
        System.out.println(a);
    }
}

class child extends parent {
    child() {
        System.out.println("In child constructor");
    }
    int a = 11;
    void show() {
        System.out.println(a);
    }
}

public class main_pgm {
    public static void main (String[] args) {
        child obj1 = new child();
        obj1.show();
    }
}
