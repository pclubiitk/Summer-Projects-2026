"use client";

import { useState } from "react";
import Link from "next/link";

const API = "http://localhost:8000";

export default function HomePage() {
  const [url, setUrl] = useState("");
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState("");
  const [result, setResult] = useState<{ short_code: string; short_url: string } | null>(null);

  async function handleSubmit(e: React.FormEvent) {
    e.preventDefault();
    setError("");

    let u = url.trim();
    if (!u) { setError("type something duh"); return; }
    if (!u.startsWith("http://") && !u.startsWith("https://")) u = "https://" + u;
    try { new URL(u); } catch { setError("that aint a url bro"); return; }
    if (!new URL(u).hostname.includes(".")) { setError("invalid domain"); return; }

    setLoading(true);
    try {
      const res = await fetch(`${API}/shorten`, {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify({ url: u }),
      });
      if (!res.ok) throw new Error((await res.json().catch(() => ({}))).detail || "Failed");
      setResult(await res.json());
      setUrl("");
    } catch (err) {
      setError(err instanceof Error ? err.message : "idk something broke");
    } finally {
      setLoading(false);
    }
  }

  return (
    <main className="flex flex-col items-center justify-center min-h-screen p-4">
      <div className="w-full max-w-lg text-center space-y-6">
        <h1 className="text-4xl font-bold text-gray-900">mini url</h1>
        <p className="text-gray-500">make big link smol</p>

        <form onSubmit={handleSubmit} className="space-y-3">
          <div className="flex gap-2">
            <input type="text" value={url} onChange={(e) => setUrl(e.target.value)}
              placeholder="paste ur monstrosity here" disabled={loading}
              className="flex-1 px-4 py-3 border border-gray-300 rounded-lg focus:outline-none focus:ring-2 focus:ring-blue-500 text-gray-900 placeholder-gray-400" />
            <button type="submit" disabled={loading}
              className="px-6 py-3 bg-blue-600 text-white font-medium rounded-lg hover:bg-blue-700 disabled:opacity-50 transition-colors">
              {loading ? "..." : "shorten"}
            </button>
          </div>
          {error && <p className="text-red-500 text-sm">{error}</p>}
        </form>

        {result && (
          <div className="bg-white border rounded-lg p-4 space-y-3 shadow-sm">
            <a href={result.short_url} target="_blank" rel="noopener noreferrer"
               className="block text-blue-600 font-medium truncate hover:underline">{result.short_url}</a>
            <Link href={`/${result.short_code}/stats`}
                  className="block text-sm text-gray-500 hover:text-gray-700 underline">
              view stats &rarr;
            </Link>
          </div>
        )}
      </div>
    </main>
  );
}
