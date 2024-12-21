package bonus.generics;
public class GenericSwap {
    public static <T> void swap(T[] array, int i, int j) {
        T temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    public static void main(String[] args) {
        Integer[] arr = {1, 2, 3, 4};
        swap(arr, 0, 0);
        for (int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
        }
    }
}
