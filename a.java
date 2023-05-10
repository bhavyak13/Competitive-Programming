public class Main
{
	public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int t=in.nextInt();
        for(int i=1; i<=t; i++){
            String s=in.next();
            System.out.println(isValid(s));
        }
    }
    public static int isValid(String s) {
        int maxi=Integer.MAX_VALUE;
        if(s.charAt(0)=='>'){
            return 0;
        }
        Stack<Character> st=new Stack<>();
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i)=='<'){
                st.push(s.charAt(i));
            }
            else{
                if(!st.isEmpty()){
                    st.pop();
                } else{     //st is empty
                    return i;                //
                }
            }
        }
        if(st.isEmpty()){
            return s.length();    //string was totally balanced
        } else{
            return 0;     //contains an open bracket, start prefix not balanced
        }
    }
}
