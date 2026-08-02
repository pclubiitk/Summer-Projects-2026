"use client";

// this page shows u how many ppl clicked ur link
// (spoiler: its probably just u refreshing 50 times)

import { useState, useEffect } from "react";
import Link from "next/link";

const API = "http://localhost:8000";

export default function StatsPage({ params }: { params: Promise<{ code: string }> }) {
  const [code, setCode] = useState("");
  const [data, setData] = useState<{ original_url: string; total_clicks: number; created_at: string } | null>(null);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState("");

  useEffect(() => { params.then((p) => setCode(p.code)); }, [params]);

  useEffect(() => {
    if (!code) return;
    setLoading(true);
    fetch(`${API}/${code}/stats`)
      .then((r) => r.ok ? r.json() : Promise.reject())
      .then(setData)
      .catch(() => setError("that code dont exist bro"))
      .finally(() => setLoading(false));
  }, [code]);

  if (!code || loading || (!data && !error)) return <main className="min-h-screen flex items-center justify-center"><p className="text-gray-500">loading...</p></main>;
  if (error) return <main className="min-h-screen flex flex-col items-center justify-center gap-4"><p className="text-red-500">{error}</p><Link href="/" className="text-blue-600 hover:underline text-sm">&larr; go back</Link></main>;

  return (
    <main className="flex flex-col items-center justify-center min-h-screen p-4">
      <div className="w-full max-w-md bg-white border rounded-lg p-6 shadow-sm space-y-4">
        <h1 className="text-2xl font-bold text-gray-900">click stats</h1>
        <p className="text-sm text-gray-500 font-mono">{code}</p>
        <div className="space-y-3">
          <div className="flex justify-between items-center py-2 border-b border-gray-100">
            <span className="text-gray-600">url</span>
            <a href={data.original_url} target="_blank" rel="noopener noreferrer"
               className="text-blue-600 hover:underline text-sm truncate max-w-[250px]">{data.original_url}</a>
          </div>
          <div className="flex justify-between items-center py-2 border-b border-gray-100">
            <span className="text-gray-600">clicks</span>
            <span className="text-3xl font-bold text-gray-900">{data.total_clicks}</span>
          </div>
          <div className="flex justify-between items-center py-2">
            <span className="text-gray-600">created</span>
            <span className="text-sm text-gray-700">{new Date(data.created_at + "Z").toLocaleDateString()}</span>
          </div>
        </div>
        <Link href="/" className="block text-center text-sm text-gray-500 hover:text-gray-700 underline">&larr; shorten another</Link>
      </div>
    </main>
  );
}
