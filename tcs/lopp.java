import java.util.*;

public class loopMaster {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<String> placementlelo = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            placementlelo.add(sc.nextLine().trim());
        }
        processCommands(placementlelo);
    }

    private static void processCommands(List<String> placementlelo) {
        Stack<Integer> loopCounts = new Stack<>();
        Stack<Integer> currIter = new Stack<>();
        StringBuilder output = new StringBuilder();
        int index = 0;

        while (index < placementlelo.size()) {
            String command = placementlelo.get(index);
            if (command.startsWith("for")) {
                int times = Integer.parseInt(command.split(" ")[1]);
                loopCounts.push(times);
                currIter.push(0);
            } else if (command.equals("do")) {
                // No operation for "do"
            } else if (command.equals("done")) {
                int current = currIter.pop() + 1;
                int max = loopCounts.pop();
                if (current < max) {
                    loopCounts.push(max);
                    currIter.push(current);
                    index = findLoopStart(placementlelo, index);
                    continue;
                }
            } else if (command.startsWith("break")) {
                int breakAt = Integer.parseInt(command.split(" ")[1]);
                if (currIter.peek() + 1 == breakAt) {
                    loopCounts.pop();
                    currIter.pop();
                    index = findLoopEnd(placementlelo, index);
                }
            } else if (command.startsWith("continue")) {
                int continueAt = Integer.parseInt(command.split(" ")[1]);
                if (currIter.peek() + 1 == continueAt) {
                    int max = loopCounts.peek();
                    int current = currIter.pop() + 1;
                    if (current < max) {
                        currIter.push(current);
                        index = findLoopStart(placementlelo, index);
                    }
                    continue;
                }
            } else if (command.startsWith("print")) {
                String message = command.substring(command.indexOf("\"") + 1, command.lastIndexOf("\""));
                output.append(message).append("\n");
            }
            index++;
        }
        System.out.print(output.toString());
    }

    private static int findLoopStart(List<String> placementlelo, int ci) {
        int nestedLoops = 0;
        for (int i = ci - 1; i >= 0; i--) {
            if (placementlelo.get(i).equals("done")) {
                nestedLoops++;
            } else if (placementlelo.get(i).equals("do")) {
                if (nestedLoops == 0) {
                    return i;
                }
                nestedLoops--;
            }
        }
        return 0;
    }

    private static int findLoopEnd(List<String> placementlelo, int ci) {
        int nestedLoops = 0;
        for (int i = ci + 1; i < placementlelo.size(); i++) {
            if (placementlelo.get(i).equals("do")) {
                nestedLoops++;
            } else if (placementlelo.get(i).equals("done")) {
                if (nestedLoops == 0) {
                    return i;
                }
                nestedLoops--;
            }
        }
        return placementlelo.size();
    }
}