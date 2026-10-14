# Aridade - NomeModulo.nomeFunção/numParâmetros

defmodule Example do
  def function(name) do
    IO.puts "Hello #{name}"
  end

  def functionOneLine(name, name2), do: IO.puts "Hello #{name} #{name2}"
end

Example.function("Gustavo");
Example.functionOneLine("Gustavo", "Brendler");
