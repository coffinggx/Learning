struct Stack<T> {
    stack: Vec<T>,
}
impl<T> Stack<T> {
    fn new() -> Self {
        Stack { stack: Vec::new() }
    }
    fn pop(&mut self) -> Option<T> {
        self.stack.pop()
    }
    fn push(&mut self, item: T) {
        self.stack.push(item);
    }
    fn empty(&self) -> bool {
        self.stack.is_empty()
    }
    fn peek(&self) -> Option<&T> {
        self.stack.last()
    }
}
fn main() {
    let mut stack: Stack<i32> = Stack::new();
    stack.push(2);
    println!("{}", stack.peek().unwrap());
}
