public class client {
    public static void main(String[] args) {
        int[] arr = { 12, 15, -5, 6, 2, 8, 10, -12, 3, 4, 25, 16, 0, -1 };
        heap obj = new heap(arr, true);
        obj.push(-30);
        while (obj.size() != 0) {
            System.out.println(obj.top());
            obj.pop();
        }
        // obj.display();
    }
}