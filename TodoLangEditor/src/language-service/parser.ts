import { TodoLangGrammarParser, TodoExpressionsContext } from "../ANTLR/TodoLangGrammarParser";
import { TodoLangGrammarLexer } from "../ANTLR/TodoLangGrammarLexer";
import { ANTLRInputStream, CommonTokenStream } from "antlr4ts";
import TodoLangErrorListener, { ITodoLangError } from "./TodoLangErrorListener";
import { MyTodoLangGrammarVisitor } from "../ANTLR/TodoLangGrammarVisitor";

function parse(code: string): {ast:TodoExpressionsContext, errors: ITodoLangError[]} {
    const inputStream = new ANTLRInputStream(code);
    const lexer = new TodoLangGrammarLexer(inputStream);
    lexer.removeErrorListeners()
    const todoLangErrorsListner = new TodoLangErrorListener();
    lexer.addErrorListener(todoLangErrorsListner);
    const tokenStream = new CommonTokenStream(lexer);
    const parser = new TodoLangGrammarParser(tokenStream);
    parser.removeErrorListeners();
    parser.addErrorListener(todoLangErrorsListner);
    const ast =  parser.todoExpressions();
    const errors: ITodoLangError[]  = todoLangErrorsListner.getErrors();
    return {ast, errors};
}
export function parseAndGetASTRoot(code: string): TodoExpressionsContext {
    const {ast} = parse(code);
    return ast;
}
export function parseAndGetSyntaxErrors(code: string): ITodoLangError[] {
    const {errors} = parse(code);
    return errors;
}
export function parseTODO(ast: TodoExpressionsContext): String[]{
    const visitor = new MyTodoLangGrammarVisitor();
    visitor.visitTodoExpressions(ast);
    let out = visitor.getTodos();
    return out;
}